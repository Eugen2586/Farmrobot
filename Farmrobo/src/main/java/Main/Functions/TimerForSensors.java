package Main.Functions;
import Main.Functions.Communictaion.Database;
import Main.Functions.Communictaion.toServer;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.util.Duration;
import javafx.animation.Animation;

import java.io.IOException;
import java.sql.SQLException;
import java.util.Timer;
import java.util.TimerTask;

public class TimerForSensors implements Runnable{
        Database db = new Database();
        toServer t = new toServer();

        Timer timeline;
        @Override
        public void run(){
            timersToDo();
        }

        public void timersToDo(){
            timeline = new Timer();
            TimerTask t = new TimerTask() {
                @Override
                public void run() {
                    try {
                        timerDo();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            };
            timeline.scheduleAtFixedRate(t, 1000, 1000);

        }
        public void timerDo() throws IOException, SQLException {
            db = new Database();
            t = new toServer();
            t.schreibeNachricht(t.getW_Ray_ComPort(), "V");
            String getted =  t.leseNachricht(t.getW_Ray_ComPort());
            db.eintragMessdaten(getted);
            t.schreibeNachricht(t.getW_Ray_ComPort(), "A");
            getted =  t.leseNachricht(t.getW_Ray_ComPort());
            db.eintragMessdaten(getted);
        }
    }

