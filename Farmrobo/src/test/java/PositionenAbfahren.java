import Constants.NETWORK;
import org.junit.Test;
import Constants.NETWORK;
import java.io.*;
import java.net.Socket;

import static java.lang.Thread.sleep;


public class PositionenAbfahren {
    public static class toServer {
        //Deklarations
        static Socket A_Ray_ComPort = null;
        final static String  A_RAY_IP = "192.168.100.38";
        final static int A_RAY_PORT = 9012;


        //Method Areas

        public toServer(){
            try {
                if (A_Ray_ComPort == null || !A_Ray_ComPort.isConnected()){
                    A_Ray_ComPort = new Socket(A_RAY_IP, A_RAY_PORT);
                    System.out.println(A_Ray_ComPort.toString());
                }

            } catch (IOException e) {
                e.printStackTrace();
            }
        }

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
        public Socket getA_Ray_ComPort() { return A_Ray_ComPort;   }

    }

    @Test
    public void anfahrenGrundstellung(){
        toServer t = new toServer();
        try {
            for(int i = 0; i < 100; i++) {
                t.schreibeNachricht(t.getA_Ray_ComPort(), "A");
                sleep(100);
                String h = new String();
                h = t.leseNachricht(t.getA_Ray_ComPort());
                h = h.replace("\n", "");
                h = h.replace("\r", "");
                h = h.replace(" ", "");
                if(h.contains("0")||
                        h.contains("1")||
                        h.contains("2")||
                        h.contains("3")||
                        h.contains("4")||
                        h.contains("5")||
                        h.contains("6")||
                        h.contains("7")||
                        h.contains("8")||
                        h.contains("9")){
                    System.out.println( i +". "+ h);
                }
            }
        } catch (IOException e) {
            //assert(false);
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}
