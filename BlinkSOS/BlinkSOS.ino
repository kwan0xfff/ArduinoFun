/*
  BlinkSOS - Use Arduino on-board LED to emit Morse code "SOS".

  Based on the basic Blink.ino example provided by Arduino IDE.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and
  ZERO it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN
  is set to the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on
  your Arduino model, check the Technical Specs of your board at:
      https://www.arduino.cc/en/Main/Products

  Created 2017
  by Rick Kwan

  This example code is in the public domain.

  https://github.com/kwan0xfff/arduinofun/BlinkSOS

*/

// Speed up or slow down the LED by changing DOT_LENGTH.

#define DOT_LENGTH      200             // milliseconds of dot
#define DASH_LENGTH     (DOT_LENGTH*3)  // dash length
#define PAUSE_ELEMS     DOT_LENGTH      // pause between elements
#define PAUSE_CHARS     (DOT_LENGTH*3)  // pause between characters
#define PAUSE_WORDS     (DOT_LENGTH*7)  // pause between characters

void pause(int delay_time) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(delay_time);
}

void dot() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(DOT_LENGTH);
}

void dash() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(DASH_LENGTH);
}

void letter_S() {
    dot(); pause(PAUSE_ELEMS);
    dot(); pause(PAUSE_ELEMS);
    dot();
}

void letter_O() {
    dash(); pause(PAUSE_ELEMS);
    dash(); pause(PAUSE_ELEMS);
    dash();
}

void word_SOS() {
    letter_S(); pause(PAUSE_CHARS);
    letter_O(); pause(PAUSE_CHARS);
    letter_S();
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  pause(PAUSE_WORDS);
}

// the loop function runs over and over again forever
void loop() {
    word_SOS(); pause(PAUSE_WORDS);
}
