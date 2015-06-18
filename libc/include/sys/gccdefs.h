#ifndef _SYS_GCCDEFS_H
#define _SYS_GCCDEFS_H

#define UNUSED __attribute__ ((unused))
#define NO_RETURN __attribute__ ((noreturn))
#define NO_INLINE __attribute__ ((noinline))
#define INLINE __attribute__ ((always_inline))
#define PACKED __attribute__ ((packed))
#define PRINTF_FORMAT(FMT, FIRST) __attribute__ ((format (printf, FMT, FIRST)))

#endif
