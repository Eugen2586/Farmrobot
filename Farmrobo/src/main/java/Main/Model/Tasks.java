package Main.Model;

import Main.Functions.Koodinates;

import java.util.ArrayList;

public class Tasks {

    static ArrayList tasks = new ArrayList();

    public void add(Koodinates k){
        System.out.println(k.toString());
        tasks.add(k);
    }

    public Koodinates getNext(){
        if(tasks.size()< 1){
            return null;
        }
        Koodinates k = (Koodinates) tasks.get(0);
        tasks.remove(k);
        System.out.println(k.toString());
        return k;
    }
}
