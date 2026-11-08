// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0067.h"

M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, M2C_UNK, f32, s32, f32); /* extern */
extern M2C_UNK D_60028F0;
extern M2C_UNK D_80877580;

void func_80001770(Actor *thisx) {
    func_80137788((u8 *)thisx + 0x144, &D_60028F0, 0xBF800000, 0x420C0000, 0.0f, 2, -4.0f);
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) | 0x10);
    M2C_FIELD(thisx, s16 *, 0x302) = 0x19;
    M2C_FIELD(thisx, M2C_UNK **, 0x2FC) = &D_80877580;
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
}
