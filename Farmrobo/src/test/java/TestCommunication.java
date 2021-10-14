import Constants.AktualKoodinates;
import Main.Functions.Communictaion.Database;
import Main.Functions.Communictaion.toServer;
import Main.Functions.Koodinates;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;
import org.junit.Test;

import java.io.IOException;
import java.sql.SQLException;

public class TestCommunication {


    @Test
    public void communicationsTest() {
        toServer t = null;
        Database db = new Database();


        try {
            t = new toServer();
        } catch (IOException e) {
            e.printStackTrace();
        }
        for (int i = 0; i < 3000; i++) {
            String st = null;
            try {
                t.schreibeNachricht(t.getX_Ray_ComPort(), "V");
                st = t.leseNachricht(t.getX_Ray_ComPort());
                System.out.print(st);
            } catch (IOException e) {
               e.printStackTrace();
            }
             JSONParser parser = new JSONParser();
             JSONObject obj = null;
             String help = new String();
             for(int j = 0; j < st.length(); j++){
                 char r = st.charAt(j);
                 if( r != '\r' && r != '\n') {
                     help = help + r;
                     continue;
                 }

             }
             if(help.equals("")){
                 continue;
             }
            try {
                obj = (JSONObject) parser.parse(help.toString());
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
