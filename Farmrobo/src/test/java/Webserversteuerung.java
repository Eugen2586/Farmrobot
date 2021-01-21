import Main.Functions.Koodinates;
import Main.Model.Tasks;
import org.junit.Test;

public class Webserversteuerung {
    @Test
    public void testDasDingens(){

        for(int i = 0; i < 20; i++) {
            for(int j = 0; j < 20; j++) {
                for(int l = 0; l < 20; l++ ) {
                    Koodinates k = new Koodinates(i, j, l, "", "");
                    Tasks task = new Tasks();
                    task.add(k);
                }
            }
        }

    }










}
