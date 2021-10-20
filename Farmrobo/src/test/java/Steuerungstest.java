import Main.Functions.Communictaion.toServer;
import org.junit.Test;

import java.io.IOException;

public class Steuerungstest {

    @Test
    public void manuelleSteuerung() {
        toServer t = null;

            t = new toServer();
        try {
            int j = 0;
            while(j < 100) {
                int i = 0;
                while (i < 30) {
                    t.schreibeNachricht(t.getX_Ray_ComPort(), "A");
                    System.out.println(t.leseNachricht(t.getX_Ray_ComPort()));
                    i++;
                }
                while (i > 0) {
                    t.schreibeNachricht(t.getX_Ray_ComPort(), "D");
                    System.out.println(t.leseNachricht(t.getX_Ray_ComPort()));
                    i--;
                }
                j++; //Abbruchkriterium
            }
            System.out.println("Test manuelleSteuerung durchgelaufen");

        } catch (Exception e) {

        }

    }

    @Test
    public void manuelleSteuerungEinStep() {
        toServer t = null;
        //Database db = new Database();
            t = new toServer();
        try {
            t.schreibeNachricht(t.getX_Ray_ComPort(), "A");
            System.out.println(t.leseNachricht(t.getX_Ray_ComPort()));
            System.out.println("Test manuelleSteuerung durchgelaufen");
            } catch (IOException ioException) {
            ioException.printStackTrace();
        }
    }



}
