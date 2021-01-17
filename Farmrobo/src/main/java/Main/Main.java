package Main;

import Constants.AktualKoodinates;
import Constants.NETWORK;
import Main.Functions.Communictaion.Database;
import Main.Functions.Communictaion.toServer;
import Main.Functions.Koodinates;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.IOException;
import java.sql.SQLException;

public class Main {

    public static void main(String[] args){
        System.out.println("Farmrobo startet");

        toServer t = null;
        Database db = new Database();
        System.out.println("erreicht!");


        try {
            t = new toServer(NETWORK.X_RAY_IP, NETWORK.X_RAY_PORT);
        } catch (IOException e) {
            e.printStackTrace();
        }
        for(int i = 0; i < 10; i++) {
            String st = null;
            try {
                t.schreibeNachricht(t.getX_Ray_ComPort(), "W");
                st = t.leseNachricht(t.getX_Ray_ComPort());
                System.out.print(t.leseNachricht(t.getX_Ray_ComPort()));
            } catch (IOException e) {
                e.printStackTrace();
            }
            JSONParser parser = new JSONParser();
            JSONObject obj = null;
            try {
                obj = (JSONObject) parser.parse(st.toString());
            } catch (ParseException e) {
                e.printStackTrace();
            }
            try {
                db.eintragMessdaten(
                        new Koodinates(
                                AktualKoodinates.getX(),
                                AktualKoodinates.getY(),
                                AktualKoodinates.getZ(),
                                obj.get("T").toString(),
                                obj.get("V").toString()));
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }


    }


}