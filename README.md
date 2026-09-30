# 🤍 RGB LED Fade to White

> **Arduino Project #09** — RGB LED يزيد سطوع الألوان الثلاثة معاً تدريجياً حتى يصل للأبيض ثم يطفي فجأة

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Level](https://img.shields.io/badge/Level-Beginner-green?style=for-the-badge)](https://github.com/S-mohannad)

---

## 📋 Description

RGB LED يزيد سطوع قنوات R, G, B الثلاثة بنفس القيمة في نفس الوقت — مما ينتج تأثير Fade من الإطفاء التام إلى الأبيض الكامل، ثم يطفي فجأة ويعيد الدورة من جديد.

---

## 🔌 Circuit

```
Arduino UNO
┌─────────────────┐
│             9 ●─┼──[220Ω]──🟢 RGB Green pin
│            10 ●─┼──[220Ω]──🔵 RGB Blue pin
│            11 ●─┼──[220Ω]──🔴 RGB Red pin
│           GND ●─┼──────────⚫ RGB Common Cathode (-)
└─────────────────┘
```

- 🌈 RGB LED من نوع **Common Cathode**
- مقاومة 220Ω لكل pin
- Pin 9 → أخضر | Pin 10 → أزرق | Pin 11 → أحمر

---

## 💡 Concepts Used

- `analogWrite()` — التحكم في سطوع الألوان الثلاثة عبر PWM
- **White = R(255) + G(255) + B(255)** — الأبيض ناتج عن تساوي الألوان الثلاثة
- **Fade Effect** — تزايد تدريجي بخطوات 5 كل 150ms
- `if / else` — للتحقق من الوصول لأقصى قيمة والإطفاء

---

## 📊 Behavior

| المرحلة | قيمة x | اللون | المدة |
|---------|--------|-------|-------|
| Fade In | 0 → 255 | أسود → أبيض تدريجياً | 150ms × 51 خطوة |
| إطفاء فجائي | 255 → 0 | أبيض → أسود فوراً | 300ms توقف |
| تكرار ∞ | — | — | — |

---

## 🔗 Code

```cpp
int B = 10;
int G = 9;
int R = 11;
int x = 0;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  analogWrite(G, x);
  analogWrite(B, x);
  analogWrite(R, x);
  delay(150);

  if (x < 255) {
    x = x + 5;
  } else {
    x = 0;
    delay(300);
  }
}
```

---

## 🔧 How to Run

1. افتح **Arduino IDE**
2. وصّل الدائرة كما في الرسم
3. انسخ الكود والصقه
4. اختر **Board:** Arduino UNO
5. اختر **Port** الصحيح
6. اضغط ⬆️ **Upload**
7. شاهد الـ LED يتحول تدريجياً من الأسود للأبيض ثم يطفي فجأة

---

## 👨‍💻 Author

**S-mohannad** — [@S-mohannad](https://github.com/S-mohannad)
