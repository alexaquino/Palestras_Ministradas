from pyfirmata import Arduino
from time import sleep

# Caso necessário, vericar porta no arduino IDE
board = Arduino("/dev/cu.usbserial-AL008BFQ")

# loop()
while True:
    # digitalWrite(13, 1);
    board.digital[13].write(1)
    # delay(1000);
    sleep(1)
    # digitalWrite(13, 0);
    board.digital[13].write(0)
    # delay(1000);
    sleep(1)
