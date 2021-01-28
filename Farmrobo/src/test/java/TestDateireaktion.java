import Main.Functions.worker.worker;
import Main.Model.Tasks;
import org.junit.Test;

import static java.lang.Thread.sleep;

public class TestDateireaktion {
    /* In diesem Test wird die Taskliste gefüllt und währenddessen abgearbeitet.
    */
    @Test
    public void testeDateireaktionen(){
        System.out.println("Workersystem gestartet:");
        worker w = new worker();
        //w.work();
        Tasks t = new Tasks();
        t.getControls();
        while(true){
            try {
                System.out.println("Eine Sekunde ist rum!");
                sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
