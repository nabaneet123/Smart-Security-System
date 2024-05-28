# Smart-Security-System
This project implements a secure access control system using an Arduino board and RFID technology. The system authorizes or restricts entry based on predetermined conditions, serving as an effective security measure for doors or gates.

### Features:
- Utilizes MFRC522 RFID reader module for reading RFID tags/cards.
- Defines authorized RFID tag IDs to grant access.
- Controls an electric lock or servo motor to lock/unlock the door/gate.
- Serial communication for debugging and monitoring.

### Usage:
1. Connect the MFRC522 RFID reader module and the electric lock/servo motor to the Arduino board.
2. Modify the `authorizedTag1` and `authorizedTag2` arrays with the IDs of authorized RFID tags/cards.
3. Upload the provided C++ code to the Arduino board.
4. When a card is detected, the system checks if it matches an authorized tag. If authorized, it unlocks the door/gate for a predetermined period before locking it again.

### Hardware Required:
- Arduino board (e.g., Arduino Uno)
- MFRC522 RFID reader module
- RFID tags/cards
- Electric lock or servo motor (optional)

### Note:
- Ensure proper wiring and connections as per the provided code and hardware setup.
- Customize the code and hardware according to specific requirements and use cases.
- Additional security measures such as encryption can be implemented for enhanced security.
