// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013E578(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80A7A96C;
extern M2C_UNK D_80A7DC90;

void func_8000122C(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) + 120.0f);
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    func_8013E578(arg0 + 0x148, &D_80A7DC90, 0, arg0 + 0x2FC);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~9);
    M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) & 0xFFDE);
    M2C_FIELD(arg0, s16 *, 0x3C0) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A7A96C;
}
