#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0476.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801017FC(u8 *, s16, s16, s16, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_80B12EB0;

void func_800019C0(u8 *arg0) {
    func_801017FC(arg0 + 0x31C, (s16) (s32) M2C_FIELD(arg0, f32 *, 0x24), (s16) (s32) M2C_FIELD(arg0, f32 *, 0x28), (s16) (s32) M2C_FIELD(arg0, f32 *, 0x2C), 0, 0, 0, 0);
    M2C_FIELD(arg0, s16 *, 0x190) = 0;
    M2C_FIELD(arg0, s16 *, 0xBE) = 0;
    M2C_FIELD(arg0, s8 *, 0x194) = 0;
    M2C_FIELD(arg0, s8 *, 0x197) = 0;
    M2C_FIELD(arg0, s8 *, 0x195) = 0;
    M2C_FIELD(arg0, u8 *, 0x196) = 0xC8;
    M2C_FIELD(arg0, s16 *, 0xBC) = 0;
    M2C_FIELD(arg0, f32 *, 0xC4) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0x28);
    M2C_FIELD(arg0, f32 *, 0x58) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x5C) = 0.0f;
    func_800B8C4C(arg0, 0x28E0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B12EB0;
}
