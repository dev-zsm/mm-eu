// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK GameState_GetInput(s32);                         /* extern */
M2C_UNK GameState_IncrementFrameCount(s32);                         /* extern */
M2C_UNK Audio_Update();                            /* extern */
extern void *D_801EB7E0;

void Graph_UpdateGame(s32 arg0) {
    GameState_GetInput(arg0);
    GameState_IncrementFrameCount(arg0);
    if (M2C_FIELD(D_801EB7E0, s16 *, 0xFC) < 3) {
        Audio_Update();
    }
}
