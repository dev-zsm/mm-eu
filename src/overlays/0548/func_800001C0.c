// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800BDD44(s32, M2C_UNK *);              /* extern */
M2C_UNK func_8018132C(f32, f32, s32, M2C_UNK);      /* extern */
M2C_UNK func_8018142C(f32, f32, f32, M2C_UNK);      /* extern */
M2C_UNK func_80181508(s16, M2C_UNK);                /* extern */
M2C_UNK func_80181A3C(s16, M2C_UNK);                /* extern */
extern M2C_UNK D_6000360;
extern f32 D_80B99B4C;

void func_800001C0(Actor *thisx, PlayState *play) {
    func_8018132C(M2C_FIELD(thisx, f32 *, 0x24), M2C_FIELD(thisx, f32 *, 0x28), M2C_FIELD(thisx, s32 *, 0x2C), 0);
    if (M2C_FIELD(thisx, s16 *, 0xBC) != 0) {
        func_80181A3C(M2C_FIELD(thisx, s16 *, 0x16), 1);
        func_80181508(M2C_FIELD(thisx, s16 *, 0xBC), 1);
        func_80181A3C((s16) (M2C_FIELD(thisx, s16 *, 0xBE) - M2C_FIELD(thisx, s16 *, 0x16)), 1);
    } else {
        func_80181A3C(M2C_FIELD(thisx, s16 *, 0xBE), 1);
    }
    func_8018142C(D_80B99B4C, D_80B99B4C, D_80B99B4C, 1);
    func_800BDD44(play, &D_6000360);
}
