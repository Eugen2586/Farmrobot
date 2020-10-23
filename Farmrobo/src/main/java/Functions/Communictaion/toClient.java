package Functions.Communictaion;

import java.io.*;

public class toClient {
    java.net.Socket socket = null;
    String ip;
    int port;

    public toClient(String ip, int port){
        this.ip = ip;
        this.port = port;

        try {
            socket = new java.net.Socket(ip,port); // verbindet sich mit Server
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

/*        public static void main(String[] args) {
            Client client = new Client();
            try {
                client.test();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        void test() throws IOException {

            String zuSendendeNachricht = "Hello, world!";
            schreibeNachricht(socket, zuSendendeNachricht);
            String empfangeneNachricht = leseNachricht(socket);
            System.out.println(empfangeneNachricht);
        }*/
        public void schreibeNachricht(String nachricht) throws IOException {
            PrintWriter printWriter =
                    new PrintWriter(
                            new OutputStreamWriter(
                                    socket.getOutputStream()));
            printWriter.print(nachricht);
            printWriter.flush();
        }

        public String leseNachricht( ) throws IOException {
            BufferedReader bufferedReader =
                    new BufferedReader(
                            new InputStreamReader(
                                    socket.getInputStream()));
            char[] buffer = new char[200];
            int anzahlZeichen = bufferedReader.read(buffer, 0, 200); // blockiert bis Nachricht empfangen
            String nachricht = new String(buffer, 0, anzahlZeichen);
            return nachricht;
        }

}
