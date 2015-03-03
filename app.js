'use strict'
var express = require('express');
var app = express();
var http = require('http').Server(app);

var io = require('socket.io')(http);

var port = process.env.PORT || 3000;

// Serve some static content
app.use( express.static(__dirname + '/dist') );

// Serial Port Stuff

var SerialPort = require("serialport").SerialPort;
var parsers = require("serialport").parsers;

var serialPort = new SerialPort("/dev/ttyACM0", {
    baudrate: 9600,
    parser: parsers.readline("\n")
});

var buttonValue;
var comparitor = 0;
var parseIntData;

io.on('connection', function(socket){
    console.log('a user connected');
});

serialPort.on("open", function () {
    console.log('opening serial port');
    serialPort.on('data', function( data ){
        parseIntData = parseInt( data );
        if(typeof parseIntData === 'number' && parseIntData > -1 && parseIntData < 256){
            buttonValue = parseIntData;
            if( buttonValue != comparitor ){
                console.log(''+ parseIntData);
                io.sockets.emit('data', parseIntData);
            };
            comparitor = buttonValue;
        }; 
    });
});

// Http Stuff

http.listen(port, function(){
    console.log('\nListening on port:' + port + '\n');
});