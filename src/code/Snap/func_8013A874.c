// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_snap.h"

u32 Snap_CheckFlag(s32 flag) {
    SaveContext* saveCtx = &gSaveContext;

    if (flag < 0x20) {
        return saveCtx->save.saveInfo.pictoFlags0 & (1 << flag);
    } else {
        flag &= 0x1F;
        return saveCtx->save.saveInfo.pictoFlags1 & (1 << flag);
    }
}
