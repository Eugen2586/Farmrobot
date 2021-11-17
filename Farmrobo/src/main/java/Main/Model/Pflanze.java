package Main.Model;

public class Pflanze {
    private int x;
    private int y;
    private int wasser;
    private String bez;

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getWasser() {
        return wasser;
    }

    public void setWasser(int wasser) {
        this.wasser = wasser;
    }

    public String getBez() {
        return bez;
    }

    public void setBez(String bez) {
        this.bez = bez;
    }

    public Pflanze(int x, int y, String bez) {
        this.x = x;
        this.y = y;
        this.bez = bez;
    }
}
