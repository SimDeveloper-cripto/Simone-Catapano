import serial
import time

ARDUINO = serial.Serial('COM6',9600)
time.sleep(1)

while(True):
    # PER PYTHON2 SI UTILIZZA: 'raw_input()'
    valore = input("DIGITARE IL COMANDO (A/S): ")
    ARDUINO.write(valore.encode()) # CONVERSIONE IN BYTES DEL COMANDO IN INPUT
    print(valore)
