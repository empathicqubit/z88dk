
SECTION code_fp_math32

PUBLIC cm32_sccz80_ldexp

EXTERN m32_fsldexp_callee

; float ldexpf(float x, int16_t pw2);

.cm32_sccz80_ldexp

    ; Entry:
    ; Stack: int right, float left, ret

    pop af                      ; my return
    pop hl                      ; (float)x
    pop de
    pop bc                      ; pw2
    push af                     ; my return   
    push bc                     ; pw2
    push de                     ; (float)x
    push hl
    call m32_fsldexp_callee
    pop bc                      ; my return
    push bc
    push bc
    push bc
    push bc
    ret
    
