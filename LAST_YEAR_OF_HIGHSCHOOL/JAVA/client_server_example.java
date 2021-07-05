/*
 * CREARE UN PROGRAMMA CLIENT/SERVER IN CUI IL CLIENT INVIA DUE NUMERI AL SERVER: 
 * IL SERVER LI SOMMA E INVIA AL CLIENT IL VALORE COMPLESSIVO.
*/

package somma_c_s;

import java.net.*;
import java.io.*;

public class Server {
	public static void main(String argv[]) throws IOException{
		try {
			while(true) {
				System.out.println("In attesa di connessioni...");
				ServerSocket ss = new ServerSocket(4004);
				Socket connessione = ss.accept();
				System.out.println("Connessione avvenuta");
				
				InputStream is = connessione.getInputStream();
				InputStreamReader input = new InputStreamReader(is);
				BufferedReader tastiera = new BufferedReader(input);
				String valore = tastiera.readLine();
				String valore1 = tastiera.readLine();
			
				tastiera.close();
				
				int numero1 = Integer.parseInt(valore);
				int numero2 = Integer.parseInt(valore1);
				int somma = numero1 + numero2;
				
				System.out.println("La somma dei due numeri è: " + somma);
				
				connessione.close();
				System.out.println("Connessione terminata!");
			}
		}catch(Exception e) {}
	}
}

__________________________________________________________________________________________________________________________

package somma_c_s;

import java.net.*;
import java.io.*;

public class Client {
	public static void main(String argv[]) throws IOException{
		try {
			Socket connessione = new Socket("127.0.0.1",4004);
			System.out.println("Connessione in corso...");
			
			InputStreamReader input =  new InputStreamReader(System.in); 
			BufferedReader tastiera = new BufferedReader(input); 
			String valore = "", valore1 = "";
			
			System.out.println("Digitare il primo numero:");
			valore = tastiera.readLine(); 
			int numero1 = Integer.parseInt(valore);
			System.out.println("Digitare secondo numero:");
			valore1 = tastiera.readLine(); 
			int numero2 = Integer.parseInt(valore1);
			
			OutputStream out = connessione.getOutputStream();
			PrintWriter sOUT = new PrintWriter(out);
			sOUT.println(numero1); sOUT.println(numero2);
			
			sOUT.close();
			connessione.close();
			System.out.println("Connessione terminata!");
		}catch(Exception e) {}
	}
}
