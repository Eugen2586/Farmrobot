import Main.Functions.Koodinates;
import Main.Functions.worker.worker;
import Main.Model.Tasks;
import org.junit.Test;

public class Webserversteuerung {
    @Test
    public void testDasDingens(){
        Tasks task = new Tasks();
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                for(int l = 0; l < 5; l++ ) {
                    Koodinates k = new Koodinates(i, j, l, "", "");
                    task.add(k);
                }
            }
            System.out.println("Yeah run!");
        }
        System.out.println("Ich gehe jetzt in den Worker");
        worker w = new worker();
        w.work();
    }
}
