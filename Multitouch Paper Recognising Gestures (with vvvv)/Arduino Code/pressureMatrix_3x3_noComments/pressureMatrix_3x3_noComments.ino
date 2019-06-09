/*
  Pressure Sensor Matrix Code
  parsing through a pressure sensor matrix grid by switching individual 
  rows/columns to be HIGH, LOW or INPUT (high impedance) to detect 
  location and pressure.
  >> https://www.kobakant.at/DIY/?p=7443
*/

void setup() {
  Serial.begin(9600);
}

void loop() {

  ////////////////////////////////////////////////////////////////////////

  //////// -ROW1- ////////
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  //////// -A- ////////
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.print(analogRead(A0));
  Serial.print("\t");
  delay(10);

  //////// -B- ////////
  pinMode(A0, INPUT);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT);
  Serial.print(analogRead(A1));
  Serial.print("\t");
  delay(10);

  //////// -C- ////////
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT_PULLUP);
  Serial.print(analogRead(A2));
  Serial.print("\t");
  delay(10);


  ////////////////////////////////////////////////////////////////////////

  //////// -ROW2- ////////
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  pinMode(7, INPUT);

  //////// -A- ////////
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.print(analogRead(A0));
  Serial.print("\t");
  delay(10);

  //////// -B- ////////
  pinMode(A0, INPUT);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT);
  Serial.print(analogRead(A1));
  Serial.print("\t");
  delay(10);

  //////// -C- ////////
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT_PULLUP);
  Serial.print(analogRead(A2));
  Serial.print("\t");
  delay(10);


  ////////////////////////////////////////////////////////////////////////

  //////// -ROW3- ////////
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);

  //////// -A- ////////
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.print(analogRead(A0));
  Serial.print("\t");
  delay(10);

  //////// -B- ////////
  pinMode(A0, INPUT);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT);
  Serial.print(analogRead(A1));
  Serial.print("\t");
  delay(10);

  //////// -C- ////////
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT_PULLUP);
  Serial.print(analogRead(A2));
  Serial.print("\t");
  delay(10);

}
