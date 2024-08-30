int x, y;
int value = 0;
int valueA = 1;
int count = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(2, INPUT); //input connected as pull down method
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  value = digitalRead(2);
  if (value == valueA) {
    if (value == 1) {
      count = count + 1;
      Serial.println(count);
      digitalWrite(count + 3 , 1);
      digitalWrite(count + 2 , 0);

      if (count == 6) {
        count = 0;
      }
    }
    valueA = !value;
    delay(100);
  }

}
