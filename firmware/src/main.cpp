#include <Arduino.h>
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

// Create the LED matrix object.
// This is the built-in display on the Arduino R4.
ArduinoLEDMatrix matrix;

// ---- Global state ----
// These variables keep track of the LED blink timing and button behavior.

unsigned long lastToggle = 0;      // Last time the main LED changed state
bool ledState = false;             // Current state of the main LED (ON/OFF)
bool incButtonPushed = false;      // Old flag used to avoid repeated presses
bool lastButtonState = HIGH;       // Previous state of the button (HIGH = not pressed)

// Timing controls for the blink speed.
// The interval is measured in milliseconds.
unsigned long flashInterval = 1000;
unsigned const long MAX_FLASH_INTERVAL = 1000;
unsigned const long MIN_FLASH_INTERVAL = 200;
unsigned const int FLASH_INCREASE_INCREMENT = 25;

// ---- Pin assignments ----
// These are the physical Arduino pins used by the circuit.
const int MAIN_LED = 13;          // Built-in LED pin or external LED pin
const int INC_INTERVAL_BTTN = 2;   // Button input, active LOW with INPUT_PULLUP
const int STATUS_LED = 4;          // Extra LED that shows when the button is pressed

// ---- Display helper ----
// This function updates the built-in LED matrix with the current interval.
// The value is divided by 10 so it fits on the small display better.
void showInterval(unsigned long value) {
  matrix.clear();                  // Clear the display before drawing
  matrix.beginDraw();              // Start drawing operations
  matrix.stroke(0xFFFFFFFF);       // Set text color to white
  matrix.textFont(Font_4x6);       // Use the smaller built-in font
  matrix.beginText(0, 0, 0xFFFFFF); // Draw starting near the top-left
  matrix.print(value / 10);        // Show a smaller version of the interval
  matrix.endText();                // Finish drawing text
  matrix.endDraw();                // Push the changes to the matrix
}

// ---- Arduino setup ----
// Runs once when the board powers up or resets.
void setup() {
  // Configure pins:
  pinMode(MAIN_LED, OUTPUT);         // Main flash LED
  pinMode(INC_INTERVAL_BTTN, INPUT_PULLUP); // Button uses internal pull-up resistor
  pinMode(STATUS_LED, OUTPUT);       // Status LED for press indication

  // Initialize the onboard LED matrix and show the starting interval.
  matrix.begin();
  showInterval(flashInterval);

  // Start with the status LED off.
  digitalWrite(STATUS_LED, LOW);
}

// ---- Main loop ----
// This repeats continuously forever.
void loop() {
  // Read the current button state.
  // With INPUT_PULLUP, pressed = LOW and released = HIGH.
  bool buttonState = digitalRead(INC_INTERVAL_BTTN);

  // Detect a press edge: HIGH -> LOW.
  // This means the button was just pressed, not held down.
  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(10); // Small debounce delay to ignore switch bounce

    // Re-check after a tiny delay to confirm the button is still actually pressed.
    if (digitalRead(INC_INTERVAL_BTTN) == LOW) {
      // Reduce the flash interval by a small increment.
      // This makes the LED blink faster.
      if (flashInterval >= (MIN_FLASH_INTERVAL + FLASH_INCREASE_INCREMENT)) {
        flashInterval -= FLASH_INCREASE_INCREMENT;
      } else {
        // If the interval would go below the minimum, reset to the maximum.
        // This creates the wrap-around behavior you want.
        flashInterval = MAX_FLASH_INTERVAL;
      }

      // Update the LED matrix display to show the new interval.
      showInterval(flashInterval);
    }
  }

  // Save the current button state for the next loop iteration.
  lastButtonState = buttonState;

  // Status LED behavior:
  // It turns on whenever the button is being pressed.
  if (buttonState == LOW) {
    digitalWrite(STATUS_LED, HIGH);
  } else {
    digitalWrite(STATUS_LED, LOW);
  }

  // ---- Non-blocking LED blink logic ----
  // This creates the blinking without using delay().
  unsigned long now = millis();
  if (now - lastToggle >= flashInterval) {
    lastToggle = now;      // Save the current time so the next toggle is based on this moment
    ledState = !ledState;  // Flip LED state
    digitalWrite(MAIN_LED, ledState);
  }
}
