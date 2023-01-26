#!/bin/sh
stty -F /dev/ttyUSB0 1000000
st -g 80x24 -i -l /dev/ttyUSB0 1000000
