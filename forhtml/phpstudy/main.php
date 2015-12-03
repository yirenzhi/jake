<?php
/**
 * Created by PhpStorm.
 * User: zhoud
 * Date: 15-12-3
 * Time: 下午5:05
 */
echo '<p>There is the main file.</p>';
require('reusable.php');
echo 'The script will end now<br/>';


function reverse_i($str)
{
    for($i=1;$i<=strlen($str);$i++)
    {
        echo substr($str,-$i,1);
        echo "\t";
    }
}
reverse_i('hello');
echo '<br/>';
echo "<p>递归调用</p>";
function reverse_r($str)
{
    if(strlen($str)>1)
    {
        reverse_i(substr($str,1));
    }
    echo substr($str,0,1);
}
echo reverse_r('hello').'<br/>';


?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Document</title>
</head>
<body>

</body>
</html>
