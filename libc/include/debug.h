#ifndef _DEBUG_H
#define _DEBUG_H

#include <sys/gccdefs.h>

#define PANIC(...) debug_panic (__FILE__, __LINE__, __func__, __VA_ARGS__)

void debug_panic (const char *file, int line, const char *function,
                  const char *message, ...) PRINTF_FORMAT (4, 5) NO_RETURN;
void debug_backtrace (void);

#endif

#undef ASSERT
#undef NOT_REACHED

#ifndef NDEBUG
#define ASSERT(CONDITION)                                       \
        if (CONDITION) { } else {                               \
                PANIC ("Assertion `%s' failed.", #CONDITION);   \
        }
#define NOT_REACHED() PANIC ("Executed an unreachable statement.");
#else
#define ASSERT(CONDITION) ((void) 0)
#define NOT_REACHED() for (;;)
#endif
