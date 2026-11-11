#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
M2C_UNK func_8013796C(u8 *, M2C_UNK *, f32);  /* extern */
M2C_UNK func_80A3B12C(u8 *);                      /* extern */
M2C_UNK func_80A3B3BC(u8 *);                      /* extern */
extern M2C_UNK D_6000174;
extern M2C_UNK D_80A3BF9C;
extern f32 D_80A3D260;

void func_80001030(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x18C) = 0;
    M2C_FIELD(arg0, s16 *, 0x190) = 0xC8;
    M2C_FIELD(arg0, s16 *, 0x192) = 0;
    func_800FF30C(arg0 + 0x24, arg0 + 8);
    M2C_FIELD(arg0, f32 *, 0xC4) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0xBC) = (s16) M2C_FIELD(arg0, s16 *, 0x14);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x16);
    M2C_FIELD(arg0, s16 *, 0xC0) = (s16) M2C_FIELD(arg0, s16 *, 0x18);
    func_80A3B12C(arg0);
    func_80A3B3BC(arg0);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_8013796C(arg0 + 0x144, &D_6000174, 0.0f);
    M2C_FIELD(arg0, f32 *, 0x25C) = (f32) D_80A3D260;
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, s32 *, 0xC8) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80A3BF9C;
}
