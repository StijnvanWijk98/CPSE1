.cpu cortex-m0
sentence: 
    .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"
.align 2
.text
.global print_asciz
.global application

application:
    push { lr }
    ldr r0 , =sentence
    bl print_asciz
    pop { pc }

print_asciz:
    push { r5, lr }
    mov r5, r0
loop:
    ldrb r0, [ r5 ]
    add r0, r0, #0
    beq done
    bl uart_put_char
    add r5, r5, #1
    b loop
done:
    pop { r5, pc }