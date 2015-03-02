'use strict'
var SerialPort = require("serialport").SerialPort;
var parsers = require("serialport").parsers;

var serialPort = new SerialPort("/dev/ttyACM0", {
	baudrate: 9600,
	parser: parsers.readline("\n")
});

var buttonValue;
var comparitor = 0;

serialPort.on("open", function () {
	console.log('open');
	serialPort.on('data', function( data ){
		buttonValue = data;
		if( buttonValue != comparitor ){
			console.log(''+ data);
		};
		comparitor = buttonValue;
		
	}); 
});
