# Sistemas Operacionais II
# Aluno Artur R Campos
# Exe 2

.global _start
_start:
    li t0, 0            # total soma
    la t3, vetor        # base do vetor
    la t4, fimvet
loop:
    lb t2, (t3)
    add t0, t0, t2     # t0 = 01 + t2
    addi t3, t3, 1
    blt t3, t4, loop
addi sp, sp, -8 # Aumenta a pilha em 8 bytes
sb t0, (sp)     # Move parte do conteúdo de t0 para o topo da pilha
#Parâmetros para write
li a0, 1        # stdout
mv a1, sp       # a1 <= sp
li a2, 1        # tamanho do buffer (1 byte)
li a7,  64      # número da syscall write
ecall
exit:
    li a0, 0
    li a7, 93
    ecall
vetor: .byte 60, 1, 2, 3
fimvet:         # endereço do final do vetor (vetor + 1)

# exe 2
# Qual a saída do programa soma-vetori.s? Como você a interpreta?
# como a diretiva no fim do codigo ".byte" pega exatamente 8bit(1 byte) a medida qe a posiçao no vetor vai sendo incrementada t2 copia o valor na posiçao de t3 e repassa para a soma de t0, sendo a soma 60 + 1 >> 61 + 2 >> 62 + 3 = 65 como resultado da soma


# Qual a consequência de copiarmos para a memória apenas 1 byte do registrador t0 (linha 12) em vez copiar todo o conteúdo do registrador?
# copiaremos apenas o ultimo resultado que nos interessa
