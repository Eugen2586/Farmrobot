package Main.Functions;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Read {

    public static String ladeDatei(String datName) {
        String s = new  String();
        File file = new File(datName);

        //if (!file.canRead() || !file.isFile())
        //    System.exit(0);

        BufferedReader in = null;
        try {
            in = new BufferedReader(new FileReader(datName));
            String zeile = null;
            while ((zeile = in.readLine()) != null) {
                s +=  zeile;
            }
        } catch (Exception e) {
        } finally {
            if (in != null)
                try {
                    in.close();
                    //löschen der Datei!
                    if (file.exists()) {
                        file.delete();// Doch nicht deleted... ;......(
                    }
                    return s;
                } catch (IOException e) {
                }
        }
        return s;
    }
}