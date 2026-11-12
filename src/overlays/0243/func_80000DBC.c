// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0243.h"

M2C_UNK func_800FF30C();      /* extern */
M2C_UNK func_801378E0();   /* extern */
extern M2C_UNK D_60000F0;
extern M2C_UNK D_80980728;
extern u8 *D_80980DE0;
extern s32 D_80980E0C;
extern f32 D_80980E38;

void func_80000DBC(u8 *arg0) {
    if (D_80980E0C == 0xA) {
        M2C_FIELD(arg0, s16 *, 0x1C) = 1;
        D_80980E0C = 0;
        M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x21C), s16 *, 0x36) = (s16) (s32) ((f32) M2C_FIELD(D_80980DE0, s16 *, 0x20) * D_80980E38 * 100.0f);
    } else {
        M2C_FIELD(arg0, s16 *, 0x1C) = 0;
        M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x21C), s16 *, 0x36) = (s16) M2C_FIELD(D_80980DE0, s16 *, 0x20);
    }
    func_801378E0(arg0 + 0x144, &D_60000F0, arg0);
    func_800FF30C(arg0 + 0x24, arg0 + 8, arg0);
    M2C_FIELD(arg0, s16 *, 0xBC) = 0;
    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    M2C_FIELD(arg0, s16 *, 0x18E) = 0x12C;
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80980728;
    M2C_FIELD(arg0, f32 *, 0xC4) = 2000;
    M2C_FIELD(arg0, f32 *, 0x54) = 2000.0f;
    M2C_FIELD(arg0, f32 *, 0x290) = 0.0f;
}
