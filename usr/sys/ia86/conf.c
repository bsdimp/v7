#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
#include "../h/tty.h"
#include "../h/conf.h"
#include "../h/proc.h"
#include "../h/text.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/file.h"
#include "../h/inode.h"
#include "../h/acct.h"

int	nulldev();
int	nodev();
int	hdopen(), hdstrategy();
struct buf hdtab;
int	fdstrategy();
struct buf fdtab;
int	mdstrategy();
struct buf mdtab;
struct	bdevsw	bdevsw[] =
{
	hdopen, nulldev, hdstrategy, &hdtab,	/* hd = 0 */
	nulldev, nulldev, fdstrategy, &fdtab,	/* fd = 1 */
	nulldev, nulldev, mdstrategy, &mdtab,	/* md = 2 */
	0
};

int	hdread(), hdwrite();
int	syopen(), syread(), sywrite(), sysioctl();
int	scopen(), scclose(), scread(), scwrite(), scioctl();
int	mmread(), mmwrite();
int	sropen(), srclose(), srread(), srwrite(), srioctl();
struct	tty	sr[];
int	fdread(), fdwrite();
int	mdread(), mdwrite();
int	cdread();

struct	cdevsw	cdevsw[] =
{
	scopen, scclose, scread, scwrite, scioctl, nulldev, 0,	/* console = 0 */
	nulldev, nulldev, mmread, mmwrite, nodev, nulldev, 0,	/* mem = 1 */
	syopen, nulldev, syread, sywrite, sysioctl, nulldev, 0,	/* tty = 2 */
	sropen, srclose, srread, srwrite, srioctl, nulldev, sr,	/* sr = 3 */
	hdopen, nulldev, hdread, hdwrite, nodev, nulldev, 0,	/* hd = 4 */
	nulldev, nulldev, fdread, fdwrite, nodev, nulldev, 0,	/* fd = 5 */
	nulldev, nulldev, mdread, mdwrite, nodev, nulldev, 0,	/* md = 6 */
	nulldev, nulldev, cdread, nodev, nodev, nulldev, 0,	/* cd = 7 */
	0
};

int	ttyopen(), ttyclose(), ttread(), ttwrite(), ttyinput(), ttstart();
struct	linesw	linesw[] =
{
	ttyopen, nulldev, ttread, ttwrite, nodev, ttyinput, ttstart, /* 0 */
	0
};
int	rootdev	= makedev(0, 0);
int	swapdev	= makedev(0, 0);
int	pipedev = makedev(0, 0);
int	nldisp = 1;
daddr_t	swplo	= 4000;
int	nswap	= 872;
	
struct	buf	buf[NBUF];
struct	file	file[NFILE];
struct	inode	inode[NINODE];
#if 0
int	mpxchan();
int	(*ldmpx)() = mpxchan;
#endif
struct	proc	proc[NPROC];
struct	text	text[NTEXT];
struct	buf	bfreelist;
struct	acct	acctbuf;
struct	inode	*acctp;
struct user u;

/* XXX */
caddr_t waitloc;
