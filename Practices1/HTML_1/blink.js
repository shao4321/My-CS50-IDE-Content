function blink()
{
    let body = document.querySelector('body');
    if(body.style.visibility == "visible")
    {
        body.style.visibility = "hidden";
    }
    else
    {
        body.style.visibility = "visible";
    }
}
function blinkcolour()
{
    let body = document.querySelector('body');
    if(body.style.backgroundColor == 'white')
    {
        body.style.backgroundColor = 'black';
    }
    else
    {
        body.style.backgroundColor = 'white';
    }
}
window.setInterval(blink, 5000);