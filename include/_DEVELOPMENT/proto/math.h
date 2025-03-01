include(__link__.m4)

#ifndef __MATH_H__
#define __MATH_H__

#include <stdint.h>

// THE SELECTED FLOATING POINT PACKAGE MAY NOT SUPPORT ALL LISTED FUNCTIONS

#ifndef _FLOAT_T
#define _FLOAT_T

   #ifdef __CLANG
   typedef float float_t;
   #endif

   #ifdef __SDCC
   typedef float float_t;
   #endif
   
   #ifdef __SCCZ80
   typedef double float_t;
   #endif
   
#endif

#ifndef _DOUBLE_T
#define _DOUBLE_T

   #ifdef __CLANG
   typedef float double_t;
   #endif

   #ifdef __SDCC
   typedef float double_t;
   #endif
   
   #ifdef __SCCZ80
   typedef double double_t;
   #endif
   
#endif

#ifndef _FLOAT16_T
#define _FLOAT16_T

   #ifndef __SCCZ80
   typedef short _Float16;      /* IEEE-754 half float type */  
   #endif

typedef _Float16 half_t;

#endif

// XSI EXTENSION
// temporary : math lib should supply these via func call

#define M_E                    2.718281828459
#define M_INVLN2               1.442695040889   /* 1 / log(2) */
#define M_LOG2E                1.442695040889
#define M_IVLN10               0.434294481903  /* 1 / log(10) */
#define M_LOG10E               0.434294481903
#define M_LOG2_E               0.693147180560
#define M_LN2                  0.693147180560
#define M_LN10                 2.302585092994
#define M_PI                   3.141592653590
#define M_TWOPI                6.283185307180
#define M_PI_2                 1.570796326795
#define M_PI_4                 0.7853981633974
#define M_3PI_4                2.3561944901923
#define M_SQRTPI               1.7724538509055
#define M_1_PI                 0.3183098861838
#define M_2_PI                 0.6366197723676
#define M_4_PI                 1.2732395447352
#define M_1_SQRTPI             0.5641895835478
#define M_2_SQRTPI             1.1283791670955
#define M_SQRT2                1.4142135623731
#define M_SQRT3                1.7320508075689
#define M_SQRT1_2              0.7071067811865

//

#define FLT_EVAL_METHOD        1
#define MATH_ERRNO             1
#define MATH_ERREXCEPT         2
#define math_errhandling       1

#ifdef __CLANG

#define HUGE_VAL               (1.7014117331E+38)
#define HUGE_VALF              (1.7014117331E+38)
#define INFINITY               (1.7014117331E+38)

#endif

#ifdef __SDCC

#define HUGE_VAL               (1.7014117331E+38)
#define HUGE_VALF              (1.7014117331E+38)
#define INFINITY               (1.7014117331E+38)

#endif

#ifdef __SCCZ80

#define HUGE_VAL               (1.7014118346E+38)
#define HUGE_VALF              (1.7014118346E+38)
#define INFINITY               (1.7014118346E+38)

#endif

#ifdef __MATH_AM9511

#define HUGE_POS_F32            (+9.2e+18)
#define TINY_POS_F32            (+2.7e-20)
#define HUGE_NEG_F32            (-9.2e+18)
#define TINY_NEG_F32            (-2.7e-20)

#define MAXL2_F32               (+63.0)
#define MINL2_F32               (-64.0)
#define MAXLOG_F32              (+43.6657)
#define MINLOG_F32              (−45.0)
#define MAXL10_F32              (+18.9638)
#define MINL10_F32              (−19.5686)

#define HUGE_VAL_F32           (0x7F800000)
#define INFINITY_POS_F32       (0x7F800000)
#define INFINITY_NEG_F32       (0xFF800000)

#endif

#ifdef __MATH_MATH32

#define HUGE_POS_F32           (+3.4028234664E+38)
#define TINY_POS_F32           (+1.1754943508E−38)
#define HUGE_NEG_F32           (-1.7014118346E+38)
#define TINY_NEG_F32           (-1.1754943508E-38)

#define MAXL2_F32              (+127.999999914)
#define MINL2_F32              (-126.0)
#define MAXLOG_F32             (+88.722839052)
#define MINLOG_F32             (−87.336544751)
#define MAXL10_F32             (+38.230809449)
#define MINL10_F32             (−37.929779454)

#define HUGE_VAL_F32           (0x7F800000)
#define INFINITY_POS_F32       (0x7F800000)
#define INFINITY_NEG_F32       (0xFF800000)

#endif

#ifdef __MATH_MATH16

#define HUGE_POS_F16            (+6.5504E+4)        /* 0x7BFF */
#define TINY_POS_F16            (+6.10352E-5)       /* 0x0400 */
#define HUGE_NEG_F16            (-6.5504E+4)        /* 0xFBFF */
#define TINY_NEG_F16            (-6.10352E-5)       /* 0x8400 */

#define MAXL2_F16               (+15.999)           /* 0x4BFF */
#define MINL2_F16               (-14.00)            /* 0xCB00 */
#define MAXLOG_F16              (+11.086)           /* 0x498B */
#define MINLOG_F16              (-9.700)            /* 0xC8DA */      
#define MAXL10_F16              (+4.816)            /* 0x44D1 */
#define MINL10_F16              (-4.215)            /* 0xC437 */

#define HUGE_VAL_F16            (0x7C00)
#define INFINITY_POS_F16        (0x7C00)
#define INFINITY_NEG_F16        (0xFC00)

#endif

__DPROTO(,,double_t,,acos,double_t x)
__DPROTO(,,double_t,,asin,double_t x)
__DPROTO(,,double_t,,atan,double_t x)
__DPROTO(,,double_t,,atan2,double_t y,double_t x)

__DPROTO(,,double_t,,cos,double_t x)
__DPROTO(,,double_t,,sin,double_t x)
__DPROTO(,,double_t,,tan,double_t x)

__DPROTO(,,double_t,,acosh,double_t x)
__DPROTO(,,double_t,,asinh,double_t x)
__DPROTO(,,double_t,,atanh,double_t x)

__DPROTO(,,double_t,,cosh,double_t x)
__DPROTO(,,double_t,,sinh,double_t x)
__DPROTO(,,double_t,,tanh,double_t x)

__DPROTO(,,double_t,,exp,double_t x)
__DPROTO(,,double_t,,exp2,double_t x)
__DPROTO(,,double_t,,expm1,double_t x)
__DPROTO(,,double_t,,frexp,double_t value,int *exp)
__DPROTO(,,int,,ilogb,double_t x)
__DPROTO(,,double_t,,ldexp,double_t x,int exp)
__DPROTO(,,double_t,,scalbn,double_t x,int n)	
__DPROTO(,,double_t,,scalbln,double_t x,int n)

__DPROTO(,,double_t,,log,double_t x)
__DPROTO(,,double_t,,log10,double_t x)
__DPROTO(,,double_t,,log1p,double_t x)
__DPROTO(,,double_t,,log2,double_t x)
__DPROTO(,,double_t,,logb,double_t x)

__DPROTO(,,double_t,,fabs,double_t x)
__DPROTO(,,double_t,,hypot,double_t x,double_t y)

__DPROTO(,,double_t,,pow,double_t x,double_t y)
__DPROTO(,,double_t,,sqrt,double_t x)
__DPROTO(,,double_t,,cbrt,double_t x)

__DPROTO(,,double_t,,erf,double_t x)
__DPROTO(,,double_t,,erfc,double_t x)
__DPROTO(,,double_t,,lgamma,double_t x)
__DPROTO(,,double_t,,tgamma,double_t x)

__DPROTO(,,double_t,,ceil,double_t x)
__DPROTO(,,double_t,,floor,double_t x)
__DPROTO(,,double_t,,nearbyint,double_t x)
__DPROTO(,,double_t,,rint,double_t x)
__DPROTO(,,long,,lrint,double_t x)
__DPROTO(,,double_t,,round,double_t x)
__DPROTO(,,long,,lround,double_t x)
__DPROTO(,,double_t,,trunc,double_t x)

__DPROTO(,,double_t,,modf,double_t value,double_t *iptr)
__DPROTO(,,double_t,,fmod,double_t x,double_t y)
__DPROTO(,,double_t,,remainder,double_t x,double_t y)
__DPROTO(,,double_t,,remquo,double_t x,double_t y,int *quo)

__DPROTO(,,double_t,,copysign,double_t x,double_t y)
__DPROTO(,,double_t,,nan,const char *tagp)

__DPROTO(,,double_t,,nextafter,double_t x,double_t y)
__DPROTO(,,double_t,,nexttoward,double_t x,double_t y)

__DPROTO(,,double_t,,fdim,double_t x,double_t y)

__DPROTO(,,double_t,,fmax,double_t x,double_t y)
__DPROTO(,,double_t,,fmin,double_t x,double_t y)

__DPROTO(,,double_t,,fma,double_t x,double_t y,double_t z)

__DPROTO(,,int,,isgreater,double_t x,double_t y)
__DPROTO(,,int,,isgreaterequal,double_t x,double_t y)
__DPROTO(,,int,,isless,double_t x,double_t y)
__DPROTO(,,int,,islessequal,double_t x,double_t y)
__DPROTO(,,int,,islessgreater,double_t x,double_t y)
__DPROTO(,,int,,isunordered,double_t x,double_t y)

#ifdef __MATH_MATH32

__DPROTO(,,double_t,,neg,double_t x)
__DPROTO(,,double_t,,sqr,double_t x)
__DPROTO(,,double_t,,inv,double_t x)
__DPROTO(,,double_t,,invsqrt,double_t x)
__DPROTO(,,double_t,,div2,double_t x)
__DPROTO(,,double_t,,mul2,double_t x)
__DPROTO(,,double_t,,mul10u,double_t x)
__DPROTO(,,double_t,,exp10,double_t x)
__DPROTO(,,double_t,,poly, const float x, const float d[], unsigned int n)

#endif

#ifdef __MATH_AM9511

__DPROTO(,,double_t,,f32_fam9511,double_t x)
__DPROTO(,,double_t,,fam9511_f32,double_t x)
__DPROTO(,,double_t,,neg,double_t x)
__DPROTO(,,double_t,,sqr,double_t x)
__DPROTO(,,double_t,,div2,double_t x)
__DPROTO(,,double_t,,mul2,double_t x)
__DPROTO(,,double_t,,mul10u,double_t x)
__DPROTO(,,double_t,,exp10,double_t x)

#endif

#ifdef __MATH_MATH16

__DPROTO(,,half_t,,f16_f48,double_t x)
__DPROTO(,,double_t,,f48_f16,half_t x)

__DPROTO(,,half_t,,f16_f32,float_t x)
__DPROTO(,,float_t,,f32_f16,half_t x)

__DPROTO(,,int16_t,,i16_f16,half_t x)
__DPROTO(,,uint16_t,,u16_f16,half_t x)
__DPROTO(,,int32_t,,i32_f16,half_t x)
__DPROTO(,,uint32_t,,u32_f16,half_t x)

__DPROTO(,,half_t,,f16_i8,int8_t x)
__DPROTO(,,half_t,,f16_i16,int16_t x)
__DPROTO(,,half_t,,f16_i32,int32_t x)
__DPROTO(,,half_t,,f16_u8,uint8_t x)
__DPROTO(,,half_t,,f16_u16,uint16_t x)
__DPROTO(,,half_t,,f16_u32,uint32_t x)

__DPROTO(,,half_t,,addf16,half_t x,half_t y)
__DPROTO(,,half_t,,subf16,half_t x,half_t y)
__DPROTO(,,half_t,,mulf16,half_t x,half_t y)
__DPROTO(,,half_t,,divf16,half_t x,half_t y)

__DPROTO(,,half_t,,fmaf16,half_t x,half_t y,half_t z)
__DPROTO(,,half_t,,polyf16,half_t x,float_t d[],uint16_t n)
__DPROTO(,,half_t,,hypotf16,half_t x,half_t y)

__DPROTO(,,half_t,,invf16,half_t x)
__DPROTO(,,half_t,,invsqrtf16,half_t x)

__DPROTO(,,half_t,,sqrtf16,half_t x)

__DPROTO(,,half_t,,div2f16,half_t x)
__DPROTO(,,half_t,,mul2f16,half_t x)
__DPROTO(,,half_t,,mul10f16,half_t x)
__DPROTO(,,half_t,,frexpf16,half_t x,int16_t *pw2)
__DPROTO(,,half_t,,ldexpf16,half_t x,int16_t pw2)

__DPROTO(,,half_t,,acosf16,half_t x)
__DPROTO(,,half_t,,asinf16,half_t x)
__DPROTO(,,half_t,,atanf16,half_t x)
__DPROTO(,,half_t,,atan2f16,half_t y,half_t x)

__DPROTO(,,half_t,,cosf16,half_t x)
__DPROTO(,,half_t,,sinf16,half_t x)
__DPROTO(,,half_t,,tanf16,half_t x)

__DPROTO(,,half_t,,expf16,half_t x)
__DPROTO(,,half_t,,exp2f16,half_t x)
__DPROTO(,,half_t,,exp10f16,half_t x)
__DPROTO(,,half_t,,logf16,half_t x)
__DPROTO(,,half_t,,log2f16,half_t x)
__DPROTO(,,half_t,,log10f16,half_t x)
__DPROTO(,,half_t,,powf16,half_t x,half_t y)

__DPROTO(,,half_t,,fabsf16,half_t x)
__DPROTO(,,half_t,,negf16,half_t x)
__DPROTO(,,half_t,,ceilf16,half_t x)
__DPROTO(,,half_t,,floorf16,half_t x)

__DPROTO(,,int,,isgreaterf16,half_t x,half_t y)
__DPROTO(,,int,,isgreaterequalf16,half_t x,half_t y)
__DPROTO(,,int,,islessf16,half_t x,half_t y)
__DPROTO(,,int,,islessequalf16,half_t x,half_t y)
__DPROTO(,,int,,islessgreaterf16,half_t x,half_t y)
__DPROTO(,,int,,isnotequalf16,half_t x,half_t y)
__DPROTO(,,int,,isunorderedf16,half_t x,half_t y)

#define scalbnf16(x,pw2) ldexpf16(x,pw2)

#define truncf16(a) (a>0.?floorf16(a):ceilf16(a))
#define roundf16(a) (a>0.?floorf16(a+0.5):ceilf16(a-0.5))
#define rintf16(a) ceilf16(a)

#endif

// NO DISTINCTION BETWEEN FLOAT AND DOUBLE

#define acosf        acos
#define asinf        asin
#define atanf        atan
#define atan2f       atan2

#define cosf         cos
#define sinf         sin
#define tanf         tan

#define acoshf       acosh
#define asinhf       asinh
#define atanhf       atanh

#define coshf        cosh
#define sinhf        sinh
#define tanhf        tanh

#define expf         exp
#define exp2f        exp2
#define exp10f       exp10
#define expm1f       expm1
#define frexpf       frexp
#define ilogbf       ilogb
#define ldexpf       ldexp

#define logf         log
#define log2f        log2
#define log10f       log10
#define log1pf       log1p
#define logbf        logb

#define scalbnf      scalbn
#define scalblnf     scalbln

#define fabsf        fabs
#define hypotf       hypot

#define powf         pow
#define sqrtf        sqrt
#define cbrtf        cbrt

#define erff         erf
#define erfcf        erfc
#define lgammaf      lgamma
#define tgammaf      tgamma

#define ceilf        ceil
#define floorf       floor
#define nearbyintf   nearbyint
#define rintf        rint
#define lrintf       lrint
#define llrintf      llrint
#define roundf       round
#define lroundf      lround
#define llroundf     llround
#define truncf       trunc

#define modff        modf
#define fmodf        fmod
#define remainderf   remainder
#define remquof      remquo

#define copysignf    copysign
#define nanf         nan

#define nextafterf   nextafter
#define nexttowardf  nexttoward

#define fdimf        fdim

#define fmaxf        fmax
#define fminf        fmin

#define fmaf         fma

#ifdef __MATH_MATH32

#define sqrf         sqr
#define invf         inv
#define invsqrtf     insqrt
#define div2f        div2
#define mul2f        mul2
#define mul10uf      mul10u
#define exp10f       exp10
#define polyf        poly

#endif

#ifdef __MATH_AM9511

#define sqrf         sqr
#define div2f        div2
#define mul2f        mul2
#define mul10uf      mul10u
#define exp10f       exp10

#endif

#endif
