#ifndef _STDDEF_H
#define _STDDEF_H

#define NULL ((void *) 0)
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *) 0)->MEMBER)

typedef __PTRDIFF_TYPE__ ptrdiff_t;
typedef __SIZE_TYPE__ size_t;

#endif
