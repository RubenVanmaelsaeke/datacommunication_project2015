<?php
	if (isset($_POST['btnSubmit'])) 
	{
		if (isset($_POST['aantalleds']) || isset($_POST['kleur'])) 
		{
			$aantal = $_POST['aantalleds'];
			$kleur = $_POST['kleur'];



			print_r("Aantal leds: " . $aantal . "<br/>");
			print_r("Kleur: " . $kleur . "<br/>");

			exec('sudo /home/pi/Desktop/leds ' . $aantal . " " . $kleur, $out);

			print_r($out);
		}
	}	
?>

<!DOCTYPE HTML>
<html>
<head>
	<title>RGB Leds</title>
	<link rel="stylesheet" type="text/css" href="screen.css">
</head>

<body>
	<form action="<?php print $_SERVER['PHP_SELF']; ?>" method='post'>
	<h2>RGB LEDS Aansturen</h2>

		<p>Selecteer hoeveel leds moeten aanstaan:</p>
		</br>
		<input placeholder="Bijv. 5" type="text" name="aantalleds">
		</br>
		</br>
		<p>Geef hier een kleur in (hexadecimale waarde):</p>
		</br>
		<input placeholder="Bijv. 0xFF0000" type="text" name="kleur">
		</br>
		</br>
		<input id="button" type="submit" name="btnSubmit" value="Verander Kleur">
	</form>
</body>

</html>