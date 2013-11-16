/*
 *	armccsp_types.h -- assorted types for ARM/CCSP
 *	Copyright (C) 2013 Fred Barnes, University of Kent <frmb@kent.ac.uk>
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef __ARMCCSP_TYPES_H
#define __ARMCCSP_TYPES_H

#ifdef __GNUC__
#define _PACK_STRUCT __attribute__ ((packed))
#else	/* !__GNUC__ */
#warning "Unable to enforce alignment and packing on structures."
#define _PACK_STRUCT
#endif	/* !__GNUC__ */

struct TAG_ccsp_sched;

/* for processes, maximum number of parameters (words) that may be passed */
#define MAXPARAMS (16)

/* process workspace type */
typedef struct TAG_ccsp_pws {
	struct TAG_ccsp_sched *sched;			/* link to associated scheduler structure (used in enqueue) */
	void *stack;					/* process stack (current) */
	void *stack_base;				/* process stack (base address) */
	struct TAG_ccsp_pws *link;			/* link to next process in queue */
	void *pointer;
	uint32_t priofinity;
	uint32_t params[MAXPARAMS];
	int nparams;
} _PACK_STRUCT ccsp_pws_t;

#define NotProcess_p	NULL

/* scheduler state */
typedef struct TAG_ccsp_sched {
	void *stack;
	ccsp_pws_t *curp;				/* currently executing process */
	ccsp_pws_t *fptr, *bptr;			/* run-queue front and back pointers */
} _PACK_STRUCT ccsp_sched_t;


extern ccsp_sched_t *ccsp_scheduler (void);

#endif	/* !__ARMCCSP_TYPES_H */

