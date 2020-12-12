/
/ Low core routines for ia86 port of V7
/
	.arch i8086,jumps
	.code16
	.att_syntax prefix
#NO_APP
	.text
	.globl	_start
_start:	cli
	call	main
	ret

	.globl	spl0,spl1,spl2,spl3,spl4,spl5,spl6,spl7,splx
spl0:
	pushf
	sti
	pop	%ax	/ Return old flags for splx
        ret
spl1:
spl2:
spl3:
spl4:
spl5:
spl6:
spl7:
	pushf
	cli
	pop     %ax	/ Return old flags for splx
	ret
splx:
        pop     %cx
        popf
	pushf
	jmp	*%cx
	
	.globl copyin
copyin:
	.globl copyiin
copyiin:
	.globl copyout
copyout:
	.globl copyiout
copyiout:
	.globl copyseg
copyseg:
	.globl	suibyte
suibyte:
	.globl	fuibyte
fuibyte:
	.globl	subyte
subyte:
	.globl	fubyte
fubyte:
	.globl	suiword
suiword:
	.globl	fuiword
fuiword:
	.globl	suword
suword:
	.globl	fuword
fuword:
	.globl	idle
idle:
	.globl	save
save:
	.globl	resume
resume:
	.globl	savfp
savfp:
	.globl	clearseg
clearseg:
	.globl	restfp
restfp:
	.globl	stst
stst:
	.globl	backup
backup:
	.globl	addupc
addupc:
	.globl	timeout
timeout:
	.globl	ttioccom
ttioccom:
	.globl	__divsi3
__divsi3:
	.globl	__mulsi3
__mulsi3:
	.globl	__modsi3
__modsi3:
	.globl	__ashrsi3
__ashrsi3: