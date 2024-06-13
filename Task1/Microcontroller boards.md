
## ARDUINO UNO R3 ##
![[Pasted image 20240426161619.png]]
![[Pasted image 20240427153459.png|400]]
![[Pasted image 20240426181422.png|600]]
![[Pasted image 20240426181611.png]]
 - [[DC POWER CONNECTOR]]
 - [[USB CONNECTORS]](uses type B USB connector)
 - [[CAPACITORS]](uses aluminum electrolytic capacitors)
 - [[RECTIFIERS]](Arduino uses a single phase rectifier but it is a DC to DC buck converters) 
 - [[REGULATORS]](Arduino uses a linear LDO regulator) 
 - [[OSCILLATORS]] (Arduino uses 16Mhz Quartz crystal and a ceramic oscillator connected to main controller) 
 - Microcontroller used is [[ATMEGA328P]]
 - It also contains [[ATMEGA16U2]] chip for USB-Serial communication.
 - It contains [[ICSP]] Pins for programming in [[ATMEGA328P]] directly.
 - [[DAC]]
-  [[Arduino Interrupts, timers and counters]]

   
## PIN OUT ##
It has 14 digital input/output pins (of which 6 can be used as PWM outputs), 6 analog inputs.
![[Pasted image 20240427215520.png|800]]
![[Pasted image 20240427215613.png]]
## [[Arduino Ports]] ##

![[Pasted image 20240428205431.png]]
![[Pasted image 20240429180052.png|500]]
1. **Digital Pins (0-13):** These pins can be used for digital input or output. Pins 0 and 1 are also used for serial communication (RX and TX).
2. **Analog Pins (A0-A5):** These pins can be used for analog input. They can also function as digital pins (14-19).
3. **Power Pins:**
   - **VCC:** Supply voltage pin (typically 5V).
   - **GND:** Ground pins.
   - **AVCC:** Analog supply voltage pin for ADC (Analog to Digital Converter external reference voltage but should be 5v).(AREF pin to set reference voltage for analog to digital converter other than 5v)
4. **Reset (RESET):** This pin is used to reset the microcontroller.
5. **Crystal Pins (XTAL1 and XTAL2):** These pins are connected to an external crystal oscillator for providing clock signals to the microcontroller.
6. **Serial Communication Pins (RX, TX):** Used for UART serial communication with other devices.
7. **PWM Pins (3, 5, 6, 9, 10, 11):** These pins support Pulse Width Modulation for analog output.
8. **SPI Pins (MISO, MOSI, SCK):** Used for Serial Peripheral Interface communication.
9. **I2C Pins (SDA, SCL):** Used for Inter-Integrated Circuit communication.
10. **Interrupt Pins (2, 3):** These pins can be configured to trigger interrupts on certain events.
11. contains a **Watch dog timer** .The ATmega328P has a Watchdog Timer which is a useful feature to help the system recover from scenarios where the system hangs or freezes due to errors in the code written or due to conditions that may arise due to hardware issues. The watchdog timer needs to be configured according to the need of the application. The watchdog timer uses an internal 128kHz clock source. When enabled, it starts counting from 0 to a value selected by the user. If the watchdog timer is not reset by the time it reaches the user selected value, the watchdog resets the microcontroller.

These are the primary pins of the ATmega328P microcontroller, each serving specific functions to enable various features and functionalities of the Arduino Uno and similar boards.

## ESP-32 ##
![[Pasted image 20240429091709.png]]
![[Pasted image 20240429094319.png]]
![[Pasted image 20240429111617.png]]

-  Processors:
    - CPU: Xtensa dual-core (or single-core)(two processing units in the chip) 32-bit LX6 microprocessor, operating at 160 or 240 MHz and performing at up to 600 DMIPS(Dhrystone MIPS (Million Instructions per Second))
    - Ultra low power (ULP) co-processor
- Memory: 520 KB RAM, 448 KB ROM
- [[wireless connectivity]]:
    - Wi-Fi: 802.11 b/g/n(2.4GHz)
    - Bluetooth: v4.2 BR/EDR and BLE (shares the radio with Wi-Fi)
    - ESP32-WROOM-32 (ESP-WROOM-32) is a powerful, generic Wi-Fi+BT+BLE MCU module
- - Peripheral interfaces:
    - 34 × programmable GPIOs
    - 12-bit SAR [[ADC]] up to 18 channels
    - 2 × 8-bit DAC
    - 10 × touch sensors (capacitive  GPIOs)
    - 4 × SPI
    - 2 ×[[I2S]] interfaces
    - 2 × I2C interfaces
    - 3 × UART
    - SD/SDIO/CE-ATA/MMC/eMMC host controller[[SD]]
    - SDIO/SPI slave controller[[SDIO]]
    - 
    - Ethernet MAC interface with dedicated DMA and planned IEEE 1588 Precision Time Protocol support
    - [[CAN 2.0]]
    - [[Infrared remote controller]] (TX/RX, up to 8 channels)
    - Pulse counter 
    - Motor PWM
    - LED PWM (up to 16 channels)
- Power management:
    - Internal low-dropout regulator
    - Individual power domain for RTC
    - Wake up from GPIO interrupt, timer, ADC measurements, capacitive touch sensor interrupt
- Micro-USB Port  is used to connect ESP32 to computer for programming([[USB CONNECTORS]])
- Firmware is programming that's written to a hardware device's non-volatile memory or usually found on dedicated memory chips. Firmware is installed directly onto a piece of hardware during manufacturing. It is used to run user programs on the device and can be thought of as the software that enables hardware to run. It communicates directly with the hardware, providing fundamental link and method of control to the about a particular hard ware to the system. Firmware performs all monitoring controls and data manipulation functions.
- Boot button is used to upload the program from Arduino IDE into ESP32.
- The EN button is used to reset the ESP module.
- **NOTE:** don’t press the EN button with the Boot button otherwise ESP enters into firmware uploading mode.
- The USB to UART Bridge Controller provides USB connectivity to devices with a UART interfaces
- The ESP32 peripherals include:
- 18 Analog-to-Digital Converter (ADC) channels
- 3 SPI interfaces
- 3 UART interfaces
- 2 I2C interfaces
- 16 PWM output channels
- 2 Digital-to-Analog Converters (DAC)
- 2 I2S interfaces
- 10 Capacitive sensing GPIOs





