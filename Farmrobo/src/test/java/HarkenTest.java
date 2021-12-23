import Main.Functions.Communictaion.toServer;
import org.junit.Test;
import java.io.IOException;

public class HarkenTest {

    @Test
    public void HarkenTest(){

        toServer x = null;
        //Database db = new Database();
        x = new toServer();

        try {

        for(int steps = 0; steps < 150; steps++) {
            x.schreibeNachricht(x.getZ_Ray_ComPort(), "Q");
            System.out.println("ZRichtung: " + x.leseNachricht(x.getZ_Ray_ComPort()) + String.valueOf(steps));
        }
        x.schreibeNachricht(x.getH_Ray_ComPort(), "w");
        x.leseNachricht(x.getH_Ray_ComPort());
        for(int steps = 0; steps < 150; steps++) {
            x.schreibeNachricht(x.getZ_Ray_ComPort(), "E");
            System.out.println("ZRichtung" + x.leseNachricht(x.getZ_Ray_ComPort()) + String.valueOf(steps));

        }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
