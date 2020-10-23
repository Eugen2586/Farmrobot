import Constants.NETWORK;
import Functions.Communictaion.toClient;
import Functions.Communictaion.toServer;
import Functions.Koodinates;
import org.junit.Test;

import java.io.IOException;

public class TestCommunication {


    @Test
    public void communicationsTest(){
        toClient t =  new Functions.Communictaion.toClient(NETWORK.X_RAY_IP, NETWORK.X_RAY_PORT);
        Koodinates k = new Koodinates(30,80,40, "Messen", "?");
        try {
            t.schreibeNachricht(k.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
