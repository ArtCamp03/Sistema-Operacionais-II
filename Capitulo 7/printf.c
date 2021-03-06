#include "types.h"
#include "defs.h"
#include <stdarg.h>

static char *digits = "0123456789abcdef";

void
printlng(long val, int base) {
    long l;
    int i = 0;
    //Para base 2, um long ocupa 64 bits. Para cada bit, 1 caracter, além do '0b' inicial
    char s[66]; 
    if (val < 0) {
        l = -val;
    }
    else {
        l = val;
    }
    //Imprime o número zero    
    if ( l == 0) {
        s[i++] = '0';
    }
    while(l) {
        s[i++] = digits[ l % base];
        l = l / base;
    }
    if (base == 16) {
        s[i++] = 'x';
        s[i++] = '0';
    }
    if (base == 2) {
        s[i++] = 'b';
        s[i++] = '0';
    }
    if (val < 0) s[i++] = '-';
    
    while(i > 0) {
        uartputc(s[--i]);
    }
}

void printptr(uint64 *ptr){
   uint64 addr = (uint64) ptr;
   char s[64];
   int i = 0;
   while(addr != 0) {
       s[i++] =  digits[addr % 16]; 
       addr /= 16;
   }
   s[i++] = 'x';
   s[i++] = '0';
   while (--i >= 0) {
       uartputc(s[i]);
   }
}

void printf(char *s, ...){
    va_list ap; // argument pointer 
    int c;
    char *str; 
    // https://www.gnu.org/software/libc/manual/html_node/Receiving-Arguments.html#Receiving-Arguments
    // ap aponta para o primeiro argumento opcional
    va_start(ap, s);
    for (; (c = *s) != 0; s++) {
        if (c == '%') { 
            c = *(s+1);
            if (c != 0) { // String mal-formatada terminando em '%' (ex.: "bla%") ?
                // É preciso saltar o caracter que indica a formatação, que não pode ser impresso. 
                // Ex.: Em %x, ignoramos o 'x' 
                s++;     
            }           
            switch(c) {
                 case '%':
                    uartputc(c);
                    break;
                 case 'd':
                  //va_arg retorna os sucessivos argumentos opcionais. A cada chamada, o próximo argumento
                    printlng(va_arg(ap, int), 10); 
                    break;
                 case 'x':
                    printlng(va_arg(ap, int), 16);
                    break;
                 case  'l':
                    printlng(va_arg(ap, long), 10);
                    break;
                 case 's':
                    str = va_arg(ap, char *);
                    while(*str != '\0') {
                        uartputc(*str++);
                    }               
                    break;
                 case 'p':
                    printptr(va_arg(ap, uint64 *)); 
                    break;     
            }
        }
        else {
            uartputc(c);
        }
    }
}

void
panic(char *s) {
    printf("\u2671 panic - %s\n", s);
    for(;;)
    ;
}