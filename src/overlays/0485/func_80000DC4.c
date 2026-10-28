// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(M2C_UNK, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_800B87A0(u8 *, M2C_UNK, M2C_UNK, f32, f32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_8013CD14(u8 *, M2C_UNK, f32, f32, s32, s32); /* extern */
M2C_UNK func_80B21750(u8 *);                      /* extern */
M2C_UNK func_80B219B0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B21A4C(u8 *);                      /* extern */
M2C_UNK func_80B21BF0(u8 *, M2C_UNK);             /* extern */
s32 func_80B21C90(u8 *, M2C_UNK);                 /* extern */
s32 func_80B21D74(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80B21E4C(u8 *, M2C_UNK);             /* extern */
extern u8 D_801E7DFF;

void func_80000DC4(u8 *arg0, M2C_UNK arg1) {
    f32 sp2C;
    f32 sp28;
    f32 temp_f0;
    f32 temp_f2;

    if ((func_80B21C90(arg0, arg1) == 0) && (func_80B21D74(arg0, arg1) != 0)) {
        func_80B21E4C(arg0, arg1);
        func_80137070(arg0 + 0x144);
        func_80B21A4C(arg0);
        func_80B21BF0(arg0, arg1);
    } else {
        M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x188)(arg0, arg1);
        func_80137070(arg0 + 0x144);
        func_80B21A4C(arg0);
        func_80B21BF0(arg0, arg1);
        func_800B680C(arg0);
        func_800B763C(arg1, arg0, 0x41F00000, 0x41400000, 0.0f, 4);
        temp_f0 = (f32) (M2C_FIELD(arg0, s16 *, 0x1CC) + 0x32);
        temp_f2 = (f32) (M2C_FIELD(arg0, s16 *, 0x1CE) + 0x1E);
        if ((M2C_FIELD(arg0, u16 *, 0x322) & 0x400) && !(D_801E7DFF & 0x20)) {
            sp2C = temp_f0;
            sp28 = temp_f2;
            func_800B87A0(arg0, arg1, 0xBA, temp_f0, temp_f2);
        }
        func_8013CD14(arg0, arg1, temp_f0, temp_f2, 0, M2C_FIELD(arg0, u16 *, 0x322) & 7);
        func_800B64E0(arg0, 0x41F00000);
        func_80B219B0(arg0, arg1);
    }
    if (M2C_FIELD(arg0, u16 *, 0x322) & 0x100) {
        func_80B21750(arg0);
    }
}
