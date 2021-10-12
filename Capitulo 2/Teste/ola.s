.global _start
_start:

    li a0, 1
    la a1, msg
    li a2, 10
    li a7, 64 # id ,da syscall write
    ecall

    li a0, 0
    lo a7,93 # id ,da syscall exit
    ecall

msg: .asciz "ola Mundo \n"