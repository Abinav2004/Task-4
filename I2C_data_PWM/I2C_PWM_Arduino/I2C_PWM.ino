#include<Wire.h>

uint8_t Slave_address=12;
uint8_t Size=4;
uint8_t Send_Array[4]={10,40,70,100};

void setup() {
  Wire.begin(Slave_address);
  Serial.begin(9600);
}
void Data_Transmit(uint8_t Data[4]);

void Data_Transmit(uint8_t Data[4])
{
  Wire.beginTransmission(Slave_address);
  Wire.write(Data,Size);
  uint8_t Status = Wire.endTransmission();
  if (Status==0) {
    Serial.println("Transmission Successful");
  }
  else {
  Serial.print("transmission failed with error code ");
  Serial.println(Status);
  }
}

void loop() {
  Data_Transmit(Send_Array);
}

/*In C, when calling a function and passing an array, the function needs to know the memory address where the array elements are stored. Directly using `{25, 50, 75, 100}` as an argument does not provide such an address. This is because `{25, 50, 75, 100}` is an initializer list, which can only be used in variable declarations or in compound literals. Here are the details:

1. **Initializer List**:
   An initializer list `{25, 50, 75, 100}` is used to initialize arrays or structures during their declaration. It cannot be used directly as a function argument because it does not have an address in memory that can be passed to the function.

2. **Compound Literals**:
   C99 introduced compound literals, which allow you to create an unnamed array or structure in place. When using a compound literal like `(int[]){25, 50, 75, 100}`, you create an unnamed array of type `int` and provide an address to this array, which can then be passed to the function.

3. **Pre-defined Array**:
   By declaring an array first, such as `int array[] = {25, 50, 75, 100};`, you allocate memory for the array and the name `array` becomes a pointer to the first element of this array. You can pass this pointer to a function.

### Example Breakdown

**Incorrect Approach:**
```c
Data_Transmit({25, 50, 75, 100});
```
This line attempts to pass an initializer list directly, which is not valid because the initializer list does not have a memory address.

**Correct Approaches:**

1. **Using a Pre-defined Array:**
   ```c
   int array[] = {25, 50, 75, 100};
   Data_Transmit(array, 4);
   ```
   Here, `array` is a pointer to the first element of the array, and you pass its address along with the length of the array.

2. **Using a Compound Literal:**
   ```c
   Data_Transmit((int[]){25, 50, 75, 100}, 4);
   ```
   The compound literal `(int[]){25, 50, 75, 100}` creates an unnamed array of type `int`, and the function receives the address of the first element of this array.

*/