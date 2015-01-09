
#ifndef _INTTYPES_H
#define _INTTYPES_H

#include <stdint.h>

// DATA STRUCTURES

typedef struct imaxdiv_s
{

   long quot;
   long rem;

} imaxdiv_t;

#ifdef __SDCC

// SDCC

extern intmax_t                       imaxabs(intmax_t j);
extern void                           _imaxdiv_(imaxdiv_t *md, intmax_t numer, intmax_t denom);
extern intmax_t                       strtoimax(const char *nptr, char **endptr, int base);
extern uintmax_t                      strtoumax(const char *nptr, char **endptr, int base);

#else

// SCCZ80

extern intmax_t  __LIB__ __FASTCALL__ imaxabs(intmax_t j);
extern void      __LIB__              _imaxdiv_(imaxdiv_t *md, intmax_t numer, intmax_t denom);
extern intmax_t  __LIB__              strtoimax(const char *nptr, char **endptr, int base);
extern uintmax_t __LIB__              strtoumax(const char *nptr, char **endptr, int base);

// SCCZ80 CALLEE LINKAGE

extern void      __LIB__  __CALLEE__  _imaxdiv__callee(imaxdiv_t *md, intmax_t numer, intmax_t denom);
extern intmax_t  __LIB__  __CALLEE__  strtoimax_callee(const char *nptr, char **endptr, int base);
extern uintmax_t __LIB__  __CALLEE__  strtoumax_callee(const char *nptr, char **endptr, int base);

// SCCZ80 MAKE CALLEE LINKAGE THE DEFAULT

#define _imaxdiv_(a,b,c)              _imaxdiv__callee(a,b,c)
#define strtoimax(a,b,c)              strtoimax_callee(a,b,c)
#define strtoumax(a,b,c)              strtoumax_callee(a,b,c)

#endif

// PRINTF FORMAT SPECIFIERS

#define PRId8          "%d"
#define PRId16         "%d"
#define PRId32         "%ld"

#define PRIi8          "%i"
#define PRIi16         "%i"
#define PRIi32         "%li"

#define PRIdLEAST8     "%d"
#define PRIdLEAST16    "%d"
#define PRIdLEAST32    "%ld"

#define PRIiLEAST8     "%i"
#define PRIiLEAST16    "%i"
#define PRIiLEAST32    "%li"

#define PRIdFAST8      "%d"
#define PRIdFAST16     "%d"
#define PRIdFAST32     "%ld"

#define PRIiFAST8      "%i"
#define PRIiFAST16     "%i"
#define PRIiFAST32     "%li"

#define PRIdMAX        "%ld"
#define PRIiMAX        "%li"

#define PRIdPTR        "%d"
#define PRIiPTR        "%i"

#define PRIo8          "%o"
#define PRIo16         "%o"
#define PRIo32         "%lo"

#define PRIu8          "%u"
#define PRIu16         "%u"
#define PRIu32         "%lu"

#define PRIx8          "%x"
#define PRIx16         "%x"
#define PRIx32         "%lx"

#define PRIX8          "%X"
#define PRIX16         "%X"
#define PRIX32         "%lX"

#define PRIoLEAST8     "%o"
#define PRIoLEAST16    "%o"
#define PRIoLEAST32    "%lo"

#define PRIuLEAST8     "%u"
#define PRIuLEAST16    "%u"
#define PRIuLEAST32    "%lu"

#define PRIxLEAST8     "%x"
#define PRIxLEAST16    "%x"
#define PRIxLEAST32    "%lx"

#define PRIXLEAST8     "%X"
#define PRIXLEAST16    "%X"
#define PRIXLEAST32    "%lX"

#define PRIoFAST8      "%o"
#define PRIoFAST16     "%o"
#define PRIoFAST32     "%lo"

#define PRIuFAST8      "%u"
#define PRIuFAST16     "%u"
#define PRIuFAST32     "%lu"

#define PRIxFAST8      "%x"
#define PRIxFAST16     "%x"
#define PRIxFAST32     "%lx"

#define PRIXFAST8      "%X"
#define PRIXFAST16     "%X"
#define PRIXFAST32     "%lX"

#define PRIoMAX        "%lo"
#define PRIuMAX        "%lu"
#define PRIxMAX        "%lx"
#define PRIXMAX        "%lX"

#define PRIoPTR        "%o"
#define PRIuPTR        "%u"
#define PRIxPTR        "%x"
#define PRIXPTR        "%X"

// SCANF FORMAT SPECIFIERS

#define SCNd8          "%d"
#define SCNd16         "%d"
#define SCNd32         "%ld"

#define SCNi8          "%i"
#define SCNi16         "%i"
#define SCNi32         "%li"

#define SCNdLEAST8     "%d"
#define SCNdLEAST16    "%d"
#define SCNdLEAST32    "%ld"

#define SCNiLEAST8     "%i"
#define SCNiLEAST16    "%i"
#define SCNiLEAST32    "%li"

#define SCNdFAST8      "%d"
#define SCNdFAST16     "%d"
#define SCNdFAST32     "%ld"

#define SCNiFAST8      "%i"
#define SCNiFAST16     "%i"
#define SCNiFAST32     "%li"

#define SCNdMAX        "%ld"
#define SCNiMAX        "%li"

#define SCNdPTR        "%d"
#define SCNiPTR        "%i"

#define SCNo8          "%o"
#define SCNo16         "%o"
#define SCNo32         "%lo"

#define SCNu8          "%u"
#define SCNu16         "%u"
#define SCNu32         "%lu"

#define SCNx8          "%x"
#define SCNx16         "%x"
#define SCNx32         "%lx"

#define SCNoLEAST8     "%o"
#define SCNoLEAST16    "%o"
#define SCNoLEAST32    "%lo"

#define SCNuLEAST8     "%u"
#define SCNuLEAST16    "%u"
#define SCNuLEAST32    "%lu"

#define SCNxLEAST8     "%x"
#define SCNxLEAST16    "%x"
#define SCNxLEAST32    "%lx"

#define SCNoFAST8      "%o"
#define SCNoFAST16     "%o"
#define SCNoFAST32     "%lo"

#define SCNuFAST8      "%u"
#define SCNuFAST16     "%u"
#define SCNuFAST32     "%lu"

#define SCNxFAST8      "%x"
#define SCNxFAST16     "%x"
#define SCNxFAST32     "%lx"

#define SCNoMAX        "%lo"
#define SCNuMAX        "%lu"
#define SCNxMAX        "%lx"

#define SCNoPTR        "%o"
#define SCNuPTR        "%u"
#define SCNxPTR        "%x"

#endif
