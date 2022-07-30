/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

#pragma pack(2)
/* This structure is returned by GetSample function */
struct PTSample
{
	UBYTE Name[22];		/* 22 Null terminated string with samplename */ 
	UWORD Length;		/* 02 Sample length in words */
	UBYTE FineTune;		/* 01 FineTune of sample in lower 4 bits */
	UBYTE Volume;		/* 01 Volume of sample */ 
	UWORD Repeat;		/* 02 Repeat start in number of words */ 
	UWORD Replen;		/* 02 Repeat length in number of words */ 
// = 30 bytes.
};
#pragma pack()

struct PTSample * _PTReplay_PTGetSample(struct PTReplayIFace *Self,
	struct Module *module, WORD Nr)
{
	struct PTSample *samples = (module -> file_data + 0x14);
	return samples+Nr;
}

