/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

ULONG _PTReplay_PTStop(struct PTReplayIFace *Self,
       struct Module * module)
{
	dbug(("ptreplay::PTStop\n"));

	_PTSendCommand(Self, module, PTCMD_STOP);
	return TRUE;
}
