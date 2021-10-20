package Main;

import Constants.AktualKoodinates;
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

            t = new toServer();
        for(int i = 0; i < 10; i++) {
            String st = null;
            try {
                t.schreibeNachricht(t.getX_Ray_ComPort(), "W");
                st = t.leseNachricht(t.getX_Ray_ComPort());
                System.out.print(t.leseNachricht(t.getX_Ray_ComPort()));
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                db.eintragMessdaten(st);
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
    }
}