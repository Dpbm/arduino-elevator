int andar;
int your = 0;

void setup(){
  //sensores para ir para algum canto
  for (int i = 4; i<=7; i++){ pinMode(i, INPUT_PULLUP); }

  //sensores qual q ta
  for (int i = 8; i<=11; i++){ pinMode(i, INPUT_PULLUP); }
   
  
  //LEDS
  for (int i = 22; i <= 28; i++){ pinMode(i, OUTPUT); }
 
  //motor
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
 
  Serial.begin(9600);
}

void getAndar(){  
  // pega qual ta 
  if(digitalRead(4) == LOW){ andar = 4; }
  else if (digitalRead(5) == LOW){ andar = 3; }
  else if (digitalRead(6) == LOW){ andar = 2; }
  else { andar = 1; }
}

void getYourAndar(){
  // pega qual ta
  if(digitalRead(8) == LOW){
    your = 1;
    digitalWrite(22, LOW);
    digitalWrite(28, LOW);
    digitalWrite(25, LOW);
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);
    digitalWrite(23, HIGH);
    digitalWrite(24, HIGH);
  }
 
  else if (digitalRead(9) == LOW){
    your = 2;
    digitalWrite(22, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(26, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(24, LOW);
    digitalWrite(27, LOW);
  }
 
  else if (digitalRead(10) == LOW){
    your = 3;
    digitalWrite(22, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);
  }
 
  else if (digitalRead(11) == LOW) {
    your = 4;
    digitalWrite(23, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(22, LOW);
    digitalWrite(25, LOW);
    digitalWrite(26, LOW);
  }
 
  else {
    your = 0;
    digitalWrite(22, LOW);
    digitalWrite(28, LOW);
    digitalWrite(25, LOW);
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);
    digitalWrite(23, LOW);
    digitalWrite(24, LOW);
  }
}

void move(){
  if(your < andar){
    digitalWrite(3, HIGH);
  }else{
    digitalWrite(2, HIGH);
  }
}

void goNext(){
    while(andar != your){
      move();
      getAndar();
    }
}

void loop()
{ 
  getAndar();
  getYourAndar();
  Serial.print("qual ta --> ");
  Serial.println(andar);
  if(your != 0){ goNext(); }
}
