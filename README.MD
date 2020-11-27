# DVR Power Manager
I have an old Linux box that acts as the DVR for my OTA TV system.  It's old, headless, and sits in the corner in the basement.  I'm cheap and lazy.

The box occasionally hangs and needs to be hard booted.  Fine if I know and I'm home, but otherwise not so much.  There's a VPN server on my home network, so I can get to anything on the local home network on the from anywhere, so there's a solution to this problem.

I had an rPI laying around along with some high power electromechanical relays....
### The solution
An rPI with:
+ A very simple web page served up by Apache
  + A little css to make it purdy
  + A javascript file to do a little ajax
+ A cgi script written in c++ (don't judge - it's only visible to the local network, not directly on the internet)
+ An electromechanical relay with a contact rating of 20A at 120VAC connected to a GPIO point of the PI
+ An outlet in a 3-gang box to hold a single outlet, the rPI, and relay
### The details
File structure:  
+ cgi-source - the c++ source for the cgi script (obviously)
  + `main.cpp` sits here, along with the `Makefile`
  + `Makefile` builds the cgi script and does install.  A `make install` just copies the compiled binary to the correct directory as well as the html/css/javascript stuff.  Yes, the install will `setguid` of the installed script to root because GPIO has to be done as root.  Again, this is only visible to the local network, don't judge me.
  + `/http`
    + `http.cpp` is a simple class with some helpers; parse the POST string, generate HTTP header, etc.
  + `/util`
    + `io.cpp` to do the GPIO stuffs
    + `util.cpp` does `stringFormat` - a `vsprints()` implementation for `std::string`
+ ui - the web stuffs
  + `/css` just a couple of classes
  + `/js` one js script that gets linked in the header
  + `index.html` a very simple web page
