//Example: Find IP address for domain name.

import java.net.*;
import java.util.*;
public class App {
public static void main(String[] args) throws Exception {
{
String host;
Scanner input = new Scanner(System.in);
System.out.print("\n\nEnter host name: ");
host = input.next();
try {
InetAddress address =
InetAddress.getByName(host);
System.out.println(("\n IP address: "
+ address.toString());
}
catch (UnknownHostException uhEx)
{
System.out.println("Could not find " + host);
} }}}
Example 2: Get the IP address of the current machine.
import java.net.*;
public class App
{
public static void main(String[] args)
{
try {
InetAddress address = InetAddress.getLocalHost();
System.out.println(address); }
catch (UnknownHostException uhEx)
{
System.out.println("Could not find local address!"); } } }

----------------------------------------------------------------------

/*Example 1:
Checks for ports on the local machine by attempting to create ServerSocket objects 
on them and seeing on which ports that fails. If you’re using Unix and are not 
running as root, this program works only for ports 1,024 and above.
*/	
for (int port = 1; port <= 65535; port++) {
try {
ServerSocket server = new ServerSocket(port);
System.out.println("Available : " + port + ".");
}
catch (IOException ex) {
System.out.println("There is a server on port " + port + ".");
} // end catch
}
-----------------------------------------------------------------------

//Example: demonstrating how to establish a TCP connection using Java

String serverHostname = "localhost"; // Change this to the server's 
hostname or IP address
int serverPort = 80; // Change this to the server's port
try (Socket socket = new Socket(serverHostname, serverPort);
PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
BufferedReader in = new BufferedReader(new
InputStreamReader(socket.getInputStream()))) {
// Send data to the server
out.println("Hello, server!");
// Receive data from the server
String response = in.readLine();
System.out.println("Server response: " + response);
} catch (UnknownHostException e) {
System.err.println("Unknown host: " + serverHostname);
} catch (IOException e) {
System.err.println("Error communicating with the server: " +
e.getMessage());
}

----------------------------------------------------------------------

//A simple client-server communication setup using sockets.
import java.io.*;
import java.net.*; 
import java.util.*;
public class App {
public static void main(String[] args) throws Exception {
 //Server
String hostname = "www.oreilly.com"; 
ServerSocket ss = new ServerSocket(1286);
Socket s =ss.accept();
OutputStream socketOutStream = s.getOutputStream();
DataOutputStream socketDos = new DataOutputStream(socketOutStream);
socketDos.writeUTF("Hello World!");
socketDos.close();
socketOutStream.close();
s.close();
ss.close(); 
 // Client
 Socket s = new Socket("localhost",1286);
InputStream sIn = s.getInputStream();
DataInputStream socketDis = new DataInputStream(sIn);
String testString = new String(socketDis.readUTF());
System.out.println(testString);
socketDis.close();
sIn.close();
s.close(); 
}
}

---------------------------------------------------------------
//Example of a simple UDP client and server implemented in Java:
UDP Client Example:
import java.io.*;
import java.net.*;
public class UDPClient {
 public static void main(String[] args) {
 final String serverHost = "localhost";
 final int serverPort = 12345;
 try {
 DatagramSocket clientSocket = new DatagramSocket();
 InetAddress serverAddress = InetAddress.getByName(serverHost);
 byte[] sendData = "Hello, UDP Server!".getBytes();
 DatagramPacket sendPacket = new DatagramPacket(sendData, 
sendData.length, serverAddress, serverPort);
 clientSocket.send(sendPacket);
 byte[] receiveData = new byte[1024];
 DatagramPacket receivePacket = new DatagramPacket(receiveData, 
receiveData.length);
 clientSocket.receive(receivePacket);
 String receivedMessage = new String(receivePacket.getData(), 0, 
receivePacket.getLength());
 System.out.println("From Server: " + receivedMessage);
 clientSocket.close();
 } catch (IOException e) {
 e.printStackTrace();
 }
 }
}

//UDP Server Example:
import java.io.*;
import java.net.*;
public class UDPServer {
 public static void main(String[] args) {
 final int serverPort = 12345;
 try {
 DatagramSocket serverSocket = new DatagramSocket(serverPort);
 byte[] receiveData = new byte[1024];
 DatagramPacket receivePacket = new DatagramPacket(receiveData, 
receiveData.length);
 while (true) {
 serverSocket.receive(receivePacket);
 String clientMessage = new String(receivePacket.getData(), 0, 
receivePacket.getLength());
 System.out.println("From Client: " + clientMessage);
 InetAddress clientAddress = receivePacket.getAddress();
 int clientPort = receivePacket.getPort();
 byte[] sendData = "Hello, UDP Client!".getBytes();
 DatagramPacket sendPacket = new DatagramPacket(sendData, 
sendData.length, clientAddress, clientPort);
 serverSocket.send(sendPacket);
 }
 } catch (IOException e) {
 e.printStackTrace();
 }
 }
}

--------------------------------------------------------------

//Example: Implementing a Simple DHCP Client
import java.io.*;
import java.net.*;
public class DHCPClient {
 public static void main(String[] args) {
 DatagramSocket socket = null;
 try {
 socket = new DatagramSocket();
 socket.setSoTimeout(5000); // Set timeout to 5 seconds
 // Prepare DHCP Discover packet
 byte[] discoverData = {0x01, 0x01, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00};
 InetAddress serverAddress = InetAddress.getByName("255.255.255.255");
 int serverPort = 67;
 DatagramPacket discoverPacket = new DatagramPacket(discoverData, 
discoverData.length, serverAddress, serverPort);
 // Send DHCP Discover packet
 socket.send(discoverPacket);
 // Receive DHCP Offer packet
 byte[] offerData = new byte[1024];
 DatagramPacket offerPacket = new DatagramPacket(offerData, 
offerData.length);
 socket.receive(offerPacket);
 // Process DHCP Offer packet
 // You can parse and extract IP address and other configuration details here
 System.out.println("Received DHCP Offer from server.");
 } catch (SocketTimeoutException e) {
 System.err.println("No response from DHCP server.");
 } catch (IOException e) {
 e.printStackTrace();
 } finally {
 if (socket != null) {
 socket.close();
 }
 }
 }
}
