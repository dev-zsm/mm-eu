// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 KaleidoManager_GetRamAddr(M2C_UNK *);                       /* extern */
extern s32 D_801EE3C0;
extern s32 D_801EE3C4;
extern s32 D_801EE3C8;
extern s32 D_801EE3CC;
extern M2C_UNK D_808411B8;
extern M2C_UNK D_808457AC;
extern M2C_UNK D_80845C1C;
extern M2C_UNK D_808467C8;

void PlayerCall_InitFuncPtrs(void) {
    D_801EE3C0 = KaleidoManager_GetRamAddr(&D_808411B8);
    D_801EE3C4 = KaleidoManager_GetRamAddr(&D_808467C8);
    D_801EE3C8 = KaleidoManager_GetRamAddr(&D_808457AC);
    D_801EE3CC = KaleidoManager_GetRamAddr(&D_80845C1C);
}
