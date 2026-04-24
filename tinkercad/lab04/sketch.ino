const int analogPin = A0;

void setup() {
    // Initialize Serial Monitor
    Serial.begin(9600);
}

void loop() {
    int reading = analogRead(analogPin);

    float voltage = reading * (5.0 / 1024.0);
    float temp_in_celsius = voltage * 100;

    Serial.print("Temperature: ");
    Serial.print(temp_in_celsius);
    Serial.println("C");

    delay(1000);
}