// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x1DC];
    u32 cmd[14];
    u8 pad[5];
    u8 n;
    u8 pad2[2];
} Chan;
extern Chan D_801F7980[];
void AudioSeq_ReplaceSeqCmdSetupOpVolRestore(u8 a, u8 b) {
    u8 i;
    u8 new_var;
    for (i = 0; i < D_801F7980[a].n; i++) {
        if (b == (new_var = (u8) ((D_801F7980[a].cmd[i] & 0xF00000) >> 20))) {
            D_801F7980[a].cmd[i] = 0xFF000000;
        }
    }

}
