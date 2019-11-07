import java.io.*;
import java.net.*;
import java.util.*;

public class UDPClient {
	public DatagramSocket socket = null;
	public DatagramPacket packet = null;
	public byte buf[] = null;
	public String inp = null;

	public UDPClient(int port) {
		try {
			Scanner sc = new Scanner(System.in);
			socket = new DatagramSocket();
			InetAddress ip = InetAddress.getLocalHost();

			while (!inp.equals("over")) {
				try {
					inp = sc.nextLine();
					buf = inp.getBytes();

					packet = new DatagramPacket(buf, buf.length, ip, port);
					socket.send(packet);
				} catch (IOException e) {
					System.out.println(e);
				}
			}
		} catch (SocketException e) {
			System.out.println(e);
		}
	}

	public static void main(String args[]) {
		UDPClient client = new UDPClient(3000);
	}
}