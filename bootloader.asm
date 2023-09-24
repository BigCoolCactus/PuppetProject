; Код загрузчика Puppet-OS

bits 32

section .text
    align 4
    dd 0x1BADB002
    dd 0x00
    dd - (0x1BADB002 + 0x00)
global boot

extern Kernelload  ; Точка входа в ядро

start:      ; Предполётная подготовка
    cli

    mov esp, stack_space
    call Kernelload

    hlt

section .bss
align 4
stack_space: resb 8192  ; Размер стека 8192 байт
