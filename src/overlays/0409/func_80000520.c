#include "types.h"
#include "m2c_compat.h"
extern u8 D_80AAF078[];
typedef struct { u8 pad0[0x1680C]; u8 *f1680C; u8 pad1[0xC]; s32 f1681C; u8 pad2[0xE]; u8 f1682E; } PS;

void func_80000520(u8 *a, PS *play) {
    if (M2C_FIELD(play->f1680C, u8 *, 1) == 0 && play->f1682E == 0x1B) {
        M2C_FIELD(a, s16 *, 0x14) = 5;
        M2C_FIELD(a, void **, 0x144) = D_80AAF078;
        play->f1681C = 0;
        play->f1682E = 0;
    }
}
