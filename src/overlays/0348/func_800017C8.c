#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0348.h"

M2C_UNK func_80A3C2D0();                            /* extern */
extern M2C_UNK D_80A3C6E4;

void func_800017C8(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
    M2C_FIELD(arg0, f32 *, 0x70) = 5.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 8.0f;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    func_80A3C2D0();
    M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) & 0xFFE6);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80A3C6E4;
}
