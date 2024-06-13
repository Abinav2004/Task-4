![[Pasted image 20240427224706.png]]
A voltage regulator is used to regulate voltage levels. When a steady, reliable voltage is needed, then the voltage regulator is the preferred device. It generates a fixed output voltage that remains constant for any changes in an input voltage or load conditions.
components used in voltage regulators:
1. Feedback Circuit
2. Stable Reference Voltage
3. Pass Element Control Circuit
 
 feedback circuit is used to detect the changes within the DC voltage output. Based on the reference voltage as well as feedback, a control signal can be generated and drives the Pass Element to pay off the changes.
Here, pass element is a semiconductor device similar to a BJT transistor OR a MOSFET. the DC output voltage can be maintained approximately stable.
Most commonly these regulators are used for converting DC/DC power, AC/AC otherwise AC/DC.

**Types of voltage Regulators**:
1. Linear voltage regulator.
   - series(a variable element placed in series with the load, resistance changes to give const Vout )
   - shunt(excess re-directed to ground)
2. switching voltage regulator.
   - step-up
   - step-down
   - inverting

**Linear voltage regulator:**
The resistance of the voltage regulator varies with load resulting in constant output voltage. Linear voltage regulators are the original type of regulators use to regulate the power supplies. Once a load is allied, the changes in any input otherwise load will consequence in a difference in current throughout the transistor to maintain the output is constant. To change the current of the transistor, it should be worked in an active otherwise Ohmic region. Lot of heat is dissipated due to voltage drop. It gives a fixed output. It is positive and negative adjustable
LDO-A **low-dropout regulator** (**LDO regulator**) is a DC linear voltage that can operate even when the supply voltage is very close to the output voltage.

**switching voltage regulators:**
A switching regulator rapidly switches a series device on and off. The switch’s duty cycle sets the amount of charge transferred to the load. This is controlled by a feedback mechanism similar to that of a linear regulator. Switching regulators are efficient because the series element is either fully conducting or switched off because it dissipates almost no power. Switching regulators are able to generate output voltages that are higher than the input voltage or of opposite polarity, unlike linear regulators.