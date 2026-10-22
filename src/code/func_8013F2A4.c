// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK View_InitDistortion();                            /* extern */

void View_Init(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0xF0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0x140;
    M2C_FIELD(arg0, s32 *, 0) = 0x56494557;
    M2C_FIELD(arg0, s32 *, 0x164) = 0;
    M2C_FIELD(arg0, s32 *, 0x160) = 7;
    M2C_FIELD(arg0, f32 *, 0x24) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x44) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x18) = 60.0f;
    M2C_FIELD(arg0, f32 *, 0x28) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x2C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x34) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x40) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x48) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x1C) = 10.0f;
    M2C_FIELD(arg0, f32 *, 0x20) = 12800.0f;
    M2C_FIELD(arg0, f32 *, 0x30) = -1.0f;
    View_InitDistortion();
}
