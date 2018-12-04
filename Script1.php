<?php
$conn =  mysql_connect("localhost","root","") or die("Unable to connect to MySQL");
mysql_select_db("magazin") or die("nu se gasesti bd");
echo "conectat la server si baza de date";
$temp=$_POST['temperature'];
$umid=$_POST['humidity'];
echo "$temp si $umid sunt de inserat";
mysql_query("insert into DATC values($temp,$umid)") or die("INSERT Query has Failed");
echo "adaugare finalizata";
?>