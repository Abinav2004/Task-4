![[Pasted image 20240429103506.png]]
converts digital input to analog output.
types of DAC:(Digital to analog converter)
![[Pasted image 20240429104807.png]]
0111 is input given to the DAC it switches accordingly in the circuit and voltage is supplied to op-amp and negative analog voltage. In a binary-weighted Digital-to-Analog Converter (DAC), inputs are typically given to the inverting input of the operational amplifiers, not the non-inverting input. 
The reason for this configuration lies in the principle of [[negative feedback]] in operational amplifiers. In an inverting amplifier configuration, the output voltage is proportional to the difference between the inverting input voltage and the reference voltage (usually ground or a reference voltage). By applying the input voltage to the inverting input, the amplifier adjusts its output to maintain the inverting input at the same voltage as the input voltage. This allows for accurate conversion of digital input values to corresponding analog output voltages.
In summary, using the inverting input of the operational amplifier in a binary-weighted DAC configuration allows for precise control of the output voltage based on the digital input values, facilitating accurate digital-to-analog conversion. 
![[Pasted image 20240429104846.png]]
other form to convert digital signal to analog is using PWM.
The output analog signal obtained after conversion is not 100% accurate 
![[Pasted image 20240429105251.png]]
since they are made up of small digital signals.