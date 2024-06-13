**In-system programming** (ISP), or also called **in-circuit serial programming** (ICSP), is the ability of some microcontrollers and other embedded systems to be programmed while installed in a complete system, rather than requiring the chip to be programmed prior to installing it into the system.

The Arduino Uno is based on the Atmega328P microcontroller. It supports ICSP for programming the microcontroller while it's on the board. 
1. **ICSP Pins**:
   - The Arduino Uno has an ICSP header located near the digital pins. This header consists of six pins: MOSI, MISO, SCK, RESET, VCC, and GND.
   - These pins are used for programming and debugging the Atmega328P microcontroller on the Arduino Uno board.
2. **Programming Tool**:
   - To program the Arduino Uno using ICSP, you typically use the Arduino IDE along with a compatible programming tool. The most common tool is the AVR ISP programmer, such as the USBtinyISP or AVRISP mkII.
4. **Functionality**:
   - When you upload a sketch to the Arduino Uno using ICSP, the programming tool communicates with the Atmega328P microcontroller through the ICSP pins.
   - The programming tool sends the compiled firmware or sketch to the microcontroller's flash memory, where it is stored for execution.
   - ICSP can also be used for burning the bootloader onto the microcontroller 
   - ![[Pasted image 20240427222108.png]]
