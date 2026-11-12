#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
s32 func_800B7164(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_800BC370(u8 *, u8 *);                  /* extern */
M2C_UNK func_800FEC70(u8 *, s16, M2C_UNK);        /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
s32 func_80975688(u8 *, u8 *, M2C_UNK);         /* extern */
M2C_UNK func_80975B8C(u8 *, u8 *);              /* extern */
M2C_UNK func_80975F40(u8 *);                      /* extern */
M2C_UNK func_80976688(u8 *);                      /* extern */
M2C_UNK func_80976944(u8 *);                      /* extern */
M2C_UNK func_80976F7C(u8 *);                      /* extern */
s32 func_80978DCC(u8 *, u8 *, u8 *);          /* extern */
extern f32 D_8097907C;
extern f32 D_80979080;

void func_8000118C(u8 *arg0, u8 *arg1) {
    f32 sp2C;
    s32 sp28;
    s16 temp_v0;
    u8 *sp20;
    s16 temp_v0_2;

    sp20 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (func_80978DCC(arg1, arg0, arg1) == 0) {
        func_800FEC70(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 0x1F4);
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
        if (func_800BC370(arg1, arg0) != 0) {
            sp2C = 150.0f;
        } else {
            sp2C = 0.0f;
        }
        temp_v0 = M2C_FIELD(sp20, s16 *, 0xBE) - M2C_FIELD(arg0, s16 *, 0xBE);
        if (temp_v0 < 0) {
            sp28 = (s32) -temp_v0;
        } else {
            sp28 = (s32) temp_v0;
        }
        if ((M2C_FIELD(arg0, f32 *, 0x98) < (150.0f + sp2C)) && (M2C_FIELD(sp20, s8 *, 0xADB) != 0) && (sp28 >= 0x1F40)) {
            temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x92);
            M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0_2;
            M2C_FIELD(arg0, s16 *, 0x32) = temp_v0_2;
            if (D_8097907C < func_8008704C()) {
                func_80976688(arg0);
                return;
            }
        }
        func_80137070(arg0 + 0x144);
        if (func_80975688(arg1, arg0, 0) == 0) {
            if (func_800B7164(arg0, 0x11C7) == 0) {
                if (func_8008704C() > 0.5f) {
                    func_80976688(arg0);
                } else {
                    func_80975F40(arg0);
                }
            } else if (M2C_FIELD(arg0, f32 *, 0x98) < (90.0f + sp2C)) {
                if ((func_800BC370(arg1, arg0) == 0) && ((D_80979080 < func_8008704C()) || ((M2C_FIELD(arg0, f32 *, 0x98) <= 80.0f) && (sp28 < 0x38E0)))) {
                    func_80976944(arg0);
                } else if ((func_800BC370(arg1, arg0) != 0) && (func_8008704C() > 0.5f)) {
                    func_80976F7C(arg0);
                } else {
                    func_80976688(arg0);
                }
            }
            if (M2C_FIELD(arg0, u16 *, 0x2A2) == 0) {
                func_800B8C4C(arg0, 0x383E);
            }
            func_80975B8C(arg0, arg1);
        }
    }
}
