#include "types.h"

typedef struct {
    u16 type;
    u16 startFrame;
    u16 endFrame;
} CsCmdAA34;

typedef struct {
    u8 pad0[0x10];
    u16 curFrame;
} CsCtxAA34;

void AudioSeq_QueueSeqCmd(u32);

void CutsceneCmd_FadeOutSequence(void *play, CsCtxAA34 *csCtx, CsCmdAA34 *cmd) {
    u8 duration;

    if ((csCtx->curFrame == cmd->startFrame) && (csCtx->curFrame < cmd->endFrame)) {
        duration = cmd->endFrame - cmd->startFrame;
        if (cmd->type == 2) {
            AudioSeq_QueueSeqCmd((duration << 16) | 0x110000FF);
        } else {
            AudioSeq_QueueSeqCmd((duration << 16) | 0x100000FF);
        }
    }
}
