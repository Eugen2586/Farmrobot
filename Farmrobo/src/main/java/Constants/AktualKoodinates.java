package Constants;

import javafx.application.Platform;

public class AktualKoodinates {
    static int x;
    static int y;
    static int z;

    public static int getX() {
        return x;
    }

    public static void setX(int x) {
            AktualKoodinates.x = x;
    }

    public static int getY() {
        return y;
    }

    public static void setY(int y) {
            AktualKoodinates.y = y;
    }

    public static int getZ() {
        return z;
    }

    public static void setZ(int z) {
            AktualKoodinates.z = z;
    }


    static {
            x = 0;
            y = 0;
            z = 0;
    }




}
