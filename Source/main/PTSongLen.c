/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

UBYTE _PTReplay_PTSongLen(struct PTReplayIFace *Self,
	struct Module *module)
{
	uint32 res = 0;
	
	dbug(("ptreplay::PTSongLen\n"));
	
	IExec->MutexObtain(module->mutex);
	IPtPlay->PtGetAttr(module->mod_handle, PTPLAY_Positions, &res);
	IExec->MutexRelease(module->mutex);
	
	return res;
}
