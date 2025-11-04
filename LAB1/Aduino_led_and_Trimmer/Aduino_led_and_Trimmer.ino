#define led_pin 6
void setup() {
  Serial.begin(9600);
  pinMode(led_pin,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_pin, HIGH);
  delay(500);
  digitalWrite(led_pin, LOW);
  delay(500);

  Serial.println(analogRead(A1));
}
