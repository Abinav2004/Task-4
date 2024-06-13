
**Maskable Interrupts:**  An Interrupt that can be disabled or ignored by the instructions of CPU are called as Maskable Interrupt. The interrupts are either edge-triggered or level-triggered .
**Non-Maskable Interrupt :** An interrupt that cannot be disabled or ignored by the instructions of CPU are called as Non-Maskable Interrupt. A Non-maskable interrupt is often used when response time is critical or when an interrupt should never be disable during normal system operation. Such uses include reporting non-recoverable hardware errors, system debugging and profiling and handling of species cases like system resets.
Polling involves continually checking the status of a device, while interrupts allow devices to signal when an event needs immediate attention.

Interrupts in the AVR architecture, including on the ATmega328P microcontroller, are essential for handling time-sensitive events or external signals without delaying the main program execution. 
1. **Interrupt Sources**:
   - Interrupts can be triggered by various events, such as external signals, timer overflows, or specific conditions within the microcontroller.
   - Each interrupt source has a dedicated program vector in the program memory space, allowing the microcontroller to jump to specific interrupt handling routines when an interrupt occurs.
2. **Interrupt Enable Bits**:
   - Each interrupt source has an individual enable bit that must be set, along with the global interrupt enable bit (I-bit) in the Status Register, to enable the interrupt.
   - This enables flexibility in enabling or disabling specific interrupts based on application requirements.
3. **Interrupt Vector Priority**:
   - Interrupt vectors are assigned addresses in the program memory space, with lower addresses corresponding to higher priority interrupts.
   - the RESET interrupt has the highest priority, followed by other interrupts such as external interrupts (e.g., INT0).
4. **Interrupt Vector Location**:
   - By default, interrupt vectors are located at the lowest addresses in the program memory space.
   - The Interrupt Vector Select (IVSEL) bit in the MCU Control Register (MCUCR) can be used to move the interrupt vectors to the start of the boot flash section, providing flexibility in memory organization.
5. **Interrupt Handling**:
   - When an interrupt occurs, the global interrupt enable bit (I-bit) is cleared, and all interrupts are disabled.
   - The microcontroller jumps to the corresponding interrupt vector to execute the interrupt handling routine.
   - Nested interrupts can be enabled by setting the I-bit within the interrupt handling routine, allowing higher-priority interrupts to interrupt lower-priority ones.
6. **Types of Interrupts**:
   - There are two types of interrupts: flag-based interrupts and level-triggered interrupts.
   - Flag-based interrupts are triggered by an event that sets the interrupt flag. The microcontroller automatically clears the flag and jumps to the corresponding interrupt vector.
   - Level-triggered interrupts trigger as long as the interrupt condition is present. These interrupts do not necessarily have interrupt flags.
7. **Interrupt Return**:
   - After servicing an interrupt, the microcontroller returns to the main program and executes one more instruction before handling any pending interrupts.

 **Note:** a program vector refers to a specific memory address in the program memory space where the microcontroller jumps to execute a particular routine or function when an interrupt occurs. A program vector serves as an index or pointer to a specific location in the program memory where the microcontroller knows to find the instructions for handling a particular event.

**_NOTE:_** reset is the highest priority interrupt in a microcontroller and there are only two external interrupts because every does not have a compare registers,

Interrupts are pretty well what the name implies, a method of interrupting the execution of a program in order to take care of something else.

In its basic form, an interrupt works like this:
- A program is running.
- An interrupt occurs.
- The program is paused, and its data is put aside so that it can resume later.
- The code related to the interrupt is run.
- When the interrupt code has finished, the program resumes where it left off.

They can all be divided broadly into two categories:
- **Hardware Interrupts** **–** These usually come from external signals.
- **Software Interrupts** – These are internal signals, usually controlled by timers .

The Arduino Uno supports three types of interrupts:
- **Hardware Interrupts** – External interrupt signals on specific pins.
- **Pin Change Interrupts** – External interrupts on any pin, grouped into ports.
- **Timer Interrupts** – Internal timer-generated interrupts, manipulated in software.

![[Pasted image 20240501092015.png|500]]
code execution branches out of the Loop and to the ISR(Interrupt Service Routine). Once the ISR code is finished, the code execution is back at the Loop, in the same place that it branched off
**NOTE:**
The primary difference between register and memory is that register holds the data that the CPU is currently processing whereas, the memory holds the data the that will be required for processing
## HARDWARE INTERRUPTS ##
Hardware interrupts are external interrupts, and on most Arduino models are limited to specific pins.  These pins are configured as inputs and can trigger hardware interrupts by manipulating their logic state.
It contains two hardware interrupt pins(Digital Pins):
- **Pin 2** – Interrupt vector 0
- **Pin 3** – Interrupt vector 1
In Arduino, an interrupt vector refers to a specific memory location that holds the address of the interrupt service routine (ISR). When an interrupt occurs, the microcontroller jumps to this address to execute the ISR. It's called a vector because it points to a specific location in memory, indicating where the microcontroller should go to handle the interrupt.

Function used in Arduino to work on interrupts:

**attachInterrupt Function**:
![[Pasted image 20240501093135.png]]

This function has the following syntax and parameters:
- **Interrupt Vector** – the interrupt that you wish to use. Note that this is the internal Interrupt Vector number and NOT the pin number.
- **ISR** – The name of the Interrupt Service Routine function that you are gluing to the interrupt.
- **Mode** – How you want to trigger the interrupt.
For Mode, there are four selections:
- **RISING** – Triggers when an input goes from LOW to HIGH.
- **FALLING** – Triggers when an input goes from HIGH to LOW.
- **LOW** – Triggered when the input stays LOW.
- **CHANGE** – Triggers whenever the input changes state from HIGH to LOW or LOW to HIGH.

The Interrupt Vector parameter in the **attachInterrupt** function is not the same as the pin number, and it can vary between Arduino boards. A (better) way of obtaining this number is with the **digitalPinToInterrupt** function.

the function is modified as:
**attachInterrupt(digitalPinToInterrupt(pin),ISR,Mode)**

## Pin Change Interrupts ##
Pin Change Interrupts are another form of a hardware interrupt. Unlike the interrupts we have just used, they are not restricted to specific pins, all the pins can be used for Pin Change Interrupts.
Pin Change Interrupts are restricted, as their name might imply, to only monitoring a CHANGE of logic state.
24 Pin Change Interrupts.
![[Pasted image 20240501094127.png|450]]
![[Pasted image 20240501094159.png|450]]
![[Pasted image 20240501094231.png|400]]

In order to use Pin Change Interrupts, you’ll need to do the following:
- Determine which pin(s) that you want to use.  This will also tell you which port(s) you’ll need to use.
- Enable the port(s) that you need.
- Enable the pin(s) within that port that must be enabled for interrupts.
- Edit the appropriate Interrupt Service Routine(s). If you are using more than one pin on the same port, then the ISR will need to be able to determine which pin caused the interrupt
**Select the port:**
![[Pasted image 20240501094809.png]]
enable the port you need.

select the pins you need:
![[Pasted image 20240501094935.png|500]]

ISR:
![[Pasted image 20240501095117.png|400]]

## Timer Interrupts##
 these interrupts are generated in software, and their timing is based upon the Arduino Uno’s 16 MHz clock oscillator.

#### Arduino Uno has 3 timers ####
![[Pasted image 20240501095606.png|400]]
The value in these timers is incremented by either the clock frequency or a fraction of it. we can use software to determine the count you wish to set the interrupt to trigger at, we can also trigger an interrupt when the timer overflows.

To slow down the clock signal, the ATmega328 has a “Prescaler”, essentially a divider for the clock frequency. The Prescaler can divide the clock down to a more manageable lower frequency, 
![[Pasted image 20240501095824.png|400]]

Each timer has three Clock Select Bits(LEAST 3 SIGNIFICANT BITS):
![[Pasted image 20240501095953.png|400]]
![[Pasted image 20240501100054.png|400]]
![[Pasted image 20240501100209.png|400]]

Timer Interrupts can be operated in a couple of different modes, including **Compare Match Mode and Overflow Mode and input capture mode.**

In Compare Match Mode, you place a counter value into a Compare Match Register. The timer interrupt is generated when the timer counter matches the value in that register.

In Overflow Mode the timer interrupt is generated when the timer reaches the end of its count, an interrupt is generated and the timer resets to zero and begins counting again.

In Input capture mode which is on Arduino uno can be implemented on timer1.In this case the timer could store its value in different register each time an external event happens on the Arduino pins. 

**ISR for Timer interrupts:**
![[Pasted image 20240501100437.png|500]]
![[Pasted image 20240526112051.png|400]]


The Timer-associated registers are as follows:

- **TCCRxA**: Timer/Counter Control Register A.
- **TCCRxB**: Timer/Counter Control Register B.
- **TCNTx**: Timer/Counter Registers.
- **OCRxA**: Output Compare A Register.
- **OCRxB**: Output Compare B Register.
- **TMISKx**: Timer Interrupts Mask Register, enable/disable timer interrupts.
- **TIFRx**: Timer interrupts Flag Bits Register, read/clear timer interrupt flag bits.
Where **x** can be 0, 1, or 2 for timers (Timer0, Timer1, and Timer2) respectively.
1. **TCCRxA (Timer/Counter Control Register A)**:
   - This register controls the operation of Timer/Counter unit A. It typically includes settings related to the waveform generation mode, such as Fast PWM, Phase Correct PWM, or CTC (Clear Timer on Compare Match) mode.
2. **TCCRxB (Timer/Counter Control Register B)**:
   - Similar to TCCRxA, this register controls the operation of Timer/Counter unit B. It often includes settings related to the clock source selection (like internal clock, external clock, or prescaler settings), and sometimes additional settings depending on the specific microcontroller.
3. **TCNTx (Timer/Counter Registers)**:
   - These are the Timer/Counter registers themselves. They store the current count value of the respective timer/counter unit (x denotes the specific timer/counter, like A or B). This value increments or decrements based on the timer's clock source and mode of operation.
4. **OCRxA (Output Compare A Register)**:
   - This register is used to set the value at which Timer/Counter A will generate an output compare match interrupt or trigger an action, depending on the operating mode. When the TCNTx matches the value in OCRxA, it can trigger an interrupt or toggle an output pin, among other actions.
5. **OCRxB (Output Compare B Register)**:
   - Similar to OCRxA, this register is used to set the compare value for Timer/Counter B. It determines when the Timer/Counter B will generate an output compare match interrupt or trigger an action.
6. **TMISKx (Timer Interrupts Mask Register)**:
   - This register is used to enable or disable specific timer interrupts. By setting or clearing bits in this register, you can choose which timer-related interrupts are allowed to trigger the CPU.
7. **TIFRx (Timer Interrupts Flag Bits Register)**:
   - This register contains flag bits that indicate whether specific timer-related interrupts have occurred. Typically, reading from this register allows the CPU to check if a timer-related event has happened, and writing to certain bits can clear these flags.
![[Pasted image 20240503200705.png|600]]

### COUNTER MODE ###
The timer module in counter mode is configured to have an external pin as the clock source with multiple prescaler options. It’s generally used to count external input pulses or measure an input signal by counting its rising or falling edges over a fixed time interval.

To set an Arduino Timer module to operate in counter mode, we’ll use the clock selection bits in the **TCCRxB** register.
![[Pasted image 20240501102607.png]]

APPLICATIONS:
- Pulse counting
- frequency measurement-by counting the pulses over a period of time we can find the frequency of a particular input signal.
- can be use as an additional interrupt:
  set the time in counter mode and preload the timer counter register with the maximum value (255 or 65535) depending on the timer resolution. Now, the timer module is on the edge of overflow, one RISING or FALLING edge on the Tn pin, and an OVF interrupt will be fired.
## TIMERS ##
These are like clocks which is used to and could be used to measure time events, toggle interrupts and generate delays.
A timer in a microprocessor or microcontroller is a hardware device that counts clock pulses to measure time intervals or generate specific time delays. Timers can be used in a variety of applications such as generating precise time delays, counting events, and generating pulse-width modulation (PWM) signals. The timer continues to run in the background even when the Interrupt Service Routine (ISR) is being executed. The hardware timer itself is independent of the CPU's main execution flow, so it keeps counting clock pulses regardless of what code the CPU is currently running, including during an ISR.
Timers in microcontrollers and microprocessors can be categorized into two types: hardware timers and software timers. Both types are used to measure time intervals, create delays, or schedule events, but they operate in fundamentally different ways.
technically there is no background the clock is always on and the timer comes into play wheneer called

### Hardware Timers

#### Characteristics:
1. **Dedicated Hardware**: Hardware timers are dedicated peripherals within the microcontroller. They operate independently of the main CPU.
2. **Precision and Reliability**: They are generally more precise and reliable than software timers because they count clock cycles directly and are not affected by CPU load.
3. **Interrupts**: Hardware timers can generate interrupts at specific intervals, allowing the CPU to execute particular tasks at precise times.
4. **Multiple Modes**: Hardware timers support various modes like one-shot, periodic, PWM generation, input capture, and output compare.

#### Applications:
- **PWM Generation**: For controlling motors, LEDs, and other devices that require precise timing.
- **Event Counting**: Counting external events or pulses.
- **Periodic Tasks**: Generating periodic interrupts for tasks like sensor readings or timekeeping.
### Software Timers

#### Characteristics:
1. **Implemented in Software**: Software timers are created using code and depend on the main CPU's execution to measure time. It is implemented using loops.
2. **Dependent on CPU Load**: They are less precise than hardware timers because their accuracy can be affected by the CPU's workload and the execution of other tasks.
3. **Flexibility**: Easier to implement for simple timing needs without requiring additional hardware configuration.
4. **Use of System Time Functions**: Often rely on system time functions like `millis()` or `micros()` in Arduino to measure elapsed time.
#### Applications:
- **Simple Delays**: Creating non-blocking delays in the program.
- **Timing Out Events**: Implementing timeouts for operations like waiting for user input or communication responses.
### Comparison

| Feature             | Hardware Timers                          | Software Timers                          |
|---------------------|------------------------------------------|------------------------------------------|
| Implementation      | Dedicated hardware peripherals           | Implemented in code using system time    |
| Precision           | High precision (independent of CPU load) | Lower precision (affected by CPU load)   |
| CPU Load            | Operates independently of CPU            | Consumes CPU cycles                      |
| Interrupts          | Can generate hardware interrupts         | Typically uses polling or software interrupts |
| Flexibility         | Requires hardware configuration          | Easy to implement for simple tasks       |
| Use Cases           | PWM, event counting, precise periodic tasks | Simple delays, event timeouts            |

### Key Functions of Timers

1. **Time Delay Generation**: Timers can generate precise time delays by counting clock pulses. Once a set number of pulses are counted, the timer can trigger an interrupt or set a flag.
2. **Event Counting**: Timers can count external events such as pulses from a sensor. This is useful in applications like frequency measurement or event logging.
3. **Pulse Width Modulation (PWM)**: Timers can generate PWM signals, which are used in applications like motor control, dimming LEDs, and communication protocols.
4. **Real-Time Clock (RTC)**: Timers can be used to implement a real-time clock, keeping track of actual time and date.
### Types of Timers

1. **Watchdog Timer**: This type of timer is used to reset the system if the software fails to operate correctly within a specified time frame, providing a safety mechanism against software crashes.
2. **Interval Timer**: This timer generates interrupts at regular intervals, useful for periodic tasks such as refreshing a display or sampling a sensor.
3. **Counter**: Functions as a simple counter to count external events.
### Timer Modes

1. **Up Counter**: Counts from zero up to a predefined value.
2. **Down Counter**: Counts down from a predefined value to zero.
3. **Up/Down Counter**: Can count both up and down, often used in PWM generation for symmetrical signals.
### Implementation in Microcontrollers

- **Registers**: Timers typically use several special function registers (SFRs) to configure and control their operation. These registers may include a control register to start/stop the timer, a count register to set the initial count value, and a status register to check if the timer has overflowed or completed its count.
- **Interrupts**: Timers can be configured to generate interrupts when they overflow or reach a specific count value. This allows the microcontroller to execute a specific piece of code in response to the timer event.

A timer in a microprocessor or microcontroller typically continues running even after an interrupt is generated, unless specifically configured to stop. The behavior of the timer upon generating an interrupt depends on its configuration and the specific requirements of the application. 
### Continuous Operation

1. **Free-Running Mode**: In this mode, the timer continues counting indefinitely. When it overflows or reaches a preset value, it generates an interrupt, but then it resets and starts counting again. This mode is useful for generating periodic interrupts.
### One-Shot Operation

2. **One-Shot Mode**: In this mode, the timer stops counting after it generates an interrupt. It requires a specific command to start counting again. This mode is useful for generating a single delay or timeout.
### Auto-Reload Operation

3. **Auto-Reload Mode**: The timer reloads a predefined value and continues counting after an interrupt. This is often used for creating repetitive timing intervals, such as in PWM generation or periodic tasks.

### Configurations in Microcontrollers

Different microcontrollers have various ways to configure these behaviors:
- **Configuration Registers**: Most microcontrollers have special registers to configure timer behavior, such as enabling/disabling the timer, setting the mode (one-shot, continuous, etc.), and configuring auto-reload values.
- **Interrupt Service Routine (ISR)**: When a timer interrupt occurs, the ISR can be designed to either handle the timer overflow or perform tasks like stopping the timer or reloading it with a new value.

### How It Works ###
1. **Timer Counting**: The hardware timer counts clock cycles according to its configuration (e.g., with a specific prescaler).
2. **Interrupt Generation**: When the timer reaches a certain count (e.g., an overflow or a compare match), it generates an interrupt.
3. **ISR Execution**: The interrupt signals the CPU to execute the ISR associated with that timer interrupt. The ISR is a special function that runs in response to the interrupt.
4. **Background Operation**: While the ISR is being executed, the hardware timer continues to count in the background. The timer's registers are still being updated with each clock pulse.




![[Pasted image 20240526111140.png|400]]
 The pre-scalar divides the number of pulses from the system clock from the specified amount
 ![[Pasted image 20240526111649.png|400]]
 if the input signal is 16MHz from the system clock , the output after the pre-scalar will be 8 times slower ,that is after 8 pulses of input signal the output signal is considered as 1.
![[Pasted image 20240526111945.png|400]]
### Free-Running Mode
#### Characteristics:
1. **Continuous Counting**: In free-running mode, the timer starts counting from an initial value (usually zero) and continues to count until it reaches its maximum value (e.g., 255 for an 8-bit timer, 65535 for a 16-bit timer).
2. **Wrap Around**: Once the timer reaches its maximum value, it wraps around to zero and continues counting. This cycle repeats indefinitely.
3. **Uninterrupted Operation**: The timer does not reset or reload; it simply continues counting in a loop.
#### Applications:
- **Timekeeping**: Maintaining a continuous count that can be used to measure elapsed time.
- **Frequency Measurement**: Counting the number of events (e.g., clock pulses) over a period to measure frequency.
### Auto-Reload Mode (CTC Mode in AVR)

#### Characteristics:
1. **Predefined Period**: In auto-reload mode, also known as Clear Timer on Compare Match (CTC) mode in AVR microcontrollers, the timer counts up to a predefined value set in a compare register.
2. **Reset and Reload**: When the timer reaches the compare value, it resets to zero and starts counting again from the beginning.
3. **Interrupt Generation**: The timer can generate an interrupt each time it resets, making it useful for generating periodic events.
#### Applications:
- **Periodic Interrupts**: Generating regular interrupts for tasks like updating displays or reading sensors at fixed intervals.
- **PWM Generation**: Producing precise pulse-width modulation signals.


## Difference between Timers and Counters ##

### Timers:
- **Primary Function**: Measure time intervals or generate time delays.
- **Source of Pulses**: Internal clock of the microcontroller or an external clock source.
- **Usage**: Typically used for tasks like generating periodic interrupts, creating delays, and measuring time between events. For instance, a timer can be used to blink an LED at a precise interval or to generate PWM signals.
- **Configuration**: Timers are often configured to count the internal clock cycles, which are derived from the system clock, making them ideal for precise time measurements and delay generation.
### Counters:
- **Primary Function**: Count external events or pulses.
- **Source of Pulses**: External sources like sensor outputs, user inputs, or any other external events.
- **Usage**: Used to count occurrences of external events, such as counting the number of rotations of a wheel, number of items passing on a conveyor belt, or user button presses.
- **Configuration**: Counters are configured to increment their count based on external signals applied to a specific input pin.
### Why Both?
Even though timers can count external clock pulses, having dedicated counters is advantageous because it allows:
1. **Separation of Concerns**: Timers can continue to manage time-based functions, while counters handle event counting independently, avoiding resource conflicts.
2. **Specialization**: Counters are often optimized for handling noisy signals and may include features like digital filtering or debounce mechanisms to ensure accurate counting of external events.
3. **Flexibility**: Using both allows more complex applications where both precise timing and external event counting are needed simultaneously.
### Example Use Cases:

- **Timer**: Generating a 1-second delay using a timer configured to count internal clock cycles (e.g., with a 1 MHz clock, counting 1,000,000 cycles).
- **Counter**: Counting the number of cars passing a point using an external sensor that generates a pulse for each car.

### INTERRUPT CONTROLLERS ###
### Two-Level Interrupt Controller: An Explanation from Scratch

A two-level interrupt controller is a mechanism used in microcontrollers and processors to efficiently manage multiple interrupt sources and prioritize them. Interrupts are signals that inform the processor of an event that needs immediate attention, allowing it to temporarily halt its current operations, handle the event, and then resume normal processing.

### Basic Concepts

1. **Interrupts**:
   - **Interrupt Request (IRQ)**: A signal sent to the processor to indicate an event that needs immediate attention.
   - **Interrupt Service Routine (ISR)**: A special function that executes when an interrupt is serviced.

2. **Interrupt Controller**:
   - **Single-Level**: Manages interrupts by enabling or disabling them and prioritizing which one should be handled first.
   - **Two-Level**: Adds another layer to the interrupt handling mechanism, allowing for more complex and efficient prioritization.

### Two-Level Interrupt Controller

A two-level interrupt controller consists of two main components:

1. **Primary Interrupt Controller**: The first level that receives interrupt requests from various sources.
2. **Secondary Interrupt Controllers**: The second level that receives interrupt requests from the primary controller and further prioritizes them.

#### Working Mechanism

1. **Interrupt Generation**:
   - Various peripherals and devices generate interrupts. Each interrupt source is connected to the primary interrupt controller.
2. **Primary Interrupt Controller**:
   - Receives all incoming interrupt requests.
   - Performs an initial prioritization and routing of interrupts to the appropriate secondary interrupt controller.
3. **Secondary Interrupt Controllers**:
   - Each secondary controller handles a subset of interrupts.
   - Provides more refined prioritization and handling of interrupts within its subset.
4. **Processor Handling**:
   - The highest-priority interrupt is forwarded to the processor.
   - The processor suspends its current tasks, saves the context, and executes the ISR associated with the interrupt.
   - After handling the interrupt, the processor restores the context and resumes normal operation.


### FIQ AND IRQ ###
FIQ (Fast Interrupt Request) and IRQ (Interrupt Request) are two types of interrupts with different purposes and handling mechanisms. Here are the key differences between FIQ and IRQ interrupts:

1. **Priority:** FIQ has a higher priority than IRQ. When an FIQ occurs, it can preempt the handling of an IRQ. This means that if both an FIQ and an IRQ are pending at the same time, the processor will service the FIQ first.
2. **Number of Interrupt Lines:** Typically, there is only one FIQ line in ARM-based systems, while there can be multiple IRQ lines. The presence of multiple IRQ lines allows for a wider range of devices to send interrupt requests.
3. **Handling Mechanism:** FIQ interrupts have a dedicated set of registers for handling the interrupt, separate from the registers used for IRQ interrupts. This separation allows for faster handling of FIQ interrupts as they do not need to save as much context before handling the interrupt.
4. **Context Switching:** When an interrupt occurs, the processor needs to save the current context (registers, program counter, etc.) before handling the interrupt. FIQ interrupts have a smaller context to save compared to IRQ interrupts, which contributes to their faster handling.
5. **Use Cases:** FIQ interrupts are typically used for critical, time-sensitive tasks that require immediate attention and minimal latency, such as real-time processing in embedded systems. On the other hand, IRQ interrupts are more commonly used for general-purpose interrupt handling.
 the main differences between FIQ and IRQ interrupts lie in their priority, handling mechanisms, context switching requirements, and typical use cases. FIQ interrupts have a higher priority, faster handling mechanism, and are suited for time-critical tasks, while IRQ interrupts are more general-purpose and can handle a wider range of devices.