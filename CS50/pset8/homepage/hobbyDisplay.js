function displayInfos()
{
    let enjoy = document.querySelector('#enjoy').value;
    let sport = document.querySelector('#sport').value;
    let x = document.getElementById("choice").selectedIndex;
    let col_HEX = document.getElementById("color").value;
    document.querySelector('#resultEnjoy').innerHTML = enjoy;
    document.querySelector('#resultSport').innerHTML = sport;

    if(document.getElementsByTagName("option")[x].value == "yes")
    {
        document.querySelector('#resultPool1').innerHTML = "I like to play pool too! Let's play together someday!";
        document.querySelector('#resultPool2').innerHTML = 'You like pool!';
    }
    else
    {
        document.querySelector('#resultPool1').innerHTML = "Pool is fun, too bad that you don't like it";
        document.querySelector('#resultPool2').innerHTML = 'You dislike pool!';
    }
    document.querySelector('#resultColor1').innerHTML = 'HEX(' + col_HEX + ')';
    function hexToRGBA(hex, opacity)
    {
        return 'RGBA(' + (hex = hex.replace('#', '')).match(new RegExp('(.{' + hex.length/3 + '})', 'g'))
        .map(function(l) { return parseInt(hex.length%2 ? l+l : l, 16) }).concat(opacity||1).join(',') + ')';
    }
    let RGBA = hexToRGBA(col_HEX);
    document.querySelector('#resultColor2').innerHTML = RGBA;
    alert("You have submitted 'Your Hobbies' form");
}