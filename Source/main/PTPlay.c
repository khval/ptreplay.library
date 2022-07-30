/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

ULONG _PTReplay_PTPlay(struct PTReplayIFace *Self,
	struct Module *module)
{
	dbug(("ptreplay::PTPlay\n"));

	_PTSendCommand(Self, module, PTCMD_PLAY);
	return TRUE;
}
