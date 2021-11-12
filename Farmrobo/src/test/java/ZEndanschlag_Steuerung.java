import Main.Functions.Communictaion.toServer;
import org.junit.Test;

import java.io.IOException;

public class ZEndanschlag_Steuerung {

    @Test
    public void oben(){
        int maxStepsZ = 480;
        int maxStepsY = 10;
        try {
            toServer x = new toServer();
            x.schreibeNachricht(x.getZ_Ray_ComPort(), "G");
            System.out.println("ZRichtung " + x.leseNachricht(x.getZ_Ray_ComPort()));
            for(int i = 0; i < maxStepsZ; i++){
                x.schreibeNachricht(x.getZ_Ray_ComPort(), "Q");
                System.out.println("ZRichtung " + x.leseNachricht(x.getZ_Ray_ComPort()));
            }
            for(int i = 0; i < maxStepsY; i++){
                x.schreibeNachricht(x.getZ_Ray_ComPort(), "A");
                System.out.println("YRichtung " + x.leseNachricht(x.getY_Ray_ComPort()));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
}
}
