#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_801377D0(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_6003610;
extern M2C_UNK D_6004248;
extern M2C_UNK D_600D208;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80BC253C;
extern M2C_UNK D_80BC2A90;

void func_80000CB8(u8 *arg0, s32 arg1) {
    u8 *sp34;
    u8 *temp_a1;

    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41A00000);
    func_800B6564(arg0, 0x3C23D70A);
    M2C_FIELD(arg0, M2C_UNK **, 0x618) = &D_80BC253C;
    temp_a1 = arg0 + 0x144;
    sp34 = temp_a1;
    func_80136ED0(arg1, temp_a1, &D_600D208, &D_6004248, arg0 + 0x1D4, arg0 + 0x24C, 0x14);
    func_801377D0(sp34, &D_6003610);
    M2C_FIELD(arg0, s16 *, 0x2C8) = 1;
    func_800E1134(arg1, arg0 + 0x188, arg0, &D_80BC2A90);
    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    M2C_FIELD(arg0, s16 *, 0x2CA) = 0;
    M2C_FIELD(arg0, s16 *, 0x2CC) = 0;
    M2C_FIELD(arg0, s16 *, 0x2CE) = 0;
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(arg0, s16 *, 0x116) = 0;
    M2C_FIELD(arg0, s16 *, 0x34) = (s16) M2C_FIELD(arg0, s16 *, 0xC0);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
}
