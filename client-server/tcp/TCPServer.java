import java.net.*;
import java.io.*;

public class TCPServer {
  public Socket socket = null;
  public ServerSocket server = null;
  public DataInputStream input = null;

  public TCPServer(int port) {
    try {
      server = new ServerSocket(port);
      System.out.println("server started");
      socket = server.accept();
      System.out.println("client accepted");

      input = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
      String line = "";

      while(!line.equals("over")) {
        try {
          line = input.readUTF();
          System.out.println(line);
        } catch(IOException i) {
          System.out.println(i);
        }
      }

      System.out.println("closing connection");
      socket.close();
      input.close();

    } catch(IOException i) {
      System.out.println(i);
    }
  }

  public static void main(String args[]) {
    TCPServer server = new TCPServer(3000);
  }
}