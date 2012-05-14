<h3>Further information:</h3>



<?php 

foreach ($items as $delta => $item) { 

	print '<p><a href="' . render($item) . '" target="_blank">';

	print render($item);

	print '</a></p>';

}

?>