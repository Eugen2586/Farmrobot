package Main.Model;

import Constants.AktualKoodinates;
import Main.Functions.Koodinates;
import Main.Functions.engine;

import java.io.*;
import java.util.ArrayList;

import static java.lang.Thread.sleep;

public class Tasks {

    static ArrayList  tasks;

    public Tasks(){
        if( tasks == null){
            tasks = new ArrayList();
        }
    }

    public void add(Koodinates k){
        tasks.add(k);
    }

    public Koodinates getNext(){
        if(tasks.size() < 1){
            return null;
        }
        Koodinates k = (Koodinates) tasks.get(0);
        tasks.remove(k); //Todo Vorsichtig hier wird eigentlich der Wert heraus gelöscht.
        return k;
    }
    public void getControls(){
        System.out.println("Erreiche get Controls.");
        Runnable task = () -> {
            AktualKoodinates g = new AktualKoodinates();
            int x = g.getX();
            int y = g.getY();
            int z = g.getZ();
            int dat = 0;
            schreibeDatei("OrdnerZurDateiEinlesung.con");
            while(true) {
                System.out.println("Taskeingelesen!");
                try {
                    String control = ladeDatei(dat+".control");
                    dat++;
                    if(dat > 1000){
                        dat = 0;
                    }
                    //Todo Implementiere hier die verstrickung zu den einzelnen Tasks hin und wie sie arbeiten sollen.
                    if( control == "A"){
                        x++;
                    }
                    if( control == "D"){
                        x--;
                    }
                    if( control == "W"){
                        y++;
                    }
                    if( control == "S"){
                        y--;
                    }
                    if( control == "Q"){
                        z++;
                    }
                    if( control == "E"){
                        z--;
                    }
                   tasks.add(new Koodinates(x,y,z,"manuell", "true"));
                }catch(Exception e){
                    dat = 0;
                }
            }
        };
        task.run();
        System.out.println("Das System wurde gestartet!");
        Thread thread = new Thread(task);
        thread.start();
    }

    private static String ladeDatei(String datName) {
        String inFile = new String();
        File file = new File(datName);

        if (!file.canRead() || !file.isFile())
            System.exit(0);

        BufferedReader in = null;
        try {
            in = new BufferedReader(new FileReader(datName));
            String zeile = null;
            while ((zeile = in.readLine()) != null) {
                inFile += zeile;
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (in != null)
                try {
                    in.close();
                } catch (IOException e) {
                }
        }
        return inFile;
    }
    private void schreibeDatei(String dat){
        File file = new File(dat);
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(file, true)); //Text wird ans Dateiende angehangen
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
