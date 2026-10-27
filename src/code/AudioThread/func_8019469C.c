#include "types.h"

typedef struct {
    s32 op;
    s32 arg;
} AudioCmd;
typedef struct {
    u8 pad0[0x7978];
    u8 writePos;
    u8 readPos;
    u8 pad797A[0x7A];
    AudioCmd cmds[256];
} AudioCmdQueue;
extern AudioCmdQueue D_801F84B0;
void AudioThread_QueueCmd(s32 op, s32 *arg) {
    AudioCmd *cmd = &D_801F84B0.cmds[D_801F84B0.writePos & 0xFFu];
    s32 new_var;
    new_var = op;
    cmd->op = new_var;
    cmd->arg = *arg;
    D_801F84B0.writePos++;
    if (D_801F84B0.writePos == D_801F84B0.readPos) {
        D_801F84B0.writePos--;
    }
}
