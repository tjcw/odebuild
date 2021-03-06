/*
 * @OSF_FREE_COPYRIGHT@
 * COPYRIGHT NOTICE
 * Copyright (c) 1992, 1991, 1990  
 * Open Software Foundation, Inc. 
 *  
 * Permission is hereby granted to use, copy, modify and freely distribute 
 * the software in this file and its documentation for any purpose without 
 * fee, provided that the above copyright notice appears in all copies and 
 * that both the copyright notice and this permission notice appear in 
 * supporting documentation.  Further, provided that the name of Open 
 * Software Foundation, Inc. ("OSF") not be used in advertising or 
 * publicity pertaining to distribution of the software without prior 
 * written permission from OSF.  OSF makes no representations about the 
 * suitability of this software for any purpose.  It is provided "as is" 
 * without express or implied warranty. 
 */
/*
 * HISTORY
 * $Log: getcwd.c,v $
 * Revision 1.2.4.2  1993/01/13  16:43:58  damon
 * 	CR 382. Removed PATH_MAX
 * 	[1993/01/05  20:55:12  damon]
 *
 * Revision 1.2.2.2  1992/12/03  17:21:44  damon
 * 	ODE 2.2 CR 183. Added CMU notice
 * 	[1992/12/03  17:08:41  damon]
 * 
 * Revision 1.2  1991/12/05  20:44:55  devrcs
 * 	Changes for Reno make
 * 	[91/03/22  16:09:33  mckeen]
 * 
 * $EndLog$
 */
/*
 * Portable version for getcwd suitable for use by make, but not for others
 */

#include <sys/param.h>
#include <sys/errno.h>
#include <stdio.h>

extern int errno;

char *
getcwd(buf, bufsize)
    char *buf;
    int bufsize;
{
    if (bufsize != PATH_MAX + 1) {
	errno = ERANGE;
	return(NULL);
    }
    if (getwd(buf) == NULL) {
	if (errno == 0)
	    errno = EACCES;	/* better than 0 ? */
	return(NULL);
    }
    return(buf);
}
