<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>orderform</title>
</head>
<body>

<?php
/**
 * Created by PhpStorm.
 * User: zhoud
 * Date: 15-12-2
 * Time: 上午10:52
 */
define('TIREPRICE',100);
define('OILPRICE',10);
define('SPARKPRICE',4);

$tireqty=$_POST['tireqty'];
$oilqty=$_POST['oilqty'];
$sparkqty=$_POST['sparkqty'];
$find=$_POST['find'];
$address=$_POST['address'];

$date=date("H:i,jS F Y");
setzero($tireqty);
setzero($oilqty);
setzero($sparkqty);
function setzero(&$m)
{
    if(empty($m))
    {
        $m=0;
    }
}
$totalqty=$tireqty+$oilqty+$sparkqty;
$totalamout=$tireqty*TIREPRICE+$oilqty*OILPRICE+$sparkqty*SPARKPRICE;

$outputstring = $date."\t".$tireqty." tireqty\t".$oilqty." oil\t".$sparkqty." spark\t\$".$totalamout."\t".$address."\n";

echo "<h1>Bob's Auto Parts</h1>";
echo "<h3>Order Result</h3>";

if ($totalqty==0)
{
    echo "<p>您没有买任何东西！</p>";
}
else {


    echo '<p>Order processed at' . date("H:i,jS F Y") . '</p>';
    echo 'Your order is follow:<br/>';
    echo $tireqty . ' tires <br/>';
    echo $oilqty . ' oil <br/>';
    echo $sparkqty . ' spark plugs <br/>';

    echo "<p>Items ordered: " . number_format($totalqty, 2), "</p>";
    echo "<p>totalamout: " . number_format($totalamout, 2), "</p>";

    $a = 56;
    echo gettype($a) . "<br/>";
    settype($a, 'double');
    echo gettype($a) . "<br/>";

    echo 'isset($tireqty): ' . isset($tireqty) . '<br/>';
    echo 'isset($nothere): ' . isset($nothere) . '<br/>';
    echo 'empty($tireqty): ' . empty($tireqty) . '<br/>';
    echo 'empty($nothere): ' . empty($nothere) . '<br/>';

    echo $find;
    switch ($find) {
        case "o":
            echo '<p>没有选</P>';
            break;
        case "a":
            echo '<p>常客</P>';
            break;
        case "b":
            echo '<p>电视广告</P>';

        case "c":
            echo '<p>手机</P>';
        case "d":
            echo '<p>别人说</P>';
    }
    $DOCUMENT_ROOT = $_SERVER['DOCUMENT_ROOT'];
    echo $DOCUMENT_ROOT. '<br/>';
    $fp=fopen("$DOCUMENT_ROOT/orders/orders.txt","ab");
    if(!$fp)
    {
        echo "<p>打开文件失败<p/>";
    }
    fwrite($fp,$outputstring);
    fclose($fp);
}
?>

<h2>循环创建代码</h2>
<table border="2" cellpadding="3">
    <tr bgcolor="#7fffd4">
        <td>Distance</td>
        <td>Cost</td>
    </tr>
    <?php
    for($i=1;$i<=5;$i++)
    {
        echo "<tr>
                <td>".(50*$i)."</td>
                <td>".(5*$i)."</td>
              </tr>";
    }

    ?>
</table>


</body>
</html>
