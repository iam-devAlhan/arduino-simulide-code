int led = 13;
int led2 = 12;
int led3 = 8;
int redDelay = 6000;
int yellowDelay = 2000;
int greenDelay = 4000;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  digitalWrite(led3, HIGH);
  delay(redDelay);
  digitalWrite(led3, LOW);
  
  // Delay for Yellow Light
  digitalWrite(led2, HIGH);
  delay(yellowDelay);
  digitalWrite(led2, LOW);

  // Delay for Green Light
  digitalWrite(led, HIGH);
  delay(greenDelay);
  digitalWrite(led, LOW);

  // Repeat the loop
}
