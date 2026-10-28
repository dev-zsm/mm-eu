// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80917CE8;
extern M2C_UNK D_80917D64;

void func_80000CF4(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0xBD6) = 0;
    M2C_FIELD(arg0, s16 *, 0xBD2) = 0;
    M2C_FIELD(arg0, s16 *, 0xBD0) = 0;
    M2C_FIELD(arg0, s16 *, 0xBCA) = 0x64;
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) M2C_FIELD(arg0, f32 *, 0xBA8);
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) M2C_FIELD(arg0, f32 *, 0xBAC);
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) M2C_FIELD(arg0, f32 *, 0xBB0);
    if (M2C_FIELD(arg0, s16 *, 0x1C) & 0x4000) {
        M2C_FIELD(arg0, s8 *, 0xBD6) = 2;
        M2C_FIELD(arg0, s16 *, 0xBCA) = 0xA;
        M2C_FIELD(arg0, s16 *, 0xBD2) = 0xFA0;
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80917D64;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80917CE8;
}
