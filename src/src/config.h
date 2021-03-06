/* src/config.h.  Generated automatically by configure.  */
/* Copyright (c) 1993 Stephen F. White */

#ifndef CONFIG_H
#define CONFIG_H

/* Define if on AIX 3.
   System headers sometimes define this.
   We just want to avoid a redefinition error message.  */
#ifndef _ALL_SOURCE
/* #undef _ALL_SOURCE */
#endif

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#define TIME_WITH_SYS_TIME 1

/* Define if you have the getdtablesize function.  */
/* #undef HAVE_GETDTABLESIZE */

/* Define if you have the herror function.  */
/* #undef HAVE_HERROR */

/* Define if you have the index function.  */
/* #undef HAVE_INDEX */

/* Define if you have the gettimeofday function.  */
#define HAVE_GETTIMEOFDAY 1

/* Define if you have the lrand48 function.  */
#define HAVE_LRAND48 1

/* Define if you have the random function.  */
/* #undef HAVE_RANDOM */

/* Define if you have the strcasecmp function.  */
#define HAVE_STRCASECMP 1

/* Define if you have the <crypt.h> header file.  */
#define HAVE_CRYPT_H 1

/* Define if you have the <memory.h> header file.  */
#define HAVE_MEMORY_H 1

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Define if you have the <sys/select.h> header file.  */
#define HAVE_SYS_SELECT_H 1

/* Define if you have the <sys/time.h> header file.  */
#define HAVE_SYS_TIME_H 1

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the dbm library (-ldbm).  */
/* #undef HAVE_LIBDBM */

/* Define if you have the inet library (-linet).  */
/* #undef HAVE_LIBINET */

/* Define if you have the nsl library (-lnsl).  */
#define HAVE_LIBNSL 1

/* Define if you have the resolv library (-lresolv).  */
#define HAVE_LIBRESOLV 1

/* Define if you have the socket library (-lsocket).  */
#define HAVE_LIBSOCKET 1

/* System-specific configuration:  fun with header files */

#if STDC_HEADERS
#include <stdlib.h>
#include <unistd.h>
#endif /* STDC_HEADERS */

#if STDC_HEADERS || HAVE_STRING_H

/* we're probably on a SYSV system here */

#include <string.h>

/* An ANSI string.h and pre-ANSI memory.h might conflict */
#if !STDC_HEADERS && HAVE_MEMORY_H
#include <memory.h>
#endif

/*
 * I use bsd-style calls (bcopy, index, etc), so define some macros
 * if we're on SYSV
 */

#define bcopy(s, d, n)   memcpy((d), (s), (n))
#define bcmp(s1, s2, n)  memcmp((s1), (s2), (n))
#define bzero(s, n)      memset((s), 0, (n))
#else
#include <strings.h>
#endif /* HAVE_STRING_H */

#if !HAVE_INDEX

#define index strchr
#define rindex strrchr

#endif

/* Include whatever combination of time.h and sys/time.h works */

#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#else
#if HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif
#endif

#if !HAVE_GETTIMEOFDAY
#define gettimeofday(TV, TZ) cool_gettimeofday((TV), (TZ))
#else
extern int gettimeofday(struct timeval *tv, struct timezone *tzp);
#endif

#if HAVE_CRYPT_H
#include <crypt.h>
#endif /* HAVE_CRYPT_H */

/*
 * malloc() might be weird
 */

#ifdef NOVOIDPTR
#define MALL_T char *
#else
#define MALL_T void *
#endif

#define raise(x) cool_raise(x)	/* so as not to conflict with signal.h */

/*
 * useful macros
 */

#define Arraysize(x)	(sizeof(x) / sizeof(x[0])) 
#ifndef MIN
#define MIN(A, B) ((A) < (B) ? (A) : (B))
#endif
#ifndef MAX
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#endif

#define INT_SIZE	10	/* size of buffer big enough to hold an int */
#define LONG_SIZE	20	/* size of buffer big enough to hold a long */

#define STRING_INIT_SIZE	16	/* initialize length of String values */
#define STRING_DOUBLING			/* double Strings when needed */
#define STRING_GROW_BY		32	/* or use this to increment linearly */

#define CODE_INIT_SIZE	32
#define SYM_INIT_SIZE   16
#define STACK_SIZE	128

#define HASH_INIT_SIZE	37
#define HASH_INIT_LOAD	2

#define MAX_TOKEN_LEN	40	/* maximum length of internal token names */
#define MAX_PATH_LEN	1024	/* maximum length of path names */

#define SYS_OBJ		0
#define ROOT_OBJ	1	/* if defined, the server will force 1 root */
#define MAX_AGE		20	/* default max. recursion, essentially */
#define MAX_TICKS	10000	/* default maximum instructions per task */
#define PLAYER_PORT	7777	/* default player port */

typedef short	Serverid;
typedef int	Playerid;

#define NOTHING	(-1)		/* represents an invalid player */

#define BLOCK_SIZE 512		/* size of input block */
#define UDP_BLOCK_SIZE 2048		/* size of input block for YO packets */
#define PROGDIR		"/tmp"	/* temp directory for COOL programs */
#define RUNDIR		"online"	/* directory for on-line files */

#define MALLOC(what, number) (what *) cool_malloc((number) * sizeof(what))
#define FREE(what) cool_free( (void *) what)

#if HAVE_LRAND48
#define cool_random()	lrand48()
#define cool_srandom(x)	srand48(x)
#elif !HAVE_RANDOM
#define cool_random()	rand()			/* sysv has no random() */
#define cool_srandom(x)	srand(x)
#endif /* !HAVE_RANDOM */

#if !HAVE_GETDTABLESIZE
#define getdtablesize()	sysconf(_SC_OPEN_MAX)	/* or getdtablesize() */
#endif /* !HAVE_GETDTABLESIZE */

/*
 * timing stuff
 */

#define MSG_TIMEOUT	30	/* message timeout, in seconds */
#define MSG_RETRY	1500	/* message retry interval, in msec */
#define EXP_BACKOFF		/* define this for exponential backoff */
#define LOCK_TIMEOUT	30	/* lock timeout, in seconds */
#define CONNECT_TIMEOUT	60	/* connect() timeout, in seconds */

/*
 * input quotas
 */
#define MAX_CMDS	100	/* maximum commands in a burst */
#define MSEC_PER_CMD	1000	/* time between commands after a burst */

#define MAX_OUTPUT 16384 	/* maximum amount of queued output */
#define OUTBOUND_TIMEOUT 5	/* timeout for gethostbyname() */

#define CONNECT_MSG "*** Connected ***\r\n"
#define DISCONNECT_MSG "*** Disconnected ***\r\n"
#define TRANSFER_MSG1 "*** Transferring to new connection ***\r\n"
#define TRANSFER_MSG2 "*** Reconnecting to old connection ***\r\n"

#if HAVE_STRCASECMP
#ifdef PROTO
extern int	 strcasecmp(const char *s, const char *t);
extern int	 strncasecmp(const char *s, const char *t, int n);
#endif /* PROTO */
#define cool_strcasecmp(a, b) strcasecmp(a, b)
#define cool_strncasecmp(a, b, n) strncasecmp(a, b, n)
#else /* don't have strcasecmp(), use our own */
extern int	 cool_strcasecmp(const char *s, const char *t);
extern int	 cool_strncasecmp(const char *s, const char *t, int n);
#endif

#endif /* !CONFIG_H */
