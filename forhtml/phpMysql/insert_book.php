<?php
/**
 * Created by PhpStorm.
 * User: zhoud
 * Date: 16-1-14
 * Time: 上午11:23
 */
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Document</title>
</head>
<body>
<h1>书籍录入</h1>
<?php
$isbn=$_POST['isbn'];
$title=$_POST['title'];
$author=$_POST['author'];
$price=$_POST['price'];

if(!$isbn||!$title||!$author||!$price)
{
    echo "你没有输入全部的正确数据，请重新输入<br/>";
    exit;
}

@ $db= new mysqli('localhost','bookorama','bookorama123','books');
if(mysqli_connect_errno())
{
    echo "链接错误<br/>";
    exit;
}

$query = "insert into books value
            ('".$isbn."','".$author."','".$title."','".$price.""."')";
echo $query,"<br/>";
$result= $db->query($query);
//$result= mysqli_query($db,$query);//此种方式为成功
if($result)
{
    echo $db->affected_rows."书籍添加成功<br/>";
    //insert.delete和update是用此函数，select时用$result->num_rows
}
else
{
    echo "书籍添加失败<br/>";
}
$db->close();
?>
</body>
</html>


