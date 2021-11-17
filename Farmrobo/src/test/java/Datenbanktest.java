import Main.Functions.Communictaion.Database;
import Main.Functions.Communictaion.toServer;
import Main.Functions.TimerForSensors;
import org.junit.Test;

import java.io.IOException;
import java.sql.SQLException;

import static java.lang.Thread.sleep;

public class Datenbanktest {

    @Test
    public void doEntrance(){
        TimerForSensors tfs = new TimerForSensors();
        tfs.run();
        while(true) {
            try {
                sleep(10000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    @Test
    public void Datenbanktest(){
        try {
            Database db = new Database();
            toServer t = new toServer();
            t.schreibeNachricht(t.getW_Ray_ComPort(), "V");
            String getted =  t.leseNachricht(t.getW_Ray_ComPort());
            db.eintragMessdaten(getted);
        } catch (IOException | SQLException e) {
            e.printStackTrace();
        }
    }

}
