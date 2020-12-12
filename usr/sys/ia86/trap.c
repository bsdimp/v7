#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
#include "../h/reg.h"
#include "../h/seg.h"

/*
 * Offsets of the user's registers relative to
 * the saved r0. See reg.h
 */
char	regloc[9] =
{
	R0, R1, R2, R3, R4, R5, R6, R7, RPS
};

/*
 * Called from l40.s or l45.s when a processor trap occurs.
 * The arguments are the words saved on the system stack
 * by the hardware and software during the trap processing.
 * Their order is dictated by the hardware and the details
 * of C's calling sequence. They are peculiar in that
 * this call is not 'by value' and changed user registers
 * get copied back on return.
 * dev is the kind of trap that occurred.
 */
trap(dev, sp, r1, nps, r0, pc, ps)
int *pc;
dev_t dev;
{
}

/*
 * nonexistent system call-- set fatal error code.
 */
nosys()
{
	u.u_error = EINVAL;
}

/*
 * Ignored system call
 */
nullsys()
{
}
