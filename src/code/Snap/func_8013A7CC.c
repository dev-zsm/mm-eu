#include "types.h"

typedef struct {
    u8 pad0[0xE78];
    u32 flagsLo;
    u32 flagsHi;
} SnapState;

extern SnapState D_801E6EF0;

void Snap_SetFlag(s32 flag) {
    if (flag < 32) {
        D_801E6EF0.flagsLo |= 1 << flag;
    } else {
        flag &= 0x1F;
        D_801E6EF0.flagsHi |= 1 << flag;
    }
}
