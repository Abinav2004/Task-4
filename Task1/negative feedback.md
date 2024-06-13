Operational Amplifiers or op-amps for short are perhaps the most widely used component amongst all analog electronics. Because of their versatility, only a few external components are needed to configure them to perform a wide range of tasks like amplification, addition, subtraction, multiplication, integration and so on, hence the name **_operational amplifier_**, since it performs mathematical functions.
This functionality comes from the fact that they use _feedback_, 
There are two types of feedback, **positive feedback and negative feedback in op-amp**_,_ both of which will be covered in this article in detail.

## NEGATIVE FEEDBACK ##
Negative feedback takes a part of the output and subtracts it from the input in such a way that the output is in equilibrium with the input. This means that any change in the input is followed by a similar change in the output.
![[Pasted image 20240501002626.png]]
Following the rules of op-amp behavior where the op-amp will try to maintain a 0V difference in voltage across the inverting and non-inverting inputs. If the input to this circuit was 1V, then the output would also be 1V, since the output is directly connected to the inverting input, hence making the voltage difference between the inverting and non-inverting pins 0V.

## POSITIVE FEEDBACK ##
The inverting and the non-inverting inputs of the op-amps are switched so that the inverting input becomes the signal input and the non-inverting input becomes the pin that receives feedback from the output through the voltage divider.
![[Pasted image 20240501002856.png|500]]
when the voltage on the input becomes higher than the voltage at the non-inverting input, the output goes low. Since the op-amp is powered from a ±12V rail, the output sits at -12V and therefore the non-inverting input at -6V.
The output now stays latched at -12V till the input goes below -6V, at which point the output goes high to 12V, putting 6V at the non-inverting input.
Now the input has to cross 6V to make the output change state again. It is not stable and has only two states. Therefore, positive feedback cannot be used to create an amplifier since feedback is highly non-linear The best way to demonstrate an op-amp with positive feedback is a **positive feedback oscillator**
**NOTE:**
![[Pasted image 20240501004028.png]]
![[Pasted image 20240501004045.png]]
