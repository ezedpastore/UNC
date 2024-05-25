.equ SCREEN_WIDTH, 	640
.equ SCREEN_HEIGH, 	480
.equ BITS_PER_PIXEL, 32

.equ GPIO_BASE,    0x3f200000
.equ GPIO_GPFSEL0, 0x00
.equ GPIO_GPLEV0,  0x34


/*
Fun: reset_bg
Hace: Pinta toda la pantalla de negro
*/

reset_bg:
	// Reserva espacio en el stack y guarda la dir de retorno en el stack
    SUB SP, SP, #8
    STUR LR, [SP, #0]

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



	// Se copia la base del framebuffer en el X9
    MOV X9, X20

	// Guardo el color negro (0x000000) en X9
	MOVZ X10, 0x00, LSL 16
	MOVK X10, 0x0000, LSL 00

	LDR X11, =SCREEN_WIDTH
	LDR X12, =SCREEN_HEIGH

	// X13 el al dirección final del framebuffer ( X11 = &A[0][0] + (680*480*8) )
	MUL X13, X11, X12
	LSL X13, X13, #3
	ADD X13, X13, X0

	loop_reset_bg:
		CMP X9,X13
		B.EQ end_reset_bg

		STUR W10, [X9, #0]  // Colorear el pixel N
		ADD X9, X9, #4    // Siguiente pixel

		B loop_reset_bg
	end_reset_bg:



	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Carga la direccion de retorno y libera la memoria del stack
    LDUR LR, [SP, #0]
    ADD SP, SP, #8
ret






/*
Fun: calcular_pixel
Hace: Dado una coordenada (x, y) de una matriz de pixeles, calcula la posición de esta en un arreglo de una dimension

Parámetros:
    X3 -> Posición del pixel x
    X4 -> Posición del pixel y

Asignación:
    X0 -> posición pixel en memoria (&A[y][x])
*/

calcular_pixel:
	// Reserva espacio en el stack y guarda la dir de retorno en el stack
    SUB SP, SP, #8
    STUR LR, [SP, #0]

    // (Se calcula la fila)     ==      640 * y                         ==      &A[y]
    MOV X0, SCREEN_WIDTH
    MUL X0, X0, X4

    // (Se calcula la posición del pixel)   ==  ((640 * y) + x) * 4     ==      &A[y][x]
    ADD X0, X0, X3
    LSL X0, X0, #2

    // (Se coloca la dirección de memoria del pixel en X0)              ==      X0 = &A[y][x]
    ADD X0, X0, X20

    // Carga la dirección de retorno y libera la memoria del stack
    LDUR LR, [SP, #0]
    ADD SP, SP, #8
ret






/*
Fun: pintar_pixel
Hace: Dado una coordenada (x, y) de una matriz de pixeles y color, pinta dicho pixel

Parámetros:
    X3 -> Posición del pixel x
    X4 -> Posición del pixel y
    X5 -> Color
*/

pintar_pixel:
	// Reserva espacio en el stack y guarda la dir de retorno en el stack
	SUB SP, SP, #8
	STUR LR, [SP, #0]

    // Chequeamos que las coordenadas estén dentro de la pantalla, si no lo están, no pintamos
    CMP X3, SCREEN_WIDTH
    B.HS skip_pintar_pixel					 	// 640 <= X1 entonces skip

    CMP X4, SCREEN_HEIGH
    B.HS skip_pintar_pixel						// 480 <= X2 entonces skip

    // Calculamos la dirección del pixel a pintar, la cual se guarda en X0
    BL calcular_pixel

    // Pintamos el Pixel
    STUR X5, [X0, #0]

    skip_pintar_pixel:

	// Carga la dirección de retorno y libera la memoria del stack
	LDUR LR, [SP, #0]
	ADD SP, SP, #8
ret






/* 	-- Dibujar Linea Horizontal --
*
*	-- ARGS --
*	X11=x_init, X12=y, X13=x_final, X6=color

coordenada (X11, X12) == (x0, y0)
*/

/*
Fun: dib_linea_h
Hace: Dibujar Linea Horizontal
*/

dib_linea_h:
    SUB SP, SP, #54           // reservar espacio en la pila para guardar registros
    STUR X5, [SP, #48]
    STUR X4, [SP, #40]
    STUR X3, [SP, #32]
    STUR X12, [sp, #24]        // guardar y en la pila
    STUR X13, [sp, #16]        // guardar x_final en la pila
    STUR X11, [sp, #8]         // guardar x_init en la pila
    STUR X30, [sp, #0]         // guardar el return pointer en la pila

dib_linea_h_loop:
    ADDS X11, X11, 1         // Suma los pixeles que se van pintando
    CMP X13, X11              // Comparar c (x13) con la cantidad de pixeles dibujados (x10)
    B.EQ fin_dib_linea_h      // Si son iguales, terminar el bucle

    MOV X3, X11
    MOV X4, X12
    MOV X5, X6

    BL pintar_pixel			  // llamar a la función p/ pintar el pixel

    B dib_linea_h_loop        // repetir loop
fin_dib_linea_h:
    LDUR X5, [SP, #48]
    LDUR X4, [SP, #40]
    LDUR X3, [SP, #32]
    LDUR X12, [SP, #24]        // guardar y en la pila
    LDUR X13, [SP, #16]        // guardar x_final en la pila
    LDUR X11, [SP, #8]         // guardar x_init en la pila
    LDUR X30, [SP, #0]         // guardar el return pointer en la pila
    ADD SP, SP, #54           // reservar espacio en la pila para guardar registros
ret






/*
Fun: rectangulo
Hace: Dada dos coordenada (x1, y1) y (x2, y2), pinta un rectángulo que comienza en la coordenada (x1, y1) y finaliza en (x2, y2)

Parámetros:
    X1 -> Posición del pixel x1
    X2 -> Posición del pixel y1
    X3 -> Posición del pixel x2
    X4 -> Posición del pixel y2
    X5 -> Color
*/

rectangulo:
	// Reserva espacio en el stack y guarda la dir de retorno en el stack
	SUB SP, SP, #8
	STUR LR, [SP, #0]

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



	/*
	Variables auxiliares:
	X9 = coordenada x1
	X10 = coordenada y1
	X11 = coordenada x2
	X12 = coordenada y2

	*/
	MOV X9, X1
	MOV X10, X2
	MOV X11, X3
	MOV X12, X4

	rectangulo_loop:
		// Si y1 <= y2 entonces continuo, si y2 < y1 corto el bucle
		CMP X10, X12
		B.HI rectangulo_end

		/*
		Parámetros de linea_recta_horizontal
		X1 = coordenada x1		=>		x1
		X2 = coordenada y1		=>		y1
		X3 = coordenada x2		=>		x2
		X4 = coordenada y2		=>		y1
		X5 = color
		*/
		MOV X1, X9
		MOV X2, X10
		MOV X3, X11
		MOV X4, X10

		BL dib_linea_h

		// Muevo el y1 para la linea recta en la siguiente fila de la matriz de pixeles
		ADD X10, X10, #4

		B rectangulo_loop
	rectangulo_end:



	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// Carga la dirección de retorno y libera la memoria del stack
	LDUR LR, [SP, #0]
	ADD SP, SP, #8
ret
