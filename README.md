# Controlling an LED via Peer-to-Peer NodeMCU Communication (ESP-NOW)

Peer-to-peer wireless communication between two NodeMCU (ESP8266) boards
using the ESP-NOW protocol. One NodeMCU acts as the sender and the other as
the receiver. A switch on the sender turns an LED on the receiver on or off,
with no WiFi router or server involved.

## Concepts
- **Peer-to-peer (P2P)**: a decentralised setup with no server managing the
  network. The two NodeMCUs talk to each other directly.
- **ESP-NOW**: a protocol from Espressif that lets ESP boards communicate
  directly, without a router or central server.
- **MAC address pairing**: the sender is given the MAC address of the
  receiver, and uses it to address its messages.
- **Roles**: one NodeMCU is set as sender (controller) and the other as
  receiver (slave).

## Hardware
| Part | Connection |
|---|---|
| NodeMCU ESP8266 (sender) | Switch between D4 and GND (internal pull-up) |
| NodeMCU ESP8266 (receiver) | LED on D2 through a [10k] resistor |

## Software
- Arduino IDE with the ESP8266 board package
- Libraries: `ESP8266WiFi`, `espnow`

## How it works
1. Both boards start in WiFi station mode and initialise ESP-NOW.
2. The sender reads the switch. Pressed (pin LOW) sends `LED_ON`, released
   sends `LED_OFF`.
3. The sender transmits the message to the receiver's MAC address every
   100 ms.
4. The receiver's callback function reads the message and sets the LED pin
   HIGH or LOW.

## Setup
1. Upload `receiver/receiver.ino` to the receiver board.
2. Print its MAC address with `WiFi.macAddress()` and read it in the serial
   monitor.
3. Put that address in `receiverAddress` in `transmitter/transmitter.ino`
   and upload it to the sender board.
4. Press the switch to turn the LED on.

## Result
[Photo of the setup or link to a demo video]

## Folder structure
- `transmitter/`: sender code
- `receiver/`: receiver code
- `images/`: wiring photos

## Possible extensions
- Servo or motor control on the receiver
- Two-way communication with acknowledgements
- Multiple receivers

## Author
Thirakala Pranav Sai | [LinkedIn](www.linkedin.com/in/pranav-sai-thirakala)
