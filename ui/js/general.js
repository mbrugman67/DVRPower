var pingRequest;
var resetRequest;

function pingCallback()
{
    if (pingRequest.readyState == 4 && pingRequest.status == 200)
    { 
        document.getElementById('status').innerHTML = pingRequest.responseText;
        button = document.getElementById('recheck');
        button.disabled = false;    
    }
}

function resetCallback()
{
    if (resetRequest.readyState == 4 && resetRequest.status == 200)
    { 
        document.getElementById('resetting').innerHTML = resetRequest.responseText;  
    }
}

function checkComms()
{
    document.getElementById('status').innerHTML = '<i>...Getting Status...</i>';
    button = document.getElementById('recheck');
    button.disabled = true;
    try
    {
        // Not crappy IE
        pingRequest = new XMLHttpRequest();
    }
    catch (e)
    {
        // Internet Explorer
        try
        {
            pingRequest = new ActiveXObject('Msxml2.XMLHTTP');
        }
        catch (e)
        {
            pingRequest = new ActiveXObject('Microsoft.XMLHTTP');
        }
    }

    pingRequest.open('POST', '/cgi-bin/timer.cgi', true);
    pingRequest.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
    pingRequest.onreadystatechange = pingCallback;
    pingRequest.send('func=ping');
}

function resetPower()
{
    document.getElementById('resetting').innerHTML = '<i>...Starting power cycle process...</i>';
    button = document.getElementById('reset');
    button.disabled = true;

    try
    {
        // Not crappy IE
        resetRequest = new XMLHttpRequest();
    }
    catch (e)
    {
        // Internet Explorer
        try
        {
            resetRequest = new ActiveXObject('Msxml2.XMLHTTP');
        }
        catch (e)
        {
            resetRequest = new ActiveXObject('Microsoft.XMLHTTP');
        }
    }

    resetRequest.open('POST', '/cgi-bin/timer.cgi', true);
    resetRequest.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
    resetRequest.onreadystatechange = resetCallback;
    resetRequest.send('func=reset');

    setTimeout(restoreButton, 3000);
}

function restoreButton()
{
    button = document.getElementById('reset');
    button.disabled = false;
}