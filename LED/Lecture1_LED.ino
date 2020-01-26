// Define Pins
#define RED 3

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  digitalWrite(RED, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED, HIGH);
  delay(10000);
  digitalWrite(RED, LOW);
  delay(1000);
}
