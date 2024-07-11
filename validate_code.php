<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $access_code = $_POST['access_code'];
    $valid_code = 'ma1ma2'; // Cambia esto al código de acceso que desees

    if ($access_code === $valid_code) {
        header('Location: download.php');
        exit();
    } else {
        header('Location: descarga.html?error=1');
        exit();
    }
}
?>
