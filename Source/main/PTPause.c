/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

ULONG _PTReplay_PTPause(struct PTReplayIFace *Self,
	struct Module *module)
{
	dbug(("ptreplay::PTPause\n"));

	_PTSendCommand(Self, module, PTCMD_PAUSE);
	return TRUE;
}
