

// #include <SPI.h>
// #include <MFRC522.h>

// #define RST_PIN         7
// #define SS_PIN          10
// #define LED_PIN         4           // Add an LED for visual feedback

// MFRC522 mfrc522(SS_PIN, RST_PIN);

// void setup() {
//   Serial.begin(9600);
//   pinMode(LED_PIN, OUTPUT);

//   // Blink LED to show program started
//   digitalWrite(LED_PIN, HIGH);
//   delay(1000);
//   digitalWrite(LED_PIN, LOW);

//   SPI.begin();
//   mfrc522.PCD_Init();

//   // Test the MFRC522 chip
//   byte v = mfrc522.PCD_ReadRegister(MFRC522::VersionReg);
//   Serial.print("MFRC522 Version: 0x");
//   Serial.println(v, HEX);

//   // Set antenna gain to maximum
//   mfrc522.PCD_SetAntennaGain(MFRC522::RxGain_max);

//   // Clear any existing cards
//   mfrc522.PCD_StopCrypto1();

//   Serial.println("Starting card detection loop...");
// }

// void loop() {
//   // Print debug info every second
//   Serial.println("\n--- Debug Info ---");

//   // Step 1: Check if card is present
//   Serial.print("Looking for card... ");
//   bool cardPresent = mfrc522.PICC_IsNewCardPresent();
//   Serial.println(cardPresent ? "FOUND!" : "none");

//   if (cardPresent) {
//     digitalWrite(LED_PIN, HIGH);  // Turn on LED if card detected

//     // Step 2: Try to read card serial
//     Serial.print("Attempting to read card... ");
//     bool serialRead = mfrc522.PICC_ReadCardSerial();
//     Serial.println(serialRead ? "SUCCESS!" : "FAILED");

//     if (serialRead) {
//       // Print card details
//       Serial.print("Card UID: ");
//       for (byte i = 0; i < mfrc522.uid.size; i++) {
//         Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
//         Serial.print(mfrc522.uid.uidByte[i], HEX);
//       }
//       Serial.println();

//       // Get card type
//       MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
//       Serial.print("Card type: ");
//       Serial.println(mfrc522.PICC_GetTypeName(piccType));

//       mfrc522.PICC_HaltA();
//       mfrc522.PCD_StopCrypto1();
//     }
//     digitalWrite(LED_PIN, LOW);  // Turn off LED
//   }

//   delay(1000);  // Wait a second before next debug output
// }










#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


#define RST_PIN 9
#define SS_PIN 10
#define LED_PIN A0
#define BUZZER_PIN A1  // Define pin for the active buzzer

MFRC522 mfrc522(SS_PIN, RST_PIN);

// Buzzer functions
void successBuzz() {
  tone(BUZZER_PIN, 1000);  // 1kHz sound
  delay(200);
  noTone(BUZZER_PIN);
  ;
}

void failureBuzz() {
  // Two short beeps
  tone(BUZZER_PIN, 2000);  // 2kHz sound
  delay(100);
  noTone(BUZZER_PIN);
  delay(100);
  tone(BUZZER_PIN, 2000);
  delay(100);
  noTone(BUZZER_PIN);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Blink LED to show program started
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);

  SPI.begin();
  mfrc522.PCD_Init();

  // Test the MFRC522 chip
  byte v = mfrc522.PCD_ReadRegister(MFRC522::VersionReg);
  Serial.print("MFRC522 Version: 0x");
  Serial.println(v, HEX);

  // Set antenna gain to maximum
  mfrc522.PCD_SetAntennaGain(MFRC522::RxGain_max);

  // Clear any existing cards
  mfrc522.PCD_StopCrypto1();

  Serial.println("Starting card detection loop...");

  lcd.begin(16, 2);
  // lcd.print("FrontEnd Developer")
}

void loop() {
  // Print debug info every second
  Serial.println("\n--- Debug Info ---");

  // Step 1: Check if card is present
  Serial.print("Looking for card... ");
  bool cardPresent = mfrc522.PICC_IsNewCardPresent();
  Serial.println(cardPresent ? "FOUND!" : "none");

  if (cardPresent) {
    digitalWrite(LED_PIN, HIGH);  // Turn on LED if card detected

    // Step 2: Try to read card serial
    Serial.print("Attempting to read card... ");
    bool serialRead = mfrc522.PICC_ReadCardSerial();
    Serial.println(serialRead ? "SUCCESS!" : "FAILED");

    if (serialRead) {
      // Successful read - one long beep
      successBuzz();

      // Print card details
      Serial.print("Card UID: ");
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
      }
      Serial.println();

      // Get card type
      MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
      Serial.print("Card type: ");
      Serial.println(mfrc522.PICC_GetTypeName(piccType));

      mfrc522.PICC_HaltA();
      mfrc522.PCD_StopCrypto1();

    } else {
      // Failed read - two short beeps
      failureBuzz();
    }
    digitalWrite(LED_PIN, LOW);  // Turn off LED
  }

  lcd.setCursor(0, 0);

  for (byte i = 0; i < mfrc522.uid.size; i++) {
    lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    lcd.print(mfrc522.uid.uidByte[i], HEX);
  };

  // lcd.setCursor(0, 1);
  



  // if (mfrc522.uid.uidByte === {0xA3, 0x18, 0xB9, 0xFC}) {
  // lcd.setCursor(0, 1);
  // lcd.print("Mahmud");
  // };




  delay(1000);  // Wait a second before next debug output
}















// #include <SPI.h>
// #include <MFRC522.h>
// #include <LiquidCrystal.h>

// const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// #define RST_PIN 9
// #define SS_PIN 10
// #define LED_PIN A0
// #define BUZZER_PIN A1

// MFRC522 mfrc522(SS_PIN, RST_PIN);

// // Buzzer functions
// void successBuzz() {
//   tone(BUZZER_PIN, 1000);
//   delay(200);
//   noTone(BUZZER_PIN);
// }

// void failureBuzz() {
//   tone(BUZZER_PIN, 2000);
//   delay(100);
//   noTone(BUZZER_PIN);
//   delay(100);
//   tone(BUZZER_PIN, 2000);
//   delay(100);
//   noTone(BUZZER_PIN);
// }

// // New function to change card UID
// bool changeCardUID(byte newUID[], byte size) {
//   // Verify if a card is present
//   if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
//     Serial.println("No card present or cannot read!");
//     return false;
//   }

//   // Check if the card type supports UID changing
//   MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
//   if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
//       piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
//       piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
//     Serial.println("This card type doesn't support UID changing");
//     return false;
//   }

//   // Authentication using key A
//   MFRC522::MIFARE_Key key;
//   for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;  // Default key

//   // Select block 0 (contains UID)
//   byte block = 0;
//   byte status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
//   if (status != MFRC522::STATUS_OK) {
//     Serial.println("Authentication failed!");
//     return false;
//   }

//   // Write new UID
//   byte buffer[18];
//   byte bytesToWrite = min(size, (byte)4);  // Maximum 4 bytes for UID
  
//   // Prepare buffer - first 4 bytes are UID
//   for (byte i = 0; i < bytesToWrite; i++) {
//     buffer[i] = newUID[i];
//   }
  
//   // Calculate BCC (Block Check Character)
//   buffer[4] = buffer[0] ^ buffer[1] ^ buffer[2] ^ buffer[3];
  
//   // Write the data
//   status = mfrc522.MIFARE_Write(block, buffer, 16);
//   if (status != MFRC522::STATUS_OK) {
//     Serial.println("Writing failed!");
//     return false;
//   }

//   Serial.println("UID changed successfully!");
//   return true;
// }

// void setup() {
//   Serial.begin(9600);
//   pinMode(LED_PIN, OUTPUT);
//   pinMode(BUZZER_PIN, OUTPUT);
//   digitalWrite(LED_PIN, HIGH);
//   delay(1000);
//   digitalWrite(LED_PIN, LOW);
  
//   SPI.begin();
//   mfrc522.PCD_Init();
  
//   byte v = mfrc522.PCD_ReadRegister(MFRC522::VersionReg);
//   Serial.print("MFRC522 Version: 0x");
//   Serial.println(v, HEX);
  
//   mfrc522.PCD_SetAntennaGain(MFRC522::RxGain_max);
//   mfrc522.PCD_StopCrypto1();
//   Serial.println("Starting card detection loop...");
  
//   lcd.begin(16, 2);
// }

// void loop() {
//   Serial.println("\n--- Debug Info ---");
//   Serial.print("Looking for card... ");
  
//   bool cardPresent = mfrc522.PICC_IsNewCardPresent();
//   Serial.println(cardPresent ? "FOUND!" : "none");
  
//   if (cardPresent) {
//     digitalWrite(LED_PIN, HIGH);
//     Serial.print("Attempting to read card... ");
//     bool serialRead = mfrc522.PICC_ReadCardSerial();
//     Serial.println(serialRead ? "SUCCESS!" : "FAILED");
    
//     if (serialRead) {
//       successBuzz();
      
//       // Print current UID
//       Serial.print("Current Card UID: ");
//       for (byte i = 0; i < mfrc522.uid.size; i++) {
//         Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
//         Serial.print(mfrc522.uid.uidByte[i], HEX);
//       }
//       Serial.println();

//       // Example of changing UID (uncomment and modify as needed)
//       byte newUID[] = {0x01, 0x02, 0x03, 0x04};  // New UID you want to write
//       if (changeCardUID(newUID, 4)) {
//         lcd.clear();
//         lcd.setCursor(0, 0);
//         lcd.print("UID Changed!");
//         successBuzz();
//       } else {
//         lcd.clear();
//         lcd.setCursor(0, 0);
//         lcd.print("Change Failed!");
//         failureBuzz();
//       }
      
//       MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
//       Serial.print("Card type: ");
//       Serial.println(mfrc522.PICC_GetTypeName(piccType));
      
//       mfrc522.PICC_HaltA();
//       mfrc522.PCD_StopCrypto1();
//     } else {
//       failureBuzz();
//     }
//     digitalWrite(LED_PIN, LOW);
//   }

//   // Update LCD with current UID
//   lcd.setCursor(0, 0);
//   for (byte i = 0; i < mfrc522.uid.size; i++) {
//     lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
//     lcd.print(mfrc522.uid.uidByte[i], HEX);
//   }

//   delay(1000);
// }

















// #include <SPI.h>
// #include <MFRC522.h>
// #include <LiquidCrystal.h>

// // Pin definitions
// const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
// #define RST_PIN 9
// #define SS_PIN 10
// #define LED_PIN A0
// #define BUZZER_PIN A1

// // Initialize instances
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// MFRC522 mfrc522(SS_PIN, RST_PIN);

// // Function declarations
// void successBuzz();
// void failureBuzz();
// bool isCardUIDChangeable();
// bool changeCardUID(byte newUID[], byte size);

// // Buzzer functions
// void successBuzz() {
//   tone(BUZZER_PIN, 1000);  // 1kHz sound
//   delay(200);
//   noTone(BUZZER_PIN);
// }

// void failureBuzz() {
//   tone(BUZZER_PIN, 2000);  // 2kHz sound
//   delay(100);
//   noTone(BUZZER_PIN);
//   delay(100);
//   tone(BUZZER_PIN, 2000);
//   delay(100);
//   noTone(BUZZER_PIN);
// }

// // Card type check function
// bool isCardUIDChangeable() {
//   if (!mfrc522.PICC_IsNewCardPresent()) {
//     lcd.clear();
//     lcd.setCursor(0, 0);
//     lcd.print("No card");
//     return false;
//   }
  
//   if (!mfrc522.PICC_ReadCardSerial()) {
//     lcd.clear();
//     lcd.setCursor(0, 0);
//     lcd.print("Read error");
//     return false;
//   }

//   MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  
//   bool isSupported = (
//     piccType == MFRC522::PICC_TYPE_MIFARE_MINI ||
//     piccType == MFRC522::PICC_TYPE_MIFARE_1K ||
//     piccType == MFRC522::PICC_TYPE_MIFARE_4K
//   );

//   lcd.clear();
//   lcd.setCursor(0, 0);
//   if (isSupported) {
//     lcd.print("Card OK");
//   } else {
//     lcd.print("Unsupported");
//   }
  
//   lcd.setCursor(0, 1);
//   lcd.print(mfrc522.PICC_GetTypeName(piccType));

//   return isSupported;
// }

// // UID change function
// // bool changeCardUID(byte newUID[], byte size) {
// //   if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
// //     Serial.println("No card present or cannot read!");
// //     return false;
// //   }

// //   MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
// //   if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
// //       piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
// //       piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
// //     Serial.println("This card type doesn't support UID changing");
// //     return false;
// //   }

// //   MFRC522::MIFARE_Key key;
// //   for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;  // Default key

// //   byte block = 0;
// //   byte status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
// //   if (status != MFRC522::STATUS_OK) {
// //     Serial.println("Authentication failed!");
// //     return false;
// //   }

// //   byte buffer[18];
// //   byte bytesToWrite = min(size, (byte)4);
  
// //   for (byte i = 0; i < bytesToWrite; i++) {
// //     buffer[i] = newUID[i];
// //   }
  
// //   buffer[4] = buffer[0] ^ buffer[1] ^ buffer[2] ^ buffer[3];
  
// //   status = mfrc522.MIFARE_Write(block, buffer, 16);
// //   if (status != MFRC522::STATUS_OK) {
// //     Serial.println("Writing failed!");
// //     return false;
// //   }

// //   Serial.println("UID changed successfully!");
// //   return true;
// // }

// void setup() {
//   // Initialize serial communication
//   Serial.begin(9600);
  
//   // Initialize pins
//   pinMode(LED_PIN, OUTPUT);
//   pinMode(BUZZER_PIN, OUTPUT);
  
//   // Initial LED test
//   digitalWrite(LED_PIN, HIGH);
//   delay(1000);
//   digitalWrite(LED_PIN, LOW);
  
//   // Initialize SPI and MFRC522
//   SPI.begin();
//   mfrc522.PCD_Init();
  
//   // Print MFRC522 version
//   byte v = mfrc522.PCD_ReadRegister(MFRC522::VersionReg);
//   Serial.print("MFRC522 Version: 0x");
//   Serial.println(v, HEX);
  
//   // Set antenna gain
//   mfrc522.PCD_SetAntennaGain(MFRC522::RxGain_max);
  
//   // Initialize LCD
//   lcd.begin(16, 2);
//   lcd.print("Ready...");
  
//   Serial.println("System Ready");
// }

// void loop() {
//   Serial.println("\n--- Debug Info ---");
  
//   if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
//     digitalWrite(LED_PIN, HIGH);
    
//     if (isCardUIDChangeable()) {
//       successBuzz();
//       Serial.println("Card supports UID change");
      
//       // Example of changing UID - uncomment to use
//       /*
//       byte newUID[] = {0x01, 0x02, 0x03, 0x04};  // New UID
//       if (changeCardUID(newUID, 4)) {
//         lcd.clear();
//         lcd.setCursor(0, 0);
//         lcd.print("UID Changed!");
//         successBuzz();
//       } else {
//         lcd.clear();
//         lcd.setCursor(0, 0);
//         lcd.print("Change Failed!");
//         failureBuzz();
//       }
//       */
      
//     } else {
//       failureBuzz();
//       Serial.println("Card does not support UID change");
//     }
    
//     // Print current UID
//     Serial.print("Current UID: ");
//     for (byte i = 0; i < mfrc522.uid.size; i++) {
//       Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
//       Serial.print(mfrc522.uid.uidByte[i], HEX);
//     }
//     Serial.println();
    
//     mfrc522.PICC_HaltA();
//     mfrc522.PCD_StopCrypto1();
//     digitalWrite(LED_PIN, LOW);
//   }
  
//   delay(1000);
// }






