<h3>Related URLs:</h3>

<?php 

foreach ($items as $delta => $item) { 

	print '<p><a href="' . render($item) . '" target="_blank">';

	print render($item);

	print '</a></p>';

}

?>

