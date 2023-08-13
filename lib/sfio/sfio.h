/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: Details at https://graphviz.org
 *************************************************************************/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*	Public header file for the sfio library
**
**	Written by Kiem-Phong Vo
*/

#include "config.h"

#ifdef HAVE_SYS_TYPES_H
#   include <sys/types.h>
#endif // HAVE_SYS_TYPES_H

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

#define Sflong_t	long long
#define Sfulong_t	unsigned long long
#define Sfdouble_t	long double

/* formatting environment */
    typedef struct _sffmt_s Sffmt_t;
    typedef int (*Sffmtext_f)(void *, Sffmt_t *);
    struct _sffmt_s {
	Sffmtext_f extf;	/* function to process arguments        */

	char *form;		/* format string to stack               */
	va_list args;		/* corresponding arg list               */

	int fmt;		/* format character                     */
	ssize_t size;		/* object size                          */
	int flags;		/* formatting flags                     */
	int width;		/* width of field                       */
	int precis;		/* precision required                   */
	int base;		/* conversion base                      */

	const char *t_str;		/* type string                          */
	ssize_t n_str;		/* length of t_str                      */
    };

#define SFFMT_SSHORT	00000010	/* 'hh' flag, char                     */
#define SFFMT_TFLAG	00000020	/* 't' flag, ptrdiff_t                 */
#define SFFMT_ZFLAG	00000040	/* 'z' flag, size_t                    */

#define SFFMT_LEFT	00000100	/* left-justification                  */
#define SFFMT_SIGN	00000200	/* must have a sign                    */
#define SFFMT_BLANK	00000400	/* if not signed, prepend a blank      */
#define SFFMT_ZERO	00001000	/* zero-padding on the left            */
#define SFFMT_ALTER	00002000	/* alternate formatting                */
#define SFFMT_THOUSAND	00004000	/* thousand grouping                   */
#define SFFMT_SKIP	00010000	/* skip assignment in scanf()          */
#define SFFMT_SHORT	00020000	/* 'h' flag                            */
#define SFFMT_LONG	00040000	/* 'l' flag                            */
#define SFFMT_LLONG	00100000	/* 'll' flag                           */
#define SFFMT_LDOUBLE	00200000	/* 'L' flag                            */
#define SFFMT_VALUE	00400000	/* value is returned                   */
#define SFFMT_ARGPOS	01000000	/* getting arg for $ patterns          */
#define SFFMT_IFLAG	02000000	/* 'I' flag                            */
#define SFFMT_JFLAG	04000000	/* 'j' flag, intmax_t                  */
#define SFFMT_SET	07777770	/* flags settable on calling extf      */

#define SF_MALLOC	0000020	/* buffer is malloc-ed                  */
#define SF_LINE		0000040	/* line buffering                       */
#define SF_SHARE	0000100	/* stream with shared file descriptor   */
#define SF_EOF		0000200	/* eof was detected                     */
#define SF_STATIC	0001000	/* a stream that cannot be freed        */
#define SF_IOCHECK	0002000	/* call exceptf before doing IO         */
#define SF_PUBLIC	0004000	/* SF_SHARE and follow physical seek    */
#define SF_WHOLE	0020000	/* preserve wholeness of sfwrite/sfputr */

#define SF_FLAGS	0077177	/* PUBLIC FLAGS PASSABLE TO SFNEW()     */

     extern ssize_t _Sfi;

    extern int sfprint(FILE*, Sffmt_t *format);
    extern int sfscanf(FILE*, const char *, ...);
    extern int sfvscanf(FILE*, const char *, va_list);

/* miscellaneous function analogues of fast in-line functions */
    extern ssize_t sfslen(void);

#undef extern

#ifdef __cplusplus
}
#endif
