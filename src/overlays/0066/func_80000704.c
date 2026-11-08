// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0066.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BBB30(s32, u8 *, s32, M2C_UNK, s32, f32, s32, s32, s32); /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, M2C_UNK, f32, s32, f32); /* extern */
extern M2C_UNK D_60019CC;
extern M2C_UNK D_808746F8;

void func_80000704(Actor *thisx, PlayState *play) {
    func_80137788((u8 *)thisx + 0x144, &D_60019CC, 0x3F800000, 0x42240000, (f32) func_80134AE8(&D_60019CC), 2, -3.0f);
    func_800BBB30(play, thisx, (u8 *)thisx + 0x24, 0x41700000, 6, 20.0f, 0x12C, 0x64, 1);
    func_800B8C4C(thisx, 0x3893);
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_808746F8;
}
