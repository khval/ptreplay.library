/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

STATIC APTR load_file (const char *filename, int32 *file_size) {
	BPTR file;
	APTR memory = NULL;
	file = IDOS->Open(filename, MODE_OLDFILE);
	if (file && (*file_size = IDOS->GetFileSize(file)) > 0) {
		memory = IExec->AllocVec(*file_size, MEMF_SHARED);
		if (memory && IDOS->Read(file, memory, *file_size) != *file_size) {
			IExec->FreeVec(memory);
			memory = NULL;
		}
		IDOS->Close(file);
	}
	return memory;
}

struct Module *_PTReplay_PTLoadModule(struct PTReplayIFace *Self,
	STRPTR name)
{
	struct Module *module;
	
	IExec->DebugPrintF("ptreplay::PTLoadModule\n");
	
	module = IExec->AllocVec(sizeof(*module), MEMF_SHARED|MEMF_CLEAR);
	if (!module) goto out;
	
	module->file_data = load_file(name, &module->file_size);
	if (!module->file_data) goto out;
	module->free_file_data = TRUE;
	
	return _PTSetupModInternal(Self, module, name);
out:
	Self->PTUnloadModule(module);
	return NULL;
}
