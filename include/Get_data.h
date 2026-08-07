// 04.08.2026

#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ModbusMaster.h>
#define MAX485_DE 5
#define MAX485_RE_NEG 4

#define RX_PIN 16
#define TX_PIN 17

bool flag = 0;
const int X = 40001;

void init_whole() {
  Serial1.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
  pinMode(MAX485_RE_NEG, OUTPUT);
  pinMode(MAX485_DE, OUTPUT);
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);
  flag = 1;
}

class modb {
public:
  modb(int id_, String endpoint_) {
    id = id_;
    endpoint = endpoint_;
    if (!flag) {
      init_whole();
    }
    node.begin(id, Serial1);
    node.preTransmission(preTransmission);
    node.postTransmission(postTransmission);
  }

  void load_data() {
    float PFAverage = modbus_read((43907 - X), 2, "pfavg");
    float VLLAverage = modbus_read((43909 - X), 2, "vllavg");
    float VLNAverage = modbus_read((43911 - X), 2, "vlnavg");
    double wh = modbus_read((43961 - X), 2, "wh");
    float current = modbus_read((43913 - X), 2, "current");
    float wattsrphase = modbus_read((43919 - X), 2, "rphase");
    float wattsyphase = modbus_read((43933 - X), 2, "yphase");
    float wattsbphase = modbus_read((43947 - X), 2, "bphase");
    float frequency = modbus_read((43915 - X), 2, "freq");

    data = String(current) + "," + String(PFAverage) + "," + String(VLLAverage) + "," + String(VLNAverage) + "," +
     String(wh/1000) + "," + String(wattsrphase) + "," + String(wattsyphase) + "," + String(wattsbphase) + "," + 
     String(frequency);

    Serial.println("id " + String(id) + "-> " + data);
  }

  void load_data1() {
    float PFAverage1 = modbus_read1((43192 - X), 2, "pfavg");
    float VLLAverage1 = modbus_read1((43026 - X), 2, "vllavg");
    float VLNAverage1 = modbus_read1((43036 - X), 2, "vlnavg");
    double wh1 = modbus_read1((42700 - X), 2, "wh");
    float current1 = modbus_read1((43010 - X), 2, "current");
    float wattsrphase1 = modbus_read1((43000 - X), 2, "rphase");
    float wattsyphase1 = modbus_read1((43002 - X), 2, "yphase");
    float wattsbphase1 = modbus_read1((43004 - X), 2, "bphase");
    float frequency1 = modbus_read1((43110 - X), 2, "freq");

    data = String(current1) + "," + String(PFAverage1) + "," + String(VLLAverage1) + "," + String(VLNAverage1) + "," + 
    String(wh1) + "," + String(wattsrphase1) + "," + String(wattsyphase1) + "," + String(wattsbphase1) + "," + 
    String(frequency1);

    Serial.println("id " + String(id) + "-> " + data);
  }

  void load_data2() {
    float PFAverage1 = modbus_read1((43192 - X), 2, "pfavg");
    float VLLAverage1 = modbus_read1((43026 - X), 2, "vllavg");
    float VLNAverage1 = modbus_read1((43036 - X), 2, "vlnavg");
    double wh1 = modbus_read1((42700 - X), 2, "wh");
    float current1 = modbus_read1((43010 - X), 2, "current");
    float wattsrphase1 = modbus_read1((43000 - X), 2, "rphase");
    float wattsyphase1 = modbus_read1((43002 - X), 2, "yphase");
    float wattsbphase1 = modbus_read1((43004 - X), 2, "bphase");
    float frequency1 = modbus_read1((43110 - X), 2, "freq");

    data = String(current1) + "," + String(PFAverage1) + "," + String(VLLAverage1) + "," + String(VLNAverage1) + "," + 
    String(wh1) + "," + String(wattsrphase1) + "," + String(wattsyphase1) + "," + String(wattsbphase1) + "," + 
    String(frequency1);

    Serial.println("id " + String(id) + "-> " + data);
  }

  bool push_data() {
    String lnk = endpoint + data;
    HTTPClient http;
    http.begin(lnk);
    int httpCode = http.GET();

    if (httpCode > 0) {
      String res = http.getString();
      Serial.println(res);
      return true;
    } else {
      Serial.print("GET err: ");
      Serial.println(httpCode);
      return false;
    }
  }

private:
  ModbusMaster node;
  int id;
  String data = "";
  String endpoint = "";

  float modbus_read(int addr, int sm, String name) {
    Serial.print("Reading the id:");
    Serial.println(id);
    int result = node.readHoldingRegisters(addr, sm);
    int data[10];
    float flt = 0;

    if (result == node.ku8MBSuccess) {
      for (int j = 0; j < 2; j++) {
        data[j] = node.getResponseBuffer(j);
      }
      unsigned long temp = (unsigned long)data[0] + (unsigned long)data[1] * 65536;
      flt = *((float*)&temp);

      Serial.print(id);
      Serial.print(": ");
      Serial.println(name + ": " + String(flt));
      delay(100);
    } else {
      Serial.print(id);
      Serial.print(": ");
      Serial.print("Failed, Response Code: ");
      Serial.print(result, HEX);
      Serial.println(" ");
      delay(100);
    }

    return flt;
  }

  float modbus_read1(int addr, int sm, String name) {
    Serial.print("Reading the id:");
    Serial.println(id);
    int result = node.readHoldingRegisters(addr, sm);
    int data[10];
    float flt = 0;

    if (result == node.ku8MBSuccess) {
      for (int j = 0; j < 2; j++) {
        data[j] = node.getResponseBuffer(j);
      }
      unsigned long temp = (unsigned long)data[1] + (unsigned long)data[0] * 65536;
      flt = *((float*)&temp);

      Serial.print(id);
      Serial.print(": ");
      Serial.println(name + ": " + String(flt));
      delay(100);
    } else {
      Serial.print(id);
      Serial.print(": ");
      Serial.print("Failed, Response Code: ");
      Serial.print(result, HEX);
      Serial.println(" ");
      delay(100);
    }

    return flt;
  }

  float modbus_read2(int addr, int sm, String name) {
    Serial.print("Reading the id:");
    Serial.println(id);
    int result = node.readHoldingRegisters(addr, sm);
    int data[10];
    float flt = 0;

    if (result == node.ku8MBSuccess) {
      for (int j = 0; j < 2; j++) {
        data[j] = node.getResponseBuffer(j);
      }
      unsigned long temp = (unsigned long)data[1] + (unsigned long)data[0] * 65536;
      flt = *((float*)&temp);

      Serial.print(id);
      Serial.print(": ");
      Serial.println(name + ": " + String(flt));
      delay(100);
    } else {
      Serial.print(id);
      Serial.print(": ");
      Serial.print("Failed, Response Code: ");
      Serial.print(result, HEX);
      Serial.println(" ");
      delay(100);
    }

    return flt;
  }

  static void preTransmission() {
    digitalWrite(MAX485_RE_NEG, 1);
    digitalWrite(MAX485_DE, 1);
  }

  static void postTransmission() {
    digitalWrite(MAX485_RE_NEG, 0);
    digitalWrite(MAX485_DE, 0);
  }
};