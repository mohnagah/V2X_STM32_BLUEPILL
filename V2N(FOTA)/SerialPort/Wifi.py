import serial
import time
import urllib.request

def send_data(line):
    try:
        my_serial.write(line.encode(encoding="utf-8"))
    except Exception as e:
        print("Serial error:", e)

try:
    my_serial = serial.Serial(port="COM3", baudrate=9600, bytesize=8, timeout=3, parity="N", stopbits=1)
except Exception as e:
    print("Serial error:", e)
else:
    print("Serial opened")

url = "http://nagahfota.atwebpages.com/uploads/Application.txt"

x = ""
while True:
    with urllib.request.urlopen(url) as file:
        contents = file.read().decode('utf-8')
    if x != contents:
        lines = contents.split('\n')
        for line in lines:
            send_data(line+"\n")

            #response = my_serial.readline().strip().decode('utf-8')

            #while response != "OK":
             #   response = my_serial.readline().strip().decode('utf-8')
            #print("Received:", response)
            time.sleep(0.3)  # Adjust delay as needed
    x = contents


# Close the serial port
my_serial.close()
