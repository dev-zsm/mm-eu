#include "types.h"
#include "m2c_compat.h"

s32 func_80087010();                                /* extern */
s16 func_800FF250(M2C_UNK, s16);                    /* extern */
M2C_UNK func_80902150(u8 *);                      /* extern */
extern M2C_UNK D_80902C18;
extern s16 D_809045C4[];

void func_80000A40(u8 *arg0) {
    s16 var_a1;

    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x78) = 0.0f;
    if (!(func_80087010() & 3)) {
        if (!(func_80087010() & 7) && (M2C_FIELD(arg0, s8 *, 0x278) != 0)) {
            var_a1 = 0x50;
        } else {
            var_a1 = 0x2D;
        }
    } else {
        var_a1 = D_809045C4[M2C_FIELD(arg0, s8 *, 0x278)];
    }
    M2C_FIELD(arg0, s16 *, 0x240) = func_800FF250(0xF, var_a1);
    M2C_FIELD(arg0, s32 *, 0x248) = 0;
    M2C_FIELD(arg0, s16 *, 0x26E) = 0x190;
    M2C_FIELD(arg0, s16 *, 0x272) = 0x190;
    M2C_FIELD(arg0, s16 *, 0x26C) = 0;
    func_80902150(arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x23C) = &D_80902C18;
}
