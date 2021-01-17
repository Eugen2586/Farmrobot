import Constants.NETWORK;
import Functions.Communictaion.Database;
import Functions.Communictaion.toServer;
import org.junit.Test;

import java.io.IOException;

public class Steuerungstest {

    @Test
    public void manuelleSteuerung() {
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

        } catch (Exception e) {

        }

    }

}
