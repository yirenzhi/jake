<?php
/**
 * Created by PhpStorm.
 * User: zhoud
 * Date: 15-12-3
 * Time: 下午2:22
 */
//create short vaviable names
$name=$_POST['name'];
$email=$_POST['email'];
$feedback=$_POST['feedback'];

//set up some static information
$toaddress= "yiren_zhi@163.com";
$subject="Feedback from web site";
$mailcontent="Customer name".$name."\n".
             "Customer email:".$email."\n".
            "Customer comments:\n".$feedback."\n";

$fromaddress="From: 328478762@qq.com";

mail($toaddress,$subject,$mailcontent,$fromaddress);
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Document</title>
</head>
<body>
<h1>反馈提交</h1>
<p>你的反馈已经提交完成。</p>
</body>
</html>
