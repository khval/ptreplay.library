/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

VOID _PTReplay_PTSetVolume(struct PTReplayIFace *Self,
	struct Module *module, UBYTE vol)
{
	struct TagItem tags[2];

	dbug(("ptreplay::PTSetVolume\n"));
	
	tags[0].ti_Tag = PTPLAY_MasterVolume;
	tags[0].ti_Data = (uint32)vol << 2;
	tags[1].ti_Tag = TAG_END;
	IExec->MutexObtain(module->mutex);
	IPtPlay->PtSetAttrs(module->mod_handle, tags);
	IExec->MutexRelease(module->mutex);
}
