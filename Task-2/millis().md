The `millis()` function in Arduino is another essential tool for timing and creating delays, but it works quite differently from the `delay()` function. While `delay()` pauses the program execution, `millis()` allows you to keep track of the elapsed time since the Arduino board began running the current program.

1. **Initialization**: When your Arduino sketch starts running, it initializes an internal timer.

2. **Timer Tick**: This timer ticks continuously at a fixed rate, typically every millisecond. Each tick increments a counter maintained by the microcontroller.

3. **Reading Elapsed Time**: When you call `millis()`, it reads the current value of this counter, which represents the number of milliseconds since the sketch started running.

4. **Using Elapsed Time**: You can use this value to determine how much time has passed since a particular event occurred. For example, you can store the result of `millis()` when an event starts, and then compare it to the current value of `millis()` later to calculate the elapsed time.

5. **Non-Blocking Delays**: Unlike `delay()`, which pauses the program execution, `millis()` allows you to create delays without stopping the rest of your code. You can check the elapsed time using `millis()` and perform other tasks in the meantime.



