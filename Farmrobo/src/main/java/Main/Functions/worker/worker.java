package Main.Functions.worker;

/*
 * 1. Task aus Liste nehmen
 * 1.a Task interpretieren
 * 2. Kommunikation zum Chip aufbauen
 * 3. Task in für Chip verständilches Fromat übersetzen
 * 4. Task versenden
 * 5. Auf Antwort warten
 * 6. Neuen Befehl abarbeiten/erwarten
 */

import Main.Functions.Communictaion.toServer;
import Main.Functions.Koodinates;
import Main.Functions.Read;
import Main.Functions.engine;
import Main.Model.Tasks;

import java.io.IOException;
import java.util.ArrayList;

import static java.lang.Thread.sleep;

public class worker{
    Tasks tasks;
    Koodinates k = null;
    engine e = new engine(0,0,0);

    boolean engineStop = false;


    public void work() {
        this.tasks = new Tasks();
        System.out.println("Das System wurde gestartet!");
        dateieinlesenWorker();
        Runnable task1 = () -> {
            toServer x = null;
            try {
                x = new toServer();
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
            while(ifWork()) {

                k = getNext();
                if(k != null) {
                    System.out.println("einen Task abgearbeitet!");
                    if (compX() != 0) {
                        try {
                            x.schreibeNachricht(x.getX_Ray_ComPort(), compX() < 0 ? "S":"W");
                            System.out.println("" + x.leseNachricht(x.getX_Ray_ComPort()));
                        } catch (IOException ioException) {
                            ioException.printStackTrace();
                        }
                    }
                    if (compY() != 0) {

                    }
                    if (compZ() != 0) {

                    }
                }
                else {
                    try {
                        sleep(80);
                    } catch (InterruptedException interruptedException) {
                        interruptedException.printStackTrace();
                        System.out.println("Beim (Task-)Sleepen verhaspelt");
                    }
                }
            }
        };

        task1.run();
        System.out.println("Das System wurde gestartet!");
        Thread thread = new Thread(task1);
        try {
            thread.join();
        } catch (InterruptedException interruptedException) {
            interruptedException.printStackTrace();
        }
        thread.start();

    }

    protected void dateieinlesenWorker(){
        Runnable task2 = () -> {
            ArrayList<String> tasklist = new ArrayList<>();
            while(true) {
                for (int i = 1; i < 7; i++) {
                    String h = new Read().ladeDatei(String.valueOf(i) + ".control");
                    System.out.println(h);
                    if(!h.equals("")) {
                        int x = 0, y = 0, z = 0;
                        if(h.equals("A")) {
                            x = 1;
                        }if(h.equals("D")){
                            x = -1;
                        }
                        dotasking(new Koodinates((e.getX() + x), e.getY()+y, e.getZ()+z, "", ""));
                    }
                    i++;
                    try {
                        sleep(100);
                    } catch (InterruptedException interruptedException) {
                        interruptedException.printStackTrace();
                        System.out.println("Ich wurde beim Schlafen gestört.");
                    }
                }
            }
        };
        //task2.run();
        System.out.println("Das System wurde gestartet!");
        Thread thread = new Thread(task2);
        try {
            thread.join();
        } catch (InterruptedException interruptedException) {
            interruptedException.printStackTrace();
        }
        thread.start();

    }

    private void dotasking(Koodinates koodinates) {
       tasks.add(koodinates);
    }

    protected Koodinates getNext() {
        Koodinates k = tasks.getNext();
        return k;
    }

    protected int compX() {
        if(k.getX() == e.getX()) {
            return 0;
        }
            return k.getX() - e.getX();
    }
    protected int compY() {
        if(k.getY() == e.getY()) {
            return 0;
        }
        return k.getY() - e.getY();
    }
    protected int compZ() {
        if(k.getZ() == e.getZ()) {
            return 0;
        }
        return k.getZ() - e.getZ();
    }
    public boolean ifWork(){
        return true;
    }
    public void stopWorker(){

    }
}
