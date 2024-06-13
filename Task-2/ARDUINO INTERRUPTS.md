## PROBLEM STATEMENT ##

create a circuit using Arduino that contains two LEDs 
1. toggle all time with a delay of 500ms
2. toggle for a time period of 200ms when interrupted by a push button (mode used: RISING) 


## SOLUTION: ##
![[Pasted image 20240523173950.png]]
![[Pasted image 20240523174023.png|600]]
**logical errors possible in this code:** 
- you should not use ISR to change the state in this code, like used above.
- reasons for why we should not use delay function inside the ISR:
  - Interrupt Service Routines often need to be executed quickly to respond to time-sensitive events. If a delay function is called inside an ISR, it may hold off lower-priority tasks from executing, causing priority inversion issues where higher-priority tasks are delayed by lower-priority ones.
  - ISR_B has a lower priority than ISR_A, ISR_A should ideally complete its execution before ISR_B is serviced. However, because ISR_B is blocked by the delay function, ISR_A may be forced to wait for ISR_B to finish, causing priority inversion.
  - timers typically continue to run in the background even when an ISR (Interrupt Service Routine) is being executed. This behavior allows timers to keep track of time or count pulses independently of the processor's current task.

  1.  Initially, the LED starts toggling every 100 milliseconds as expected because the ISR toggles the LED state without any delay.
  2. As soon as the `delay(50)` function is added inside the ISR, the behavior changes. Now, the ISR takes an additional 50 milliseconds to execute due to the delay, effectively reducing the time available between consecutive interrupts.
  3. If the delay (50 milliseconds) exceeds half of the timer period (100 milliseconds), it's possible for the timer to overflow while the ISR is still executing. This situation leads to a missed timer overflow interrupt, and the LED toggling becomes out of sync with the intended 100-millisecond period.
  4. Over time, the timing inaccuracies introduced by the delay inside the ISR can accumulate, leading to further drift and instability in the system's timing behavior.

In summary, introducing delays inside ISRs can disrupt the timing behavior of the system, especially when they exceed significant portions of the timer period, leading to missed interrupts and timing inaccuracies. It's essential to minimize or avoid such delays within ISRs to maintain precise timing and ensure the reliability of embedded systems.
### FUNCTION USED: ###
1. pinMode(pin, mode)
   - Configures the specified pin to behave either as an input or an output.
   - Mode: INPUT, OUTPUT OR INPUT_PULLUP
3. **INPUT:**
   **Default Input Configuration**: Arduino pins using Atmega microcontrollers default to inputs. This means they are ready to read signals without needing to explicitly set them up as inputs using pinMode()
  
   **High-Impedance State**: When configured as inputs, Arduino pins enter a high-impedance state. This state presents minimal load to the circuit being sampled.
   
	**Minimal Current Demands**: Input pins have very low current requirements. It's as if there's a large resistor (approximately 100 megohms) in series with the pin, making it sensitive to small changes in voltage.
	
	**Potential Issues**:
	- **Electrical Noise**: Pins left unconnected or connected to wires not attached to other circuits can pick up electrical noise from the environment. This can lead to seemingly random changes in the pin state.
	- **[[capacitive coupling]]**: Nearby pins or circuits can influence the state of an input pin through capacitive coupling. This can also result in erratic behavior if not properly accounted for in the circuit design.

3. **OUTPUT**:  Pins configured as OUTPUT with pinMode() are said to be in a low-impedance state. This means that they can provide a substantial amount of current to other circuits.

4. **INPUT_PULLUP:** There are 20K pullup resistors built into the Atmega chip that can be accessed from software. These built-in pullup resistors are accessed by setting the pinMode() as INPUT_PULLUP. This effectively inverts the behavior of the INPUT mode, where HIGH means the sensor is off, and LOW means the sensor is on.![[Pasted image 20240523181154.png]]

5. **DIGITAL WRITE:**
   digitalWrite(pin, value)
   If the pin has been configured as an OUTPUT with pinMode, its voltage will be set to the corresponding value: 5V (or 3.3V on 3.3V boards) for HIGH, 0V (ground) for LOW.
   If the pin is configured as an INPUT, writing a HIGH value with digitalWrite() will enable an internal 20K pullup resistor. Writing LOW will disable the pullup.

6. **DIGITAL READ:**
   digitalRead(pin)
   Reads the value from a specified digital pin, either `HIGH` or `LOW`.

7. **Delay():**
   Pauses the program for the amount of time (in milliseconds) specified as parameter
   In Arduino, the delay()  function is a built-in function used to pause the execution of the program for a specified amount of time. 
   
   Internally, the delay() function relies on the microcontroller's timer hardware to keep track of time. When you call delay() with a certain number of milliseconds as an argument, the Arduino's microcontroller sets up a timer to count for that duration. While the timer is counting, the microcontroller typically enters a low-power mode to conserve energy.
   
   During this time, the microcontroller doesn't execute any other code, so it essentially "waits" until the timer expires. Once the timer reaches the specified duration, the microcontroller resumes normal operation, and your sketch continues executing from where it left off.
   
   using non-blocking techniques such as [[millis()]] or micros() for timing instead of delay(). These functions allow you to create delays without halting the entire program execution, enabling multitasking-like behavior in your Arduino sketches.

8. **PUSH BUTTON**:
   ![[Pasted image 20240523185330.png|300]]![[Pasted image 20240523185413.png|400]]
   ![[Pasted image 20240523185443.png|400]]

9. attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)
   ISR(Interrupt Service Routine): It is function that gets executed once the interrupt is triggered.
  
   **Interrupt_Vector:**
   In microcontroller programming, an interrupt vector is a mechanism used to handle interrupts. An interrupt is a signal that halts the normal execution flow of a program to handle a specific event. When an interrupt occurs, the microcontroller stops what it's doing and jumps to a predefined location in memory called the interrupt vector.
   1. **Interrupt Request (IRQ)**: An external event, such as a hardware input changing state or a timer reaching a certain value, triggers an interrupt request.
   2. **Interrupt Controller**: The microcontroller's interrupt controller detects the interrupt request and prioritizes it relative to other pending interrupts if multiple interrupts can occur simultaneously.
   3. **Interrupt Vector Table**: The microcontroller has a table called the Interrupt Vector Table (IVT) or Interrupt Vector Address Table (IVAT). This table contains memory addresses corresponding to specific interrupt service routines (ISRs) for each type of interrupt.
   4. **Jump to ISR**: When an interrupt occurs, the microcontroller looks up the appropriate memory address in the interrupt vector table and jumps to that location to execute the ISR associated with the interrupt.
   5. **Interrupt Service Routine (ISR)**: The ISR is a special function or subroutine responsible for handling the interrupt. It typically performs tasks related to the interrupt, such as reading sensor data, updating variables, or responding to external events.
   6. **Return from Interrupt**: After executing the ISR, the microcontroller returns to the point in the program where it was interrupted and resumes normal execution.

10. **digitalPinToInterrupt(pin):**
    it provides the interrupt vector number(a pointer)
    The interrupt vector number, also known as the interrupt vector index or interrupt vector address, is a numerical identifier associated with a specific type of interrupt. In microcontroller systems, each type of interrupt has a unique vector number or index, which corresponds to a specific memory location where the interrupt service routine (ISR) is stored.
    When an interrupt occurs, the microcontroller uses this vector number to locate the corresponding ISR in memory and execute it. The vector number is typically used as an index into the interrupt vector table (IVT) or interrupt vector address table (IVAT), which contains the addresses of all ISRs for the different types of interrupts supported by the microcontroller.
    Interrupt vector number is a pointer that points the memory location of the ISR.
    1. **Direction**: an interrupt vector points or directs the program flow to a specific location in memory where the ISR is located. When an interrupt occurs, the microcontroller follows the interrupt vector to determine where to go next.
    2. **Magnitude**: The "magnitude" of an interrupt vector refers to its numerical value or index, which uniquely identifies a specific type of interrupt. Each interrupt vector has a unique number associated with it, allowing the microcontroller to differentiate between different types of interrupts and locate the corresponding ISR.

![[Pasted image 20240526112638.png]]
we use the compare mode in timers to get the PWM signal and thus analogwrite() function works.

[[Volatile Variable]]
