1. High performance, low power AVR® 8-bit microcontroller
   AVR-**AVR** is an abbreviation for Alf and Vegard’s [[RISC]] processor
2. 32  8-bit general purpose working registers
3. Fully static operation(Fully Static Operation in any microcontroller is, u can hold the controller by stopping the clock and It doesn't affects the stored content in registers or RAM. Again the controller can be resumed by allowing the clock.  this static operation is possible only as long as controller is provided with the power.)
4. 16MIPS  throughput speed of 16Mhz
5. On-chip 2-cycle multiplier(ALU in the microcontroller has a hardware multiplier, which takes two instruction clock cycles to perform a calculation.)
6. 32KB of in-system self -programmable flash program memory
7. 1KB EEPROM(Electrically Erasable Programmable Read-Only Memory).
8. 2Kbytes internal SRAM(Static RAM)
9.  Write/erase cycles: 10,000 flash/100,000 EEPROM
10. Optional boot code section with independent lock bits 
    - In-system programming by on-chip boot program 
    -  True read-while-write operation(read or write to the mc memory simultaneously)
11.  Programming lock for software security
12. Two 8-bit Timer/Counters with separate prescaler and compare mode
13. One 16-bit Timer/Counter with separate prescaler, compare mode, and capture mode(ICP1- input capture pin for timer/counter1 and OC1A and OC1B pins represents the compare mode)
14. Real time counter with separate oscillator
15. Six PWM channels
16. 8-channel 10-bit [[ADC]] in TQFP and QFN/MLF package(chip variant)
17. Programmable serial USART
18.  Master/slave SPI serial interface
19. Byte-oriented 2-wire serial interface owned by atmel/ (Phillips I2C compatible)
20. On-chip analog comparator
21. Atmega328P supports Pin Change Interrupts on its I/O pins. These interrupts trigger whenever any of the enabled pins change state (from LOW to HIGH or HIGH to LOW). You need to enable the Pin Change Interrupt for the specific pin or pins you're interested in monitoring.
22. Internal calibrated oscillator (RC oscillator)
23. External and internal interrupt sources

#### CPU CORE ####
![[Pasted image 20240525144239.png]]

**Timers:**
TCCRo – Timer/Counter Control Register (contain CLOCK SELECT bits used to setup the prescaler)
TCNTo – Timer/Counter Register ( This is the real counter in the TIMER0 counter. the timer clock increases the value of this 8 bit register by 1 with every timer clock pulse.)
TIMSKo – Timer/Counter Interrupt Mask Register(This register, used to activate/deactivate the INTERRUPTS related to timers,controls)
there will be a overflow flag register to notify when the timer reaches the top.

### BLOCK DIAGRAM ###
![[Pasted image 20240503162655.png|550]]
   - The internal bandgap voltage reference in the Atmega328P microcontroller serves as a stable voltage reference for various analog functions within the device, including the analog comparator and the Analog-to-Digital Converter (ADC).The bandgap voltage reference operates on the principle of exploiting the temperature dependence of the bandgap energy in semiconductors. As the temperature changes, the bandgap energy remains relatively constant, resulting in a stable voltage output.
   - **Analog Comparator**: In the Atmega328P, the analog comparator can use the internal bandgap voltage reference as one of its input sources. By comparing an external analog voltage with the internal bandgap voltage, the comparator can determine whether the external voltage is higher or lower than the reference voltage.
 **ARITHMETIC LOGIC UNIT (ALU):** 
1. **Direct Connection with Working Registers**:
   - The ALU directly interacts with all 32 general-purpose working registers in the microcontroller. These registers are used to store data temporarily during program execution.

2. **Single Clock Cycle Operation**:
   - Arithmetic operations between general-purpose registers or between a register and an immediate value (a constant value used in the instruction) are executed within a single clock cycle.
   
3. **Three Main Categories of Operations**:
   - **Arithmetic Operations**: These involve basic arithmetic calculations such as addition, subtraction, multiplication, and division.
   - **Logical Operations**: These involve logical operations such as AND, OR, XOR, and NOT, which manipulate individual bits in data.
   - **Bit-Functions**: These include operations like shifting bits left or right, setting or clearing specific bits, and testing the state of individual bits.

4. **Multiplier Support**:
   -  include a powerful multiplier unit.
   - This multiplier supports both signed and unsigned multiplication, allowing the microcontroller to efficiently perform multiplication operations on large numbers.
   - It also supports fractional format, which is useful for applications involving calculations with fractional numbers.

 **SREG/AVR-STATUS REGISTER:**
The AVR Status Register (SREG) is a crucial component in the ATmega328P microcontroller, containing various flags that provide information about the outcome of arithmetic and logic operations, as well as controlling interrupt behavior. 
![[Pasted image 20240503180713.png]]
1. **Bit 7 – I: Global Interrupt Enable**:
   - This bit controls the enabling and disabling of interrupts globally.
   - When set (value of 1), interrupts are enabled, allowing the microcontroller to respond to external events or interrupts generated by peripherals.
   - When cleared (value of 0), interrupts are disabled, preventing the microcontroller from responding to interrupt requests.

2. **Bit 6 – T: Bit Copy Storage**:
   - The T-bit is used as a temporary storage location for bit copy instructions _**(BLD and BST).**_
   - BLD instruction copies the value of a specified bit in the T-flag (T in the Status Register) to a specified bit in a destination register.
   - BST instruction copies the value of a specified bit in a source register to the T-flag (T in the Status Register).
   - These instructions allow the copying of individual bits between the SREG register and other registers in the microcontroller.

3. **Bit 5 – H: Half Carry Flag**:
   - The H-bit indicates a half-carry in certain arithmetic operations, particularly useful in Binary Coded Decimal (BCD) arithmetic.
   - It is used to detect carry-out from the lower nibble to the upper nibble in addition and subtraction operations involving BCD numbers.

4. **Bit 4 – S: Sign Bit**:
   - The S-bit represents the sign of a result in arithmetic or logic operations.
   - It is determined by an exclusive OR (XOR) operation between the Negative Flag (N) and the Two's Complement Overflow Flag (V).
   - If the result is negative, the S-bit is set (1); otherwise, it is cleared (0).

5. **Bit 3 – V: Two's Complement Overflow Flag**:
   - The V-bit indicates overflow in two's complement arithmetic operations.
   - Overflow occurs when the result of a signed operation is too large or too small to be represented in the available number of bits.

6. **Bit 2 – N: Negative Flag**:
   - The N-bit indicates a negative result in arithmetic or logic operations.
   - If the result is negative, the N-bit is set (1); otherwise, it is cleared (0).

7. **Bit 1 – Z: Zero Flag**:
   - The Z-bit indicates a zero result in arithmetic or logic operations.
   - If the result is zero, the Z-bit is set (1); otherwise, it is cleared (0).

8. **Bit 0 – C: Carry Flag**:
   - The C-bit indicates a carry-out or borrow in arithmetic or logic operations.
   - It is used to detect overflow or underflow in unsigned arithmetic operations.

**FLASH MEMORY:**
The ATmega328P contains 32Kbytes on-chip in-system reprogrammable flash memory for program storage. Since all AVR instructions are 16 or 32 bits wide, the flash is organized as        16K x16(capacity of 16 kilobytes and operates with a data width of 16 bits). For software security, the flash program memory space is divided into two sections, boot loader section and application program section in ATmega328P.**Flash** memory in microcontroller-based systems is part of its ROM. The flash memory is where the system's firmware is stored to be executed

The bootloader section, if utilized, typically occupies a smaller portion of the flash memory. However, the size of the bootloader section can vary depending on the specific bootloader implementation and the configuration of the microcontroller.
a common configuration might allocate 2KB of flash memory for the bootloader section
leaving the remaining 30KB (or 30,720 bytes) of flash memory available for user application code and data.

**SRAM DATA MEMORY:**
static-even if we stop the clock it does not affect the stored content.
The first 32 locations address the register file, which consists of 32 general-purpose registers used for data manipulation.

1. **Opcode Limitation for IN and OUT Instructions**:
   - The IN and OUT instructions in AVR microcontrollers are used to transfer data between I/O registers and the general-purpose register file.
   - The opcode space for these instructions is limited to 64 locations, meaning that only 64 different I/O registers can be directly accessed using the IN and OUT instructions.

2. **Extended I/O Space**:
   - The ATmega328P provides an extended I/O space from addresses 0x60 to 0xFF in the Special Function Register (SFR) memory space.
   - This extended I/O space cannot be accessed using the IN and OUT instructions due to the opcode limitation.
   - Instead, data in this extended I/O space must be accessed using the  store and load instructions.
   -  The remaining 2048 locations address the internal data SRAM, which is used for storing variables and data during program execution.
    ![[Pasted image 20240503192405.png]]


**EEPROM:**
EEPROM (Electrically Erasable Programmable Read-Only Memory) is a type of non-volatile memory that can store data even when power is removed. In the ATmega328P microcontroller, EEPROM is used to store small amounts of data that need to be retained between power cycles or program executions. Here's an explanation of EEPROM and why the CPU is halted during writing and reading processes:

1. **EEPROM Organization**:
   - The ATmega328P contains 1 kilobyte (1KB) of data EEPROM memory.
   - EEPROM memory is organized as a separate data space, meaning it has its own memory addresses distinct from the program memory (flash) and the volatile data memory (SRAM).
   - Each address in EEPROM corresponds to a single byte of data that can be read from or written to independently.
2. **Endurance**:
   - EEPROM memory has a limited endurance, typically rated for at least 100,000 write/erase cycles.
   - This means that data can be written to or erased from EEPROM up to 100,000 times before the memory cells degrade significantly.
3. **Access Mechanism**:
   - Access to EEPROM memory is facilitated through dedicated EEPROM access registers located in the I/O space.
   - These registers include EEPROM address registers, EEPROM data register, and EEPROM control register.
   - Writing data to EEPROM involves specifying the address to write to and then writing the data to be stored at that address using the appropriate registers.
   - Similarly, reading data from EEPROM involves specifying the address to read from and then reading the data from the specified address using the appropriate registers.
4. **CPU Halt During Access**:
   - When the CPU writes data to EEPROM, it is halted for two clock cycles before the next instruction is executed.
   - This halt ensures that the write operation to EEPROM completes successfully without interruption.
   - Similarly, when the CPU reads data from EEPROM, it is halted for four clock cycles before the next instruction is executed.
   - This halt ensures that the data read from EEPROM is stable and can be safely used by the CPU.
**APPLICATION:**
The EEPROM (Electrically Erasable Programmable Read-Only Memory) in the ATmega328P microcontroller finds various applications due to its characteristics. Here are some common applications of EEPROM in the ATmega328P:

1. **Storing Calibration Data**:
   - EEPROM can be used to store calibration data for sensors or other peripherals connected to the microcontroller.
   - Calibration parameters, such as sensor offset or gain values, can be stored in EEPROM and retrieved during system initialization to ensure accurate sensor readings.

2. **Storing Configuration Settings**:
   - EEPROM is often used to store configuration settings that customize the behavior of the microcontroller or its peripherals.
   - User-defined parameters, such as communication settings (baud rate, protocol), display preferences, or system operation modes, can be stored in EEPROM.

3. **Data Logging**:
   - EEPROM can be utilized for data logging applications where small amounts of data need to be stored periodically.
   - In systems that require logging of sensor readings, event timestamps, or system states, EEPROM can be used as a non-volatile storage medium to store log entries.
![[Pasted image 20240503194033.png|600]]
![[Pasted image 20240503194116.png]]
![[Pasted image 20240503224741.png]]
![[Pasted image 20240503194350.png]]
-  Bit 3 – EERIE:   _EEPROM Ready Interrupt Enable Writing EERIE_ to one enables the EEPROM ready interrupt if the I bit in SREG is set. Writing EERIE to zero disables the interrupt. The EEPROM ready interrupt generates a constant interrupt when EEPE is cleared. Setting this bit indicates to the microcontroller that you want to be notified when a write operation to the EEPROM is completed
- Bit 2 – EEMPE: _EEPROM Master Write Enable_ The EEMPE bit determines whether setting EEPE to one causes the EEPROM to be written. When EEMPE is set, setting EEPE within four clock cycles will write data to the EEPROM at the selected address If EEMPE is zero, setting EEPE will have no effect
-  Bit 1 – EEPE: _EEPROM Write Enable The EEPROM_ Write enable signal EEPE is the write strobe to the EEPROM. When address and data are correctly set up, the EEPE bit must be written to one to write the value into the EEPROM. The EEMPE bit must be written to one before a logical one is written to EEPE, otherwise no EEPROM write takes place. 
-  Bit 0 – _EERE: EEPROM Read Enable_ The EEPROM read enable signal EERE is the read strobe to the EEPROM. When the correct address is set up in the EEAR register, the EERE bit must be written to a logic one to trigger the EEPROM read. The EEPROM read access takes one instruction, and the requested data is availed.


**CLOCK SYSTEMS AND THEIR DISTRIBUTIONS:**
![[Pasted image 20240503195516.png|500]]
1. **CPU Clock (clkCPU)**:
   - This clock signal is routed to components directly related to the operation of the AVR core, such as the general-purpose register file, status register, and data memory holding the stack pointer.
   - Halting the CPU clock inhibits the core from performing general operations and calculations, effectively pausing the execution of instructions by the CPU.
2. **I/O Clock (clkI/O)**:
   - The I/O clock is used by most I/O modules, including Timer/Counters, SPI, USART, and external interrupts.
3. **Flash Clock (clkFLASH)**:
   - The flash clock controls the operation of the flash memory interface.
   - Typically active simultaneously with the CPU clock, it ensures proper access to flash memory for program execution and data storage.
4. **Asynchronous Timer Clock (clkASY)**:
   - This clock signal allows the asynchronous Timer/Counter to be clocked directly from an external clock or an external 32kHz clock crystal.
   - The dedicated clock domain enables using this Timer/Counter as a real-time counter even when the device is in sleep mode.
5. **ADC Clock (clkADC)**:
   - The ADC (Analog-to-Digital Converter) is provided with its dedicated clock domain.
   - Halting the CPU and I/O clocks reduces noise generated by digital circuitry, leading to more accurate ADC conversion results.
   - This separation ensures that the ADC operates independently of other system clocks, maintaining precision in analog measurements.
![[Pasted image 20240503201625.png]]
![[Pasted image 20240503201711.png]]
if the input clock signal has a frequency of 16 MHz, and the prescaler is set to divide by 64, the output frequency will be 16 MHz / 64 = 250 kHz.

**POWER MANAGEMENT AND SLEEP MODE:**
Sleep modes enable the application to shut down unused modules in the MCU, thereby saving power. There are 6 sleep modes.

Sleep modes in the ATmega328P microcontroller allow the device to enter low-power states while maintaining the ability to wake up quickly in response to specific events. These sleep modes help conserve power in battery-operated or energy-efficient applications. 

1. **Idle Mode (SM2..0 = 000)**:
   - **Description**: Idle mode stops the CPU but allows most peripherals to continue operating.
   - **Peripherals Operating**: SPI, USART, analog comparator, ADC, Two-Wire Serial Interface (TWI), Timer/Counters, watchdog timer, and interrupt system.
   - **Power Consumption**: clkCPU and clkFLASH are halted, but other clocks continue running, leading to moderate power savings.
   - **Wake-Up Sources**: External triggered interrupts, timer overflow interrupts, USART transmit complete interrupts, etc.

2. **ADC Noise Reduction Mode (SM2..0 = 001)**:
   - **Description**: ADC noise reduction mode halts the CPU but allows the ADC, external interrupts, TWI address watch, Timer/Counter2(1), and watchdog timer to continue operating.
   - **Power Consumption**: clkI/O, clkCPU, and clkFLASH are halted, significantly reducing power consumption.
   - **Peripherals Operating**: ADC is operational, enabling higher-resolution measurements in a low-noise environment.
   - **Wake-Up Sources**: External reset, watchdog system reset, watchdog interrupt, brown-out reset, TWI address match, Timer/Counter2 interrupt, etc.

3. **Power-Down Mode (SM2..0 = 010)**:
   - **Description**: Power-down mode stops the external oscillator and halts all generated clocks except for the external interrupts, TWI address watch, and watchdog timer.
   - **Power Consumption**: All clocks are stopped, leading to minimal power consumption.
   - **Wake-Up Sources**: External reset, watchdog system reset, watchdog interrupt, brown-out reset, TWI address match, external level interrupts, pin change interrupt, etc.
   - **Note**: There is a delay between the wake-up condition and the effective wake-up, allowing the clock to restart and stabilize.

4. **Power-Save Mode (SM2..0 = 011)**:
   - **Description**: Power-save mode is similar to power-down mode, but Timer/Counter2 continues running if enabled.
   - **Power Consumption**: All clocks are stopped except for Timer/Counter2, reducing power consumption while allowing periodic wake-ups.
   - **Wake-Up Sources**: Timer/Counter2 overflow or output compare event, external reset, watchdog system reset, etc.
   - **Note**: Timer/Counter2 can be clocked synchronously or asynchronously, and its clock source may be stopped during sleep.

5. **Standby Mode (SM2..0 = 110)**:
   - **Description**: Standby mode is similar to power-down mode, but the external oscillator is kept running.
   - **Power Consumption**: Minimal power consumption with the oscillator running, enabling faster wake-up compared to power-down mode.
   - **Wake-Up Sources**: External reset, watchdog system reset, watchdog interrupt, brown-out reset, TWI address match, external level interrupts, pin change interrupt, etc.

6. **Extended Standby Mode (SM2..0 = 111)**:
   - **Description**: Extended standby mode is similar to power-save mode, but the external oscillator is kept running.
   - **Power Consumption**: Reduced power consumption with the oscillator running, enabling faster wake-up compared to power-save mode.
   - **Wake-Up Sources**: Similar to power-save mode, with additional wake-up sources from external reset, watchdog system reset, etc.
![[Pasted image 20240503205720.png]]
![[Pasted image 20240503205807.png]]

1. **Wake-Up Condition**:
   - The wake-up condition refers to the event or condition that triggers the microcontroller to exit the sleep mode and resume normal operation.
   - This condition can be any predefined event or interrupt that the microcontroller is programmed to respond to, such as an external reset, a watchdog timer expiration, an external interrupt, or a specific internal event.
   - When the wake-up condition occurs, the microcontroller initiates the process of exiting the sleep mode and transitioning to an active state.

2. **Effective Wake-Up**:
   - The effective wake-up refers to the point in time when the microcontroller has fully resumed normal operation after exiting the sleep mode.
   - While the wake-up condition triggers the transition from sleep mode to an active state, there may be a delay before the microcontroller is fully operational and ready to execute instructions.
   - During this delay, the microcontroller's internal clocks need time to restart and stabilize to their nominal frequencies, ensuring that the CPU and peripherals operate reliably.
   - The effective wake-up occurs when the microcontroller's clocks have stabilized, and the device is ready to resume executing code and processing tasks.


**BOD(Brown out detector):**
A Brown-Out Detector (BOD) is a circuitry present in microcontrollers and other electronic devices that monitors the voltage level of the power supply. Its purpose is to prevent the microcontroller from operating improperly or erratically when the supply voltage falls below a certain threshold, which could lead to unpredictable behavior or data corruption.

1. **Voltage Monitoring**: The Brown-Out Detector continuously monitors the voltage level of the power supply provided to the microcontroller.

2. **Threshold Setting**: It is typically configured with a programmable threshold voltage level. When the supply voltage drops below this threshold, indicating a potential brown-out condition, the BOD circuit is triggered.

3. **Reset Generation**: Upon detection of a brown-out condition, the Brown-Out Detector generates a reset signal to the microcontroller. This reset signal causes the microcontroller to reset and enter a known, safe state.

**WATCH DOG TIMERS:**
The WDT is a timer counting cycles of a separate on-chip 128kHz oscillator. The WDT gives an interrupt or a system reset when the counter reaches a given time-out value. A watchdog timer is a device that provides a reset output if it has not received a periodic pulse signal from a processor within a specific time frame. monitors microcontroller to see if they are out of control.
Features:
- Clocked from separate on-chip oscillator
- 3 operating modes
  - Interrupt
  - System reset
  - Interrupt and system reset
- Selectable time-out period from 16ms to 8s

INTERRUPT MODE:
- In interrupt mode, the WDT gives an interrupt when the timer expires. This interrupt can be used to wake the device from sleep-modes, and also as a general system timer.
SYSTEM RESET MODE:
- the WDT gives a reset when the timer expires. This is typically used to prevent system hang-up in case of runaway code
INTERRUPT AND RESET MODE:
- Interrupt and system reset mode, combines the other two modes by first giving an interrupt and then switch to system reset mode. This mode will for instance allow a safe shutdown

![[Pasted image 20240503215338.png|600]]

control register for WDT:
![[Pasted image 20240503220103.png]]
Bit 7 - WDIF: Watchdog Interrupt Flag This bit is set when a time-out occurs in the watchdog timer and the watchdog timer is configured for interrupt.
Bit 6 - WDIE: Watchdog Interrupt Enable When this bit is written to one and the I-bit in the status register is set, the watchdog interrupt is enabled.
Bit 4 - WDCE: Watchdog Change Enable This bit is used in timed sequences for changing WDE and prescaler bits.
Bit 3 - WDE: Watchdog System Reset Enable WDE is overridden by WDRF in MCUSR. This means that WDE is always set when WDRF is set
Bit 5, 2..0 - WDP3..0: Watchdog Timer Prescaler 3, 2, 1 and 0 The WDP3..0 bits determine the watchdog timer prescaling when the watchdog timer is running
![[Pasted image 20240503220648.png]]

[[DEBUGGING]]

DebugWire is a debugging interface used in Atmel AVR microcontrollers, including the ATmega328P. It allows for real-time, on-chip debugging of AVR microcontrollers. 

The ATmega328P is commonly used in Arduino boards, and DebugWire can be utilized for troubleshooting and debugging purposes during software development. It enables developers to observe the behavior of their code on the microcontroller in real-time, helping them identify and fix issues more efficiently.

The use of two pins for DebugWire communication in AVR microcontrollers like the ATmega328P is a design choice made by Atmel (now Microchip Technology) to balance functionality and simplicity.

1. **RESET Pin (PC6)**:
   - The RESET pin serves as the primary means of communication during DebugWire operation.
   - By repurposing the RESET pin for communication, DebugWire is able to establish a connection with the microcontroller without requiring additional dedicated communication pins, thereby keeping the pin count low.

2. **PB3 (DebugWire Data pin)**:
   - PB3 is dedicated as the DebugWire Data pin, which handles bidirectional communication between the debugger and the microcontroller during DebugWire operation.
   - Having a separate pin for data communication allows for efficient and reliable exchange of debugging information between the debugger and the microcontroller.
   - By using PB3 for DebugWire communication, it keeps the RESET pin available exclusively for its role in the DebugWire protocol, ensuring that there is no conflict between communication and other functions associated with the RESET pin during debugging operations.
