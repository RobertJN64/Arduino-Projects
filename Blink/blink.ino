void setup() {
    Serial.begin(115200);
}

void loop() {
    digitalWrite(LED_BUILTIN, true);
    delay(1000);
    digitalWrite(LED_BUILTIN, false);
    delay(1000);

    Serial.println("HELLO WORLD!");
    delay(100);

    Serial.println(">input:600");
    delay(10);
    Serial.println(">input:300");
}