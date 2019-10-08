cpu cortex-m0
.align 2
.text
.global print_buffer

// WORKS: print out the current buffer
print_buffer:
	push {r5, lr}
	ldr r5, =buffer				// mem add off buffer[0]
	mov r1, #39						// #39 is max buffer_pos
	add r4, r5, r1				// mem add off buffer[39] (max pos)
pr_buffer_loop:
	cmp r4, r5
	beq pr_buffer_done		// if mem add off buffer[i] == buffer[0] than done
	ldrb r0, [r4]					// get value off buffer[i-1]
	bl uart_put_char
	sub r4, r4, #1				// decrease the loop
	b pr_buffer_loop
pr_buffer_done:
	ldrb r0, [r5]
	bl uart_put_char
	pop {r5, pc}