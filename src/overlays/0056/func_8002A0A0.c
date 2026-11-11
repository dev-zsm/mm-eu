#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

M2C_UNK func_800B2030(u8 *, u8 *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_800BA9E4(u8 *, u8 *, M2C_UNK, s32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_8082D86C(u8 *);                      /* extern */
M2C_UNK func_8083F584(u8 *, u8 *, M2C_UNK);     /* extern */
extern M2C_UNK D_801C9EE0;
extern f32 D_8085DDB4;

void func_8002A0A0(u8 *arg0, u8 *arg1) {
    if (M2C_FIELD(arg1, u16 *, 0x90) & 2) {
        M2C_FIELD(arg1, f32 *, 0xB0C) = (f32) ((M2C_FIELD(arg1, f32 *, 0xB08) * D_8085DDB4) + M2C_FIELD(arg1, f32 *, 0xB0C));
        if (M2C_FIELD(arg1, s16 *, 0xB88) == 0) {
            if (M2C_FIELD(arg1, s8 *, 0xAE7) == 1) {
                M2C_FIELD(arg1, s8 *, 0xAE7) = 2;
                func_8083F584(arg0, arg1, 0x8E8);
                M2C_FIELD(arg0, s8 *, 0x1CA2) = 4;
                func_800B2030(arg0, arg1 + 0x24, &D_801C9EE0, &D_801C9EE0);
                M2C_FIELD(arg1, s16 *, 0xAE8) = 0;
                M2C_FIELD(arg1, f32 *, 0xB08) = 0.0f;
                func_800BA9E4(arg0 + 0x1CA0, arg0, 1, M2C_FIELD(arg1, s32 *, 0x24), M2C_FIELD(arg1, f32 *, 0x28), M2C_FIELD(arg1, f32 *, 0x2C), 0, 0, 0, 0);
            } else {
                M2C_FIELD(arg1, s8 *, 0xAE7) = 4;
            }
        }
        func_8082D86C(arg1);
    }
}
