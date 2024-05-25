.equ SCREEN_WIDTH,   640
	.equ SCREEN_HEIGH,   480

reset_bg:
	//Reserva espacio en el stack y guarda la dir de retorno en el stack
    SUB SP, SP, #8
    STUR X30, [SP, #0]

	/* Comienzo de la funcion "reset_bg" */
	// Guarda la dirección base del framebuffer en x20
	MOV X20, X0

	MOVZ X10, 0x00, LSL 16
	MOVK X10, 0x0000, LSL 00

	// Y Size
	MOV X2, SCREEN_HEIGH
	loop1_reset_bg:
		// X Size
		MOV X1, SCREEN_WIDTH
		loop0_reset_bg:
			STUR W10, [X0]  // Colorear el pixel N
			ADD X0, X0, #4    // Siguiente pixel

			// Decrementar contador X, si no terminó la fila, salto
			SUB X1, X1, #1
			CBNZ X1, loop0_reset_bg

		// Decrementar contador Y, si no es la última fila, salto
		SUB X2, X2, #1
		CBNZ X2, loop1_reset_bg


	// Resetea el valor de X0 para no perder la direccion base del framebuffer
    MOV X0, X20

	//Carga la direccion de retorno y libera la memoria del stack
    LDUR x30, [SP, #0]
    ADD SP, SP, #8
ret
