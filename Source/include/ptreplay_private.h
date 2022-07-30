/*
 * ptreplay.library (C) 2009 Fredrik Wikstrom
*/

#ifndef PTREPLAY_PRIVATE_H
#define PTREPLAY_PRIVATE_H

#include <exec/exec.h>
#include <dos/dos.h>
#include <devices/ahi.h>
#include <libraries/ptplay.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/ptplay.h>
#include <proto/ptreplay.h>

#ifdef DEBUG
#define dbug(x) IExec->DebugPrintF x
#else
#define dbug(x)
#endif

struct PTReplayBase {
	struct Library libNode;
	BPTR segList;
	APTR mutex;
};

enum {
	PTCMD_DIE = 0,
	PTCMD_STARTUP,
	PTCMD_PLAY,
	PTCMD_STOP,
	PTCMD_PAUSE,
	PTCMD_RESUME,
	PTCMD_FADE,
	PTCMD_STARTFADE
};

enum {
	PTSIG_RESTART = 0,
	PTSIG_POS,
	PTSIG_ROW,
	PTSIG_FADE,
	PTSIG_MAX
};

struct PTReplayMessage {
	struct Message ptm_Msg;
	struct Module *ptm_Module;
	int32 ptm_Command;
	uint32 *ptm_Args;
};

struct Module {
	APTR file_data;
	int32 file_size;
	int32 free_file_data;
	APTR mutex;
	uint32 mod_type;
	APTR mod_handle;
	struct MsgPort *reply_port;
	struct MsgPort *player_port;
	struct PTReplayMessage *cmd_msg;
	struct DeathMessage *death_msg;
	struct Process *parent_proc;
	struct Process *player_proc;
	int8 signals[PTSIG_MAX];
	uint32 ptplay_flags;
};

/* ptreplay_private.c */
struct Module *_PTSetupModInternal(struct PTReplayIFace *Self,
	struct Module *module, STRPTR name);
void _PTFreeModInternal(struct PTReplayIFace *Self,
	struct Module *module);
void VARARGS68K _PTSendCommand(struct PTReplayIFace *Self,
	struct Module *module, int32 command, ...);

/* player_main.c */
int player_main ();

#endif
