#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E0F5C(s32, u8 *);                 /* extern */
M2C_UNK func_800E1064(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_808E379C(u8 *);                      /* extern */
extern M2C_UNK D_6000194;
extern M2C_UNK D_6002BF0;
extern M2C_UNK D_808E44E0;
extern M2C_UNK D_808E450C;
extern M2C_UNK D_808E452C;
extern f32 D_808E4570;

void func_80000000(u8 *arg0, s32 arg1) {
    u8 *temp_a1;

    func_800FF8DC(arg0, &D_808E452C);
    M2C_FIELD(arg0, M2C_UNK **, 0xA0) = &D_808E450C;
    M2C_FIELD(arg0, s8 *, 0xB6) = 0xA;
    M2C_FIELD(arg0, s8 *, 0xB7) = 2;
    func_80136ED0(arg1, arg0 + 0x144, &D_6002BF0, &D_6000194, arg0 + 0x188, arg0 + 0x1BE, 9);
    temp_a1 = arg0 + 0x1F8;
    func_800E0F5C(arg1, temp_a1);
    func_800E1064(arg1, temp_a1, arg0, &D_808E44E0);
    M2C_FIELD(arg0, s16 *, 0x248) = 0;
    M2C_FIELD(arg0, s8 *, 0xB6) = 0x5A;
    M2C_FIELD(arg0, s16 *, 0xBE) = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = (f32) D_808E4570;
    M2C_FIELD(arg0, s16 *, 0x244) = 0;
    M2C_FIELD(arg0, s8 *, 0x252) = 0;
    M2C_FIELD(arg0, f32 *, 0x68) = -1.0f;
    func_800B6564(arg0, 0x3BC49BA6);
    func_808E379C(arg0);
}
