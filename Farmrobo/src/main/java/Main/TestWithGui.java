package Main;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.util.Calendar;

public class TestWithGui extends Application {

    private Stage s;

    @Override
    public void start(Stage primaryStage) throws Exception {
        final FXMLLoader load = new FXMLLoader(getClass().getResource("Wassermessung.fxml"));
        final Parent root = load.load();
        primaryStage.setTitle("Farmrobostuff :)");
        primaryStage.setScene(new Scene(root));
        s = primaryStage;
        show();
    }

    public void show() {
        s.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

}
