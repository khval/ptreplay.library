/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

void _PTReplay_PTSetPos(struct PTReplayIFace *Self,
	struct Module *module, UBYTE pos)
{
	struct TagItem tags[2];

	dbug(("ptreplay::PTSetPos\n"));
	
	tags[0].ti_Tag = PTPLAY_SongPosition;
	tags[0].ti_Data = pos;
	tags[1].ti_Tag = TAG_END;
	IExec->MutexObtain(module->mutex);
	IPtPlay->PtSetAttrs(module->mod_handle, tags);
	IExec->MutexRelease(module->mutex);
}
