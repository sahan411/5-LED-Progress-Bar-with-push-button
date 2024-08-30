int x, y;
int value_up;
int value_down;
int valueA_up=1;
int valueA_down=1;
int count = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(2, INPUT); //input connected as pull down method
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  value_up = digitalRead(2);
  value_down = digitalRead(3);
  
  if (value_up == valueA_up) {
    if (value_up == 1) {
      count = count + 1;

      if (count > 9) {
        count = 9;
      }
    }
    valueA_up = !value_up;
    delay(100);
  }

  if (value_down == valueA_down) {
    if (value_down == 1) {
      count = count - 1;

      if (count < 4) {
        count = 4;
      }
    }
    valueA_down = !value_down;
    delay(100);
  }
  //--------------------------------------------
  int i = 4;
  
  while(i<count){
    digitalWrite(i, HIGH);
    i = i +1;
    Serial.println(i);
  }

  while(i<9){
    digitalWrite(i, LOW);
    i = i +1;
    Serial.println(i);
  }

}
