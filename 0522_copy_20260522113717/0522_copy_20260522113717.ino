#include "pitches.h"

// --- 蜂鳴器設定 ---
const int buzzerPin = 12; // 保持在 Pin 12，避開 LED

// --- 海賊王《We Are!》副歌旋律 ---
int melody[] = {
  NOTE_G4, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, // あ・りった・けの・ゆ・め・を・か・き
  NOTE_D5, NOTE_E5, NOTE_D5, 0,                                           // あ・つ・め～ (停頓)
  NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_E5,          // さが・し・もの・を・さが・し・に
  NOTE_D5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5                             // ゆ・く・の・さ～
};

// --- 對應的節拍 (4:四分音符, 8:八分音符, 16:十六分音符) ---
int noteDurations[] = {
  4, 8, 8, 8, 8, 8, 8, 8,
  4, 4, 2, 4,
  4, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 8, 2
};

// 計算總共有幾個音符
const int totalNotes = sizeof(melody) / sizeof(melody[0]);

// --- LED Bar 設定 ---
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const int ledCount = 10;

void setup() {
  // 初始化所有 LED 引腳
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // 初始化蜂鳴器
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // 循環播放海賊王旋律
  for (int thisNote = 0; thisNote < totalNotes; thisNote++) {
    
    // 1. 計算音符時間（基礎速度調快一點，展現熱血感）
    int noteDuration = 900 / noteDurations[thisNote];
    
    // 2. 讓 LED 隨音符位置亮起 (用餘數處理，讓超過 10 個音也能循環亮燈)
    int currentLed = thisNote % ledCount;
    digitalWrite(ledPins[currentLed], HIGH);

    // 3. 蜂鳴器發聲
    tone(buzzerPin, melody[thisNote], noteDuration);

    // 4. 【已修改】讓旋律間隔多一點！
    // 這裡幫你調成了 1.70，音符與音符之間會有更明顯、乾淨的空白停頓
    int pauseBetweenNotes = noteDuration * 1.70;
    delay(pauseBetweenNotes);
    
    // 5. 停止發聲，並熄滅當前 LED（讓燈光有跳動感）
    noTone(buzzerPin);
    digitalWrite(ledPins[currentLed], LOW);
  }

  // 整首播完後，全滅並停頓 1.5 秒再重播
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(1500); 
}