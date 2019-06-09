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

  // set 5 to GND and disable 6 and 7:
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  pinMode(6, INPUT);  // disable
  pinMode(7, INPUT);  // disable

  // A:
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT); // disable
  pinMode(A2, INPUT); // disable
  Serial.print(analogRead(A0));
  Serial.print("\t");
  delay(10);

  // B:
  pinMode(A0, INPUT); // disable
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT); // disable
  Serial.print(analogRead(A1));
  Serial.print("\t");
  delay(10);

  // C:
  pinMode(A0, INPUT); // disable
  pinMode(A1, INPUT); // disable
  pinMode(A2, INPUT_PULLUP);
  Serial.print(analogRead(A2));
  Serial.print("\t");
  delay(10);


////////////////////////////////////////////////////////////////////////


  // set 6 to GND and disable 5 and 7:
  pinMode(5, INPUT);  // disable
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  pinMode(7, INPUT);  // disable

  // A:
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT); // disable
  pinMode(A2, INPUT); // disable
  Serial.print(analogRead(A0));
  Serial.print("\t");
  delay(10);

  // B:
  pinMode(A0, INPUT); // disable
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT); // disable
  Serial.print(analogRead(A1));
  Serial.print("\t");
  delay(10);

  // C:
  pinMode(A0, INPUT); // disable
  pinMode(A1, INPUT); // disable
  pinMode(A2, INPUT_PULLUP);
  Serial.print(analogRead(A2));
  Serial.print("\t");
  delay(10);


  ////////////////////////////////////////////////////////////////////////


  // set 7 to GND and disable 5 and 6:
  pinMode(5, INPUT);  // disable
  pinMode(6, INPUT);  // disable
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  

  // A:
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT); // disable
  pinMode(A2, INPUT); // disable
  Serial.print(analogRead(A0));
  Serial.print("\t");
  delay(10);

  // B:
  pinMode(A0, INPUT); // disable
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT); // disable
  Serial.print(analogRead(A1));
  Serial.print("\t");
  delay(10);

  // C:
  pinMode(A0, INPUT); // disable
  pinMode(A1, INPUT); // disable
  pinMode(A2, INPUT_PULLUP);
  Serial.print(analogRead(A2));
  Serial.println();
  delay(10);

}
