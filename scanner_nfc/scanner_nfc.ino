//Arduino Code - RC522 Read RFID Tag UID
 
// #include <SPI.h>
// #include <MFRC522.h>
 
// #define SS_PIN 10
// #define RST_PIN 7
 
// MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
 
// MFRC522::MIFARE_Key key; 
 
// void setup() { 
//   Serial.begin(115200);
//   SPI.begin(); // Init SPI bus
//   rfid.PCD_Init(); // Init RC522 
// }
 
// void loop() {
 
//   // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
//   if ( ! rfid.PICC_IsNewCardPresent())
//     return;
 
//   // Verify if the NUID has been readed
//   if ( ! rfid.PICC_ReadCardSerial())
//     return;
 
//   MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
 
//   Serial.print(F("RFID Tag UID:"));
//   printHex(rfid.uid.uidByte, rfid.uid.size);
//   Serial.println("");
 
//   rfid.PICC_HaltA(); // Halt PICC
// }
 
// //Routine to dump a byte array as hex values to Serial. 
// void printHex(byte *buffer, byte bufferSize) {
//   for (byte i = 0; i < bufferSize; i++) {
//     Serial.print(buffer[i] < 0x10 ? " 0" : " ");
//     Serial.print(buffer[i], HEX);
//   }
// }






// #include <SPI.h>
// #include <MFRC522.h>

// #define SS_PIN 10
// #define RST_PIN 7

// MFRC522 rfid(SS_PIN, RST_PIN);

// void setup() {
//   Serial.begin(9600);
//   while (!Serial);
  
//   SPI.begin();
//   rfid.PCD_Init();
  
//   // Test the MFRC522 chip
//   Serial.println("\nRunning RFID diagnostics...");
  
//   // Read and print firmware version
//   byte v = rfid.PCD_ReadRegister(MFRC522::VersionReg);
//   Serial.print("Firmware Version: 0x");
//   Serial.println(v, HEX);
  
//   if (v == 0x00 || v == 0xFF) {
//     Serial.println("Warning: Communication failed or wrong firmware!");
//     Serial.println("Check your connections:");
//     Serial.println("- Is the MFRC522 properly powered with 3.3V?");
//     Serial.println("- Are the SPI pins connected correctly?");
//     Serial.println("- SS_PIN = 10, RST_PIN = 7");
//     while(1);
//   }
  
//   // Perform antenna test
//   byte antennaGain = rfid.PCD_ReadRegister(MFRC522::RFCfgReg);
//   Serial.print("Antenna Gain: 0x");
//   Serial.println(antennaGain, HEX);
  
//   // Enable antenna and check state
//   rfid.PCD_SetRegisterBitMask(MFRC522::TxControlReg, 0x03);
//   byte antennaState = rfid.PCD_ReadRegister(MFRC522::TxControlReg);
//   Serial.print("Antenna State: 0x");
//   Serial.println(antennaState, HEX);
  
//   Serial.println("\nReady to scan cards...");
// }

// void loop() {
//   // Print a dot every second to show the program is running
//   Serial.print(".");
  
//   if (rfid.PICC_IsNewCardPresent()) {
//     Serial.println("\nCard detected!");
    
//     if (rfid.PICC_ReadCardSerial()) {
//       Serial.print("Card UID: ");
//       for (byte i = 0; i < rfid.uid.size; i++) {
//         Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
//         Serial.print(rfid.uid.uidByte[i], HEX);
//       }
//       Serial.println();
      
//       rfid.PICC_HaltA();
//       rfid.PCD_StopCrypto1();
//     }
//   }
  
//   delay(1000);
// }





// #include <SPI.h>
// #include <MFRC522.h>

// #define RST_PIN         7           
// #define SS_PIN          10          

// MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

// void setup() {
//   Serial.begin(9600);     // Initialize serial communications
//   SPI.begin();            // Init SPI bus
//   mfrc522.PCD_Init();     // Init MFRC522
//   mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader
//   Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
// }

// void loop() {
//   // Reset the loop if no new card present
//   if (!mfrc522.PICC_IsNewCardPresent()) {
//     delay(50);
//     return;
//   }

//   // Select one of the cards
//   if (!mfrc522.PICC_ReadCardSerial()) {
//     delay(50);
//     return;
//   }

//   // Show some details of the PICC (that is: the tag/card)
//   Serial.print(F("Card UID:"));
//   for (byte i = 0; i < mfrc522.uid.size; i++) {
//       Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
//       Serial.print(mfrc522.uid.uidByte[i], HEX);
//   } 
//   Serial.println();

//   // Halt PICC
//   mfrc522.PICC_HaltA();
//   // Stop encryption on PCD
//   mfrc522.PCD_StopCrypto1();
// }


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

#define RST_PIN         7           
#define SS_PIN          10          
#define LED_PIN         4           
#define BUZZER_PIN      3           // Define pin for the active buzzer

MFRC522 mfrc522(SS_PIN, RST_PIN);

// Buzzer functions
void successBuzz() {
  tone(BUZZER_PIN, 1000); // 1kHz sound
  delay(200);
  noTone(BUZZER_PIN);
}

void failureBuzz() {
  // Two short beeps
  tone(BUZZER_PIN, 2000); // 2kHz sound
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
  
  delay(1000);  // Wait a second before next debug output
}