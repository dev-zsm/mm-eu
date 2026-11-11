#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
s32 func_800C5F18(u8 *, u8 *, u8 *, s32);     /* extern */
M2C_UNK func_800C92F4(M2C_UNK *, s32 *);            /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E1F14(u8 *, u8 *);              /* extern */
M2C_UNK func_800E1FB4(u8 *, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80AB31E4(u8 *);                      /* extern */
extern M2C_UNK D_60023D4;
extern M2C_UNK D_80AB4340;

void func_80000000(u8 *arg0, u8 *arg1) {
    u8 *temp_a1;
    u8 *sp20;
    s32 sp2C;
    u8 *temp_v0;
    u8 *var_s0;

    sp2C = 0;
    var_s0 = M2C_FIELD(arg1, u8 **, 0x1CE4);
    func_800CABA0(arg0, 3);
    func_800C92F4(&D_60023D4, &sp2C);
    M2C_FIELD(arg0, s32 *, 0x144) = func_800C5F18(arg1, arg1 + 0x880, arg0, sp2C);
    func_800B6564(arg0, 0x3DCCCCCD);
    temp_a1 = arg0 + 0x160;
    sp20 = temp_a1;
    func_800E1F14(arg1, temp_a1);
    func_800E1FB4(arg1, temp_a1, arg0, &D_80AB4340);
    M2C_FIELD(arg0, s16 *, 0x1AE) = 0x14;
    if (var_s0 != NULL) {
        loop_2:
        if (M2C_FIELD(var_s0, s16 *, 0) == 0xB5) {
            M2C_FIELD(arg0, u8 **, 0x120) = var_s0;
        } else {
            var_s0 = M2C_FIELD(var_s0, u8 **, 0x12C);
            if (var_s0 != NULL) {
                goto loop_2;
            }
        }
    }
    if (var_s0 == NULL) {
        func_800B6490(arg0);
        return;
    }
    temp_v0 = M2C_FIELD(arg0, u8 **, 0x120);
    if (M2C_FIELD(temp_v0, s16 *, 0x542) == 2) {
        M2C_FIELD(arg0, s8 *, 0x18C) = 0;
        M2C_FIELD(arg0, s16 *, 0x1AE) = 0x1E;
    } else {
        M2C_FIELD(arg0, s16 *, 0x1AE) = 0x11;
        M2C_FIELD(arg0, s32 *, 0x2F8) = (s32) M2C_FIELD(temp_v0, s32 *, 0x538);
        M2C_FIELD(arg0, s32 *, 0x2F4) = (s32) M2C_FIELD(temp_v0, s32 *, 0x520);
        M2C_FIELD(arg0, s32 *, 0x2F0) = (s32) M2C_FIELD(arg0, s16 *, 0x1C);
    }
    M2C_FIELD(arg0, s16 *, 0x302) = 0;
    M2C_FIELD(arg0, s16 *, 0x304) = 0;
    func_80AB31E4(arg0);
}
