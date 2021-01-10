function displayInfos()
{
    let name = document.querySelector('#name').value;
    let nationality = document.querySelector('#nationality').value;
    let age = document.querySelector('#age').value;
    let bday = document.querySelector('#bday').value;

    var today = new Date();
    var dd = today.getDate();
    var mm = today.getMonth() + 1;
    var yyyy = today.getFullYear();

    if (dd < 10) {
        dd = '0' + dd;
    }
    if (mm < 10) {
        mm = '0' + mm;
    }
    var date = yyyy +'-'+ mm +'-'+ dd;

    document.querySelector('#resultName').innerHTML = 'Hi ' + name + ' !';
    document.querySelector('#resultNatAge').innerHTML =
    'Coming from ' + nationality + ',' + ' you are ' + age + ' years old.';
    document.querySelector('#resultBday').innerHTML =
    'Your birthday falls on ' + bday + " and today's date is " + date + '.';

    alert("You have submitted 'Basic Introduction' form, " + name);
}