<?php
    session_start();
    $_SESSION = array();
    session_destroy();
    echo "Disconnessione avvenuta con successo!";
    header("Location: index.html");
?>