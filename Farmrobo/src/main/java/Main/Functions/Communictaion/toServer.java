package Main.Functions.Communictaion;

import Constants.NETWORK;

import java.io.*;
import java.net.Socket;

public class toServer {
    //Deklarations
    static Socket X_Ray_ComPort = null;
    static Socket W_Ray_ComPort = null;
    static Socket Y_Ray_ComPort = null;

    //Method Areas

    public toServer(){
        try {
        if (X_Ray_ComPort == null || !X_Ray_ComPort.isConnected()){
            X_Ray_ComPort = new Socket(NETWORK.X_RAY_IP, NETWORK.X_RAY_PORT);
            System.out.println(X_Ray_ComPort.toString());
        }
        if (W_Ray_ComPort == null || !W_Ray_ComPort.isConnected()){
            W_Ray_ComPort = new Socket(NETWORK.W_RAY_IP, NETWORK.W_RAY_PORT);
            System.out.println(W_Ray_ComPort.toString());
        }
        if (Y_Ray_ComPort == null || !Y_Ray_ComPort.isConnected()){
            Y_Ray_ComPort = new Socket(NETWORK.Y_RAY_IP, NETWORK.Y_RAY_PORT);
            System.out.println(Y_Ray_ComPort.toString());
        }
        } catch (IOException e) {
            e.printStackTrace();
        }
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
        //X_Ray_ComPort.close();
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
    public Socket getX_Ray_ComPort() { return X_Ray_ComPort;   }
    public Socket getW_Ray_ComPort() { return W_Ray_ComPort;   }
    public Socket getY_Ray_ComPort() { return Y_Ray_ComPort;   }
    public Socket getZ_Ray_ComPort() { return Y_Ray_ComPort;   }

}
