#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#ifndef APSSID
#define APSSID "" // DIGITARE IL NOME DELLA RETE
#define APPSK  "" // DIGITARE LA PASSWORD DELLA RETE
#endif

const char *ssid = APSSID;
const char *password = APPSK;

ESP8266WebServer server(80); // LA PORTA 80 SPECIFICA IL PROTOCOLLO HTTP

/* 
 *  CONTROLLA SUL MONITOR SERIALE L'INDIRIZZO IP DEL DISPOSITIVO COSI' DA PORTERLO CERCARE SUL WEB.
 *  SOLITAMENTE L'INDIRIZZO E': 192.168.4.1
*/
void onConnect() {
  server.send(200, "text/html", "<center> <h2> SEI CONNESSO AL WEB SERVER </h2> </center>");
}

void setup() {
  delay(1000);
  Serial.begin(9600);
  Serial.println();
  Serial.print("STO CONFIGURANDO L'ACCESS POINT...");
  
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP INDIRIZZO IP: ");
  Serial.println(myIP);
  
  server.on("/", onConnect);
  
  server.begin();
  Serial.println("IL SERVER HTTP E' ATTIVO!");
}

void loop() {
  server.handleClient();
}
