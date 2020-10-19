package Functions;

import java.util.Objects;
import java.util.Observable;
import java.util.Observer;

public class engine implements Observer {
    int X;
    int Y;
    int Z;

    public engine(int x, int y, int z) {
        X = x;
        Y = y;
        Z = z;
    }

    @Override
    public String toString() {
        return "engine{" +
                "X=" + X +
                ", Y=" + Y +
                ", Z=" + Z +
                '}';
    }

    public int getX() {
        return X;
    }

    public void setX(int x) {
        X = x;
    }

    public int getY() {
        return Y;
    }

    public void setY(int y) {
        Y = y;
    }

    public int getZ() {
        return Z;
    }

    public void setZ(int z) {
        Z = z;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        engine engine = (engine) o;
        return Objects.equals(X, engine.X) &&
                Objects.equals(Y, engine.Y) &&
                Objects.equals(Z, engine.Z);
    }

    @Override
    public int hashCode() {
        return Objects.hash(X, Y, Z);
    }


    public void setValue(int x) {

    }

    @Override
    public void update(Observable o, Object arg) {
                /*int someVariable = ((Flux) o).getSomeVariable();
        System.out.println("All is flux!  Some variable is now " + someVariable);
        */
    }
}