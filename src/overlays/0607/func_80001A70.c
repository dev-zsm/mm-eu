// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B763C(M2C_UNK, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
s32 func_8016A23C(M2C_UNK);                         /* extern */
M2C_UNK func_80BD8A04(u8 *);                      /* extern */
M2C_UNK func_80BD8C74(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BD8CB4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BD8D98(u8 *);                      /* extern */
M2C_UNK func_80BD8DC4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BD8E94(u8 *);                      /* extern */

void func_80001A70(Actor *thisx, PlayState *play) {
    func_80BD8CB4(thisx, play);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, M2C_UNK), 0x188)(thisx, play);
    M2C_FIELD(thisx, s16 *, 0xBE) = (s16) M2C_FIELD(thisx, s16 *, 0x32);
    if (!(M2C_FIELD(thisx, u16 *, 0x310) & 0x10)) {
        func_80BD8E94(thisx);
        func_80BD8D98(thisx);
        func_80BD8DC4(thisx, play);
    }
    func_800B763C(play, thisx, 0x41F00000, 0x41A00000, 0.0f, 0x1D);
    if (M2C_FIELD(thisx, f32 *, 0x88) <= -32000.0f) {
        func_800FF30C((u8 *)thisx + 0x24, (u8 *)thisx + 0x108);
    }
    func_80BD8C74(thisx, play);
    if (func_8016A23C(play) == 0) {
        func_80BD8A04(thisx);
    }
}
