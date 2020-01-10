

                SECTION         code_clib

                PUBLIC          generic_console_cls
                PUBLIC          generic_console_printc
                PUBLIC          generic_console_scrollup
                PUBLIC          generic_console_set_ink
                PUBLIC          generic_console_set_paper
                PUBLIC          generic_console_set_attribute


                EXTERN          CONSOLE_COLUMNS
                EXTERN          CONSOLE_ROWS

                EXTERN          generic_console_font32
                EXTERN          generic_console_udg32
		EXTERN		generic_console_flags

                defc            DISPLAY = 0xc000

generic_console_set_paper:
generic_console_set_attribute:
generic_console_set_ink:
        ret


generic_console_scrollup:
	push	bc
	push	de
	ld	de,DISPLAY
	ld	hl,DISPLAY+512
	ld	c,256 - 8
sloop1:
	ld	b,48
sloop2:
	ld	a,(hl)
	ld	(de),a
	inc	hl
	inc	de
	djnz	sloop2
	ld	de,16
	add	hl,de
	ld	d,h
	ld	e,l	
	dec	d
	dec	d
	dec	c
	jr	nz,sloop1
	ld	c,8
sloop3:
	ld	b,48
sloop4:
	xor	a
	ld	(de),a
	inc	de
	dec	b
	jr	nz,sloop4
	ld	hl,16
	add	hl,de
	ex	de,hl
	dec	c
	jr	nz,sloop3
	pop	de
	pop	bc
	ret

generic_console_cls:
	ld	hl,DISPLAY
	ld	c,0
loop1:
	ld	b,48
loop2:
	ld	(hl),0
	inc	hl
	djnz	loop2
	ld	de,16
	add	hl,de
	dec	c
	jr	nz,loop1
	ret

generic_console_printc:
        ld      e,d
        ld      d,0
        ld      a,e
        ld      hl,(generic_console_font32)
        rlca
        jr      nc,not_udg
        ccf
        rrca
        ld      e,d
        ld      hl,(generic_console_udg32)
        inc     h               ;We decrement later
not_udg:
        ex      de,hl
        add     hl,hl
        add     hl,hl
        add     hl,hl
        add     hl,de
        dec     h               ; -32 characters
        ex      de,hl           ; de = font
	call	xypos

        ld      a,(generic_console_flags)
        rlca
        sbc     a,a
        ld      c,a             ;x = 0 / 255
	ld	b,8
loop:
	push	bc
	ld	a,(de)
	xor	c		;Handle inverse
				;Now, mirror bits
	ld      c,a
        rlca
        rlca
        xor     c
        and     0xaa
        xor     c
        ld      c,a
        rlca
        rlca
        rlca
        ld      b,a
        ld      a,c
        rrca
        ld      c,a
        ld      a,b
        xor     c
        and     0x66
        xor     c
;	rrca
	and	@00111111
	ld	(hl),a
	inc	de
	ld	bc,64		;Move to next row
	add	hl,bc
	pop	bc
	djnz	loop
	; And now underline
	ld	a,(generic_console_flags)
	and	@000001000
	ret	z
	ld	bc,-64
	add	hl,bc
	ld	(hl),@00111111
	ret


; Entry: b = row
;	 c = column
; Exit:	hl = address
xypos:
	; 512 bytes per row
	ld	h,b		;* 256
	ld	l,0
	add	hl,hl
	ld	b,+(DISPLAY / 256)
	add	hl,bc
	ret

	ret

