STM32Nucleo-F401RE -Clock config
![[Pasted image 20240608102632.png]]

There are four primary clock sources

LSI : Low Speed Internal  
LSE : Low Speed External  
HSI : High Speed Internal  
HSE : High Speed External

1. **HSE (High-Speed External) Oscillator**:
   - An external clock source, typically a crystal or resonator, connected to the microcontroller's HSE pins.
   - Frequency range: Typically 4 MHz to 26 MHz, commonly 8 MHz

2. **LSE (Low-Speed External) Oscillator**:
   - An external low-frequency crystal oscillator, usually used for the Real-Time Clock (RTC).
   - Frequency: 32.768 kHz.

3. **HSI (High-Speed Internal) Oscillator**:
   - An internal RC oscillator.
   - Frequency: 16 MHz
   - Often used as the default clock source after reset and can also be used as an input to the PLL.

4. **LSI (Low-Speed Internal) Oscillator**:
   - An internal low-frequency RC oscillator.
   - Frequency: Approximately 32 kHz.
   - Used for the Independent Watchdog (IWDG) and can also be used for the RTC.

These oscillators can be selected and configured via the RCC (Reset and Clock Control) registers to provide the clock sources for the system and peripherals. 

### SYSTEM CLOCK ###
The First Part we need to configure is **SYSCLOCK** which is the system clock at which the microcontroller runs. It can be chosen using system clock MUX
![[Pasted image 20240608104911.png]]

3:1 MUX
![[Pasted image 20240608105805.png|200]] ![[Pasted image 20240608105917.png|300]]

The System Clock Mux in the STM32 clock configuration diagram is responsible for selecting the main clock source for the system. This clock source drives the core, memory, and most of the peripherals. 
### Clock Sources Options:

1. **HSI (High-Speed Internal) Oscillator**:
   - An internal 16 MHz RC oscillator.
   - Used for applications that do not require high precision and can tolerate some frequency variation.
   - default clock source.

2. **HSE (High-Speed External) Oscillator**:
   - An external clock source, typically provided by a crystal oscillator, resonator, or external clock signal.
   - Provides high precision and stability.
   - Commonly used when accurate timing is crucial.
   - Before the HSE can be used as the system clock source, it must be enabled and stabilized.
   - The "Enable C" line from HSE indicates the necessary enablement and readiness check before the HSE can be selected as the system clock source.

3. **PLLCLK (Phase-Locked Loop Clock)**:
   - Derived from the PLL, which can use HSI or HSE as its input.
   - The PLL multiplies and divides the input frequency to achieve a desired higher frequency.
   - Used when a high-speed clock is required.

### PLL(PHASE LOCKED LOOP)###
![[Pasted image 20240608195530.png]]

A Phase-Locked Loop (PLL) is an electronic control system that generates an output signal whose phase is related to the phase of an input signal. PLLs are widely used in radio, telecommunications, computers, and other electronic applications for purposes such as frequency synthesis, clock generation and frequency multiplier.

#### Key Components of a PLL

1. **Phase Detector (PD) or Phase Comparator**:
   - Compares the phase of the input signal with the phase of the feedback signal.
   - Produces an error voltage (Ve) that is proportional to the phase difference between these two signals.

2. **Low-Pass Filter (LPF)**:
   - Filters the error voltage to remove high-frequency noise components.
   - Provides a smooth DC voltage proportional to the phase error.

3. **Voltage-Controlled Oscillator (VCO)**:
   - Generates an output signal whose frequency is controlled by the input voltage.
   - The frequency of the VCO output is adjusted to reduce the phase difference between the input and feedback signals.

4. **Frequency Divider (Optional)**:
   - Often included in the feedback loop to divide the VCO output frequency by a factor (N).
   - Used to achieve frequency multiplication and other applications.

#### How a PLL Works

1. **Phase Comparison**:
   - The phase detector compares the phase of the reference input signal  with the feedback signal from the VCO.
   - The phase detector output is a voltage representing the phase difference between these signals.
2. **Error Signal Filtering**:
   - The error signal  passes through a low-pass filter.
   - The low-pass filter smooths the error signal, removing high-frequency components and providing a clean DC signal.
3. **Frequency Adjustment**:
   - The filtered error signal is fed into the VCO.
   - The VCO adjusts its output frequency  based on the error voltage.
   - As the VCO frequency changes, the phase difference reduces, and the PLL locks onto the input signal's phase.
4. **Feedback Loop**:
   - The VCO output is fed back to the phase detector, often through a frequency divider.
   - This feedback ensures the VCO output frequency remains locked to the reference input frequency.

### Applications of PLL
1. **Frequency Synthesis**:
2. **Clock Generation and Distribution**:
3. **Modulation and Demodulation**:
4. **Frequency Multiplication and Division**:

![[Pasted image 20240608195603.png]]

**STEP 1:**
- The selected input clock (HSI in this case) is divided by the prescaler value M before it is fed into the PLL.
- Example: If HSI (16 MHz) is divided by 16, the resulting frequency is 1 MHz
- This division helps in achieving the desired frequency range for the PLL input.
**STEP2:**
- The divided input clock is then multiplied by the multiplier value N within the PLL.
- Example: If the 1 MHz input is multiplied by 336, the resulting frequency is 336 MHz
- This step is crucial for achieving higher clock frequencies.
**STEP3:**
- The high-frequency VCO (Voltage Controlled Oscillator) output is divided down by P and Q to generate the desired system clock and peripheral clock frequencies.
- P typically sets the main system clock frequency, and Q is used for specific peripheral clocks like USB, I2S, etc.
- Example: If 336 MHz is divided by 4, the resulting system clock frequency is 84 MHz

### Advanced Peripheral Buses (APB) and Advanced High-Performance Buses(AHB): ###

- **AHB**: Often connects the core processor, high-speed memory interfaces (like Flash and RAM), and DMA controllers.
- **APB**: Used to connect peripheral devices such as timers, serial communication interfaces (USART, I2C, SPI), and analog peripherals (ADCs, DACs).
STM32F4xx.
![[Pasted image 20240608214258.png|800]]

A Direct Memory Access (DMA) controller is a hardware component that allows peripherals within a computer system to directly access the system memory for reading and writing independently of the CPU. This capability significantly enhances the performance and efficiency of the system by offloading the burden of memory operations from the CPU, allowing it to perform other tasks.

**Data Transfer Without DMA**:
- **Setup**: The CPU sets up the peripheral to start the data transfer (e.g., configuring UART to receive data).
- **Polling/Interrupts**: The CPU either polls the peripheral's status registers or handles interrupts to check if data is available.
- **Data Handling**: Upon detecting data availability, the CPU reads the data from the peripheral register and writes it to the memory location.
- **Repeat**: This process repeats for every piece of data, causing the CPU to be heavily involved in the data transfer process.
**Data Transfer with DMA**:
- **Setup**: The CPU configures the DMA controller with the source (peripheral register), destination (memory address), and transfer size.
- **Trigger**: The peripheral triggers the DMA controller when data is available.
- **Data Transfer**: The DMA controller autonomously handles the data transfer from the peripheral to the memory.
- **Completion**: Once the transfer is complete, the DMA controller can generate an interrupt to notify the CPU.

### SysTick Timer/system clock timer
1. **Purpose**:
    - Designed primarily for providing periodic interrupts for task scheduling and timekeeping.
2. **Integration**:
    - Integrated directly into the ARM Cortex-M core, making it a standardized and readily available feature across all Cortex-M microcontrollers.
3. **Simplicity**:
    - Simple to configure and use with only a few registers.
    - Limited to a 24-bit down counter, making it straightforward for basic timing functions.

### FCLK (Free-running Clock)
1. **Definition**:
    - FCLK is the primary clock signal that drives the Cortex-M CPU core, including its internal logic and operations.
2. **Purpose**:
    - It ensures the core runs at a consistent clock frequency, which is crucial for the timing and execution of instructions.