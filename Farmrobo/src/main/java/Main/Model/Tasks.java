package Main.Model;

import Main.Functions.Koodinates;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

import static java.lang.Thread.sleep;

public class Tasks {

    static ArrayList tasks = new ArrayList();

    public void add(Koodinates k){
        System.out.println(k.toString());
        tasks.add(k);
    }

    public Koodinates getNext(){
        if(tasks.size()< 1){
            return null;
        }
        Koodinates k = (Koodinates) tasks.get(0);
        tasks.remove(k);
        System.out.println(k.toString());
        return k;
    }
    public void getControls(){
        Runnable task = () -> {
            int dat = 0;
            while(true) {
                try {
                    String control = ladeDatei(dat+".control");
                    dat++;
                    if(dat > 1000){
                        dat = 0;
                    }
                    //Todo Implementiere hier die verstrickung zu den einzelnen Tasks hin und wie sie arbeiten sollen.
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
}
