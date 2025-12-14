#!/bin/bash

set -e

echo "Clearing flash..."
arm-none-eabi-gdb -batch -x flash.gdb empty/empty.elf
sleep 2

echo "Flashing image..."
arm-none-eabi-gdb -batch -x flash.gdb ../../build/s32k148-gcc/executables/referenceApp/application/RelWithDebInfo/app.referenceApp.elf

echo "Logging..."
nohup /usr/sbin/ttylog -d /dev/ttyACM0 -b 115200 -t 5 -f >log.txt


echo "Logging end."
killall ttylog

echo "Done."
