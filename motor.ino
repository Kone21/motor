#define pin_2 2
#define pin_3 3

void setup() {
  Serial.begin(9600);
  pinMode(pin_2, OUTPUT);
  pinMode(pin_3, OUTPUT);
}

void check_ds(char d, int s) {
  if (d == 'r' && s >= 0 && s <= 255) {
    analogWrite(pin_2, s);
    digitalWrite(pin_2, 0);
    digitalWrite(pin_3, 1);
    delay(2000);
  } else if (d == 'l' && s >= 0 && s <= 255) {
    analogWrite(pin_3, s);
    digitalWrite(pin_2, 1);
    digitalWrite(pin_3, 0);
    delay(2000);
  } else if (d == 's' || s < 0 || s > 255) {
    analogWrite(pin_2, 0);
    analogWrite(pin_3, 0);
    digitalWrite(pin_2, 1);
    digitalWrite(pin_3, 1);
    delay(2000);
  }
}

void loop() {
  check_ds('r', 255);
  check_ds('l', -2);
  check_ds('l', 100);
  check_ds('s', 0);
}
