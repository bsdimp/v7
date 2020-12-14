# 7th Edition Unix Ported to 8088 and 8086

As part of my Venix reconstruction efforts that have been going on for
some time, I thought I'd approach the problem from a different angle.

This work aims to take a rather vanilla 7th edition and port it to my
Old DEC Rainbow and the IBM PC/XT and maybe AT.

Look in usr for the work to date. So far it contains just a stubbed
out version of the 7th edition compiling with TKChia's ia16-elf-gcc/binutils.
I've added the drivers from Robert Nordier's V7/x86 port that targetted 32-bit
machines. It builds and creates a unix that's an acceptable size:
```
% ia16-elf-size unix
   text	   data	    bss	    dec	    hex	filename
  31448	    548	  15256	  47252	   b894	unix
```
I suspect that it will grow my 8-10k before all is said and done
and that for the Rainbow, some of that growth may be reduced by
having smaller drivers.

For the moment, to get it running, I'll be focusing on the same
mythical machine that Elks uses to test its code with QEMU: an
IBM-PC/XT, but with modern ATA controller and IDE disk. But I also
hope to see it running on my DEC Rainbow 100B someday.

7th Edition didn't have networking, so there will likely be a side
project to port 2.9BSD and/or 2.11BSD over.


