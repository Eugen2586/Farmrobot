import Main.Functions.Communictaion.toServer;
import org.junit.Test;

import java.io.IOException;

import static java.lang.Thread.sleep;

public class MotorTestVersuchsreiheEins {


    @Test
    public void MotorTestVersuchsreiheEins() {
        toServer t = null;
        //Database db = new Database();

            t = new toServer();
        try {
            while(true) {
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
            }
        }catch(Exception e){

        }

    }
}

