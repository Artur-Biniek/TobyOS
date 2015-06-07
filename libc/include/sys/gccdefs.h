#ifndef _SYS_GCCDEFS_H
#define _SYS_GCCDEFS_H 1

#define UNUSED __attribute__ ((unused))
#define NO_RETURN __attribute__ ((noreturn))
#define NO_INLINE __attribute__ ((noinline))
#define PACKED __attribute__ ((packed))
#define PRINTF_FORMAT(FMT, FIRST) __attribute__ ((format (printf, FMT, FIRST)))

#endif
