
#define toggle_mode_pin 4
bool mode = 1;
const int switchPin = 0; // پین سوئیچ
const int relayPins[] = {1, 2, 3}; // آرایه پین های رله
int relayState = 0; // متغیر وضعیت رله

void setup() {
  // پین سوئیچ را به عنوان ورودی و پین های رله را به عنوان خروجی تنظیم کنید
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(toggle_mode_pin, INPUT_PULLUP);

  for (int i = 0; i < 3; ++i) {
    pinMode(relayPins[i], OUTPUT);
  }
}

void loop() {

if (digitalRead(toggle_mode_pin) == 0) {
    
  mode = 0;
  }
  else {
    
  mode = 1;

  }




  switch (mode) {
  case 0:
    // 2 relays   toggle pin is pressed

      
  // اگر سوئیچ فشار داده شد
  if (digitalRead(switchPin) == 0) {
    // وضعیت رله را به روز کنید
    relayState = (relayState + 1) % 2;

    // رله قبلی را خاموش کنید
    if (relayState > 0) {
      digitalWrite(relayPins[relayState - 1], LOW);
    }

    // رله فعلی را روشن کنید
    digitalWrite(relayPins[relayState], HIGH);

    // منتظر 500 میلی ثانیه بمانید
    delay(1000);
    // رله فعلی را خاموش کن
    digitalWrite(relayPins[relayState], LOW);

    while (digitalRead(switchPin) == 0) {}
  }

  break;
  case 1:
   // 3 relays   toggle pin is NOT pressed

   
  // اگر سوئیچ فشار داده شد
  if (digitalRead(switchPin) == 0) {
    // وضعیت رله را به روز کنید
    relayState = (relayState + 1) % 3;

    // رله قبلی را خاموش کنید
    if (relayState > 0) {
      digitalWrite(relayPins[relayState - 1], LOW);
    }

    // رله فعلی را روشن کنید
    digitalWrite(relayPins[relayState], HIGH);

    // منتظر 500 میلی ثانیه بمانید
    delay(1000);
    // رله فعلی را خاموش کن
    digitalWrite(relayPins[relayState], LOW);

    while (digitalRead(switchPin) == 0) {}
  }

  break;










}}
