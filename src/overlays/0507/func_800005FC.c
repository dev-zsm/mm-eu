// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0507.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B83C0(u8 *, s32);                 /* extern */
M2C_UNK func_80151DF4(s32, u16, u8 *);            /* extern */
u16 func_80B59DD0(u8 *, s32);                     /* extern */
extern M2C_UNK D_80B58E64;

void func_800005FC(Actor *thisx, PlayState *play) {
    if (func_800B8254(thisx, play) != 0) {
        M2C_FIELD(thisx, u16 *, 0x3CC) = (u16) (M2C_FIELD(thisx, u16 *, 0x3CC) | 4);
        func_80151DF4(play, M2C_FIELD(thisx, u16 *, 0x3CE), thisx);
        M2C_FIELD(thisx, M2C_UNK **, 0x1DC) = &D_80B58E64;
        return;
    }
    if ((M2C_FIELD(thisx, f32 *, 0x98) < 100.0f) || (M2C_FIELD(thisx, u8 *, 0x114) != 0)) {
        func_800B83C0(thisx, play);
        M2C_FIELD(thisx, u16 *, 0x3CE) = func_80B59DD0(thisx, play);
    }
}
