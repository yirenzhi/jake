<!--
/**
* Created by PhpStorm.
* User: zhoud
* Date: 16-1-12
* Time: 下午5:28
*/
-->

<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>书店搜索结果</title>
</head>
<body>
<h1>书店搜索结果</h1>
<?php

//create short variable names
$searchtype=$_POST['searchtype'];
$searchterm=trim(['searchterm']);
if($searchtype==""||$searchterm=="")
{
    echo '你没有输入正确的搜索信息';
    exit;
}
//如果get_magic_qutes_gpc()开启就会自动给双引号加反斜杠,如果没开启就主动加.
if(!get_magic_quotes_gpc()){
    $searchtype = addslashes($searchtype);
    $searchterm = addslashes($searchterm);
}

echo $searchtype;
echo "<br/>";
echo $searchterm;
echo "<br/>";

@ $db = new mysqli('localhost','bookorama','bookorama123','books');
//$db = new mysqli('localhost','root','1','dbname');

if(mysqli_connect_errno())
{
    echo'没有连接上数据库，请重试.';
    exit;
}


$query = "select * from books where ".$searchtype." like '%".$searchterm."%'";
echo $query;
$result= $db->query($query);

$num_results = $result->num_rows;
//mysqli_num_rows($result);
echo "<p>找到了".$num_results."本书</p>";
for($i=0;$i<$num_results;$i++)
{
    $row = $result->fetch_assoc();
//    mysqli_fetch_assoc($result);
    echo "<p><strong>".($i+1).".标题:";
    echo htmlspecialchars(stripslashes($row['title']));
    echo "</strong>";
    echo "<br/>作者:";
    echo htmlspecialchars(stripslashes($row['author']));
    echo "<br/>编号:";
    echo htmlspecialchars(stripslashes($row['isbn']));
    echo "<br/>价格:";
    echo htmlspecialchars(stripslashes($row['price']));
    echo "</p>";

}
$result->free();
$db->close();

?>
</body>
</html>


