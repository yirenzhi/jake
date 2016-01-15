<?php
/**
 * Created by PhpStorm.
 * User: zhoud
 * Date: 16-1-13
 * Time: 下午3:47
 */

//$mysqli = new mysqli('localhost','bookorama','bookorama123','books');
//echo "1";
//if(mysqli_connect_errno())
//    die(sprintf("[%d] %s\n", mysqli_connect_errno(), mysqli_connect_error()));

//$query = "insert into books value
//            ('".$isbn."','".$author."','".$title."','".$price.""."')";
$query = "insert into books value
            ('".$isbn."','".$author."','".$title."','".$price.""."')";
echo $query;

?>