#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0618.h"

f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80BEA9E4;
extern f32 D_80BEB234;

void func_800000CC(u8 *arg0, u8 *arg1) {
    u32 temp_v0;
    u8 *temp_v1;

    M2C_FIELD(arg0, f32 *, 0x154) = (f32) (M2C_FIELD(arg0, f32 *, 0x154) + D_80BEB234);
    M2C_FIELD(arg0, f32 *, 0x68) = func_800FEB84((s16) (s32) M2C_FIELD(arg0, f32 *, 0x154));
    func_800FFBF8(arg0 + 0x150, 0x3DCCCCCD, 0x3E99999A, 0x3C23D70A);
    if (M2C_FIELD(arg1, s32 *, 0x1681C) == 0) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0x169);
        if (temp_v0 & 2) {
            temp_v1 = M2C_FIELD(arg1, u8 **, 0x1CCC);
            M2C_FIELD(arg0, u8 *, 0x169) = (u8) (temp_v0 & 0xFFFD);
            if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0xF43) & 0x40) && !(M2C_FIELD(&D_801E6EF0, u8 *, 0xF41) & 0x10) && !(M2C_FIELD(&D_801E6EF0, u8 *, 0xF4D) & 2)) {
                M2C_FIELD(temp_v1, s32 *, 0xA6C) = (s32) (M2C_FIELD(temp_v1, s32 *, 0xA6C) | 0x20);
                M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x100000);
            }
            M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80BEA9E4;
        }
    }
}
