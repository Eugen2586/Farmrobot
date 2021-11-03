import Main.Functions.worker.worker;
import org.junit.Test;

public class Webserversteuerung {
    @Test
    public void testDasDingens(){
        System.out.println("Ich gehe jetzt in den Worker");
        worker w = new worker();
        w.work();
    }
}
