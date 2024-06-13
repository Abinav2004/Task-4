A rectifier is a four-terminal semiconductor that allows current to flow in one direction. Rectifier diodes are used to convert AC voltage to DC voltage. Rectifiers are used even in our cell phone chargers to convert the AC from our home outlets to DC.
![[Pasted image 20240426233637.png|400]]
Depending on their input/output characteristics there are many types of Rectifiers such as
- Single Phase Rectifiers
- Three Phase Rectifiers
- Controlled Rectifiers
- Uncontrolled Rectifiers
- Half Wave Rectifiers
- Full Wave Rectifiers
- Bridge Rectifiers

1. **single phase rectifiers**:
   Single-phase rectifiers have an input of one-phase AC power. The construction is very simple, using only one, two, or four diodes (depending on the type of system).For conversion, a single-phase rectifier uses the secondary coil of a single-phase transformer with only one single phase, and diodes are linked to the secondary winding of the single-phase transformer. This results in a high ripple factor. RF is defined as the ratio of effective value of the alternating components of the rectified voltage.(Vac/Vdc).
   ![[Pasted image 20240426235639.png|300]]
   Solid-state devices are used as the primary AC-to-DC converting device in all single-phase rectifiers. Because the output is highly influenced by the reactance of the connected load, single-phase uncontrolled half-wave rectifiers are the simplest and possibly the most extensively used rectification circuit for small power levels.
   
2. **Three phase rectifiers**:
   Three-phase rectifiers have an input of three-phase AC power. Three or six diodes are required for each phase of the transformer secondary winding, and they are connected to each phase of the transformer secondary winding. To lower ripple factors, three-phase rectifiers are used instead of single-phase rectifiers. This is due to the fact that they can supply a lot of power and don't need any extra filters to lower the ripple factor. Three-phase rectifiers are more efficient and have higher transformer utilization factors.
3. **half wave rectifiers:**
   ![[Pasted image 20240427000419.png|300]]
4. **full wave rectifiers**:
   Full-wave rectifier is more complicated than a half-wave rectifier, it has certain advantages. It utilizes both half cycles of the sine wave to produce a DC output voltage that is higher than the half-wave rectifier's. Another benefit is that the output waveform has less ripples, making it easier to produce a smooth waveform. A center tapped transformer is used to get two outputs
   ![[Pasted image 20240427002057.png|300]]
5. **Bridge Rectifier:**
   The benefit of this design over the center-tapped variant is that it does not require a specific center-tapped transformer, reducing its size and cost significantly.
   ![[Pasted image 20240427003128.png|300]]
6. **Uncontrolled Rectifier:**
   The rectifier circuit using diodes only are called Uncontrolled rectifier circuit.
7. **Controlled Rectifier:**
   When SCRs (thyristor)(silicon-controlled-rectifiers) are used to convert AC to DC, they have a controlled output voltage so it is called a Controlled rectifier output.
   Unlike diodes, SCR does not become conducting immediately after its voltage has become positive.
   **Thyristor** also called SCR stands for Silicon Controlled Rectifier.
   It is a semiconductor switching device, with two power terminals, called the anode (A) and cathode (K) and one control terminal called the gate (G).
   It requires triggering by means of gate pulse signal.
   ![[Pasted image 20240427132102.png|150]]
   So it is possible to make the thyristor conducting at any point on the half wave which applies positive voltage to its anode. Thus the output voltage is controlled.
   ![[Pasted image 20240427131605.png|350]]
   