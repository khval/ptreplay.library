/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

VOID _PTReplay_PTFade(struct PTReplayIFace *Self,
	struct Module *module, UBYTE speed)
{
	dbug(("ptreplay::PTFade\n"));

	_PTSendCommand(Self, module, PTCMD_FADE, speed);
}
