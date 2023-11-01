
<?php
if (isset($_POST['submit'])){
  echo "Success Submit";

$upper_limit = $_POST['limit'];

echo "<table style='border: 1px solid black'><tr style='border: 1px solid black'><th>X</th> ";
for ($col = 1; $col <= $upper_limit; $col++){
    echo "<th style='border: 1px solid black'>".strval($col)."</th>";
}
echo "</tr>";
for ($col = 1; $col <= $upper_limit; $col++){
echo "<tr style='border: 1px solid black'><td  style='border: 1px solid black'><b>".strval($col)."</b></td>";
    for ($index = 1; $index <= $upper_limit; $index++){
    echo "<td style='border: 1px solid black'>".strval($col * $index)."</td>";
    }
}
echo "</tr>";
}
echo "</table>";
?>