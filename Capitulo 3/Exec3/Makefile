run: somamain.c
	riscv64-linux-gnu-gcc  -c somamain.c
a.out: somamain.c soma.s
	riscv64-linux-gnu-gcc -v -static  -save-temps somamain.c soma.s
getcow:
	wget https://raw.githubusercontent.com/Virviil/cow.rs/master/test/hello_world.cow
clean:
	rm -rf *.o