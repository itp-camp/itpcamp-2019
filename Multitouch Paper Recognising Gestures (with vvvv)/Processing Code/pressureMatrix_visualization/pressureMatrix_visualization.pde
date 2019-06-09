/*
 Code based on Tom Igoe's Serial Graphing Sketch
 >> http://wiki.processing.org/w/Tom_Igoe_Interview
 
 Reads X analog inputs and visualizes them by drawing a grid
 using grayscale shading of each square to represent sensor value.
 >> http://howtogetwhatyouwant.at/
 */

import processing.serial.*;

Serial myPort;  // The serial port
int rows = 3;
int cols = 3;
int maxNumberOfSensors = rows*cols;     
float[] sensorValue = new float[maxNumberOfSensors];  // global variable for storing mapped sensor values
float[] previousValue = new float[maxNumberOfSensors];  // array of previous values
int rectSize = 0;
int rectY;
void setup () { 
  size(600, 600);  // set up the window to whatever size you want
  rectSize = width/rows;

  println(Serial.list());  // List all the available serial ports
  String portName = Serial.list()[1];  // set the number of your serial port!
  myPort = new Serial(this, portName, 9600);
  myPort.clear();
  myPort.bufferUntil('\n');  // don't generate a serialEvent() until you get a newline (\n) byte
  background(255);    // set inital background
  smooth();  // turn on antialiasing
  rectMode(CORNER);
}


void draw () {
  for (int i = 0; i < maxNumberOfSensors; i++) {
    fill(sensorValue[i]);
    rect(rectSize * (i%rows), rectY, rectSize, rectSize);  //top left
    if((i+1) % rows == 0) rectY += rectSize;
  }
  rectY=0;
}


void serialEvent (Serial myPort) {
  String inString = myPort.readStringUntil('\n');  // get the ASCII string
println("test");
  if (inString != null) {  // if it's not empty
    inString = trim(inString);  // trim off any whitespace
    int incomingValues[] = int(split(inString, "\t"));  // convert to an array of ints

    if (incomingValues.length <= maxNumberOfSensors && incomingValues.length > 0) {
      for (int i = 0; i < incomingValues.length; i++) {
        // map the incoming values (0 to  1023) to an appropriate gray-scale range (0-255):
        sensorValue[i] = map(incomingValues[i], 0, 1023, 0, 255); // stretch 5x5
        println(sensorValue[i]);  // print value to see
      }
    }
  }
}
