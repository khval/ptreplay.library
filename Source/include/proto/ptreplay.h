#ifndef PROTO_PTREPLAY_H
#define PROTO_PTREPLAY_H

/*
**	$Id$
**	Includes Release 50.1
**
**	Prototype/inline/pragma header file combo
**
**	(C) Copyright 2003-2007 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Library * PTReplayBase;
 #else
  extern struct PTReplayBase * PTReplayBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/ptreplay.h>
 #ifdef __USE_INLINE__
  #include <inline4/ptreplay.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_PTREPLAY_PROTOS_H
  #define CLIB_PTREPLAY_PROTOS_H 1
 #endif /* CLIB_PTREPLAY_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct PTReplayIFace *IPTReplay;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_PTREPLAY_PROTOS_H
  #include <clib/ptreplay_protos.h>
 #endif /* CLIB_PTREPLAY_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/ptreplay.h>
  #else
   #include <ppcinline/ptreplay.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/ptreplay_protos.h>
  #endif /* __PPC__ */
 #else
  #include <pragmas/ptreplay_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_PTREPLAY_H */
