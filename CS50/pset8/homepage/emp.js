function employee_status() {
    let emp_stats = document.getElementById('emp_status').selectedIndex;
    document.getElementById('result_selfemp').innerHTML = '';
    document.getElementById('result_emp').innerHTML = '';
    document.getElementById('result_wker').innerHTML = '';
    document.getElementById('result_unemp').innerHTML = '';

    if(document.getElementsByTagName("option")[emp_stats].value == "self_emp") {
        document.getElementById('result_selfemp').innerHTML =
        "A person is self-employed if they run their own business for themselves and " +
        "are solely responsible for its success. They are not protected by the employment rights enjoyed by employees," +
        "simply because they don’t have an ‘employer’ in the same way.<br/>" +
        "You can usually tell that someone is self-employed if:<br/>" +
        "- They don’t get holiday or sick pay when they’re not working.<br/>" +
        "- They give out ‘quotes’ for their work.<br/>" +
        "- They submit invoices once their work is done.<br/>";
    }
    else if(document.getElementsByTagName("option")[emp_stats].value == "emp") {
        document.getElementById('result_emp').innerHTML =
        "The ‘employee’ employment type covers anyone working under a contract of employment." +
        "Employees enjoy all the protections of a ‘worker’, " +
        "but with a range of additional employment rights and protections.<br/>"
        "A person is generally understood to be an employee if they:<br/>" +
        "- Have a contract of employment (that doesn’t necessarily need to be a written contract, though – sometimes, a verbal contract is enough).<br/>" +
        "- Are generally required to work regularly unless they are on some form of leave – for example, sick leave or parental leave.<br/>" +
        "- Receive paid holiday.<br/>" +
        "- Are subject to redundancy procedures.<br/>" +
        "- They are also usually required to work a minimum amount of hours, and they can’t subcontract someone else to do their work for them.<br/>";
    }
    else if(document.getElementsByTagName("option")[emp_stats].value == "wker") {
        document.getElementById('result_wker').innerHTML =
        "The ‘worker’ status is the most casual of the three different types of employment status.<br/>" +
        "A person is generally defined as a ‘worker’ if:<br/>" +
        "- They have an arrangement to perform work or services.<br/>" +
        "- They have to turn up for work even if they don’t want to.<br/>" +
        "- They cannot subcontract their work out to other people.<br/>" +
        "- They aren’t doing the work as a limited company (that would make them self-employed).<br/>";
    }
    else {
        document.getElementById('result_unemp').innerHTML =
        "Unemployment occurs when a person who is actively searching for employment is unable to find work.<br/>" +
        "Unemployment is often used as a measure of the health of the economy.<br/>" +
        "The most frequent measure of unemployment is the unemployment rate," +
        "which is the number of unemployed people divided by the number of people in the labor force.<br/>";
    }
}