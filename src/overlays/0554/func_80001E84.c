// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0554.h"

s32 func_800B8254(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B83C0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80151DF4(M2C_UNK, s32, u8 *);        /* extern */
s16 func_80BA1820(u8 *, M2C_UNK);                 /* extern */
s32 func_80BA286C(u8 *, M2C_UNK);                 /* extern */
extern M2C_UNK D_80BA3798;

void func_80001E84(Actor *thisx, PlayState *play) {
    s16 temp_v0;

    if (((M2C_FIELD(thisx, s16 *, 0x1C) & 0xF) == 8) || (func_80BA286C(thisx, play) == 0)) {
        if (func_800B8254(thisx, play) != 0) {
            M2C_FIELD(thisx, u16 *, 0x1DC) = (u16) (M2C_FIELD(thisx, u16 *, 0x1DC) | 0x10);
            temp_v0 = func_80BA1820(thisx, play);
            M2C_FIELD(thisx, s16 *, 0x304) = temp_v0;
            func_80151DF4(play, temp_v0 & 0xFFFF, thisx);
            M2C_FIELD(thisx, M2C_UNK **, 0x18C) = &D_80BA3798;
        } else if ((M2C_FIELD(thisx, f32 *, 0x98) < 250.0f) || (M2C_FIELD(thisx, u8 *, 0x114) != 0)) {
            func_800B83C0(thisx, play);
        }
        func_800FFCBC((u8 *)thisx + 0xBE, M2C_FIELD(thisx, s16 *, 0x16), 5, 0x1000, 0x100);
        M2C_FIELD(thisx, s16 *, 0x32) = (s16) M2C_FIELD(thisx, s16 *, 0xBE);
    }
}
