// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F4BDC(s32);                         /* extern */
s32 KaleidoManager_GetRamAddr(M2C_UNK *);                       /* extern */
extern s32 D_801EE490;
extern s32 D_801EE494;
extern M2C_UNK D_80827CC0;
extern M2C_UNK D_80828224;

void KaleidoScopeCall_Init(s32 arg0) {
    D_801EE490 = KaleidoManager_GetRamAddr(&D_80828224);
    D_801EE494 = KaleidoManager_GetRamAddr(&D_80827CC0);
    func_800F4BDC(arg0);
}
