// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0182.h"

M2C_UNK func_800FD584(u8 *);                      /* extern */
M2C_UNK func_8094AF00(s32, M2C_UNK *);              /* extern */
s32 func_8094B0F8(s32, u8 *, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_8094BA64;

void func_80000AE0(s32 arg0, PlayState *play) {
    if (func_8094B0F8(arg0, play, 0, 1, 0, 2, 0x64, 4) != 0) {
        func_800FD584(play);
        M2C_FIELD(play, s8 *, 0x170F6) = 0x3C;
        func_8094AF00(arg0, &D_8094BA64);
    }
}
