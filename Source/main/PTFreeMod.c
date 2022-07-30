/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

void _PTReplay_PTFreeMod(struct PTReplayIFace *Self,
	struct Module *module)
{
	dbug(("ptreplay::PTFreeMod\n"));

	_PTFreeModInternal(Self, module);
}
