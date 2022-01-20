import Constants.NETWORK;
import Main.Functions.Communictaion.toServer;
import org.junit.Test;

import java.io.IOException;

import static java.lang.Thread.sleep;

public class Wasserpumpe {

    @Test
    public void Wasserpumpentest() {
        toServer t = null;
        //Database db = new Database();
            t = new toServer();

        try {
            System.out.println("Connected");
            while(true) {
                int i = 0;

                //Test für die Wasserpumpe
                while (i < 60) {
                    //Wassserpumpe ansteuern
                    t.schreibeNachricht(t.getW_Ray_ComPort(), "W");
                    System.out.print(t.leseNachricht(t.getW_Ray_ComPort()));
                    i++;
                    //sleep(200);
                }
                i = 0;
                //Test für die Saatmaschine
                while (i < 60) {
                    //Saatsteuerung
                    t.schreibeNachricht(t.getW_Ray_ComPort(), "S");
                    System.out.print(t.leseNachricht(t.getW_Ray_ComPort()));
                    i++;
                    //sleep(200);
                }
            }
        }catch(Exception e){
            e.printStackTrace();
        }

    }

}
