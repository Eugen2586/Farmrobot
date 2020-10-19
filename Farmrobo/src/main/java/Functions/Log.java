package Functions;
import org.json.simple.JSONObject;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Log {

    void Log( Koodinates k) {
        try {
            File myObj = new File(k.getID() + ".txt");
            myObj.createNewFile();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            FileWriter myWriter = new FileWriter(k.getID() + ".txt", true);
            JSONObject obj = new JSONObject();
            obj.put("ID",String.valueOf(k.getID()));
            obj.put("X",String.valueOf(k.getX()) );
            obj.put("Y",String.valueOf(k.getY()) );
            obj.put("Z",String.valueOf(k.getZ()) );
            obj.put("T",String.valueOf(k.getT()) );
            obj.put("V",String.valueOf(k.getV()) );
            myWriter.write(obj.toString());

            myWriter.close();
            System.out.println("Successfully wrote to the file.");
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
