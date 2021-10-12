PRE = riscv64-linux-gnu-
GCC = $(PRE)gcc 
#GCC = riscv64-unknown-elf-gcc
LD = $(PRE)ld
CFLAGS += -mcmodel=medany
CFLAGS += -ffreestanding
CFLAGS += -march=rv64gc 
CFLAGS += -mabi=lp64
# Habilita vários warnings, gera informações p/ debug (-g), otimiza 
# o código o mínimo possível (-O0) e não invoca o linker (-c)
CFLAGS += -Wall -g -O0 -c 
QEMU = qemu-system-riscv64
LDFLAGS = '-nostdlib'
SCRIPT=-Tkernel.ld

main.o:
	$(GCC) $(CFLAGS) main.c
boot.o: 
	$(GCC) $(CFLAGS) boot.s	
kernel: main.o boot.o
	$(LD) $(SCRIPT) $(LDFLAGS) -o kernel boot.o main.o
run: kernel
	$(QEMU) -append 'console=ttyS0'  -nographic -serial mon:stdio -smp 4 -machine virt -bios none -kernel kernel		
clean: 
	rm -rf kernel boot.o main.o
 