# Sistemas Operacionais II
# Aluno Artur R Campos
# Exe 1

.globl _start

_start:
    li a0, 1 # saida padrao
    la a1, num #  copia o endereço do rotulo "num" onde esta o numero de 4 bytes
    li a2, 1 # quantidade de bytes a ser lida da localizaçao
    li a7, 64 # syscall write (64)
    ecall
    
    li a0, 0 # exit code
    li a7, 93 # syscall exit
    ecall

num: .word 0x43414a55
