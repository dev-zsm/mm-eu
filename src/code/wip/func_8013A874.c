#include "types.h"

extern u32 D_801E7D68;
extern u32 D_801E7D6C;

u32 Snap_CheckFlag(s32 arg0) {
    if (arg0 < 0x20) {
        return D_801E7D68 & (1 << arg0);
    }
    return D_801E7D6C & (1 << (arg0 & 0x1F));
}
