#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.

// Define authorized RFID tag IDs (change these to match your RFID tags)
byte authorizedTag1[] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE};
byte authorizedTag2[] = {0x11, 0x22, 0x33, 0x44, 0x55};

// Define control pins for the lock (if using)
const int lockControlPin = 5;

void setup() {
  Serial.begin(9600); // Initialize serial communications.
  SPI.begin(); // Init SPI bus.
  mfrc522.PCD_Init(); // Init MFRC522 card
  pinMode(lockControlPin, OUTPUT); // Set lock control pin as output.
}

void loop() {
  // Look for new cards
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Check if the card is authorized
    if (isAuthorized(mfrc522.uid.uidByte)) {
      Serial.println("Access granted. Welcome!");
      unlockDoor(); // Or perform any authorized action
      delay(5000); // Allow access for 5 seconds
      lockDoor(); // Lock the door after the delay
    } else {
      Serial.println("Access denied. Unauthorized card.");
    }
    mfrc522.PICC_HaltA(); // Stop reading
  }
}

bool isAuthorized(byte uid[]) {
  // Compare UID with authorized tags
  if (memcmp(uid, authorizedTag1, 5) == 0 || memcmp(uid, authorizedTag2, 5) == 0) {
    return true;
  } else {
    return false;
  }
}

void unlockDoor() {
  digitalWrite(lockControlPin, HIGH); // Unlock the door
}

void lockDoor() {
  digitalWrite(lockControlPin, LOW); // Lock the door
}
