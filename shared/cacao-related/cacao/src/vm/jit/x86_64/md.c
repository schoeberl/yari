/* src/vm/jit/x86_64/md.c - machine dependent x86_64 functions

   Copyright (C) 1996-2005, 2006, 2007 R. Grafl, A. Krall, C. Kruegel,
   C. Oates, R. Obermaisser, M. Platter, M. Probst, S. Ring,
   E. Steiner, C. Thalinger, D. Thuernbeck, P. Tomsich, C. Ullrich,
   J. Wenninger, Institut f. Computersprachen - TU Wien

   This file is part of CACAO.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2, or (at
   your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301, USA.

   $Id: md.c 7596 2007-03-28 21:05:53Z twisti $

*/


#include "config.h"

#include <assert.h>
#include <stdlib.h>

#include "vm/jit/x86_64/md-abi.h"

#if defined(ENABLE_THREADS)
# include "threads/native/threads.h"
#endif

#include "vm/jit/asmpart.h"
#include "vm/jit/codegen-common.h"
#include "vm/jit/stacktrace.h"

#if !defined(NDEBUG) && defined(ENABLE_DISASSEMBLER)
#include "vmcore/options.h" /* XXX debug */
#include "vm/jit/disass.h" /* XXX debug */
#endif


/* md_init *********************************************************************

   Do some machine dependent initialization.

*******************************************************************************/

void md_init(void)
{
	/* nothing to do */
}


/* md_stacktrace_get_returnaddress *********************************************

   Returns the return address of the current stackframe, specified by
   the passed stack pointer and the stack frame size.

*******************************************************************************/

u1 *md_stacktrace_get_returnaddress(u1 *sp, u4 framesize)
{
	u1 *ra;

	/* on x86_64 the return address is above the current stack frame */

	ra = *((u1 **) (sp + framesize));

	return ra;
}


/* md_get_method_patch_address *************************************************

   Gets the patch address of the currently compiled method. The offset
   is extracted from the load instruction(s) before the jump and added
   to the right base address (PV or REG_METHODPTR).

   INVOKESTATIC/SPECIAL:

   4d 8b 15 e2 fe ff ff             mov    -286(%rip),%r10
   49 ff d2                         rex64Z callq  *%r10

   INVOKEVIRTUAL:

   4c 8b 17                         mov    (%rdi),%r10
   49 8b 82 00 00 00 00             mov    0x0(%r10),%rax
   48 ff d3                         rex64 callq  *%rax

   INVOKEINTERFACE:

   4c 8b 17                         mov    (%rdi),%r10
   4d 8b 92 00 00 00 00             mov    0x0(%r10),%r10
   49 8b 82 00 00 00 00             mov    0x0(%r10),%rax
   48 ff d3                         rex64 callq  *%r11

*******************************************************************************/

u1 *md_get_method_patch_address(u1 *ra, stackframeinfo *sfi, u1 *mptr)
{
	u1  mcode;
	s4  offset;
	u1 *pa;                             /* patch address                      */

	/* go back to the actual call instruction (3-bytes) */

	ra = ra - 3;

	/* get the last byte of the call */

	mcode = ra[2];

	/* check for the different calls */

	if (mcode == 0xd2) {
		/* INVOKESTATIC/SPECIAL */

		/* Get the offset from the instruction (the offset address is
		   4-bytes before the call instruction). */

		offset = *((s4 *) (ra - 4));

		/* add the offset to the return address (IP-relative addressing) */

		pa = ra + offset;
	}
	else if (mcode == 0xd3) {
		/* INVOKEVIRTUAL/INTERFACE */

		/* return NULL if no mptr was specified (used for replacement) */

		if (mptr == NULL)
			return NULL;

		/* Get the offset from the instruction (the offset address is
		   4-bytes before the call instruction). */

		offset = *((s4 *) (ra - 4));

		/* add the offset to the method pointer */

		pa = mptr + offset;
	}
	else {
		/* catch any problems */

		assert(0);
	}

	return pa;
}


/* md_codegen_get_pv_from_pc ***************************************************

   On this architecture just a wrapper function to
   codegen_get_pv_from_pc.

*******************************************************************************/

u1 *md_codegen_get_pv_from_pc(u1 *ra)
{
	u1 *pv;

	/* Get the start address of the function which contains this
       address from the method table. */

	pv = codegen_get_pv_from_pc(ra);

	return pv;
}


/* md_cacheflush ***************************************************************

   Calls the system's function to flush the instruction and data
   cache.

*******************************************************************************/

void md_cacheflush(u1 *addr, s4 nbytes)
{
	/* do nothing */
}


/* md_icacheflush **************************************************************

   Calls the system's function to flush the instruction cache.

*******************************************************************************/

void md_icacheflush(u1 *addr, s4 nbytes)
{
	/* do nothing */
}


/* md_dcacheflush **************************************************************

   Calls the system's function to flush the data cache.

*******************************************************************************/

void md_dcacheflush(u1 *addr, s4 nbytes)
{
	/* do nothing */
}


/* md_patch_replacement_point **************************************************

   Patch the given replacement point.

*******************************************************************************/

#if defined(ENABLE_REPLACEMENT)
void md_patch_replacement_point(codeinfo *code, s4 index, rplpoint *rp, u1 *savedmcode)
{
	s4 disp;
	u8 mcode;

	/* XXX this is probably unsafe! */

	if (index < 0) {
		/* write spinning instruction */
		*(u2*)(rp->pc) = 0xebfe;

		/* write 5th byte */
		rp->pc[4] = savedmcode[4];

		/* write first word */
		*(u4*)(rp->pc) = *(u4*)(savedmcode);
	}
	else {
		/* save the current machine code */
		*(u4*)(savedmcode) = *(u4*)(rp->pc);
		savedmcode[4] = rp->pc[4];

		/* build the machine code for the patch */
		disp = (code->replacementstubs - rp->pc)
			   + index * REPLACEMENT_STUB_SIZE
			   - 5;

		mcode = 0xe9 | ((u8) disp << 8);

		/* write spinning instruction */
		*(u2*)(rp->pc) = 0xebfe;

		/* write 5th byte */
		rp->pc[4] = (mcode >> 32);

		/* write first word */
		*(u4*)(rp->pc) = (u4) mcode;
	}

#if !defined(NDEBUG) && defined(ENABLE_DISASSEMBLER) && 0
	{
		u1* u1ptr = rp->pc;
		DISASSINSTR(u1ptr);
		fflush(stdout);
	}
#endif
			
    /* XXX if required asm_cacheflush(rp->pc,8); */
}
#endif /* defined(ENABLE_REPLACEMENT) */

/*
 * These are local overrides for various environment variables in Emacs.
 * Please do not remove this and leave it at the end of the file, where
 * Emacs will automagically detect them.
 * ---------------------------------------------------------------------
 * Local variables:
 * mode: c
 * indent-tabs-mode: t
 * c-basic-offset: 4
 * tab-width: 4
 * End:
 * vim:noexpandtab:sw=4:ts=4:
 */
