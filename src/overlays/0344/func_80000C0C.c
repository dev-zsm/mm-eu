#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0344.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
s32 func_800E0160(M2C_UNK);                         /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E731C(u8 *, s32, M2C_UNK *);      /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_8013B284(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80A372DC(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_600EB48;
extern u8 D_801E7DF1;
extern M2C_UNK D_80A37290;
extern M2C_UNK D_80A37B28;
extern M2C_UNK D_80A381C4;
extern M2C_UNK D_80A381F0;

void func_80000C0C(u8 *arg0, s32 arg1) {
    func_800B3B14(arg0 + 0xBC, 0, 0, 0x41600000);
    func_80136ED0(arg1, arg0 + 0x148, &D_600EB48, 0, arg0 + 0x1E4, arg0 + 0x2AA, 0x21);
    M2C_FIELD(arg0, s32 *, 0x398) = -1;
    func_80A372DC(arg0, 0);
    func_800E1134(arg1, arg0 + 0x190, arg0, &D_80A381C4);
    func_800E731C(arg0 + 0xA0, func_800E0160(0x16), &D_80A381F0);
    func_800B6564(arg0, 0x3CA3D70A);
    M2C_FIELD(arg0, s8 *, 0x1F) = 1;
    M2C_FIELD(arg0, s16 *, 0x386) = 0;
    M2C_FIELD(arg0, s16 *, 0x37C) = 0;
    func_8013B284(arg0 + 0x37C, 3, 7);
    if (D_801E7DF1 & 0x80) {
        M2C_FIELD(arg0, s32 *, 0x3A4) = 1;
    } else {
        M2C_FIELD(arg0, s32 *, 0x3A4) = 0;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A37290;
    M2C_FIELD(arg0, M2C_UNK **, 0x18C) = &D_80A37B28;
}
