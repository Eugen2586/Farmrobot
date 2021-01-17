import Main.Functions.Koodinates;
import Main.Functions.Log;
import org.junit.Assert;
import org.junit.Test;


import java.util.ArrayList;

public class TestLog {

    @Test
    public void testLogs(){
        exportK();
        importK();
    }

    private void exportK(){
        Log.deleteOlder();
        try {
            ArrayList<Koodinates> k = new ArrayList<>();
            k.add(new Koodinates(1, 30, 4, "Fahren", "X"));
            k.add(new Koodinates(1, 30, 4, "Gießen", "120ml"));
            k.add(new Koodinates(1, 30, 4, "Ackern", "4cmx4cm"));
            k.add(new Koodinates(1, 30, 4, "Pflanzen", "2cm x 2cm 5xZwiebel"));
            Log l;
            for (Object o : k) {
                l = new Log(((Koodinates) o));
                l = null;
            }
            assert(true);
        }catch(Exception e){
            assert(false);
        }

    }

    private void importK(){
        ArrayList<Koodinates> k = null;
        try{
            k = Log.getLog();
            assert(true);
            Log.deleteOlder();
        }catch(Exception e){
            e.printStackTrace();
            assert(false);
        }
        Assert.assertNotEquals(k.size(), 0);
    }



}
