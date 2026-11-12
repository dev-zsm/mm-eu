#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0239.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
f32 func_8017A844(f32);                         /* extern */
extern M2C_UNK D_600A3CC;
extern M2C_UNK D_80975FC0;

void func_80000EF0(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x461) = (u8) (M2C_FIELD(arg0, u8 *, 0x461) | 1);
    func_80137934(arg0 + 0x144, &D_600A3CC, 0xC0800000, arg0);
    M2C_FIELD(arg0, s16 *, 0x2A0) = (s16) ((s32) func_8017A844(1.0e+01f) + 2);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_80975FC0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
