<?php
/**
 * Created by PhpStorm.
 * User: zhoud
 * Date: 15-12-2
 * Time: 下午7:53
 */
$DOCUMENT_ROOT=$_SERVER['DOCUMENT_ROOT'];
define('ROOT',"$DOCUMENT_ROOT/orders/orders.txt");
?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>顾客清单</title>
</head>
<body>

<?php
    $fp=fopen("$DOCUMENT_ROOT/orders/orders.txt","rb");
    if(!$fp)
    {
        echo "<p>文件打开错误</p>";
        exit;
    }
    while(!feof($fp))
    {
        $order=fgets($fp,999);
        echo $order."<br/>";
        //fclose($fp);
    }

//    $order=readfile("$DOCUMENT_ROOT/../orders/orders.txt");
//    echo $order;

    $orders=file(ROOT);

    $number_of_orders=count($orders);
    if($number_of_orders==0)
    {
        echo "<p>there is no orders</p>";
    }

    echo "<h2>清单列表</h2>";
    echo "<table border=\"1\">
    <tr bgcolor=\"#ff7f50\">
        <th>日期</th>
        <th>Tires</th>
        <th>Oil</th>
        <th>Spark Plugs</th>
        <th>全部金额</th>
        <th>地址</th>
    </tr>";
    for($i=0;$i<$number_of_orders;$i++)
    {
        //分割函数 array explode(string separator,string string[,int limit])
        $line = explode("\t", $orders[$i]);

        $line[1] = intval($line[1]);
        $line[2] = intval($line[2]);
        $line[3] = intval($line[3]);

        echo "<tr>
        <td align=\"right\">$line[0]</td>
        <td align=\"right\">$line[1]</td>
        <td align=\"right\">$line[2]</td>
        <td align=\"right\">$line[3]</td>
        <td align=\"right\">$line[4]</td>
        <td>$line[5]</td>

    </tr>";

    }
    echo "</table>";

?>

</body>
</html>
