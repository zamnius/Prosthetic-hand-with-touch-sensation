import serial
import numpy as np
import time
import matplotlib.pyplot as plt
# set up the serial line
ser = serial.Serial('COM3', 9600)
time.sleep(2)
# Read and record the data
data =[]                       # empty list to store the data
for i in range(100):
    b = ser.readline()         # read a byte string
    string_n = b.decode()  # decode byte string into Unicode
    string = string_n.rstrip() # remove \n and \r
    print(string)

    flt = float(string)        # convert string to float
    print(flt)
    data.append(flt)           # add to the end of data list
    time.sleep(0.1)            # wait (sleep) 0.1 seconds

ser.close()
# show the data
print('THEAVERAGEIS')
print(np.mean(data))
print('WASTHEAVERAGE')



plt.plot(data)
plt.xlabel('Time (seconds)')
plt.ylabel('Potentiometer Reading')
plt.title('Potentiometer Reading vs. Time')
plt.show()
