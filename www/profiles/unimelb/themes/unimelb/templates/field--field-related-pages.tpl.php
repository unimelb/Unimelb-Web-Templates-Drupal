<h3>Related pages:</h3>

<?php 

foreach ($items as $delta => $item) { 

	print '<p>';

	print render($item);

	print '</p>';

}

?>

