/*
* I.S.I.S "ANTONIO SERRA", GRUPPO DI LAVORO PER LA REALIZZAZIONE DI UNA CASA DOMOTICA. ANNO SCOLASTICO 201972020.
* Il programma presentato in basso funziona graze ad un Arduino Uno ed è stato programmato sull' IDE di Arduino.
* Esso sfrutta un display LCD_I2C, un tastierino numerico ed un servo motore. 
* Il Display fornisce un interfaccia grafica all'utente, il servo motore apre e chiude la porta una volta digitato il codice corretto e,
* il tastierino numerico permette all'utente di digitare il codice.
*/

//LIBRERIE
#include <Password.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// VARIABILI
Servo myservo;
LiquidCrystal_I2C schermo(0x27,20,4);
Password password = Password("4578"); // CODICE DI APERTURA DELLA PORTA.
const byte RIGHE = 4; 
const byte COLONNE = 4; 
char tasti[RIGHE][COLONNE] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte righePin[RIGHE] = {2,3,4,5}; // I PRIMI QUATTRO PIN DI COLLEGAMENTO DEL TASTIERINO RAPPRESENTANO LE RIGHE.
byte colPin[COLONNE] = {6,7,8,9}; // I RESTANTI QUATTRO PIN DI COLLEGAMENTO DEL TASTIERINO RAPPRESENTANO LE COLONNE.
Keypad keypad = Keypad(makeKeymap(tasti), righePin, colPin, RIGHE, COLONNE);
int i=0;

void setup(){
  /*
  * Nel setup viene inizializzato lo schermo, attivata la seriale per debugging, chiamato il menu di interfaccia.
  * Si definisce il collegamento del servo motore "chiuso" sul pin digitale 11 e il tastierino è in attesa di un evento, ovvero l'ottenere il codice.
  */
  
  schermo.init(); 
  schermo.backlight();
  Serial.begin(9600);
  keypad.setDebounceTime(50);
  menu();
  keypad.addEventListener(keypadEvent);
  myservo.attach(11); 
  myservo.write(90); 
}

void menu(){
  // Creiamo l'interfaccia per l'utente.  

  password.reset();
  schermo.clear();
  schermo.setCursor(3,0);
  schermo.print("PORTA BLOCCATA");
  schermo.setCursor(0,1);
  schermo.print("CONFERMA: '#' ");
  schermo.setCursor(0,2);
  schermo.print("CANCELLA: '*' ");
  schermo.setCursor(0,3);
  schermo.print("CODICE: ");
  schermo.setCursor(8,3);
  keypad.addEventListener(keypadEvent); 
}

void loop(){
 // Il tastierino numerico è sempre in attesa che l'utente prema i tasti. Se però vengono premuti più di 12 caratteri,
 // il codice non verrà accettato, si cancellerà da solo e verrà mostrato nuovamente il menu.

  keypad.getKey(); 
  if (i>12){
  i=0;
  menu();
  }
  }

void keypadEvent(KeypadEvent eKey){
/*
* Questa funzione sfrutta la selezione multipla:
* Ogni volta che verrà premuto un tasto del tastierino verrà mostrato a video sottoforma di "*". 
* Se il tasto premuto è "#" verrà attivato il controllo password.
* Se il tasto premuto è "*" si ritornerà indietro al menu inziale.
*/

  switch (keypad.getState()){
  case PRESSED:
    schermo.print("*");
    i++;
    switch (eKey){
    case '#': 
      controllo_password();
      break;
    case '*': 
         menu(); break;
    default:
      password.append(eKey);
}
}
}

void controllo_password(){
  /*
  * Per controllare la password, viene sfruttata una funzione: password.evaluate()
  * "password.evaluate()" serve per ottenere l'effettivo valore della password e confrontarlo con il codice digitato.
  * Se il codice è corretto viene dato il benvenuto sullo schermo e viene chiamata la funzione "sblocca_porta()".
  * Se non è corretto il display mostrerà la scritta di accesso negato e riporterà l'utente al menu iniziale.
  */

  if (password.evaluate()){
    schermo.clear();
    delay(30);
    schermo.setCursor(5, 1);
    schermo.print("BENVENUTO!");
    sblocca_porta();
    menu();
  }
  else{
    loop(); 
	i++; {
    }
    schermo.clear();
    delay(10);
    schermo.setCursor(3, 1);
    schermo.print("ACCESSO NEGATO");
    delay(1500);
    schermo.clear();
    menu();
  }
}

void sblocca_porta(){ 
  /* Digitato il codice corretto, il servo motore apre la porta di 180 gradi e dopo 5 secondi la chiude con una rotazione di 90 gradi. */

  myservo.write(180);
  delay(5000);
  myservo.write(90);
}
