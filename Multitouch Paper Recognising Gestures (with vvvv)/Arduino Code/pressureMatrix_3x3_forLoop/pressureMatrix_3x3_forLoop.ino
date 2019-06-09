/*
  Pressure Sensor Matrix Code
  parsing through a pressure sensor matrix grid by switching individual 
  rows/columns to be HIGH, LOW or INPUT (high impedance) to detect 
  location and pressure.
  >> https://www.kobakant.at/DIY/?p=7443
*/

#define numRows 3
#define numCols 3
#define sensorPoints numRows*numCols

int rows[] = {A0, A1, A2};
int cols[] = {5,6,7};
int incomingValues[sensorPoints] = {};

void setup() {
  // set all rows and columns to INPUT (high impedance):
  for (int i = 0; i < numRows; i++) {
    pinMode(rows[i], INPUT_PULLUP);
  }
  for (int i = 0; i < numCols; i++) {
    pinMode(cols[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for (int colCount = 0; colCount < numCols; colCount++) {
    pinMode(cols[colCount], OUTPUT);  // set as OUTPUT
    digitalWrite(cols[colCount], LOW);  // set LOW

    for (int rowCount = 0; rowCount < numRows; rowCount++) {
      incomingValues[colCount * numRows + rowCount] = analogRead(rows[rowCount]);  // read INPUT
    }// end rowCount

    pinMode(cols[colCount], INPUT);  // set back to INPUT!

  }// end colCount

  // Print the incoming values of the grid:
  for (int i = 0; i < sensorPoints; i++) {
    Serial.print(incomingValues[i]);
    if (i < sensorPoints - 1) Serial.print("\t");
  }
  Serial.println();
  delay(10);
}
