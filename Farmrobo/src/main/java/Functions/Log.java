package Functions;
import org.json.simple.JSONObject;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Log {

    void Log( Koodinates k) {
        try {
            File myObj = new File(k.getID() + ".txt");
            myObj.createNewFile();
        } catch (IOException e) {
            e.printStackTrace();
        }
        JSONObject obj = new JSONObject();
        obj.put("ID",String.valueOf(k.getID()));
        obj.put("X",String.valueOf(k.getX()) );
        obj.put("Y",String.valueOf(k.getY()) );
        obj.put("Z",String.valueOf(k.getZ()) );
        obj.put("T",String.valueOf(k.getT()) );
        obj.put("V",String.valueOf(k.getV()) );
        try {
            FileWriter myWriter = new FileWriter(k.getID() + ".txt", true);
            myWriter.write(obj.toString());
            myWriter.close();
        }catch(Exception e){
            e.printStackTrace();
        }
        try{
            File myObj = new File("0.txt");
            myObj.createNewFile();
        }catch(Exception e){

        }
    }


    ArrayList<Koodinates> getLog(){
        ArrayList<Koodinates> kod = new ArrayList<Koodinates>();
        File f = new File("0.txt");
        File[] fileArray = f.listFiles();
        for (Object obj : fileArray ) {
            try{

            }catch(Exception e){

            }
        }

        return kod;
    }
}
