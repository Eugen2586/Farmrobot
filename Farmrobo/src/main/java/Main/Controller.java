package Main;

import Constants.AktualKoodinates;
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

                t = new toServer();
                t.schreibeNachricht(t.getX_Ray_ComPort(), "V".toString());
                st = t.leseNachricht(t.getX_Ray_ComPort());
                System.out.print(st);
            } catch (IOException eg) {
                eg.printStackTrace();
            }

            Platform.runLater(new Runnable() {
                @Override public void run() {
                    controller.setLabels( mw , va );
                }
            });

            try {
                db.eintragMessdaten(st);
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
