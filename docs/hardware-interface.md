<h1><u>Hardware Interface</u></h1>

Part Number: 10029482-3
Description: LED INCREMENTER ARDUINO, ASSY

----

| Ref. | Signal             | MCU Pin | Direction | Function                          |
| ---- | ------------------ | ------- | --------- | --------------------------------- |
| 1    | BLINKER_LED        | D13     | Output    | Main blinking LED                 |
| 2    | INCREMENT_BUTTON   | D2      | Input     | Speeds up blinking when pressed   |
| 3    | STATUS_LED         | D4      | Output    | Indicator that the button is pressed |

## 1. STATUS_LED

MCU pin: D4

Active HIGH.

HIGH = LED ON
LOW = LED OFF

## 2. BLINKER_LED

MCU pin: D13

Output.

The LED changes state each time the flash interval expires.

HIGH = LED ON
LOW = LED OFF

## 3. INCREMENT_BUTTON

MCU pin: D2

Input with internal pull-up resistor (`INPUT_PULLUP`).

Active LOW.

LOW = Button pressed
HIGH = Button released