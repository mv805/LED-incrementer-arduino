<h1><u>LED Incrementer Arduino Assembly Requirements</u></h1>

Document Revision: Rev A

## Purpose

This document defines the functional requirements for the LED Incrementer Arduino assembly. Requirement identifiers are intended to remain stable for use in a future compliance matrix.

## Functional Requirements

| ID | Requirement | Verification method |
| -- | ----------- | ------------------ |
| REQ-FUNC-001 | The assembly shall provide a blinker LED that alternates between its ON and OFF states at the configured flash interval. | Inspection and test |
| REQ-FUNC-003 | The initial flash interval shall be 1000 ms when the firmware starts. | Inspection and test |
| REQ-FUNC-004 | The configurable flash interval shall not be less than 200 ms. | Inspection and test |
| REQ-FUNC-005 | The configurable flash interval shall not be greater than 1000 ms. | Inspection and test |
| REQ-FUNC-006 | The assembly shall provide an increment button for controlling the blinker speed. | Inspection and test |
| REQ-FUNC-008 | Each valid increment-button press shall decrease the flash interval by 25 ms, causing the blinker LED to flash faster. | Test |
| REQ-FUNC-009 | A continuously held increment button shall produce no more than one interval change per press action; another change shall require a release followed by a new press. | Test |
| REQ-FUNC-010 | When a valid button press would reduce the flash interval below 200 ms, the firmware shall wrap the flash interval to 1000 ms. | Test |
| REQ-FUNC-011 | The assembly shall display the current flash interval on the Arduino LED matrix after startup and after every valid interval change. | Inspection and test |
| REQ-FUNC-012 | The displayed interval shall represent the flash interval in milliseconds divided by 10. | Inspection and test |
| REQ-FUNC-013 | The assembly shall provide a status LED that indicates when the increment button is pressed. | Inspection and test |
| REQ-FUNC-014 | The status LED shall be ON while the increment button is pressed and OFF while the increment button is released. | Test |

## Initial Parameter Values

| Parameter | Value |
| --------- | ----- |
| Initial flash interval | 1000 ms |
| Minimum flash interval | 200 ms |
| Maximum flash interval | 1000 ms |
| Interval change per valid press | 25 ms faster |
| Matrix display representation | Flash interval divided by 10 |

## Traceability Note

These requirements describe the behavior implemented by the initial firmware baseline, version `v0.1.0`, identified in the assembly configuration document. Compliance evidence should reference the requirement ID, verification result, and test record when the assembly is ready for release.
