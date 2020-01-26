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
  delay(3000);
  digitalWrite(RED, LOW);
  delay(3000);
}
