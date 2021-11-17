package Main.Functions;
import Main.Functions.Communictaion.Database;
import Main.Functions.Communictaion.toServer;
import Main.Model.Pflanze;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.util.Duration;
import javafx.animation.Animation;

import java.io.IOException;
import java.net.Socket;
import java.sql.SQLException;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;

public class TimerForSensors implements Runnable{
        //Database db = new Database();
        //toServer toS = new toServer();
        int i = 0;

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
            timeline.scheduleAtFixedRate(t, 1000, 1000);//Er wird hiermit sekündlich ausgeführt.

        }
        public void timerDo() throws IOException, SQLException {
            /*db = new Database();
            toS = new toServer();
            toS.schreibeNachricht(toS.getW_Ray_ComPort(), "V");
            String getted =  toS.leseNachricht(toS.getW_Ray_ComPort());
            db.eintragMessdaten(getted);
            toS.schreibeNachricht(toS.getW_Ray_ComPort(), "A");
            getted =  toS.leseNachricht(toS.getW_Ray_ComPort());
            db.eintragMessdaten(getted);*/
            System.out.println("Sekunde");
            System.out.println(LocalDateTime.now());
            i++;
            //if(i == 86400){
            if(i == 10) {
                //Grundposition erreichen
                while(!toGrundposition()){ System.out.println("Grundposition ausfuehren!"); }
                ArrayList<Pflanze> pfar = new ArrayList<>();
                Database d = new Database();
                d.readAllFromTable("PflanzenPos");
                //Lade Pflanzendaten von der Datenbank!
                //Lade Positionsdaten von der Datenbank!
                for (Pflanze p: pfar) {
                    //Ab hier findet alles in einer Loop statt für jeden Eintrag
                    int x = p.getX(), y = p.getY(), z = 0;
                    //Fahren wir die erste Bahn!

                    //Wir fahren nach X
                    this.toX(x);
                    //Wir fahren nach Y
                    this.toY(y);
                    //Wir fahren nach Z
                    this.toZ(z);
                    // Wir: Gießen, Wässern, Sähen, Harken
                    int timeG = 0;
                    this.gießen(timeG);
                    this.haken();
                    // Wir fahren nach Z wieder rein
                    this.toZ(0);
                    //Ende der Schleife und nächstes Objekt.
                }
                    System.out.println("Minute");
                    System.out.println(LocalDateTime.now());
                    i = 0;

            }
        }
    private boolean toGrundposition(){
            try{
                toServer x = new toServer();
                x.schreibeNachricht(x.getZ_Ray_ComPort(), "G");
                System.out.println("ZRichtung " + x.leseNachricht(x.getZ_Ray_ComPort()));
                x.schreibeNachricht(x.getX_Ray_ComPort(), "G");
                System.out.println("XRichtung " + x.leseNachricht(x.getX_Ray_ComPort()));
                x.schreibeNachricht(x.getY_Ray_ComPort(), "G");
                System.out.println("YRichtung " + x.leseNachricht(x.getY_Ray_ComPort()));
            }catch(Exception Jonas){
                System.out.println("Es kam zu einem Fehler, nochmal");
                return false;
            }
            return true;
        }

        private boolean haken() {
            toServer t = new toServer();
            try {
              t.schreibeNachricht(t.getW_Ray_ComPort(), "H");
              t.leseNachricht(t.getW_Ray_ComPort());
            }catch (Exception e){
              return false;
            }
            return true;
        }
        private boolean gießen(int time) throws IOException {
            toServer t = new toServer();
            for(int i = 0; i < time; i ++) {
                try {
                    t.schreibeNachricht(t.getW_Ray_ComPort(), "W");
                    t.leseNachricht(t.getW_Ray_ComPort());
                }catch (Exception e){
                    return false;
                }
            }
            return true;
        }
        private void toX(int i) throws IOException {
            toServer t = new toServer();
            fahre(i,t.getX_Ray_ComPort(), 'x' );
        }
        private void toY(int i) throws IOException {
            toServer t = new toServer();
            fahre(i,t.getY_Ray_ComPort(), 'y' );
        }
        private void toZ(int i) throws IOException {
            toServer t = new toServer();
            fahre(i,t.getZ_Ray_ComPort(), 'z' );
        }
        private void fahre(int i, Socket sock, char achs) throws IOException {
            String hin, her;
            switch(achs){
                case 'x':
                case 'y':
                    hin = "A";
                    her = "D";
                    break;
                case 'z':
                    hin = "E";
                    her = "Q";
                    break;
                default:
                    throw new IllegalStateException("Unexpected value: " + achs);
            }
            int pos = 0;
            toServer t = new toServer();
            while(true){
                if(pos == 0) {
                    t.schreibeNachricht(sock, hin);
                    String s = t.leseNachricht(sock);
                    pos = Integer.getInteger(s);
                }else if(pos < i){
                    t.schreibeNachricht(sock, hin);
                    String s = t.leseNachricht(sock);
                    pos = Integer.getInteger(s);
                }else if(pos > i){
                    t.schreibeNachricht(sock, her);
                    String s = t.leseNachricht(sock);
                    pos = Integer.getInteger(s);
                }
                else {
                    return;
                }
            }
        }
    }

