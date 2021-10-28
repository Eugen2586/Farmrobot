<?php

define('IMAGES_PATH', 'esp32cam-uploads/');

$imageFiletype = strtolower(pathinfo($_FILES['imageFile']['name'], PATHINFO_EXTENSION));
$imageFilename = IMAGES_PATH . 'img-' . time() . '.' . $imageFiletype;

if (isset($_POST['submit'])) {
    $check = getimagesize($_FILES['imageFile']['tmp_name']);
    if ($check === false) {
        logAction('ERROR: Uploaded file is not an image!');
    }
}
if (file_exists($imageFilename)) {
    logAction('ERROR: Uploaded file already exists!');
}
if ($_FILES['imageFile']['size'] > 500000) {
    logAction('ERROR: Uploaded too large!');
}
if (!in_array($imageFiletype, ['jpg', 'jpeg', 'png'])) {
    logAction('ERROR: Only JPG, JPEG and PNG formats are allowed! Give');
}
if (move_uploaded_file($_FILES['imageFile']['tmp_name'], $imageFilename)) {
    logAction('SUCCESS: Uploaded and saves ' . basename($_FILES['imageFile']['name']) . ' » ' . $imageFilename);
} else {
    logAction('ERROR: Server error on uploading file!');
}

function logAction($message) {
    $message = date('c', time()) . ' - ' . $message . ' (IP: ' . $_SERVER['REMOTE_ADDR'] . ')' . PHP_EOL;
    error_log($message, 3, IMAGES_PATH . 'actions.log');
    exit($message);
}