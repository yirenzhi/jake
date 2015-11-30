/**
 * Created by zhoud on 15-11-30.
 */
function changetext()
{

    document.getElementById("demo0").innerHTML="ABC";
}
function testCount()
{
    //加了var则不会当做全局变量
    var y=5;
    var x=y+2;
//    document.getElementById("demo0").innerHTML="ABC";
    document.getElementById("demo2").innerHTML="x="+x;
}


//数组
var cars=new Array("Audi","BMW","Volvo");

//name:value
var person={firstname:"Bill",lastname:"lastname",id:5566};
name=person.firstname;
name=person["lastname"];

//清空变量
cars=null;
person=null;


//带参数的函数
function testParameter(var1,var2)
{
    alert("Welcome "+var1+",the "+var2);
}

//带返回值的函数
//计算乘积
function testreturn(var1,var2)
{
    return var1*var2;
}


//创建对象
function createObject()
{
    people=new Object();
    people.firstelement="aa";
    people.secondelement="bb";
    people.thirdelement="cc";

}