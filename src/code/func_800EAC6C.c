// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x10];
    u16 frames;
} CutsceneContext;
typedef struct {
    u16 base;
    u16 startFrame;
    u16 endFrame;
} CsCmdFadeOutAmbience;
extern void AudioSeq_QueueSeqCmd(u32 arg);
void CutsceneCmd_FadeOutAmbience(void *play, CutsceneContext *csCtx, CsCmdFadeOutAmbience *cmd) {
    u16 new_var;
    if (cmd->startFrame == (new_var = csCtx->frames)) {
        if (new_var < cmd->endFrame) {
            u8 fadeFrames = cmd->endFrame - cmd->startFrame;
            AudioSeq_QueueSeqCmd((fadeFrames << 16) | 0x140000FF);
        }
    }
}
