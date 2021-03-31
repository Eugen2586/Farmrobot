package Main;

import Constants.AktualKoodinates;
import Constants.NETWORK;
import Main.Functions.Communictaion.Database;
import Main.Functions.Communictaion.toServer;
import Main.Functions.Koodinates;
import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.IOException;
import java.net.URL;
import java.sql.SQLException;
import java.sql.Time;
import java.util.GregorianCalendar;
import java.util.ResourceBundle;

public class Controller  implements Initializable {
    class Worker implements Runnable{
        toServer t = null;
        Database db = null;
        Controller controller = null;
        String mw = null;
        String va = null;

        public Worker(Controller controller) {
            this.controller = controller;
            try{
                db = new Database();
                db_status.setFill(Color.GREEN);
            }
            catch(Exception e){
                db_status.setFill(Color.RED);
            }
        }

        public void run() {
            String st = null;
            try {

                t = new toServer(NETWORK.X_RAY_IP, NETWORK.X_RAY_PORT);
                t.schreibeNachricht(t.getX_Ray_ComPort(), "V".toString());
                st = t.leseNachricht(t.getX_Ray_ComPort());
                System.out.print(st);
            } catch (IOException eg) {
                eg.printStackTrace();
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
                return;
            }
            try {
                obj = (JSONObject) parser.parse(help.toString());
            } catch (ParseException ez) {
                ez.printStackTrace();
            }
            mw = obj.get("V").toString();
            va = "Messreihe";

            Platform.runLater(new Runnable() {
                @Override public void run() {
                    controller.setLabels( mw , va );
                }
            });

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


    @FXML
    Circle db_status;
    @FXML
    Label messwert;
    @FXML
    Label art;
    @FXML
    Label time;
    @FXML
    Button btn;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        final Thread[] worker = {null};

        btn.setOnAction(e -> {
            Worker wt = new Worker(this);
            worker[0] = new Thread(wt);
            worker[0].start();
        });
    }
    public void setLabels(String messwert, String art){
        this.messwert.setText(messwert);
        time.setText( new GregorianCalendar().getInstance().getTime().toString());
        this.art.setText(art);
    }

}
