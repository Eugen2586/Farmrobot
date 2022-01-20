import Main.Functions.Communictaion.toServer;
import org.junit.Test;

import java.io.IOException;

import static java.lang.Thread.sleep;

public class ZEndanschlag_Steuerung {

    @Test
    public void oben(){
        int maxStepsZ = 480;
        int maxStepsY = 10;
        try {
            toServer x = new toServer();
           // x.schreibeNachricht(x.getZ_Ray_ComPort(), "G");
           // System.out.println("ZRichtung " + x.leseNachricht(x.getZ_Ray_ComPort()));
            for(int i = 0; i < maxStepsZ; i++){
               // x.schreibeNachricht(x.getZ_Ray_ComPort(), "Q");
               // System.out.println("ZRichtung " + x.leseNachricht(x.getZ_Ray_ComPort()));
            }
            for(int i = 0; i < 300000; i++){
                x.schreibeNachricht(x.getX_Ray_ComPort(), "A");
                System.out.println("gesendet");
                System.out.println("YRichtung " + x.leseNachricht(x.getX_Ray_ComPort()));
                System.out.println("empfangen");
                sleep(20);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
}
}
