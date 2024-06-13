
Debugging is the process of identifying and removing errors from computer hardware or software. When we talk about debugging embedded systems, it can be much harder than debugging on a PC. Embedded systems often involve both software and hardware debugging, as they use microcontrollers and microprocessors, which can be quite complex systems. Embedded systems control real-time processes in machines and systems, making debugging a challenging task.

**Options for Debugging**

When debugging, we want to gather as much information as possible. Options include reading documentation, seeking help from colleagues, or using various tools and techniques.

### ** Emulators** ###

The first tool used  is emulators, specifically in-circuit emulators or ICEs. While emulators are not as common today, they were widely used in the past and might still have applications, especially for legacy products. Emulators work by emulating the hardware of the microcontroller, providing real-time control of application execution. They offer full access to registers and memories(read and write), unlimited breakpoints, and advanced debugging features. However, they can be expensive and require additional effort to set up.
![[Pasted image 20240525112624.png]]

- we are emulating the microcontroller, we remove the microcontroller from the board and put a socket instead.
- the we connect it to an emulator that emulates our microcontroller and it is then connected to PC for debugging.
![[Pasted image 20240525113258.png]]
- unlimited breakpoints (Smart breakpoints) that is you can record the code execution and inspect that afterwards for potential errors and bugs 
- we have additional output and inputs on the emulator Hardware so that we don't need to use a microcontroller Hardware to for example toggle a pin 
- we can hold execution and single steps to record but be aware when controlling a real system let's say we're controlling a microcontroller at high speed it might not be the best idea to just hold 
- usually in-circuit emulators do not impact code execution ,don't need to have additional debug code to be executed


### **On-Chip Debuggers (OCDs)/Background Debug Mode (BDM)/In-circuit Debugger (ICD)** ###

 on-chip debuggers, also known as OCDs or in-circuit debuggers. These debuggers are embedded within the microcontroller itself, providing control over code execution, registers, and memories. They are connected to the PC via a debug probe, which translates signals between the microcontroller and the PC. OCDs use interfaces like JTAG or SWD to communicate with the microcontroller. They offer flexibility, support for various microcontrollers, and advanced debugging features. However, they may require additional flash space for debug information.
 - There is no need to remove the microcontroller from the board
 - The microcontroller has it's own debug module embedded in it.
 - It has access to the CPU and can control the code execution ,it has access to registers and memory.
 - if we want to set a breakpoint ,so that  the execution stops at that address then this address will be written into one of the breakpoint registers in the control module on the control module will compare this address to the running program counter if there is a match it will stop the execution.
 -  we connect the debug module inside the microcontroller to our PC that's where we use the debug probe the debug probe will translate the signals from the debug module inside the microcontroller to  USB or ethernet which then is then connected to our PC.
 ![[Pasted image 20240525121819.png]]
#### JTAG:
 JTAG, which stands for Joint Test Action Group, is a standard interface used for testing and programming integrated circuits, particularly in the context of digital electronics. Originally developed by the Joint Test Action Group, it has become widely adopted across the electronics industry.
1. **TCK (Test Clock):** This pin is used to synchronize the shifting of data between the testing device (such as a debugger or programmer) and the target device (such as a microcontroller or FPGA). The Test Clock provides timing for the data transfer.

2. **TMS (Test Mode Select):** This pin is used to control the state transitions of the JTAG state machine. By changing the state of TMS while holding TCK high, the JTAG state machine can move between different states, such as Test-Logic-Reset, Run-Test/Idle, and various other modes.

3. **TDI (Test Data-In):** This pin is used to input test data into the target device during testing or programming operations. It is typically driven by the testing device to send data to the target device.

4. **TDO (Test Data-Out):** This pin is used to output test data from the target device during testing or programming operations. It allows the testing device to receive data from the target device.

5. **TRST (Test Reset):** This pin, although optional, provides a means to reset the JTAG circuitry within the target device. It can be used to ensure a known starting state for the JTAG operation.

The "reduced pin count" JTAG definition simplifies the interface by reducing the number of pins required. Instead of using five separate pins, it only utilizes two:

1. **TMSC (Test Serial Data):** This pin combines the functionality of TMS and TDI in a serial data stream. It is used to control the JTAG state machine and input test data into the target device.

2. **TCKS (Test Clock):** This pin serves the same purpose as TCK in the standard JTAG definition, providing the clock signal for synchronizing data transfer.

Reducing the pin count simplifies the hardware design and makes it easier to interface with the target device, especially in applications where space or pin count is limited.
JTAG provides a standardized interface for testing, debugging, and programming integrated circuits, offering a convenient way to access and manipulate internal components of the target device.
![[Pasted image 20240525123821.png|500]]

### SWD: ###
Serial Wire Debug (SWD) is indeed a streamlined alternative to JTAG, particularly designed for ARM processors. 
1. **Purpose and Functionality:**
   - SWD serves the same purpose as JTAG: to facilitate debugging, testing, and programming of embedded systems, particularly those using ARM processors.
   - However, SWD achieves this with a simplified interface compared to JTAG, which typically requires more pins.

2. **Pin Reduction:**
   - JTAG typically requires five pins: Test Clock (TCK), Test Mode Select (TMS), Test Data In (TDI), Test Data Out (TDO), and optionally Test Reset (TRST).
   - SWD reduces this pin count to just two pins: Serial Wire Data (SWDIO) and Serial Wire Clock (SWCLK).

3. **Compatibility with JTAG:**
   - Importantly, SWD is backward compatible with JTAG. This means that devices supporting SWD can often be debugged using traditional JTAG tools if needed.
   - Additionally, many ARM processors feature a dedicated debug port that supports both JTAG and SWD, giving developers flexibility in choosing the debugging interface.

4. **Integration with ARM Cortex Processors:**
   - SWD is particularly popular in the context of ARM Cortex processors, where it is commonly implemented alongside JTAG support.
   - The integration of SWD on ARM Cortex processors allows developers to debug and program these devices efficiently using a compact interface.
   - ![[Pasted image 20240525124242.png]]
   
_Note_: The KEY pin in the SWD pinout typically serves as a security feature, providing a means to disable debug access to the device. When the KEY pin is enabled and locked, it prevents unauthorized access to the device's debug interface, thereby enhancing security.

The specific functionality of the KEY pin can vary depending on the implementation and the device's manufacturer. In some cases, the KEY pin may be used to enable or disable debug access, while in others, it may be involved in authentication or encryption processes to ensure secure communication with the device.


**Advanced Debug Probes**
Finally, we look at advanced debug probes like the J-Link Ultra Plus, which offer unlimited flash software breakpoints and support for various microcontrollers and memory types. These probes provide enhanced debugging capabilities but come at a higher cost.


**GDB:**
GDB, the GNU Project debugger, allows you to see what is going on inside another program while it executes.

**OpenOCD:**
Open On chip Debugger is an opensource software that provides debugging for embedded devices. It allows developers to interact with the hardware of microcontrollers. It does so with the assistance of a _debug adapter_, which is a small hardware module which helps provide the right kind of electrical signaling to the target being debugged.