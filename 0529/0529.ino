int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
int pinCount = 10; 

int lastSensorValue = 0; // 用來記錄上一次的數值

void setup() {
  for (int i = 0; i < pinCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int currentSensorValue = analogRead(A0);
  
  // 只有當「現在的數值」跟「上一次的數值」差超過 5 的時候，才改變 LED
  if (abs(currentSensorValue - lastSensorValue) > 5) {
    
    // 把目前的數值存起來，當作下一次比較的基準
    lastSensorValue = currentSensorValue;
    
    // 計算該亮幾顆燈
    int ledBar = map(currentSensorValue, 0, 1023, 0, pinCount);
    
    // 更新 LED 狀態
    for (int i = 0; i < pinCount; i++) {
      if (i < ledBar) {
        digitalWrite(ledPins[i], HIGH);
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    }
  }
  delay(10); // 微小的延遲讓訊號更穩定
}