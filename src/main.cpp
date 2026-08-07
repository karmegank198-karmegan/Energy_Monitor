// 04.08.2026

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "Get_data.h"
#include "Values.h"

// Wi-Fi credentials
String SSID = "POWERHOUSE";
String PASS = "55005500";

// Device initialization with unique ID and API endpoint
#define SERVER_URL ""
//6400 -> 29 Meters
modb dev7(7, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=107,");
modb dev8(8, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=108,");
modb dev9(9, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=109,");
modb dev10(10, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=110,");
modb dev11(11, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=111,");
modb dev16(16, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=116,");
modb dev17(17, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=117,");
modb dev18(18, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=118,");
modb dev19(19, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=119,");
modb dev25(25, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=125,");
modb dev26(26, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=126,");
modb dev27(27, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=127,");
modb dev28(28, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=128,");
modb dev29(29, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=129,");
modb dev30(30, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=130,");
modb dev31(31, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=131,");
modb dev32(32, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=132,");
modb dev33(33, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=133,");
modb dev34(34, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=134,");
modb dev35(35, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=135,");
modb dev36(36, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=136,");
modb dev37(37, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=137,");
modb dev38(38, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=138,");
modb dev39(39, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=139,");
modb dev40(40, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=140,");
modb dev41(41, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=141,");
modb dev42(42, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=142,");
modb dev43(43, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=143,");
modb dev44(44, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=144,");
//6400ng+ -> 14 Meters
modb dev22(22, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=122,");
modb dev24(24, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=124,");
modb dev45(45, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=145,");
modb dev52(52, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=152,");
modb dev53(53, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=153,");
modb dev54(54, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=154,");
modb dev55(55, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=155,");
modb dev56(56, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=156,");
modb dev57(57, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=157,");
modb dev58(58, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=158,");
modb dev59(59, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=159,");
modb dev61(61, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=161,");
modb dev62(62, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=162,");
modb dev63(63, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=163,");
//6436 -> 7 Meters
modb dev23(23, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=123,");
modb dev64(64, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=164,");
modb dev65(65, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=165,");
modb dev66(66, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=166,");
modb dev67(67, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=167,");
modb dev14(14, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=114,");
modb dev15(15, "https://adc.bitsathy.ac.in/2024/energymeter/api/log.php?energy=115,");

// Store all devices in an array for easy looping
modb devices[] = {
       // 6400 -> 29 Meters
  dev7,  dev8,  dev9,  dev10,   // 0,1,2,3,   
  dev11, dev16, dev17, dev18,   // 4,5,6,7,
  dev19, dev25, dev26, dev27,   // 8,9,10,11,
  dev28, dev29, dev30, dev31,   // 12,13,14,15,
  dev32, dev33, dev34, dev35,   // 16,17,18,19,
  dev36, dev37, dev38, dev39,   // 20,21,22,23,
  dev40, dev41, dev42, dev43,   // 24,25,26,27,
  dev44,                        // 28,
                          
       // 6400ng+ -> 14 Meters
  dev22, dev24, dev45, dev52,   // 29,30,31,32,
  dev53, dev54, dev55, dev56,   // 33,34,35,36,
  dev57, dev58, dev59, dev61,   // 37,38,39,40,
  dev62, dev63,                 // 41,42,

       // 6436h -> 7 Meters
  dev14, dev15, dev23, dev64,   // 43,44,45,46,
  dev65, dev66,dev67            // 47,48,49
};

// ---- Non-blocking 15-minute timer for pushing data ----
unsigned long previousMillis = 0;



const unsigned long interval = 15UL * 60UL * 1000UL;  // 15 minutes in ms

// ---- Non-blocking 24-hour timer for auto-reset ----
unsigned long bootMillis = 0;
const unsigned long resetInterval = 24UL * 60UL * 60UL * 1000UL;  // 24 hours in ms

void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi network
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  bootMillis = millis();  // record start time for the 24-hour reset timer
}

void loop() {
  unsigned long currentMillis = millis();

  // ---- Restart ESP32 every 24 hours ----
  if (currentMillis - bootMillis >= resetInterval) {
    Serial.println("24 hours elapsed — restarting ESP32...");
    delay(100);  // let the print flush before restart
    ESP.restart();
  }

  // ---- Decide whether this pass should also push to the server ----
  bool timeToPush = false;
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    timeToPush = true;

    // Make sure WiFi is up before pushing this cycle
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Reconnecting to WiFi...");
      WiFi.begin(SSID, PASS);
    }
    if (timeToPush) Serial.println("WiFi Connected - Pushing data to server now");
  }

  // ---- Continuously read every device (always runs, every loop pass) ----
  for (int i = 0; i < 50; i++) {
    if (i >= 0 && i <= 28) {
      devices[i].load_data();
    } else if (i >= 29 && i <= 42) {
      devices[i].load_data1();
    } else {
      Serial1.begin(9600, SERIAL_8N2, RX_PIN, TX_PIN);
      devices[i].load_data2();
      Serial1.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
    }

    // Only push to server if 15 minutes have elapsed
    if (timeToPush) {
      devices[i].push_data();
    }

    delay(200);  // Small delay between devices to avoid flooding Modbus/network
  }
}