import java.io.*;
import java.net.*;

public class UDPServer {
  public DatagramPacket packet = null;
  public DatagramSocket socket = null;
  public byte[] line = null;

  public UDPServer(int port) {
    try {
      socket = new DatagramSocket(port);
      line = new byte[65535];

      while (!data(line).toString().equals("over")) {
        try {
          packet = new DatagramPacket(line, line.length);
          socket.receive(packet);
          System.out.println(data(line));

          line = new byte[65535];
        } catch (IOException e) {
          System.out.println(e);
        }
      }
    } catch (SocketException e) {
      System.out.println(e);
    }
  }

  public static StringBuilder data(byte[] a) {
    if (a == null) {
      return null;
    }

    StringBuilder ret = new StringBuilder();
    int i = 0;

    while (a[i] != 0) {
      ret.append((char) a[i]);
      i++;
    }
    return ret;
  }

  public static void main(String[] args) {
    UDPServer server = new UDPServer(3000);
  }
}