| Signal      | MCU Pin | Direction | Function                                |
| ----------- | ------- | --------- | --------------------------------------- |
| BLINKER_LED | D13     | Output    | Main blinking LED                       |
| INCREMENT_BUTTON    | D2      | Input     | Speeds up blinking when pressed            |
| STATUS_LED  | D4      | Output    | Indicator that the button is pressed    |

## STATUS_LED

MCU pin: D4

Active HIGH.

HIGH = LED ON
LOW = LED OFF

## BLINKER_LED

MCU pin: D13

Output.

The LED changes state each time the flash interval expires.

HIGH = LED ON
LOW = LED OFF

## INCREMENT_BUTTON

MCU pin: D2

Input with internal pull-up resistor (`INPUT_PULLUP`).

Active LOW.

LOW = Button pressed
HIGH = Button released