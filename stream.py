import serial
import pickle
from time import sleep

def send_cont_bytes():
    counter = 0
    num_pairs = 6
    delay = 1

    ser = serial.Serial(
        port='COM69',     # Replace with your serial port
        baudrate=9600,   # Replace with your baud rate
        timeout=1        # Timeout in seconds
    )

    while True:
        dick = { i: (255, counter) for i in range(num_pairs) }
        dick_pickle = pickle.dumps(dick)
        ser.write(dick_pickle)
        print(f"Sent: {str(dick_pickle)}")
        # counter += 1
        if counter == 0: counter = 1
        elif counter == 1: counter = 0
        print(dick)
        sleep(delay)


if __name__ == '__main__':
    send_cont_bytes()