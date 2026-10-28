// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, f32);                 /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
s16 func_80181190(f32, f32);                        /* extern */
M2C_UNK func_8088BC30(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_8088CF18(u8 *, s32);                 /* extern */
M2C_UNK func_8088ED14(u8 *, u8 *, M2C_UNK);     /* extern */
extern M2C_UNK D_8088DA24;
extern f32 D_80890264;
extern f32 D_80890268;
extern f32 D_8089026C;

void func_80001F74(u8 *arg0, u8 *arg1) {
    s32 sp24;
    f32 temp_f0;
    f32 temp_f0_2;

    sp24 = M2C_FIELD(arg1, s32 *, 0x1CCC);
    func_80137070(arg0 + 0x144);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x250);
    M2C_FIELD(arg0, f32 *, 0x22C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x224) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x228) = (f32) (M2C_FIELD(arg0, f32 *, 0x228) + temp_f0);
    M2C_FIELD(arg0, f32 *, 0x250) = (f32) (temp_f0 - D_80890264);
    if (M2C_FIELD(arg0, f32 *, 0x250) <= 0.0f) {
        func_8088BC30(arg0, &D_8088DA24);
        M2C_FIELD(arg0, s16 *, 0x24C) = 0x800;
        M2C_FIELD(arg0, s16 *, 0x24A) = 0;
        M2C_FIELD(arg0, f32 *, 0x250) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x254) = 1.0f;
    }
    func_8088CF18(arg0, sp24 + 0xBEC);
    temp_f0_2 = M2C_FIELD(arg0, f32 *, 0x250);
    func_800B6564(arg0, (1.0f - (temp_f0_2 * temp_f0_2 * D_80890268)) * D_8089026C);
    M2C_FIELD(arg0, s16 *, 0x258) = func_80181190(M2C_FIELD(arg0, f32 *, 0x6C), M2C_FIELD(arg0, f32 *, 0x64));
    func_8088ED14(arg0, arg1, 0x20);
    func_800B8C4C(arg0, 0x20A8);
}
