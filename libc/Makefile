HOST?=$(shell ../default-host.sh)
HOSTARCH:=$(shell ../target-triplet-to-arch.sh $(HOST))

CFLAGS?=-O2
LDFLAGS?=
LIBS?=

DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
INCLUDEDIR?=$(PREFIX)/include
LIBDIR?=$(EXEC_PREFIX)/lib

CFLAGS:=$(CFLAGS) -Wall -Wextra -D__is_tobyos_libc -Iinclude 
KERNEL_CFLAGS:=$(CFLAGS) -ffreestanding -fbuiltin -D__is_tobyos_kernel

ARCHDIR:=arch/$(HOSTARCH)

include $(ARCHDIR)/make.config

CFLAGS:=$(CFLAGS) $(ARCH_CFLAGS)
KERNEL_CFLAGS:=$(KERNEL_CFLAGS) $(KERNEL_ARCH_CFLAGS)

FREEOBJS:=\
$(ARCH_FREEOBJS) \
stdio/vprintf.o \
stdio/printf.o \
stdio/puts.o \
string/memcmp.o \
string/memcpy.o \
string/memmove.o \
string/memset.o \
string/strlen.o \
debug/debug_backtrace.o \

HOSTEDOBJS:=\
$(ARCH_HOSTEDOBJS) \

OBJS:=\
$(FREEOBJS) \
$(HOSTEDOBJS) \

USER_OBJS:=\
$(OBJS) \
stdio/user/putchar.o \

KERNEL_OBJS:=$(FREEOBJS:.o=.libk.o) \
stdio/kernel/putchar.o \
debug/kernel/debug_panic.o 

BINARIES=libc.a libg.a libk.a

all: $(BINARIES)

.PHONY: all clean install install-headers install-libs

libc.a: $(USER_OBJS) 
	$(AR) rcs $@ $(USER_OBJS)

libg.a:
	$(AR) rcs $@

libk.a: $(KERNEL_OBJS)
	$(AR) rcs $@ $(KERNEL_OBJS)

%.o: %.c
	$(CC) -c $< -o $@ -std=gnu11 $(CFLAGS)

%.o: %.S
	$(CC) -c $< -o $@ $(CFLAGS)

%.libk.o: %.c
	$(CC) -c $< -o $@ -std=gnu11 $(KERNEL_CFLAGS)

%.libk.o: %.S
	$(CC) -c $< -o $@ $(KERNEL_CFLAGS)

clean:
	rm -f $(BINARIES) $(USER_OBJS) $(KERNEL_OBJS) *.o */*.o */*/*.o

install: install-headers install-libs

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -RTuv include $(DESTDIR)$(INCLUDEDIR)

install-libs: $(BINARIES)
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp -u $(BINARIES) $(DESTDIR)$(LIBDIR)
