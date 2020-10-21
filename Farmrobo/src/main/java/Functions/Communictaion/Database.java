package Functions.Communictaion;

import java.sql.*;
import java.util.ArrayList;

public class Database {

    //Constants for Connection
    final String toTable =  "localhost:3306/test";
    final String user = "root";
    final String password = "password";

    //Member Variables
    Connection myConn;

    public Database() {
        //Connect
        try {
            myConn = DriverManager.getConnection("jdbc:mysql://" + toTable, user, password);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
    }

    public Object[] readAllFromTable(String table){
        try{
            //Statement
            Statement myStat = myConn.createStatement();

            //Execute SQL Query
            ResultSet reSe = myStat.executeQuery("select * from " + table );

            /*
            Remember should implement Object in every Used Class to could get all the Variables Back.
            */
            ArrayList<Object> o = new ArrayList<Object>();
            while(reSe.next()){
                //adde hier je Tabelle einen sortiertyp!
                if( table.equals("SpecificTable")){
                    o.add(specificTable(reSe));
                }
            }
            return o.toArray();
        }catch(Exception e){
            e.printStackTrace();
            return null;
        }
    }

    //füge hier einfach die anderen Tabellen als Objekte hinzu!

    private Object specificTable(ResultSet reSe) throws SQLException {
        //Beispielsortiertyp, klar der Returnwert muss ein echtes Objekt per Uppcast sein!
        String id = reSe.getString("ID");
        String logAs = reSe.getString("LogAs");
        return null;
    }

}
