all:
	arm-none-eabi-g++ -mcpu=cortex-m4     -mfloat-abi=hard     -mfpu=fpv4-sp-d16     -fmessage-length=0          -Wno-psabi     -fdata-sections     -ffunction-sections     -fno-asynchronous-unwind-tables     -fno-builtin     -fno-common     -fshort-enums     -fstack-usage     -mno-unaligned-access     -mthumb     -femit-class-debug-always -funsigned-bitfields     -fno-exceptions     -fno-non-call-exceptions     -fno-rtti     -fno-threadsafe-statics     -fno-use-cxa-atexit -Wall -Wextra -Wvla -Wno-deprecated-volatile -g3 -O2 -DNDEBUG -mcpu=cortex-m4     -mfloat-abi=hard     -mfpu=fpv4-sp-d16     -fmessage-length=0     -specs=nano.specs -specs=nosys.specs     -static     -Wl,--gc-sections     -Wl,-Map,application.map,--cref -T application.dld startUp.S main.cpp -o empty.elf

.PHONY : all
