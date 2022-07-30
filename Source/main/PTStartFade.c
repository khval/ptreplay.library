/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

void _PTReplay_PTStartFade(struct PTReplayIFace *Self,
	struct Module *module, UBYTE speed)
{
	dbug(("ptreplay::PTStartFade\n"));

	_PTSendCommand(Self, module, PTCMD_STARTFADE, speed);
}
