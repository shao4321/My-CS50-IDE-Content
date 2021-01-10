function calculate_age_difference()
{
    let GD_age = document.querySelector('#GD_age').value;
    let GM_age = document.querySelector('#GM_age').value;
    let dad_age = document.querySelector('#dad_age').value;
    let mum_age = document.querySelector('#mum_age').value;
    let my_age = document.querySelector('#my_age').value;

    let age_diff_GD = GD_age - my_age;
    let age_diff_GM = GM_age - my_age;
    let age_diff_dad_age = dad_age - my_age;
    let age_diff_mum_age = mum_age - my_age;

    document.querySelector('#GD_diff').innerHTML = '';
    document.querySelector('#GM_diff').innerHTML = '';
    document.querySelector('#dad_diff').innerHTML = '';
    document.querySelector('#mum_diff').innerHTML = '';
    document.querySelector('#my_diff').innerHTML = '';

    if(my_age > 0) {
            if(GD_age < 0) {
            document.querySelector('#GD_diff').innerHTML = "Invalid age input for your Grandfather!";
        }
        else {
            document.querySelector('#GD_diff').innerHTML = "Your grandfather is " + age_diff_GD + " years older than you.";
        }
        if(GM_age < 0) {
            document.querySelector('#GM_diff').innerHTML = "Invalid age input for your Grandmother!";
        }
        else {
            document.querySelector('#GM_diff').innerHTML = "Your grandmother is " + age_diff_GM + " years older than you.";
        }
        if(dad_age < 0) {
            document.querySelector('#dad_diff').innerHTML = "Invalid age input for your Dad!";
        }
        else {
            document.querySelector('#dad_diff').innerHTML = "Your dad is " + age_diff_dad_age + " years older than you.";
        }
        if(mum_age < 0) {
            document.querySelector('#mum_diff').innerHTML = "Invalid age input for your Mum!";
        }
        else {
            document.querySelector('#mum_diff').innerHTML = "Your mum is " + age_diff_mum_age + " years older than you.";
        }
    }
    else {
        document.querySelector('#my_diff').innerHTML = "Invalid age input for your own age!";
    }

    alert("You have submitted 'Family Members' form");
}