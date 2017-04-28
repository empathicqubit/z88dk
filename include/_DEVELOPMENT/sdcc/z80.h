
// automatically generated by m4 from headers in proto subdir


#ifdef __Z80

#ifndef _Z80_H
#define _Z80_H

#include <stdint.h>
#include <im2.h>

extern void z80_delay_ms(uint16_t ms);
extern void z80_delay_ms_fastcall(uint16_t ms) __z88dk_fastcall;
#define z80_delay_ms(a) z80_delay_ms_fastcall(a)


extern void z80_delay_tstate(uint16_t tstates) __preserves_regs(d,e);
extern void z80_delay_tstate_fastcall(uint16_t tstates) __preserves_regs(d,e) __z88dk_fastcall;
#define z80_delay_tstate(a) z80_delay_tstate_fastcall(a)


extern uint8_t z80_get_int_state(void) __preserves_regs(b,c,d,e);

extern void z80_set_int_state(uint8_t state) __preserves_regs(b,c,d,e);
extern void z80_set_int_state_fastcall(uint8_t state) __preserves_regs(a,b,c,d,e,h,l) __z88dk_fastcall;
#define z80_set_int_state(a) z80_set_int_state_fastcall(a)



extern uint8_t z80_inp(uint16_t port) __preserves_regs(d,e);
extern uint8_t z80_inp_fastcall(uint16_t port) __preserves_regs(d,e) __z88dk_fastcall;
#define z80_inp(a) z80_inp_fastcall(a)


extern void *z80_inir(void *dst,uint8_t port,uint8_t num) __preserves_regs(d,e);
extern void *z80_inir_callee(void *dst,uint8_t port,uint8_t num) __preserves_regs(d,e) __z88dk_callee;
#define z80_inir(a,b,c) z80_inir_callee(a,b,c)


extern void *z80_indr(void *dst,uint8_t port,uint8_t num) __preserves_regs(d,e);
extern void *z80_indr_callee(void *dst,uint8_t port,uint8_t num) __preserves_regs(d,e) __z88dk_callee;
#define z80_indr(a,b,c) z80_indr_callee(a,b,c)


extern void z80_outp(uint16_t port,uint8_t data) __preserves_regs(d,e);
extern void z80_outp_callee(uint16_t port,uint8_t data) __preserves_regs(d,e) __z88dk_callee;
#define z80_outp(a,b) z80_outp_callee(a,b)


extern void *z80_otir(void *src,uint8_t port,uint8_t num) __preserves_regs(d,e);
extern void *z80_otir_callee(void *src,uint8_t port,uint8_t num) __preserves_regs(d,e) __z88dk_callee;
#define z80_otir(a,b,c) z80_otir_callee(a,b,c)


extern void *z80_otdr(void *src,uint8_t port,uint8_t num) __preserves_regs(d,e);
extern void *z80_otdr_callee(void *src,uint8_t port,uint8_t num) __preserves_regs(d,e) __z88dk_callee;
#define z80_otdr(a,b,c) z80_otdr_callee(a,b,c)



#define z80_bpoke(a,b)  (*(unsigned char *)(a) = b)
#define z80_wpoke(a,b)  (*(unsigned int *)(a) = b)
#define z80_lpoke(a,b)  (*(unsigned long *)(a) = b)

#define z80_bpeek(a)    (*(unsigned char *)(a))
#define z80_wpeek(a)    (*(unsigned int *)(a))
#define z80_lpeek(a)    (*(unsigned long *)(a))

#ifdef __CLANG

#define z80_llpoke(a,b) (*(unsigned long long *)(a) = b)
#define z80_llpeek(a)   (*(unsigned long long *)(a))

#endif

#ifdef __SDCC

#define z80_llpoke(a,b) (*(unsigned long long *)(a) = b)
#define z80_llpeek(a)   (*(unsigned long long *)(a))

#endif

#endif

#endif
