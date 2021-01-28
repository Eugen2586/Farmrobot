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

import Constants.NETWORK;
import Main.Functions.Communictaion.toServer;
import Main.Functions.Koodinates;
import Main.Functions.engine;
import Main.Model.Tasks;

import java.io.IOException;

import static java.lang.Thread.sleep;

public class worker {
    Tasks tasks = new Tasks();
    Koodinates k = null;
    engine e = new engine(0,0,0);

    boolean engineStop = false;


    public void work() {
        System.out.println("Das System wurde gestartet!");
        Runnable task = () -> {
            toServer x = null;
            try {
                x = new toServer(NETWORK.X_RAY_IP, NETWORK.X_RAY_PORT);
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
            while(ifWork()) {
                System.out.println("einen Task abgearbeitet!");
                getNext();
                if(k != null) {

                    if (compX() != 0) {
                        try {
                            x.schreibeNachricht(x.getX_Ray_ComPort(), compX() < 0 ? "S":"W");
                            System.out.println(x.leseNachricht(x.getX_Ray_ComPort()));
                        } catch (IOException ioException) {
                            ioException.printStackTrace();
                            System.out.println("X ist Scheisse");
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

        task.run();
        System.out.println("Das System wurde gestartet!");
        Thread thread = new Thread(task);
        thread.start();

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
