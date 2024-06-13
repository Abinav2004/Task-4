RC LOW pass filter is used to smoothen out the PWM signal 
**Filtering High Frequencies**: PWM signals are composed of high-frequency switching components. These components can cause electromagnetic interference (EMI) and noise, which can interfere with sensitive analog circuits or communication systems. Smoothing the PWM signal reduces these high-frequency components, resulting in a cleaner analog signal .In measurement and control systems where accuracy is paramount, smooth analog signals can provide better performance than raw PWM signals, which may carry switching noise and other distortions.
- **High-Frequency Components**: The high-frequency components of the PWM signal correspond to the rapid switching between the high and low states.

![[WhatsApp Image 2024-05-27 at 16.47.42_c264d9dc.jpg|600]]
1. The circuit takes the input voltage and passes a magnitude of voltage output depending on the frequency of the input. For example: If we put a sine wave of 1Hz on the input side of the RC filter ,we would get the same on the other side.
2. Depending on the RC combination the magnitude might come out to be same  or it might get attenuated.
3. If the PWM signal frequency is lower than the cutoff frequency (1/2*pi*RC) then the output signal would be the same.
4. As we increase the frequency of the PWM the analog signal will attenuate  the high frequency of the square wave leaving just average.
**1HZ PWM wave**![[Pasted image 20240527170408.png|700]]
**3HZ signal**
![[Pasted image 20240527173154.png|700]]
 **100 Hz signal**
 ![[Pasted image 20240527173357.png|700]]
 Duty cycle is 50%.
 ![[Pasted image 20240528180705.png]]
![[Pasted image 20240528113317.png]]
