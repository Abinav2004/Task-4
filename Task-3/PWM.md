
##  Pulse Width Modulation (PWM)

 Pulse width modulation or PWM is a commonly used control technique that generates analog signals from digital devices such as microcontrollers. The signal thus produced will have a train of pulses, and these pulses will be in the form of square waves. PWM is widely used in electronics to control the power supplied to devices such as LEDs, motors and more.
#### Digital vs. Analog Signals
- **Digital Signals**: These signals have discrete levels, usually represented by two states: HIGH (1, typically 5V) and LOW (0, typically 0V).
- **Analog Signals**: These signals can vary continuously within a range, such as from 0V to 5V, providing a smooth transition between levels.
#### PWM Signal
A PWM signal is a type of digital signal where the frequency is constant but the duty cycle varies. The duty cycle is the fraction of one period in which the signal is active (HIGH).
#### Duty Cycle
- **Definition**: The duty cycle is the percentage of one period in which the signal is high (ON).
- **Examples**:
  - **0% Duty Cycle**: The signal is always LOW. (Analog equivalent: 0V)
  - **50% Duty Cycle**: The signal is HIGH for half the period and LOW for the other half. (Analog equivalent: 2.5V if the peak is 5V)
  - **100% Duty Cycle**: The signal is always HIGH. (Analog equivalent: 5V)
#### Period and Frequency
- **Period (T)**: The duration of one complete cycle of the signal (HIGH plus LOW).
- **Frequency (f)**: The number of cycles per second, measured in Hertz (Hz). 
### Working Principle of PWM
PWM works by varying the duty cycle of a fixed frequency signal to control the power delivered to a load. By switching the signal between HIGH and LOW states at a rapid pace, the effective voltage and thus the power can be adjusted. Its just changing at what fraction of that period the signal is On Vs the signal is off ,there by not creating a Voltage but if you average over the period, the required would be obtained. The toggling happens so fast that we cant see with our own eyes. 
#### Visualizing PWM
Using an oscilloscope, the PWM signal can be visualized as a square wave where the width of the high pulse changes. The waveform's high portion (ON time) represents the duty cycle.
![[Pasted image 20240527163819.png|500]]
#### [[Smoothing PWM Output]]
When an analog signal is needed, a low-pass filter (typically a capacitor) can be used to smooth out the PWM signal. There will be little waviness in that analog voltage obtained, it comes because the capacitor doesn't smoothen out the PWM signal completely. 

### PWM GENERATION USING TIMERS ###
- Waveform Generation Mode bits (WGM): these control the overall mode of the timer. (These bits are split between TCCRnA and TCCRnB.)
- Clock Select bits (CS): these control the clock prescaler
- Compare Match Output A Mode bits (COMnA): these enable/disable/invert output A
- Compare Match Output B Mode bits (COMnB): these enable/disable/invert output B

The Output Compare Registers OCRnA and OCRnB set the levels at which outputs A and B will be affected. multiple compare is used so that we can generate multiple PWM signal using same timer

**FAST PWM:**
In the simplest PWM mode, the timer repeatedly counts from 0 to 255. The output turns on when the timer is at 0, and turns off when the timer matches the output compare register. The higher the value in the output compare register, the higher the duty cycle. This mode is known as Fast PWM Mode
![[Screenshot 2024-05-01 104659.png]]
**Phase-Correct PWM**:
The second PWM mode is called phase-correct PWM. In this mode, the timer counts from 0 to 255 and then back down to 0. The output turns off as the timer hits the output compare register value on the way up, and turns back on as the timer hits the output compare register value on the way down. The result is a more symmetrical output.
![[Screenshot 2024-05-01 104928.png]]

**Varying the timer top limit:**

Both fast PWM and phase correct PWM have an additional mode that gives control over the output frequency. In this mode, the timer counts from 0 to OCRA (the value of output compare register A), rather than from 0 to 255. This gives much more control over the output frequency than the previous modes.
![[Screenshot 2024-05-01 105103.png]]
![[Screenshot 2024-05-01 105131.png]]

In the Atmega328P microcontroller, which is commonly used in Arduino boards like the Arduino Uno, there are three timers/counters: Timer/Counter0, Timer/Counter1, and Timer/Counter2. These timers/counters can generate PWM signals on specific pins of the microcontroller. Here's how the PWM channels are distributed:
1. **Timer/Counter0 (8-bit)**:
   - Timer/Counter0 is an 8-bit timer/counter.
   - It is used for PWM generation on pins OC0A (PD6) and OC0B (PD5).
   - OC0A is connected to Arduino digital pin 6 (labeled as PWM).
   - OC0B is connected to Arduino digital pin 5 (labeled as PWM).

2. **Timer/Counter1 (16-bit)**:
   - Timer/Counter1 is a 16-bit timer/counter.
   - It provides more PWM channels compared to Timer/Counter0.
   - Timer/Counter1 is used for PWM generation on pins OC1A (PB1) and OC1B (PB2).
   - OC1A is connected to Arduino digital pin 9 (labeled as PWM).
   - OC1B is connected to Arduino digital pin 10 (labeled as PWM).

3. **Timer/Counter2 (8-bit)**:
   - Timer/Counter2 is an 8-bit timer/counter.
   - It is used for PWM generation on pins OC2A (PB3) and OC2B (PD3).
   - OC2A is connected to Arduino digital pin 11 (labeled as PWM).
   - OC2B is connected to Arduino digital pin 3 (labeled as PWM).
### PWM GENERATION USING RAMP SIGNAL ###
![[Pasted image 20240529124255.png]]
- The sawtooth generator will generate a sawtooth signal which is fed to inverting terminal of the comparator
- The modulating signal is passed through LPF to remove unwanted high frequency noise and fed into the inverting terminal of the comparator.
- The comparator will remain HIGH as long as the instantaneous amplitude of x(t) > ramp signal.
- The comparator will LOW if the instantaneous amplitude of x(t) < ramp signal.

![[Pasted image 20240529125037.png]]
- Leading edges of PWM waveform coincide with the Falling edges of Ramp signal.


### Detection of PWM signal ###
![[Pasted image 20240529125457.png]]
- The received PWM signal is fed into the Pulse generator to remove the noise there by regenerating the PWM signal.
- The PWM signal is then goes to Ramp and pedestal generator where the slope ramp is equal pulse HIGH duration and greater the width of the pulse, higher the height of the Ramp.
- The PWM signal is also fed into reference pulse generator block which produces a train of constant width pulses synchronized to the leading edges of PWM.
- both the outputs are added and clipped 
![[Pasted image 20240529131547.png|400]]
![[Pasted image 20240529131357.png|500]]
PAM signal the passed through the LPF to get the original signal.
![[Pasted image 20240529131930.png|400]]

![[WhatsApp Image 2024-05-29 at 21.41.45_24e1cc84.jpg|700]]