/// -------- PIN DEFINITIONS --------
#define PIR_PIN 5
#define TRIG_PIN 18
#define ECHO_PIN 19
#define BUZZER_PIN 26
#define LED_PIN 4

// -------- SETTINGS --------
#define DIST_THRESHOLD 100   // cm (adjust based on field)
#define CHANGE_THRESHOLD 20  // sudden movement detection
#define ALARM_DURATION 3000  // ms

long duration;
float distance = 0;
float prevDistance = 0;

// -------- SETUP --------
void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("Animal Detection System Started...");
}

// -------- DISTANCE FUNCTION --------
float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000);  // timeout 30ms

  if (duration == 0) return 999;  // no reading

  float dist = duration * 0.034 / 2;
  return dist;
}

// -------- LOOP --------
void loop() {

  int pirState = digitalRead(PIR_PIN);
  distance = getDistance();
  float change = abs(distance - prevDistance);

  Serial.print("PIR: ");
  Serial.print(pirState);
  Serial.print(" | Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Change: ");
  Serial.println(change);

  bool intrusion = false;

  // -------- LOGIC --------
  if ((pirState == HIGH && distance < DIST_THRESHOLD) || (change > CHANGE_THRESHOLD)) {
    intrusion = true;
  }

  // -------- ACTION --------
  if (intrusion) {
    Serial.println("🚨 Animal Detected!");

    digitalWrite(LED_PIN, HIGH);

    // Buzzer pattern (strong deterrent)
    // "Intruder Alert" Pattern: Rapid double-beeps followed by a solid piercing wail
    for (int i = 0; i < 4; i++) {
      // First quick beep
      digitalWrite(BUZZER_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);  // Optional: Flash LED with the beep for extra effect
      delay(80);
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
      delay(80);

      // Second quick beep
      digitalWrite(BUZZER_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);
      delay(80);
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(LED_PIN, LOW);

      // Short pause before the next double-beep
      delay(300);
    }

    // Final long, loud blast
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    delay(1200);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);

    delay(ALARM_DURATION);
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  prevDistance = distance;
  delay(200);
}
