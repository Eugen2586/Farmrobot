package Functions.logic;

import java.util.TimerTask;
import java.util.Timer;

public class SensorTimer {
    TimerTask action = null;

    SensorTimer(){
        TimerTask action = new TimerTask() {
            public void run() {
                // Do here running Stuff for the Sensors. :)
            }

        };
    }
    private void startSensors(){
        Timer caretaker = new Timer();
        caretaker.schedule( action, 1000, 5000);
    }

    }
