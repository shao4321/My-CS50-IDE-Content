var start = 1;
function set_time1()
{
    setInterval(image_show1, 3000);
}
function set_time2()
{
    setInterval(image_show2, 3000);
}
function set_time3()
{
    setInterval(image_show3, 3000);
}
function set_time4()
{
    setInterval(image_show4, 3000);
}
function image_show1()
{
    var image_data;
    if(start == 1)
    {
        image_data ="1.png";
    }
    else if(start == 2)
    {
        image_data ="2.jpg";
    }
    else if(start == 3)
    {
        image_data ="3.jpg";
    }
    else
    {
        image_data ="1.png";
        start = 1;
    }
    document.getElementById("data").src = image_data;
    start++;
}
function image_show2()
{
    var image_data;
    if(start == 1)
    {
        image_data ="4.jpg";
    }
    else if(start == 2)
    {
        image_data ="5.jpg";
    }
    else if(start == 3)
    {
        image_data ="6.jpg";
    }
    else
    {
        image_data ="4.jpg";
        start = 1;
    }
    document.getElementById("data").src = image_data;
    start++;
}
function image_show3()
{
    var image_data;
    if(start == 1)
    {
        image_data ="7.jpg";
    }
    else if(start == 2)
    {
        image_data ="8.jpg";
    }
    else if(start == 3)
    {
        image_data ="9.jpg";
    }
    else
    {
        image_data ="7.jpg";
        start = 1;
    }
    document.getElementById("data").src = image_data;
    start++;
}
function image_show4()
{
    var image_data;
    if(start == 1)
    {
        image_data ="10.jpg";
    }
    else if(start == 2)
    {
        image_data ="11.jpg";
    }
    else if(start == 3)
    {
        image_data ="12.jpg";
    }
    else
    {
        image_data ="10.jpg";
        start = 1;
    }
    document.getElementById("data").src = image_data;
    start++;
}