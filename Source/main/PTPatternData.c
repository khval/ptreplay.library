/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#include "ptreplay_private.h"

// 4 bytes per channel. 4 channels.

#define row_size 4*4
#define pattern_offset 1084
#define pattern_size 1024

APTR _PTReplay_PTPatternData(struct PTReplayIFace *Self,
	struct Module *module, UBYTE Pattern, UBYTE Row)
{
	unsigned char *patterns = module -> file_data + pattern_offset ;

	return (APTR) (patterns + (pattern_size * Pattern) + (row_size * Row));
}
