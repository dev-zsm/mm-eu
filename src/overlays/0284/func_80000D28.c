// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80137934(u8 *, u8 *, f32, u8 *);
extern u8 D_6014110;
extern u8 D_809B5FE4;

void func_80000D28(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, u8 **, 0x464) = &D_809B5FE4;
    M2C_FIELD(arg0, f32 *, 0x24) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x2C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x28) = 2400.0f;
    func_80137934(arg0 + 0x164, &D_6014110, 0.0f, arg0);
}
