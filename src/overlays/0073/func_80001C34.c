// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0073.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BBB30(s32, u8 *, u8 *, M2C_UNK, s32, f32, s32, s32, s32); /* extern */
M2C_UNK func_800FEC70(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80894D04(u8 *);                      /* extern */

void func_80001C34(Actor *thisx, PlayState *play) {
    f32 temp_f0;
    s16 temp_v0_3;
    u16 temp_v0_2;
    u8 temp_v0;

    func_800FEC70((u8 *)thisx + 0xC0, -0x8000, 0xFA0);
    temp_v0 = M2C_FIELD(thisx, u8 *, 0x2B8);
    if (temp_v0 != 0) {
        M2C_FIELD(thisx, u8 *, 0x2B8) = (u8) (temp_v0 - 1);
    } else {
        M2C_FIELD(thisx, u8 *, 0x2B8) = (u8) (u32) (func_8008704C() * 30.0f);
        M2C_FIELD(thisx, f32 *, 0x15C) = (f32) (func_8008704C() * 5.0f);
    }
    func_80137070((u8 *)thisx + 0x144);
    temp_v0_2 = M2C_FIELD(thisx, u16 *, 0x90);
    if (temp_v0_2 & 1) {
        M2C_FIELD(thisx, u8 *, 0x3BD) = (u8) (M2C_FIELD(thisx, u8 *, 0x3BD) | 1);
        if (temp_v0_2 & 2) {
            func_800BBB30(play, thisx, (u8 *)thisx + 0x24, 0x41A00000, 0xB, 4.0f, 0, 0, 0);
            func_800B8C4C(thisx, 0x387B);
        }
        temp_v0_3 = M2C_FIELD(thisx, s16 *, 0x2BC);
        if (temp_v0_3 == 0) {
            func_80894D04(thisx);
            return;
        }
        M2C_FIELD(thisx, s16 *, 0x2BC) = (s16) (temp_v0_3 - 1);
        return;
    }
    temp_f0 = M2C_FIELD(thisx, f32 *, 0xC4);
    if (temp_f0 < 2800.0f) {
        M2C_FIELD(thisx, f32 *, 0xC4) = (f32) (temp_f0 + 400.0f);
    }
}
