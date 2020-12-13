# X=${HOME}/pdp11/local/bin/pdp11-dec-aout-
X=ia16-elf-
CC=${X}gcc
CFLAGS=-ffreestanding -fno-inline -melks \
	-mtune=i8086 -mcmodel=small -mno-segment-relocation-stuff -I. \
	${CWARNS}
CWARNS=	-Wno-implicit-function-declaration \
	-Wno-implicit-int \
	-fms-extensions \
	-Wno-incompatible-pointer-types
AR=${X}ar
AS=${X}as
LD=${X}ld

VPATH=../sys:../ia86dev:../dev:.

sys_OBJS=main.o \
	trap.o \
	sig.o \
	iget.o \
	prf.o \
	slp.o \
	subr.o \
	rdwri.o \
	clock.o \
	fio.o \
	malloc.o \
	alloc.o \
	machdep.o \
	nami.o \
	pipe.o \
	prim.o \
	sysent.o \
	sys3.o \
	sys1.o \
	sys4.o \
	sys2.o \
	acct.o \
	text.o \
	fakemx.o \
	ureg.o

dev_OBJS=bio.o \
	cd.o \
	fd.o \
	hd.o \
	md.o \
	mem.o \
	partab.o \
	sc.o \
	sr.o \
	sys.o \
	tty.o \
	dsort.o \
	dkleave.o

later=	mx1.o \
	mx2.o \
	pk0.o \
	pk1.o \
	pk2.o \
	pk3.o


unix:	low.o conf.o sys.a dev.a
	# -i -x
	${LD} -o unix low.o conf.o sys.a dev.a sys.a

sys.a: ${sys_OBJS}
	${AR} -cr sys.a ${sys_OBJS}

dev.a: ${dev_OBJS}
	${AR} -cr dev.a ${dev_OBJS}

