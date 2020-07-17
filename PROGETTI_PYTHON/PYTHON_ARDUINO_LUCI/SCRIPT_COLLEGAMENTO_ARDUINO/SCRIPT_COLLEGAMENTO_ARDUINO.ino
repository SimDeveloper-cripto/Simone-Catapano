void setup(){
  Serial.begin(9600); 
  pinMode(13, OUTPUT); 
}
void loop(){
  char COMANDO = Serial.read();

  if (COMANDO == 'a' || COMANDO == 'A'){
    digitalWrite(13, HIGH); 
  } else if (COMANDO == 's' || COMANDO == 'S'){
    digitalWrite(13, LOW); 
  } else {
    Serial.print("ERRORE DI INSERIMENTO!");
  }
}
