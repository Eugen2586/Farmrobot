import Constants.DATABASE;
import Constants.NETWORK;
import Main.Functions.Communictaion.Database;
import Main.Functions.Communictaion.toServer;
import Main.Functions.Koodinates;
import Main.Functions.TimerForSensors;
import Main.Model.Pflanze;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.junit.Test;

import java.io.*;
import java.net.Socket;
import java.sql.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;

import static java.lang.Thread.sleep;

public class Datenbanktest {

    static public class Database {

        //Constants for Connection
        final String toTable =  "84.160.174.85" + ":61137/Farmbot";
        final String user = DATABASE.username;
        final String password = DATABASE.password;

        //Member Variables
        Connection myConn;



       public Database() {
            try {
                Class.forName("com.mysql.cj.jdbc.Driver").newInstance();
            } catch (InstantiationException e) {
                e.printStackTrace();
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }
            //Connect
            try {
                System.out.println("jdbc:mysql:/" + toTable);
                myConn = DriverManager.getConnection("jdbc:mysql://"+ toTable +"?" + "user=" + user + "&password="+password +"");//DriverManager.getConnection("jdbc:mysql:/" + toTable, user, password);
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }

        public void eintragMessdaten(String st) throws SQLException {
            String help = "";
            for(int j = 0; j < st.length(); j++){
                char r = st.charAt(j);
                if( r != '\r' && r != '\n') {
                    help = help + r;
                    continue;
                }

            }

            if(help.equals("")){
                return;
            }
            JSONObject obj = null;
            try {
                JSONParser parser = new JSONParser();
                obj = (JSONObject) parser.parse(help.toString());
            } catch (Exception e) {
                e.printStackTrace();
            }
            String value = obj.get("V").toString();
            String sensor = (String) obj.get("T");
            String t = "INSERT INTO Farmbot.SensorDat (sensor, value, created_at) VALUES ('" + sensor + "'," + value + " ,current_timestamp);";
            //String t = "INSERT INTO SensorDat ('value', 'sensor') VALUES ("+ value +", '"+sensor+"');";
            Statement myStat = myConn.createStatement();
            int reSe = myStat.executeUpdate(t);
        }

        private String getRay(String t) {
            return NETWORK.X_RAY_IP + NETWORK.X_RAY_PORT;
        }

    }


    static public class toServer {

        static Socket W_Ray_ComPort = null;


        //Method Areas

        public toServer(){
            try {
                if (W_Ray_ComPort == null || !W_Ray_ComPort.isConnected()){
                    W_Ray_ComPort = new Socket("192.168.178.72", NETWORK.W_RAY_PORT);
                    System.out.println(W_Ray_ComPort.toString());
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        public String leseNachricht(java.net.Socket socket) throws IOException{
            BufferedReader bufferedReader =
                    new BufferedReader(
                            new InputStreamReader(
                                    socket.getInputStream()));
            char[] buffer = new char[200];
            int anzahlZeichen = bufferedReader.read(buffer, 0, 200); // blockiert bis Nachricht empfangen
            String nachricht = new String(buffer, 0, anzahlZeichen);
            //X_Ray_ComPort.close();
            return nachricht;
        }

        public void schreibeNachricht(java.net.Socket socket, String nachricht) throws IOException {
            PrintWriter printWriter =
                    new PrintWriter(
                            new OutputStreamWriter(
                                    socket.getOutputStream()));
            printWriter.print(nachricht);
            printWriter.flush();
        }
        public Socket getW_Ray_ComPort() { return W_Ray_ComPort;   }
    }

    @Test
    public void doEntrance(){
        TimerForSensors tfs = new TimerForSensors();
        tfs.run();
        while(true) {
            try {
                sleep(5000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public class TimerForSensors implements Runnable{
        Database db = null;
        toServer toS = null;
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
            timeline.scheduleAtFixedRate(t, 1000, 20000);//Er wird hiermit sekündlich ausgeführt.

        }
        public void timerDo() throws IOException, SQLException {
            db = new Database();
            toS = new toServer();
            String getted = null;
            toS.schreibeNachricht(toS.getW_Ray_ComPort(), "V");
            getted =  toS.leseNachricht(toS.getW_Ray_ComPort());
            db.eintragMessdaten(getted);
            System.out.println("Sekunde");
            System.out.println(LocalDateTime.now());
            i++;
            db = new Database();
            toS = new toServer();
            getted = null;
            toS.schreibeNachricht(toS.getW_Ray_ComPort(), "L");
            getted =  toS.leseNachricht(toS.getW_Ray_ComPort());
            db.eintragMessdaten(getted);
            System.out.println("Sekunde");
            System.out.println(LocalDateTime.now());
            i++;
            db = new Database();
            toS = new toServer();
            getted = null;
            toS.schreibeNachricht(toS.getW_Ray_ComPort(), "T");
            getted =  toS.leseNachricht(toS.getW_Ray_ComPort());
            db.eintragMessdaten(getted);
            System.out.println("Sekunde");
            System.out.println(LocalDateTime.now());
            i++;
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
