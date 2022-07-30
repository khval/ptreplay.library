/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

UBYTE _PTReplay_PTSongPos(struct PTReplayIFace *Self,
	struct Module *module)
{
	uint32 res = 0;
	
	dbug(("ptreplay::PTSongPos\n"));
	
	IExec->MutexObtain(module->mutex);
	IPtPlay->PtGetAttr(module->mod_handle, PTPLAY_SongPosition, &res);
	IExec->MutexRelease(module->mutex);
	
	return res;
}
