#include <Wire.h>
#include <LCD-I2C.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define IR_PIN_ENTRANCE_GATE 33 // Pin for IR sensor at entrance gate
#define IR_PIN_SLOT_1 26        // Pin for IR sensor of slot 1
#define IR_PIN_SLOT_2 25        // Pin for IR sensor of slot 2
#define IR_PIN_SLOT_3 27        // Pin for IR sensor of slot 3
#define SERVO_PIN 18            // Pin for servo motor controlling barrier
#define LCD_ADDR 0x27           // Address for I2C communication with LCD
#define LCD_COLS 16             // Number of columns in the LCD
#define LCD_ROWS 2              // Number of rows in the LCD

#define BLYNK_AUTH_TOKEN "IxwXPtXrwqGDn2IeCIWRTdEL_XJWAbxq"
#define BLYNK_TEMPLATE_ID "TMPL6JE3l66Pj"
#define BLYNK_TEMPLATE_NAME "SmartParking"

char auth[] = BLYNK_AUTH_TOKEN; // Your Blynk authentication token
char ssid[] = "KCT 2nd Floor";        // Your WiFi network SSID
char pass[] = "Kct@2023";    // Your WiFi network password

LCD_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);
Servo servo;

void setup() {
  pinMode(IR_PIN_ENTRANCE_GATE, INPUT);
  pinMode(IR_PIN_SLOT_1, INPUT);
  pinMode(IR_PIN_SLOT_2, INPUT);
  pinMode(IR_PIN_SLOT_3, INPUT);
  pinMode(SERVO_PIN, OUTPUT);

  servo.attach(SERVO_PIN, 1000, 2000);
  servo.write(0);

  lcd.begin();
  lcd.display();
  lcd.backlight();

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run(); // Process Blynk commands

  lcd.setCursor(0, 0);
  lcd.print("S1");
  lcd.setCursor(5, 0);
  lcd.print("S2");
  lcd.setCursor(9, 0);
  lcd.print("S3");

  int sensor1 = digitalRead(IR_PIN_SLOT_1);
  int sensor2 = digitalRead(IR_PIN_SLOT_2);
  int sensor3 = digitalRead(IR_PIN_SLOT_3);

  int entranceSensor = digitalRead(IR_PIN_ENTRANCE_GATE);

  if (entranceSensor == LOW) {
    if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW) {
      servo.write(0);
      delay(1000);
    }
    if (sensor1 == HIGH || sensor2 == HIGH || sensor3 == HIGH) {
      servo.write(90);
      delay(1000);
    }
  }
  if (entranceSensor == HIGH) {
    servo.write(0);
    delay(1000);
  }

  // Update Blynk LED widgets based on occupancy status
  if (sensor1 == LOW) {
    Blynk.virtualWrite(V0, 255); // Set LED color to green (255 is maximum brightness)
  }
  else {
    Blynk.virtualWrite(V0, 0); // Clear LED widget (turn off)
  }

  if (sensor2 == LOW) {
    Blynk.virtualWrite(V1, 255); // Set LED color to green (255 is maximum brightness)
  }
  else {
    Blynk.virtualWrite(V1, 0); // Clear LED widget (turn off)
  }

  if (sensor3 == LOW) {
    Blynk.virtualWrite(V4, 255); // Set LED color to green (255 is maximum brightness)
  }
  else {
    Blynk.virtualWrite(V4, 0); // Clear LED widget (turn off)
  }

  lcd.setCursor(0, 1);
  if (sensor1 == LOW) {
    lcd.print("R");
  }
  else {
    lcd.print("E");
  }
  lcd.setCursor(5, 1);
  if (sensor2 == LOW) {
    lcd.print("R");
  }
  else {
    lcd.print("E");
  }
  lcd.setCursor(9, 1);
  if (sensor3 == LOW) {
    lcd.print("R");
  }
  else {
    lcd.print("E");
  }
}
void displayMessage(String message) {
  //  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);
}
