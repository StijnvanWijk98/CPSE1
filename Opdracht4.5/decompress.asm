.cpu cortex-m0
.bss
	buffer: .skip 40			// Buffer is FIFO-style
.align 2
.text
.global decompres

// Main loop of demompres, walks through asciz, and jumps based on found @ (3) or not (1)
decompres:
	push {r4, lr}
	ldr r4, =compressedtxt		// Gets first mem add of compressed asciz
decompres_loop:
	ldrb r0, [r4]							// Load char of mem add into r0
	add r0, r0, #0						// check if char is \0
	beq decompres_done				// if NUL terminator asciz sentc done
	mov r0, r4								// Move mem add to r0 for checker
	bl checker								// Call check function
	add r4, r4, r0						// checker returns jump num
	b decompres_loop					// Start loop over
decompres_done:
	pop {r4, pc}

// Function checks if char in mem add is @. Based on that puts char in buffer and cout
checker:
	push {r4, r5, r6, lr}
	mov r4, r0 								// Save the current mem add of asciz in r4
	ldrb r0, [r4]							// Load char on given mem add in r0
	cmp r0, #'@'							// Check if char is @
	beq check_at_sign					// If char == @
check_normal:								// Else:
	bl char_actions						// Does char action
	mov r0, #1								// Amount of jumps, with normal just 1
	b check_done
check_at_sign:							// If:
	ldr r0, =buffer						// Get first mem add of buffer
	ldrb r1, [r4 , #1]				// Load offset char
	ldrb r2, [r4 , #2]				// Load length char
	mov r3, #'0'							// 38 is char 0 in dec. Used to substract to get values
	sub r5, r1, r3						// Get offset replace
	sub r6, r2, r3						// Get length replace
	add r4, r0, r5						// Get start buffer pos, oldest char
at_sign_loop:
	cmp r6, #0								// Look if length is 0
	beq check_loop_done
	ldrb r0, [r4]							// Load char from buffer
	bl char_actions						// Print char and at to buffer
	sub r6, r6, #1						// Length - 1
	b at_sign_loop						// Loop
check_loop_done:
	mov r0, #3								// Amount of jumps, with @?? is 3 
check_done:
	pop {r4, r5, r6, pc}

// Funtion receives a char and cout and adds to buffer
char_actions:
	push {r4, lr}
	mov r4, r0								// Save the char in r4
	bl add_to_buffer					// Add char to buffer
	mov r0, r4								// reload char in r0
	cmp r0, #'!'								// Check if char is !
	bne char_print						// Char not ! than just print char
	mov r0, #10								// Char == ! then char = \n | Line feed
char_print:
	bl uart_put_char					// Print char to cout
	pop {r4, pc}

// WORKS: shifts and puts the given char in r0 to the front
add_to_buffer:
	push {r4, r5, lr}
	mov r4, r0								// Save variable that needs to be added to buffer
	ldr r5, =buffer						// mem add off buffer[0]
	mov r1, #39								// #39 is max buffer_pos
	add r0, r5, r1 						// mem add off buffer[39] (max pos)
add_buffer_loop:
	cmp r0, r5								// Check if new mem add is min mem add
	beq add_buffer_done				// if mem add off buffer[i] == buffer[0] than done
	sub r1, r0, #1 						// mem add off buffer[i-1] saved in r1
	ldrb r2, [r1]							// get value off buffer[i-1]
	strb r2, [r0]							// save value off buffer[i-1] in buffer[i]
	mov r0, r1								// decrease the loop
	b add_buffer_loop
add_buffer_done:
	strb r4, [r0]							// buffer[i/0] = value given in r0 at start
	pop {r4, r5, pc}