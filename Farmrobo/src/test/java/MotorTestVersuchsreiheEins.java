import Main.Functions.Communictaion.toServer;
import org.junit.Test;

import java.io.IOException;

import static java.lang.Thread.sleep;

public class MotorTestVersuchsreiheEins {


    @Test
    public void MotorTestVersuchsreiheEins_ErsterTest() {
        toServer t = null;
        //Database db = new Database();

            t = new toServer();
        try {
                int i = 0;
                while (i < 30) {
                    t.schreibeNachricht(t.getX_Ray_ComPort(), "A");
                    t.leseNachricht(t.getX_Ray_ComPort());
                    i++;
                    sleep(200);
                }
                while (i > 0) {
                    t.schreibeNachricht(t.getX_Ray_ComPort(), "D");
                    t.leseNachricht(t.getX_Ray_ComPort());
                    i--;
                    sleep(200);
                }
        }catch(Exception e){
            e.printStackTrace();
        }

    }

    @Test
    public void MotorTestVersuchsreiheOneStepXWagen() {
        toServer t = null;
        //Database db = new Database();

        t = new toServer();
        try {
            for (int i = 0; i < 6; i++){
                t.schreibeNachricht(t.getX_Ray_ComPort(), "A");
                System.out.print(t.leseNachricht(t.getX_Ray_ComPort()));
                sleep(300);
            }
        } catch (IOException | InterruptedException ioException) {
            ioException.printStackTrace();
        }
    }
    @Test
    public void MotorTestVersuchsreiheOneStepYWagen() {
        toServer t = null;
        //Database db = new Database();

        t = new toServer();
        try {
            for (int i = 0; i < 12; i++){
                t.schreibeNachricht(t.getY_Ray_ComPort(), "D");
                System.out.print(t.leseNachricht(t.getY_Ray_ComPort()));
                sleep(300);
            }
        } catch (IOException | InterruptedException ioException) {
            ioException.printStackTrace();
        }
    }
}

