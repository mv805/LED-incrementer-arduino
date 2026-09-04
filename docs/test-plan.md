<h1><u>LED Incrementer Arduino Assembly Test Plan</u></h1>

| Field | Value |
| ----- | ----- |
| Part number | 10029482-3 |
| Description | LED INCREMENTER ARDUINO ASSY |
| Test plan revision | Rev A |
| Hardware revision | Rev A |
| Firmware version | v0.1.0 |
| Test date | 2026-09-03 |
| Overall result | PASS |

## Purpose

This test plan verifies the functional requirements for the LED Incrementer Arduino assembly. It defines the setup, procedure, expected result, pass/fail criteria, and recorded result for each test.

## Test Setup

1. Assemble the Hardware Rev A unit.
2. Load firmware version `v0.1.0` onto the Arduino.
3. Connect the blinker LED, increment button, status LED, and Arduino LED matrix.
4. Power on or reset the assembly.
5. Observe the blinker LED, status LED, button response, and LED matrix during testing.

## Pass/Fail Rules

- **PASS:** The observed result meets every stated expected result for the test.
- **FAIL:** Any observed result does not meet an expected result, or the test cannot be completed.
- A requirement is compliant only when every test to which it is traced has a `PASS` result.

## Traceability

| Test ID | Requirements covered |
| ------- | -------------------- |
| TP-001 | REQ-FUNC-001, REQ-FUNC-003, REQ-FUNC-011, REQ-FUNC-012 |
| TP-002 | REQ-FUNC-004, REQ-FUNC-005 |
| TP-003 | REQ-FUNC-006 |
| TP-004 | REQ-FUNC-008 |
| TP-005 | REQ-FUNC-009 |
| TP-006 | REQ-FUNC-010 |
| TP-007 | REQ-FUNC-013, REQ-FUNC-014 |

## Test Procedures and Results

### TP-001: Startup, Blinking, and Display

**Requirements:** REQ-FUNC-001, REQ-FUNC-003, REQ-FUNC-011, REQ-FUNC-012

**Procedure:**

1. Reset the assembly.
2. Confirm that the blinker LED alternates between ON and OFF.
3. Confirm that the initial flash interval is 1000 ms by observing the timing or reviewing the firmware parameter.
4. Confirm that the LED matrix displays the current interval at startup.
5. Press the increment button once and confirm that the matrix display updates.

**Expected result:** The blinker LED alternates at the configured interval, starts at 1000 ms, and the matrix displays the current interval at startup and after the button press. The displayed value represents the interval divided by 10.

**Pass/fail criteria:** PASS if all expected results occur; otherwise FAIL.

**Recorded result:** PASS. The blinker alternated correctly, started at 1000 ms, and the matrix displayed `100` at startup and updated after the button press.

### TP-002: Flash Interval Limits

**Requirements:** REQ-FUNC-004, REQ-FUNC-005

**Procedure:**

1. Starting from the initial 1000 ms interval, press the increment button repeatedly until the minimum interval is reached.
2. Confirm that the interval steps through valid values and reaches 200 ms.
3. Confirm that no configured interval is greater than 1000 ms or less than 200 ms.

**Expected result:** The flash interval remains within the inclusive range of 200 ms through 1000 ms.

**Pass/fail criteria:** PASS if every observed interval is within the stated range; otherwise FAIL.

**Recorded result:** PASS. All observed interval values remained between 200 ms and 1000 ms inclusive.

### TP-003: Increment Button Function

**Requirement:** REQ-FUNC-006

**Procedure:**

1. Release the increment button and confirm the blinker is operating.
2. Press the increment button once.
3. Observe whether the flash interval changes.

**Expected result:** The assembly provides a functional increment button that controls the blinker speed.

**Pass/fail criteria:** PASS if a valid button press changes the blinker speed; otherwise FAIL.

**Recorded result:** PASS. The button controlled the blinker speed as expected.

### TP-004: Speed Increase Per Press

**Requirement:** REQ-FUNC-008

**Procedure:**

1. Reset the assembly and record the initial interval.
2. Release the button, then press and release it once.
3. Record the new interval and compare it with the previous interval.

**Expected result:** Each valid press decreases the flash interval by 25 ms, causing the LED to flash faster.

**Pass/fail criteria:** PASS if the interval decreases by exactly 25 ms for the valid press; otherwise FAIL.

**Recorded result:** PASS. The interval decreased from 1000 ms to 975 ms after one valid press.

### TP-005: Held Button Behavior

**Requirement:** REQ-FUNC-009

**Procedure:**

1. Reset the assembly.
2. Press and continuously hold the increment button.
3. Observe the interval for at least 2 seconds.
4. Release the button, then press and release it again.

**Expected result:** The held button causes no more than one interval change. A second interval change occurs only after release and a new press.

**Pass/fail criteria:** PASS if the interval changes once during the hold and changes again only after the new press; otherwise FAIL.

**Recorded result:** PASS. The interval changed once during the hold and changed again only after release and a new press.

### TP-006: Minimum Limit Wraparound

**Requirement:** REQ-FUNC-010

**Procedure:**

1. Press and release the increment button until the interval reaches 200 ms.
2. Press and release the increment button once more.
3. Observe the new interval and matrix display.

**Expected result:** When the next 25 ms decrease would go below 200 ms, the interval wraps to 1000 ms and the matrix display updates to `100`.

**Pass/fail criteria:** PASS if the interval changes from 200 ms to 1000 ms and the matrix displays `100`; otherwise FAIL.

**Recorded result:** PASS. The interval wrapped from 200 ms to 1000 ms and the matrix displayed `100`.

### TP-007: Status LED Indication

**Requirements:** REQ-FUNC-013, REQ-FUNC-014

**Procedure:**

1. Release the increment button and observe the status LED.
2. Press and hold the increment button and observe the status LED.
3. Release the button and observe the status LED again.

**Expected result:** The status LED is provided as a button-press indicator. It is ON while the button is pressed and OFF while the button is released.

**Pass/fail criteria:** PASS if the status LED follows the button state throughout the test; otherwise FAIL.

**Recorded result:** PASS. The status LED was OFF when released, ON while pressed, and OFF again after release.

## Test Summary

| Result | Count |
| ------ | ----- |
| PASS | 7 |
| FAIL | 0 |
| Not tested | 0 |

All requirements traced to this test plan passed on 2026-09-03. The assembly is functionally compliant with Requirements Rev A for the tested configuration. The assembly release state remains `In work` until the design is formally completed and committed as `Released`.
