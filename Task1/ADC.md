Analog to digital convertors.
start as low as 8 bit and goes up to 32 bit, most common 10,12,16 bit
convert analog signals to signals.
### FLASH/DIRECT ADC ###
![[Pasted image 20240427220057.png|500]]
It uses comparator to check the input voltage with reference voltage to give the digital output. But for high bit ADC more number of comparators are required so to solve this shift registers are used to and the output data is obtained serially.
## RAMP ADC ##
A Free running counter is fed into a DAC to produce  a saw tooth signal gets compared to analog signal and when the signals match the corresponding binary number is output.
![[Pasted image 20240427221331.png|500]]

## **SAR(SUCCESSIVE APPROXIMATION REGISTER)** :##
![[Pasted image 20240429103057.png]]
Successive Approximation Register (SAR) is a popular type of analog-to-digital converter (ADC) that works by iteratively comparing an analog input signal to a digital approximation of that signal.
1. **Initialization**: The SAR ADC starts by setting its most significant bit (MSB) to a digital value and comparing it to the analog input signal.
2. **Comparison**: The SAR ADC compares the digital approximation to the analog input signal. If the analog signal is greater than the digital approximation, the corresponding bit value remains the same; if it's less, the bit value is adjusted accordingly.
3. **Iterative Adjustment**: The ADC continues comparing the subsequent bits of the digital approximation with the analog signal, moving from the MSB towards the least significant bit (LSB). At each step, it adjusts the bit values based on the comparison results.
4. **Narrowing Range**: With each iteration, the range of possible values for the analog signal narrows down until the digital approximation closely matches the analog signal.
5. **Matching and Reset**: Once the digital approximation matches the analog signal within an acceptable range, the SAR ADC locks in the digital value and resets for the next conversion cycle.
6. **Conversion Cycle**: The process repeats for each conversion cycle, starting again with the MSB set and continuing until the entire conversion is complete.

other ADC types are  **TRACKING(it tracks the previous output and compares it with the analog signal and makes changes)**

### SAMPLE ACCUMULATION DURING ADC CONVERSION ###
In the context of Analog-to-Digital Converters (ADC), "Accumulation up to 64 Samples per Conversion" refers to a feature that allows the ADC to average multiple samples of the input signal to produce a single output value for each conversion. This technique is commonly used to improve the accuracy and reduce the noise of the ADC measurements.
#### How It Works ####
1. **Sampling**: The ADC samples the input signal multiple times. In this case, it can sample up to 64 times for each conversion.
2. **Accumulation**: Each sampled value is added (accumulated) together.
3. **Averaging**: The accumulated value is typically divided by the number of samples to obtain the average value. This average value is then presented as the final conversion result.