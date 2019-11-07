import java.net.*;
import java.io.*;

public class TCPClient {
  public Socket socket = null;
  public DataInputStream input = null;
  public DataOutputStream output = null;

  public TCPClient(String ip, int port) {
    try {
      socket = new Socket(ip, port);
      System.out.println("connected to server");
      input = new DataInputStream(System.in);
      output = new DataOutputStream(socket.getOutputStream());

      String line = "";

      while (!line.equals("over")) {
        try {
          line = input.readLine();
          output.writeUTF(line);
        } catch (IOException i) {
          System.out.println(i);
        }
      }

      input.close();
      output.close();
      socket.close();
    } catch (IOException i) {
      System.out.println(i);
    }
  }

  public static void main(String args[]) {
    TCPClient client = new TCPClient("127.0.0.1", 3000);
  }
}