import Main.Functions.Koodinates;
import Main.Functions.worker.worker;
import Main.Model.Tasks;
import org.junit.Test;

public class Webserversteuerung {
    @Test
    public void testDasDingens(){
        System.out.println("Ich gehe jetzt in den Worker");
        worker w = new worker();
        w.work();
    }
}
