<?php
	$server = "localhost";
	$user = "root";
	$password_db = "";
	$nome_db = "esercizio";
	$nome_tabella = "utenti";

	mysql_connect($server, $user, $password_db) or die('Impossibile connettersi al server: ' . mysql_error() );
	mysql_select_db($nome_db) or die('Impossibile collegarsi al database: ' . mysql_error() );

	$email = $_POST["email"];
	$password = $_POST["password"];

	$email = stripslashes($email);
	$password = stripslashes($password);
	$email = mysql_real_escape_string($email);
	$password = mysql_real_escape_string($password);

	$sql = " SELECT * FROM $nome_tabella WHERE Email='$email' and Password='$password' ";
	$result = mysql_query($sql);
	$conta = mysql_num_rows($result);
	if ($conta == 1){ 
		session_start();
		$_SESSION['email'] = $email;
        $_SESSION['password'] = $password;
		header("Location: area_privata.php");
	}
	else {
		echo "<font size='5' face='Verdana'> Identificazione non riuscita: l'email o la password non sono corretti! </font> <br/>";
		echo "<font size='5' face='Verdana'> Ritorna alla pagina di <a href=\"login.html\"> LOGIN </a> </font> <br>";
		echo " <div> <p> <object data='codici\dunnow.gif' width='400' height='200'> </object> </p> </div> <br> ";
	}
?>

<html>
	<head>
		<title> CONTROLLO LOGIN </title>
	</head>
</html>