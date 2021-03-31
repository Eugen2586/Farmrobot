package Main.Functions.Communictaion;

import Constants.AktualKoodinates;
import Constants.DATABASE;
import Constants.NETWORK;
import Main.Functions.Koodinates;

import java.sql.*;
import java.util.ArrayList;

public class Database {

    //Constants for Connection
    final String toTable =  DATABASE.db_ip + ":3300/Farmrobo";
    final String user = DATABASE.username;
    final String password = DATABASE.password;

    //Member Variables
    Connection myConn;



    public Database() {
        try {
            Class.forName("com.mysql.jdbc.Driver").newInstance();
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        //Connect
        try {
           System.out.println("jdbc:mysql:/" + toTable);
            myConn = DriverManager.getConnection("jdbc:mysql://"+ toTable +"?" + "user=" + user + "&password="+password +"");//DriverManager.getConnection("jdbc:mysql:/" + toTable, user, password);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
    }
    
    public void eintragMessdaten(Koodinates k ) throws SQLException {

        String unit = getUnit(k);
        String sensorValue = getRay(k.getT());

        String t = "INSERT INTO `Messdaten` (`K`, `Date`, `X`, `Y`, `Z`, `T`, `Value_1`, `Value_2`, `Value_3`, `Value_4`) VALUES (NULL, CURRENT_TIMESTAMP, '"+ AktualKoodinates.getX() +"', '"+ AktualKoodinates.getY() +"', '"+ AktualKoodinates.getZ() +"', '" + k.getT() + "', '" + k.getV() +"', 'V', 'V', 'V');";
        System.out.println(k.getV());
        Statement myStat = myConn.createStatement();
        int reSe = myStat.executeUpdate(t);
        System.out.println(reSe);
    }

    private String getRay(String t) {
        return NETWORK.X_RAY_IP + NETWORK.X_RAY_PORT;
    }

    private String getUnit(Koodinates k) {
        return "%";
    }

    //INSERT INTO `Messdaten` (`K`, `Date`, `X`, `Y`, `Z`, `T`, `Value_1`, `Value_2`, `Value_3`, `Value_4`) VALUES (NULL, CURRENT_TIMESTAMP, '30', '80', '150', 'Temp', '30', 'C', '-', '-');

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
