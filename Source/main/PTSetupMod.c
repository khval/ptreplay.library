/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

struct Module * _PTReplay_PTSetupMod(struct PTReplayIFace *Self,
	APTR ModuleFile)
{
	struct Module *module;
	
	dbug(("ptreplay::PTSetupMod\n"));
	
	module = IExec->AllocVec(sizeof(*module), MEMF_SHARED|MEMF_CLEAR);
	if (!module) goto out;
	
	module->file_data = ModuleFile;
	module->file_size = 0x10000000;
	module->free_file_data = FALSE;
	
	return _PTSetupModInternal(Self, module, NULL);
out:
	Self->PTUnloadModule(module);
	return NULL;
}
