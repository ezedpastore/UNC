.equ SCREEN_WIDTH, 	640
.equ SCREEN_HEIGH, 	480

// Parametros: 
// x1 -> pixel X
// x2 -> pixel Y

calcular pixel:
    mov x0, SCREEN_WIDTH
    mul x0, x0, x2
    add x0, x0, x1
    lsl x0, x0, 2
    add x0, x0, x20 
ret

        

