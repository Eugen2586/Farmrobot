import Constants.NETWORK;
import Main.Functions.Communictaion.Database;
import Main.Functions.Communictaion.toServer;
import org.junit.Test;

import java.io.IOException;

import static java.lang.Thread.sleep;

public class MotorTestVersuchsreiheEins {


    @Test
    public void MotorTestVersuchsreiheEins() {
        toServer t = null;
        Database db = new Database();


        try {
            t = new toServer(NETWORK.X_RAY_IP, NETWORK.X_RAY_PORT);
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            while(true) {
                int i = 0;
                while (i < 30) {
                    t.schreibeNachricht(t.getX_Ray_ComPort(), "A");
                    t.leseNachricht(t.getX_Ray_ComPort());
                    i++;
                }
                while (i > 0) {
                    t.schreibeNachricht(t.getX_Ray_ComPort(), "D");
                    t.leseNachricht(t.getX_Ray_ComPort());
                    i--;
                }
            }
        }catch(Exception e){

        }

    }
}

