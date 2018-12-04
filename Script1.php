<?php
$conn =  mysql_connect("localhost","root","") or die("Unable to connect to MySQL");
mysql_select_db("magazin") or die("nu se gasesti bd");
$temp=$_POST['temperature'];
$umid=$_POST['humidity'];
mysql_query("insert into DATC values($temp,$umid)");

?>