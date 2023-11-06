/*
Wenxi Wei
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  //step 1: read value in pin A0
  //step 2: change the value 0--4095 to 0--5000mv by map
  int mv;
  long x = analogRead(A0);
  mv = map(x,0,4095,0,5000);
  Serial.println(mv);

  //step 3: GPIO 1 is output. Set high when GPIO0 is less than 1V
  while(1){
    if (  mv < 100){
      analogWrite(1, 64);
      break;
    }else{
      analogWrite (1, 0);
    break;  
    }
  delay(200);
  }
  
}
