/*     ---------------------------------------------------------
 *     |  Arduino Experimentation Kit Example Code             |
 *     |  CIRC-07 .: Button Pushing :. (Pushbuttons)           |
 *     ---------------------------------------------------------
 *  A simple program that will fade the LED up when you press the top
 *  button and fade it down when you press the bottom button
 * 
 * http://tinyurl.com/c64tmt
 *
 */

//Button Variables
int buttonOne = 2; //The pin button one is attached to
int buttonTwo = 3; //The pin button one is attached to

//Led Variables
int ledPin = 9;  //The pin the LED is attached to
int ledValue = 0; //The current illumination Level of the led (0 off 255 full on)

void setup()
{
  pinMode(buttonOne, INPUT); digitalWrite(buttonOne, HIGH);  /* Sets the buttonOne pin to input and
                                                                sets the Arduinos internal pullup resistor
                                                                (this means the pin will read HIGH by default
                                                                and LOW when you press the button pulling to ground)
                                                             */
  pinMode(buttonTwo, INPUT); digitalWrite(buttonTwo, HIGH);  /* Sets the buttonOne pin to input and
                                                                sets the Arduinos internal pullup resistor
                                                             */
  pinMode(ledPin, OUTPUT);   
  
  Serial.begin(9600);  
}
 
/*
 * loop() - this function will start after setup finishes and then repeat
 * we will increase the brightness if buttonOne is pressed and decrease the
 * brightness if buttonTwo is pressed.
 */
void loop()                     // run over and over again
{
  if(digitalRead(buttonOne) == LOW){ledValue++;}
  if(digitalRead(buttonTwo) == LOW){ledValue--;}
  ledValue = constrain(ledValue,0,255);
  Serial.println(ledValue);
  analogWrite(ledPin, ledValue);
}
