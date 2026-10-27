// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80081D04(M2C_UNK *);                   /* extern */
M2C_UNK KaleidoManager_ClearOvl(s32);                         /* extern */
extern s32 D_801C9488;
extern s32 D_801C948C;
extern M2C_UNK D_801EE480;

void KaleidoManager_Destroy(void) {
    func_80081D04(&D_801EE480);
    if (D_801C948C != 0) {
        KaleidoManager_ClearOvl(D_801C948C);
        D_801C948C = 0;
    }
    D_801C9488 = 0;
}
