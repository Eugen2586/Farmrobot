import Main.Functions.Read;
import org.junit.Test;

import java.lang.reflect.Array;
import java.util.ArrayList;

public class ManuelleSteuerungDatenEinlesen {


    @Test
    public void einlesenDerDaten(){
        ArrayList<String> tasklist = new ArrayList<>();
        int i = 1;
        while(true) {
            while (i < 24) {
                    String h = new Read().ladeDatei(String.valueOf(i) + ".control");
                    System.out.println(h);
                    if(h != "") {
                        tasklist.add(h);
                    }
                    i++;
            }
            i = 1;
        }

    }
}
