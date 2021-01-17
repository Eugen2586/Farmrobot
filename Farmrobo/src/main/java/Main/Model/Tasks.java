package Main.Model;

import Main.Functions.Koodinates;

import java.util.ArrayList;

public class Tasks {

    ArrayList tasks;
    public Tasks(){
        tasks = new ArrayList();
    }
    public void add(Koodinates k){
        tasks.add(k);
    }
    public Koodinates getnext(){
        if(tasks.size()< 1){
            return null;
        }
        Koodinates k = (Koodinates) tasks.get(0);
        tasks.remove(k);
        return k;
    }
}
