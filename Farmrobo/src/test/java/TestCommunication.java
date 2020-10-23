import Constants.NETWORK;
import Functions.Communictaion.toServer;
import org.junit.Test;

import java.io.IOException;

public class TestCommunication {


    @Test
    public void communicationsTest() {
        toServer t = null;
        try {
            t = new toServer(NETWORK.X_RAY_IP, NETWORK.X_RAY_PORT);
        } catch (IOException e) {
            e.printStackTrace();
        }
            try {

                t.schreibeNachricht(t.getX_Ray_ComPort(), "L");
                t.leseNachricht(t.getX_Ray_ComPort());
                System.out.print(t.leseNachricht(t.getX_Ray_ComPort()));
            } catch (IOException e) {
                e.printStackTrace();
            }
    }
}
