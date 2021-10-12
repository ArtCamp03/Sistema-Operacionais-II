#include "types.h"
#include "defs.h"
#include <stdarg.h> //Ver explicação mais abaixo no texto

static char *digitos = "0123456789abcdef";

// funçao percorre qe imprime de tras pra frente
void inverte(char* ch){
	if (*ch != '\0'){ 
		inverte(ch + 1);
		uartputc(*ch); 
	}
}

void printlng(long num, int base) {
    char buffer[100]; 
    int pos = 0,rest; 
    while(num != 0){
        rest = num % base;
        num = num / base;
        buffer[pos++] = digitos[rest];
    } 
    switch (base){ 
        // binario
        case 2: 
            buffer[pos++] = 'b';
            buffer[pos++] = '0';
            break;
        //ou hexadecimal
        case 16: 
            buffer[pos++] = 'x';
            buffer[pos++] = '0';
            break;
    }
    // fim de string
    buffer[pos] = '\0';
    // imprime buffer
    inverte(buffer); 
}

void printptr(uint64 *ptr){
    char cache[100];
    int i=0;
    uint64 result = 0 ;
    if(ptr == 0){
        result = (uint64)ptr % 16;
        ptr =(uint64*) ((uint64)ptr / 16);
        cache[i] = digitos[result];
        i++;
    }else{
        while(ptr != 0){
            result = (uint64)ptr % 16;
            ptr =(uint64*) ((uint64)ptr / 16);
            cache[i] = digitos[result];
            i++;
        }
        cache[i] = 'x';
        i++;
        cache[i] = '0';
        i++;
        cache[i] = '\0';
    }
   //imprime ao contrario o vetor cache
    while(i > 0){   
        i--;
        uartputc(cache[i]);
    }
}

void printf(char *s, ...){
    long int valLong; 
    int valInt;
    va_list list; 
    va_start(list,s); 
    while(*s){
        if((*s) == '%'){      
            s++;
            // inteiro                
            if((*s) == 'd' ){   
                valInt = va_arg(list, int);
                if (valInt < 0){
                    valInt = valInt * (-1);
                    uartputc('-');
                    }
                    printlng(valInt, 10);
            }
            else if((*s) == 'l'){    //longo decimal
                    valLong = va_arg(list, long);
                    printlng(valLong,10);
            }else if((*s) == 'x'){    //hexadecimal
                    valLong = va_arg(list, long);
                    printlng(valLong,16);
            }else if((*s) == 'c'){    //caracter
                    uartputc(va_arg(list, int));
            }else if((*s) == 's'){    //string
                    printf(va_arg(list, char*));
            }else if((*s) == 'p'){    //ponteiro 
                   printptr(va_arg(list, uint64*));
            }
        }else{
            //imprime o caracter
            uartputc(*s);   
        }
        s++;
    }
}