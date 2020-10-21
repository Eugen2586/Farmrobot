package Functions;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Log {

    private static boolean containsString( String s, String subString ) {
        return s.indexOf( subString ) > -1 ? true : false;
    }

   public Log( Koodinates k) {
        JSONObject obj = new JSONObject();
        obj.put("ID",String.valueOf(k.getID()));
        obj.put("X",String.valueOf(k.getX()) );
        obj.put("Y",String.valueOf(k.getY()) );
        obj.put("Z",String.valueOf(k.getZ()) );
        obj.put("T",String.valueOf(k.getT()) );
        obj.put("V",String.valueOf(k.getV()) );
        try {
            FileWriter myWriter = new FileWriter(k.getID() + ".farmrobo", true);
            myWriter.write(obj.toString());
            myWriter.flush();
            myWriter.close();

        }catch(Exception e){
            e.printStackTrace();
        }
    }


    public static ArrayList<Koodinates> getLog(){
        ArrayList<Koodinates> kod = new ArrayList<Koodinates>();
        File f = new File( System.getProperty("user.dir") );
        File[] fileArray = f.listFiles();
        for (File t : fileArray ) {
            if( containsString(  t.getName(), ".farmrobo")) {
                try {
                    FileReader rw = new FileReader(t.toString());
                    JSONParser parser = new JSONParser();
                    int c;
                    StringBuffer r = new StringBuffer();
                    rw = new FileReader(t);
                    while ((c = rw.read()) != -1) {
                        r.append((char) c);
                    }
                    rw.close();
                    JSONObject obj = (JSONObject) parser.parse(r.toString());
                    try {
                        Koodinates k = new Koodinates(
                                Integer.decode( obj.get("X").toString()),
                                Integer.decode( obj.get("Y").toString()),
                                Integer.decode( obj.get("Z").toString()) ,
                                obj.get("T").toString(),
                                obj.get("V").toString()
                        );
                        kod.add(k);


                    } catch (Exception e) {
                        e.printStackTrace();
                    }

                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }

        return kod;
    }

    public static void deleteOlder(){
        File f = new File( System.getProperty("user.dir") );
        File[] fileArray = f.listFiles();
        for (File t : fileArray ) {
            if( containsString(  t.getName(), ".farmrobo")) {
                t.delete();
            }
        }
    }

}
