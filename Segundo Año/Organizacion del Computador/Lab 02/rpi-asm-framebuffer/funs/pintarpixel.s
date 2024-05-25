.equ SCREEN_WIDTH, 	640
.equ SCREEN_HEIGH, 	480

// Parametros:
// x1 -> pixel X
// x2 -> pixel Y

pintarpixel:
    BL calcular pixel
    