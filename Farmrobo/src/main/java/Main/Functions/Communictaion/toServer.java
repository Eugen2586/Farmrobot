package Main.Functions.Communictaion;

import java.io.*;
import java.net.Socket;

public class toServer {

    //Deklarations
    static Socket X_Ray_ComPort;
    static Socket Y_Ray_ComPort;
    static Socket Z_Ray_ComPOrt;

    //Method Areas

    public toServer(String ip, int port) throws IOException {


        X_Ray_ComPort = new Socket(ip, port);
        System.out.println(X_Ray_ComPort.toString());

    }
    /*
    public java.net.Socket warteAufAnmeldung(Socket serverSocket) throws IOException {
        java.net.Socket socket = serverSocket.accept(); // blockiert, bis sich ein Client angemeldet hat
        return socket;
    }
    */

    public String leseNachricht(java.net.Socket socket) throws IOException{
        BufferedReader bufferedReader =
                new BufferedReader(
                        new InputStreamReader(
                                socket.getInputStream()));
        char[] buffer = new char[200];
        int anzahlZeichen = bufferedReader.read(buffer, 0, 200); // blockiert bis Nachricht empfangen
        String nachricht = new String(buffer, 0, anzahlZeichen);
        X_Ray_ComPort.close();
        return nachricht;
    }

    public void schreibeNachricht(java.net.Socket socket, String nachricht) throws IOException {
        PrintWriter printWriter =
                new PrintWriter(
                        new OutputStreamWriter(
                                socket.getOutputStream()));
        printWriter.print(nachricht);
        printWriter.flush();
    }

    //Getter and Setter Methods
    public Socket getX_Ray_ComPort() {
        return X_Ray_ComPort;
    }


}
