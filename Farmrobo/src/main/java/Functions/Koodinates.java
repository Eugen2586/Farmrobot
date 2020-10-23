package Functions;

import org.json.simple.JSONObject;

public class Koodinates {

    /* This class is an Expression for sending to the Chips an do the
     *  exsistential Work for a expression.
     */
    static long st_id = 0;
    long id;
    int x;
    int y;
    int z;
    String t;
    String v;


    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getZ() {
        return z;
    }

    public String getT() {
        return t;
    }

    public long getID(){
        return id;
    }

    public String getV() { return v; }

    public Koodinates(int x, int y, int z, String t, String v){
        id  = st_id;
        st_id++;
        this.x = x;
        this.y = y;
        this.z = z;
        this.t = t;
        this.v = v;
    }
    @Override
    public String toString(){
        String s = null;
        JSONObject obj = new JSONObject();
        obj.put("ID",String.valueOf(this.getID()));
        obj.put("X",String.valueOf(this.getX()) );
        obj.put("Y",String.valueOf(this.getY()) );
        obj.put("Z",String.valueOf(this.getZ()) );
        obj.put("T",String.valueOf(this.getT()) );
        obj.put("V",String.valueOf(this.getV()) );
        s = obj.toString();
        return s;
    }


}
