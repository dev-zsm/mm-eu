#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B763C(s32, u8 *, f32, f32, f32, s32); /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80C03864(u8 *);                      /* extern */
extern M2C_UNK D_60005FC;
extern M2C_UNK D_600A6D0;
extern M2C_UNK D_800B3F30;
extern f32 D_80C04080;

void func_80000000(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x1F) = 1;
    M2C_FIELD(arg0, f32 *, 0xFC) = (f32) D_80C04080;
    func_800B6564(arg0, 0x3CA3D70A);
    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x42100000);
    func_80136ED0(arg1, arg0 + 0x144, &D_600A6D0, &D_60005FC, arg0 + 0x19C, arg0 + 0x262, 0x21);
    func_800B763C(arg1, arg0, 0.0f, 0.0f, 0.0f, 4);
    M2C_FIELD(arg0, s16 *, 0x334) = 0x3C;
    M2C_FIELD(arg0, s32 *, 0x198) = 0;
    M2C_FIELD(arg0, s16 *, 0x336) = 0;
    func_80C03864(arg0);
}
