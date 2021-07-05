<!DOCTYPE html>
<html>
    <head>
        <title> AREA RISERVATA </title>
        <style type="text/css">
        body {
            font-family: sans-serif;
            font-size: 12pt;
            font-style: italic;
            font-weight: bold;
        }
        #sezione_messaggio {
            font-family: sans-serif;
            font-size: 12pt;
            font-style: italic;
            font-weight: bold;
            color: #00F;
            background-color: #CCC;
            padding: 20px;
            height: 80px;
            width: 300px;
        }
        .cpp{
            font-family:sans-serif;
            width: 550px;
            height: 200px;
        }
        .java {
            font-family:sans-serif;
            width: 550px;
            height: 200px;
        }
        .arduino {
            font-family:sans-serif;
            width: 550px;
            height: 200px;
        }
    </style>
    </head>
    <body>
        <center> <h2> BENVENUTO NELL'AREA RISERVATA </h2> </center>
    
        <!--          <object data="codici\Hamming.txt" width="800" height="400"></object>        -->

        <div id="sezione_messaggio">
        <script language="javascript" type="text/javascript" src="msg.js"> </script>
        </div> <br> <br>
 
        <div class="cpp"> <center> <font size="4" face="Verdana" color="red"> C++ </font> </center>
           <p> <b> CALCOLO DEL CODICE DI HAMMING: </b>  <a href="codici\Hamming.txt" target="_blank"> VEDI IL CODICE</a> </p>
           <p> <b> SOMMA E MEDIA IN MATRICE: </b>  <a href="codici\somma_media_matrice.txt" target="_blank"> VEDI IL CODICE</a> </p>
           <p> <b> PRIMO UTILIZZO DEI THREAD: </b>  <a href="codici\primo_thread.txt" target="_blank"> VEDI IL CODICE</a> </p>
           <p> <b> GENERATORE PASSWORD CASUALE: </b>  <a href="codici\pass_casuale.txt" target="_blank"> VEDI IL CODICE</a> </p>
           <p> <b> ORIENTAMENTO AD OGGETTI: </b>  <a href="codici\c_ad_oggetti.txt" target="_blank"> VEDI IL CODICE</a> </p>
           <p> <b> CONVERSIONI BINARIO/DECIMALE E VICEVERSA : </b>  <a href="codici\conversioni.txt" target="_blank"> VEDI IL CODICE</a> </p> 
        </div> <br> <br> <br> 

        <div class="java"> <center> <font size="4" face="Verdana" color="red"> Java </font> </center>
           <p> <b> AGGIUNTA EVENTI AD INTERFACCIA (Java) </b>  <a href="codici\eventi_interfaccia.txt" target="_blank"> VEDI IL CODICE</a> </p>
           <p> <b> SOMMA DUE NUMERI TRA CLIENT E SERVER (Java) </b>  <a href="codici\somma_cs.txt" target="_blank"> VEDI IL CODICE</a> </p>
           <p> <b> LETTURA DELLA PROPRIA MAIL BOX (Java) </b>  <a href="codici\read_mail.txt" target="_blank"> VEDI IL CODICE</a> </p>
           <p> <b> INVIO DI MAIL (Java) </b>  <a href="codici\mail_sender.txt" target="_blank"> VEDI IL CODICE</a> </p>
        </div>

        <div class="arduino"> <center> <font size="4" face="Verdana" color="red"> Arduino </font> </center>
           <p> <b> ESP-8266 CONTROLLO LUCI </b>  <a href="codici\controllo_luci.txt" target="_blank"> VEDI IL CODICE</a> </p>
           <p> <b> SENS. TEMPERATURA DH11 E DISPLAY LCD_I2C </b>  <a href="codici\sens_temp.txt" target="_blank"> VEDI IL CODICE</a> </p>
           <p> <b> CREAZIONE DI UNA PORTA </b>  <a href="codici\porta.txt" target="_blank"> VEDI IL CODICE</a> </p>
        </div>

        <?php
            session_start();
            if(!isset($_SESSION['email'])) {
                header("Location: login.html");
            }
        ?>
    </body>
</html>