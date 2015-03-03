# arduino-node-d3-express

##Change the radius of a D3 circle using Arduino buttons.

###Circuit Layout
Follow the layout from CIRC-7 [Pushing buttons] (http://oomlout.com/a/products/ardx/circ-07/) example from the Arduino 
starter kit, but use the arduino sketch included in this repo

###Usage
```
git clone https://github.com/Talamantez/arduino-node-d3-express myRepo
cd myRepo
npm install
node app.js
```
* Open browser to localhost:3000
* Press the UP button on the Arduino circuit to increase the circle's radius
* Press the DOWN button on the Arduino circuit to decrease the circle's radius

###Permissions
If you are on Ubuntu, you may need to adjust the permissions of your serial ports to gain access to them.
An [accepted answer](http://askubuntu.com/questions/58119/changing-permissions-on-serial-port) on askubuntu.com
is to set your user to the dialout group:
```sudo usermod -a -G dialout terrik ```if terrik is your username.
