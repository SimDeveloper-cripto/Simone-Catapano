<?php
    $server = "localhost";
    $user = "root";
    $password_db = "";
    $nome_db = "esercizio";
    $nome_tabella = "utenti";

    mysql_connect($server, $user, $password_db) or die('Impossibile connettersi al server: ' . mysql_error());
    mysql_select_db($nome_db) or die('Impossibile collegarsi al database: ' . mysql_error());
    
    if(isset($_POST["register"])){
        $email = $_POST['email'];
        $password = $_POST['password'];

        $query2 = " SELECT * FROM $nome_tabella WHERE Email='$email' ";

        $resultexist = mysql_query($query2);
        $checkemail = mysql_num_rows($resultexist);
        
        if($checkemail > 0) { 
            echo "<font size='5' face='Verdana'> Email gia presente! </font> <br> ";
            echo "<font size='5' face='Verdana'> Clicca <a href=\"login.html\" > VAI AL LOGIN </a> </font> <br>";
            echo " <div> <p> <object data='codici\dunnow.gif' width='400' height='200'> </object> </p> </div> <br> ";
            // header("Location: login.html");
        }else {
            $query = " insert into $nome_tabella (Email,Password) VALUES('$email','$password') ";
            $result = mysql_query($query);
            echo "<font size='5' face='Verdana'> Registrazione avvenuta correttamente! </font> <br>"; 
            echo "<font size='5' face='Verdana'> Clicca <a href=\"login.html\" > VAI AL LOGIN </a> </font> <br>";
            echo " <div> <p> <object data='codici\happy.gif' width='400' height='250'> </object> </p> </div> <br> ";
            // header("Location: login.html"); 
        }  
    }
?>  

<html>
    <head>
        <title> CONTROLLO REGISTRAZIONE </title>
    </head>
</html>