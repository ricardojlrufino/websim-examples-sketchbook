# --
# Copyright (c) 2021, Ricardo JL Rufino
# Install: apt-get install avr-binutils avr-gcc avr-libc avrdude
# --

MCU=atmega328p
#FUSE_L=0x6A
#FUSE_H=0xFF
#F_CPU=1600000

AS=avr-as
AVRDUDE=avrdude

TARGET=blink
ASFLAGS=-I ./

AVR_PATH=/media/ricardo/Dados/Programacao/Arduino/arduino-1.8.16/hardware/tools/avr/
USB_PORT=/dev/ttyACM0

SRCS = blink.S

all:
	${AS} ${ASFLAGS} -o ${TARGET}.o ${SRCS}
	avr-ld -o ${TARGET}.elf  ${TARGET}.o
	avr-objcopy --output-target=ihex ${TARGET}.elf ${TARGET}.hex
	echo "=== PROGRAM ===="
	cat ${TARGET}.hex

flash:
	${AVR_PATH}/bin/avrdude -C${AVR_PATH}/etc/avrdude.conf -v -patmega328p -carduino -b115200 -D -Uflash:w:${TARGET}.hex:i -P ${USB_PORT}
	#${AVRDUDE} -p ${MCU} -c usbasp -B10 -U flash:w:${TARGET}.hex:i -F -P /dev/ttyACM1

#fuse:
#	$(AVRDUDE) -p ${MCU} -c usbasp -B10 -U hfuse:w:${FUSE_H}:m -U lfuse:w:${FUSE_L}:m

clean:
	rm -f *.asm~ *.hex *.obj *.o *.cof *.elf
