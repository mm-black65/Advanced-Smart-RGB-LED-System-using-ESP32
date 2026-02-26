// ---------------- PIN DEFINITIONS ----------------
#define PIR_PIN     27
#define LDR_PIN     34
#define RELAY_PIN   26

#define RED_PIN     14
#define GREEN_PIN   13
#define BLUE_PIN    12

// ---------------- SETTINGS ----------------
int ldrThreshold = 2000;      
unsigned long lightDuration = 10000; 

unsigned long motionTimer = 0;
bool lightON = false;

// ---------------- SETUP ----------------
void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); // Relay OFF 

  ledcAttach(RED_PIN, 5000, 8);   
  ledcAttach(GREEN_PIN, 5000, 8); 
  ledcAttach(BLUE_PIN, 5000, 8);  

  setColor(0, 0, 255); // Blue standby at start
}

// ---------------- MAIN LOOP ----------------
void loop() {

  int motion = digitalRead(PIR_PIN);
  int ldrValue = analogRead(LDR_PIN);

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // If motion detected
  if (motion == HIGH) {
    if (ldrValue > ldrThreshold) {
      // Dark + Motion -> Turn ON
      digitalWrite(RELAY_PIN, LOW); // Relay ON
      setColor(0, 255, 0);          // Green
      lightON = true;
      motionTimer = millis();
    }
    else {
      // Motion but room bright
      digitalWrite(RELAY_PIN, HIGH); 
      setColor(255, 0, 0);          // Red
      lightON = false;
    }
  }

  // Auto OFF after duration
  if (lightON && (millis() - motionTimer > lightDuration)) {
    digitalWrite(RELAY_PIN, HIGH);  // Relay OFF
    setColor(0, 0, 255);            // Blue standby
    lightON = false;
  }

  // No motion
  if (motion == LOW && !lightON) {
    setColor(0, 0, 255); // Blue standby
  }

  delay(200);
}

// ---------------- RGB FUNCTION ----------------
void setColor(int r, int g, int b) {

  ledcWrite(RED_PIN, r);   
  ledcWrite(GREEN_PIN, g); 
  ledcWrite(BLUE_PIN, b);  
}
