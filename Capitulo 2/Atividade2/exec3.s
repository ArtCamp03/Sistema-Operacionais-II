# Sistemas Operacionais II
# Aluno Artur R Campos
# Exe 3

.global _start

_start:
    li t0, 0            # total soma
    la t3, soma        # base do vetor
    la t4, fimvet
    addi a5, zero,94   # a5 igual a 94

loop:
    lb t2, (t3)
    add t0, t0, t2     # t0 = 01 + t2
    addi t3, t3, 1
    blt t3, t4, loop
addi sp, sp, -8 # Aumenta a pilha em 8 bytes
sb t0, (sp)     # Move parte do conteúdo de t0 para o topo da pilha
#Parâmetros para write
li a0, 1        # stdout
beq sp , a5,    # comparaçao sp igual ha a5
la a1,msg
li a2, 4        # tamanho do buffer (4 byte)
li a7,  64      # número da syscall write
ecall
exit:
    li a0, 0
    li a7, 93
    ecall

soma: .word 60, 14, 20  # soma igual a 94
fimvet:         # endereço do final do vetor (vetor + 1)
msg: .asciz "OK \n"     # mensagem de confirmaçao

