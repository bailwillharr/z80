#!/bin/sh

stty -F /dev/ttyUSB0 9600
sx -vv test.bin < /dev/ttyUSB0 > /dev/ttyUSB0
st -g 80x24 -i -l /dev/ttyUSB0 9600
