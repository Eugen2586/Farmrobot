#ifndef Datenbank_h
#define Datenbank_h
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
unsigned long db_currMillis = millis();

//Variablen für die Datenbank
MySQL_Connection conn((Client *)&client); // The Connector/Arduino reference
int wert1 = 0;
IPAddress server_addr(192,168,132,222);            //Hostname oder IP Adresse der Datenbank
char db_user[] = "user2";            // Name des Users, welcher in der Datenbank registriert ist
char db_password[] = "1234";         //Passwort des USER, welcher in der Datenbank registriert ist

//Datenbankanbindung(Init)
void initDB(){
  Serial.println("Connecting...");
  if(conn.connect(server_addr, 3306, db_user, db_password)){
    delay(500);
    Serial.println("Query Success!");
  }
  else{
    Serial.println("Connection failed.");
  }
  //Wassersensor initialisieren.
}

//Datensatz einfügen
void insertDaten(){
  int val = analogRead(A0);
  String INSERT_SQL = "INSERT INTO Database.Table (sensor ,celsius) VALUES (" + String(val) + ", '')";
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  // Execute the query
  cur_mem->execute(&(INSERT_SQL[0]));
}

#endif
