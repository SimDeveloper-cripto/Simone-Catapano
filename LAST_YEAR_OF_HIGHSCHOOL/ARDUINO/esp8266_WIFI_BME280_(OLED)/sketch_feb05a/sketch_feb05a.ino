#include <ESP8266WebServer.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "SH1106Wire.h"

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;
SH1106Wire schermo(0x3c,SDA,SCL);

float temperature, humidity, pressure, altitude;

const char* ssid = "Vodafone-30253197";  
const char* password = "32dyzykt8psj5vz";  

ESP8266WebServer server(80);              
 
void setup() {
  Serial.begin(115200);
  delay(100);

  schermo.init();
  schermo.flipScreenVertically();
  schermo.setFont(ArialMT_Plain_10);
  
  bme.begin(0x76);   

  Serial.println("Mi sto connettendo a: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password); 
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("");
  
  Serial.println("WiFi connesso!");
  Serial.print("Vai all'indirizzo IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server iniziato");

}

void calcola(){
  temperature = bme.readTemperature();
  humidity = bme.readHumidity();
  pressure = bme.readPressure() / 100.0F;
  altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  schermo.clear();
  schermo.drawString(0,0,"Temperatura: " + String(temperature) + "°C");
  schermo.drawString(0,15,"Umidità: " + String(humidity) + "°%");
  schermo.drawString(0,30,"Pressione: " + String(pressure) + "hPa");
  schermo.drawString(0,45,"Altitudine: " + String(altitude) + "m");
  schermo.display();
}

void loop() {
  server.handleClient();
  calcola();
  delay(1000);
}

void handle_OnConnect() {
  /*
  temperature = bme.readTemperature();
  humidity = bme.readHumidity();
  pressure = bme.readPressure() / 100.0F;
  altitude = bme.readAltitude(SEALEVELPRESSURE_HPA); 
  */
  calcola();
  server.send(200, "text/html", SendHTML(temperature,humidity,pressure,altitude)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(float temperature,float humidity,float pressure,float altitude){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>CONTROLLO METEO ESP8266</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr +="p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr +="</style>\n"; 
  //-----------Inizio Script---------
  ptr +="<script>\n";
  ptr +="setInterval(loadDoc,1000);\n";
  ptr +="function loadDoc() {\n";
  ptr +="var xhttp = new XMLHttpRequest();\n";
  ptr +="xhttp.onreadystatechange = function() {\n";
  ptr +="if (this.readyState == 4 && this.status == 200) {\n";
  ptr +="document.body.innerHTML =this.responseText}\n";
  ptr +="};\n";
  ptr +="xhttp.open(\"GET\", \"/\", true);\n";
  ptr +="xhttp.send();\n";
  ptr +="}\n";
  ptr +="</script>\n";
  //--------------Fine Script---------  
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1> CONTROLLO METEO ESP8266 </h1>\n";
  ptr +="<p>Temperature:  ";
  ptr +=temperature;
  ptr +="&deg;C</p>";
  ptr +="<p>Humidity:  ";
  ptr +=humidity;
  ptr +="%</p>";
  ptr +="<p>Pressure:  ";
  ptr +=pressure;
  ptr +="hPa</p>";
  ptr +="<p>Altitude:  ";
  ptr +=altitude;
  ptr +="m</p>";
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
} 
