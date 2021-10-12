/* um script mínimo para o compilar o kernel 'Hello World' 
A seção de texto começa no endereço 0x80000000 de acordo com o que espera 
a márquina virtual RISC-V `virt` do Qemu
*/

OUTPUT_ARCH( "riscv" )
ENTRY( _start )

SECTIONS
{
    . = 0x80000000;
    /* seção de código */
    .text :
    {
        *(.text)
    }
    . = ALIGN(0x1000);
    PROVIDE(text_end = .);
    /* seção de dados */
    .data :
    {
        *(.data)
    }
    .bss : 
    {
        *(.bss)
        *(.sbss*)
        PROVIDE(bss_end = .);
    }

    . = ALIGN(16);
    PROVIDE(stack_start = .);
    PROVIDE(stack_end = stack_start + 0x4000);

}
