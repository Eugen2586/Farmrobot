package Functions;

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

    Koodinates(int x, int y, int z, String t, String v){
        id  = st_id;
        st_id++;
        this.x = x;
        this.y = y;
        this.z = z;
        this.t = t;
        this.v = v;
    }


}
