#include "types.h"
#include "defs.h"
#include "console.h"

void puts(char *s) {
    while (*s) uartputc(*s++);
    uartputc('\n');
}

int
entry() {
    // \uXXXX e \UXXXXXXXX são chamados universal-character-name
    puts(CLEAR_SCREEN CURSOR_UP_LEFT CORAL "\u26F0  ROS - Roncador Operating System (V0.1) \U0001F920");
    printlng(4096, 10);
    printf("\n");
    printlng(4096, 16);
    printf("\n");
    printlng(4096, 2);
    printf("\n");
    uint64 *ptr = (uint64 *) 4096;
    printptr(ptr);
    printf("\n");
    printf("%d\n", 128);
    printf("%p\n", (uint64 *) 4096);
    printf("ola = 4096 \n");
    int c;
    for(;;) {
        c = uartgetc();
        if (c == -1)
            continue;
        switch(c) {
            case 127:
                uartputc('\b');
                uartputc(' ');
                uartputc('\b');
                break;
            case '\r':
                puts("\r\n");
                break;
            default:
                uartputc(c);
        }
    }
    return 0;
}
