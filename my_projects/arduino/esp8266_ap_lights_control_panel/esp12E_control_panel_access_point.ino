#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "NodeMCU";  // Inserire il nome della rete.
const char* password = "casadomo123";  // Inserire la password.
IPAddress local_ip(192,168,4,1);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);
ESP8266WebServer server(80);
uint8_t LED_bagno = D4; // led del bagno.
bool LED_bagno_status = LOW;
uint8_t LED_cucina = D5; // led della cucina.
bool LED_cucina_status = LOW;
uint8_t LED_salotto = D6; // led del salotto.
bool LED_salotto_status = LOW;
uint8_t LED_stanza = D7; // led della stanza da letto.
bool LED_stanza_status = LOW;
uint8_t LED_carmadio = D8; // led della cabina armadio.
bool LED_carmadio_status = LOW;


void setup() {
  Serial.begin(115200);
  pinMode(LED_bagno, OUTPUT);
  pinMode(LED_cucina, OUTPUT);
  pinMode(LED_salotto,OUTPUT);
  pinMode(LED_stanza,OUTPUT);
  pinMode(LED_carmadio,OUTPUT);
    
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/led1on", handle_led1on); // bagno.
  server.on("/led1off", handle_led1off);
  server.on("/led2on", handle_led2on); // cucina.
  server.on("/led2off", handle_led2off); 
  server.on("/led3on", handle_led3on); // salotto.
  server.on("/led3off", handle_led3off);
  server.on("/led4on", handle_led4on); // stanza da letto.
  server.on("/led4off", handle_led4off);
  server.on("/led5on", handle_led5on); // cabina armadio.
  server.on("/led5off", handle_led5off); 
  
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  if(LED_bagno_status)
  {digitalWrite(LED_bagno, HIGH);}
  else
  {digitalWrite(LED_bagno, LOW);}
  
  if(LED_cucina_status)
  {digitalWrite(LED_cucina, HIGH);}
  else
  {digitalWrite(LED_cucina, LOW);}

  if(LED_salotto_status)
  {digitalWrite(LED_salotto, HIGH);}
  else
  {digitalWrite(LED_salotto, LOW);}

  if(LED_stanza_status)
  {digitalWrite(LED_stanza, HIGH);}
  else
  {digitalWrite(LED_stanza, LOW);}

  if(LED_carmadio_status)
  {digitalWrite(LED_carmadio, HIGH);}
  else
  {digitalWrite(LED_carmadio, LOW);}
}

void handle_OnConnect() {
  LED_bagno_status = LOW;
  LED_cucina_status = LOW;
  LED_salotto_status = LOW;
  LED_stanza_status = LOW;
  LED_carmadio_status = LOW;
  server.send(200, "text/html", SendHTML(LED_bagno_status,LED_cucina_status,LED_salotto_status,LED_stanza_status,LED_carmadio_status)); 
}
                      // LED1 = BAGNO;
void handle_led1on() {
  LED_bagno_status = HIGH;
  server.send(200, "text/html", SendHTML(true,LED_cucina_status,LED_salotto_status,LED_stanza_status,LED_carmadio_status)); 
}
void handle_led1off() {
  LED_bagno_status = LOW;
  server.send(200, "text/html", SendHTML(false,LED_cucina_status,LED_salotto_status,LED_stanza_status,LED_carmadio_status)); 
}
                      // LED2 = CUCINA;
void handle_led2on() {
  LED_cucina_status = HIGH;
  server.send(200, "text/html", SendHTML(LED_bagno_status,true,LED_salotto_status,LED_stanza_status,LED_carmadio_status)); 
}
void handle_led2off() {
  LED_cucina_status = LOW;
  server.send(200, "text/html", SendHTML(LED_bagno_status,false,LED_salotto_status,LED_stanza_status,LED_carmadio_status)); 
}
                      // LED3 = SALOTTO;
void handle_led3on() {
  LED_salotto_status = HIGH;
  server.send(200, "text/html", SendHTML(LED_bagno_status,LED_cucina_status,true,LED_stanza_status,LED_carmadio_status)); 
}
void handle_led3off() {
  LED_salotto_status = LOW;
  server.send(200, "text/html", SendHTML(LED_bagno_status,LED_cucina_status,false,LED_stanza_status,LED_carmadio_status)); 
}
                      // LED4 = STANZA DA LETTO
void handle_led4on() {
  LED_stanza_status = HIGH;
  server.send(200, "text/html", SendHTML(LED_bagno_status,LED_cucina_status,LED_salotto_status,true,LED_carmadio_status)); 
}
void handle_led4off() {
  LED_stanza_status = LOW;
  server.send(200, "text/html", SendHTML(LED_bagno_status,LED_cucina_status,LED_salotto_status,false,LED_carmadio_status)); 
}
                     // LED5 = CABINA ARMADIO
void handle_led5on() {
  LED_carmadio_status = HIGH;
  server.send(200, "text/html", SendHTML(LED_bagno_status,LED_cucina_status,LED_salotto_status,LED_stanza_status,true)); 
}
void handle_led5off() {
  LED_carmadio_status = LOW;
  server.send(200, "text/html", SendHTML(LED_bagno_status,LED_cucina_status,LED_salotto_status,LED_stanza_status,false)); 
}


void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t led1stat,uint8_t led2stat,uint8_t led3stat,uint8_t led4stat,uint8_t led5stat){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>Controllo Luci</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #1abc9c;}\n";
  ptr +=".button-on:active {background-color: #16a085;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>HOME CASA DOMOTICA</h1>\n";
  ptr +="<h3>ESP8266 CONTROLLO LUCI</h3>\n";
  
   if(led1stat)
  {ptr +="<p>LED_Bagno Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";}
  else
  {ptr +="<p>LED_Bagno Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";}

  if(led2stat)
  {ptr +="<p>LED_Cucina Status: ON</p><a class=\"button button-off\" href=\"/led2off\">OFF</a>\n";}
  else
  {ptr +="<p>LED_Cucina Status: OFF</p><a class=\"button button-on\" href=\"/led2on\">ON</a>\n";}

  if(led3stat)
  {ptr +="<p>LED_Salotto Status: ON</p><a class=\"button button-off\" href=\"/led3off\">OFF</a>\n";}
  else
  {ptr +="<p>LED_Salotto Status: OFF</p><a class=\"button button-on\" href=\"/led3on\">ON</a>\n";}

  if(led4stat)
  {ptr +="<p>LED_Stanza_da_letto Status: ON</p><a class=\"button button-off\" href=\"/led4off\">OFF</a>\n";}
  else
  {ptr +="<p>LED_Stanza_da_letto Status: OFF</p><a class=\"button button-on\" href=\"/led4on\">ON</a>\n";}

  if(led5stat)
  {ptr +="<p>LED_Cabina_armadio Status: ON</p><a class=\"button button-off\" href=\"/led5off\">OFF</a>\n";}
  else
  {ptr +="<p>LED_Cabina_armadio Status: OFF</p><a class=\"button button-on\" href=\"/led5on\">ON</a>\n";}
  
  ptr +="</body>\n";
  ptr +="</html>\n";
  
  return ptr;
}
