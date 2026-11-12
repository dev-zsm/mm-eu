#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80151E7C(u8 *, s32);                 /* extern */
s32 func_801529DC(u8 *);                          /* extern */
M2C_UNK func_801A00B8();                            /* extern */
M2C_UNK func_801A00E0();                            /* extern */
s32 func_8094DE2C(s32);                             /* extern */
M2C_UNK func_8094DF84(u8 *, u8 *);              /* extern */
s32 func_8094E0EC(u8 *, u8 *);                  /* extern */
extern M2C_UNK D_8094E238;

void func_800010E8(u8 *arg0, u8 *arg1) {
    s32 pad;
    u8 *sp28;
    s32 temp_v0;
    s32 temp_v0_3;
    u8 temp_v0_2;

    sp28 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    func_80137070(arg0 + 0x144);
    func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 6, 0x1838, 0x64);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    temp_v0 = func_801529DC(arg1 + 0x4908);
    switch (temp_v0) {                              /* switch 1; irregular */
        case 4:                                         /* switch 1 */
            if ((func_80147B34(arg1) != 0) && (M2C_FIELD(arg1, u16 *, 0x16810) == 0x2215)) {
            temp_v0_2 = M2C_FIELD(arg1, u8 *, 0x1692D);
            switch (temp_v0_2) {                    /* switch 2; irregular */
                case 0:                                 /* switch 2 */
                    func_801A00B8();
                    func_80151E7C(arg1, 0x2217);
                    return;
                case 1:                                 /* switch 2 */
                    func_801A00E0();
                    func_80151E7C(arg1, 0x2216);
                    return;
            }
            } else {
            return;
            }
            break;
        case 5:                                         /* switch 1 */
            if (func_80147B34(arg1) != 0) {
            temp_v0_3 = M2C_FIELD(arg1, u16 *, 0x16810);
            switch (temp_v0_3) {                    /* switch 3 */
                case 0x220C:                            /* switch 3 */
                    M2C_FIELD(arg0, u16 *, 0x2B8) = (u16) (M2C_FIELD(arg0, u16 *, 0x2B8) | 1);
                    if (func_8094DE2C(M2C_FIELD(arg0, s16 *, 0x1C) & 0xF) == 0) {
                    func_80151E7C(arg1, 0x220F);
                    return;
                    }
                    func_80151E7C(arg1, 0x220D);
                    return;
                case 0x220D:                            /* switch 3 */
                case 0x2213:                            /* switch 3 */
                    func_80151E7C(arg1, (temp_v0_3 + 1) & 0xFFFF);
                    return;
                case 0x220E:                            /* switch 3 */
                    func_80151E7C(arg1, 0xFF);
                    M2C_FIELD(arg0, M2C_UNK **, 0x2C4) = &D_8094E238;
                    return;
                case 0x2210:                            /* switch 3 */
                case 0x2211:                            /* switch 3 */
                case 0x2212:                            /* switch 3 */
                    M2C_FIELD(sp28, s8 *, 0xA87) = 0;
                    func_80151E7C(arg1, 0xFF);
                    M2C_FIELD(arg0, M2C_UNK **, 0x2C4) = &D_8094E238;
                    return;
                case 0x2214:                            /* switch 3 */
                case 0x2217:                            /* switch 3 */
                    if (func_8094E0EC(arg0, arg1) == 0) {
                    func_8094DF84(arg0, arg1);
                    return;
                    }
                    break;
                default:                                /* switch 3 */
                    func_8094DF84(arg0, arg1);
                    break;
            }
            }
            break;
    }
}
