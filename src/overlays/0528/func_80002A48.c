#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0528.h"

M2C_UNK D_80B7DE48(u8 *, u8 *);                 /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80147CC4(u8 *);                      /* extern */
M2C_UNK func_80151E7C(u8 *, s32);                 /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80B7DCD4(u8 *, u8 *);              /* extern */

void func_80002A48(u8 *arg0, u8 *arg1) {
    u16 temp_v0;

    if (!(M2C_FIELD(arg0, u16 *, 0x2F2) & 4)) {
        func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 2, 0x800, 0x100);
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    }
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        switch ((M2C_FIELD(arg1, u16 *, 0x16810))) {
            case 0x12BB:
                M2C_FIELD(arg0, u16 *, 0x2F2) = (u16) (M2C_FIELD(arg0, u16 *, 0x2F2) & 0xFFFB);
                /* fallthrough */
            case 0x12BC:
            case 0x12C0:
            case 0x12C3:
                func_80151E7C(arg1, (M2C_FIELD(arg1, u16 *, 0x16810) + 1) & 0xFFFF);
                return;
            case 0x12BE:
                func_80147CC4(arg1);
                M2C_FIELD(arg0, M2C_UNK (**)(u8 *, u8 *), 0x2F8) = func_80B7DCD4;
                func_80B7DCD4(arg0, arg1);
                return;
            default:
                func_80147CC4(arg1);
                M2C_FIELD(arg0, M2C_UNK (**)(u8 *, u8 *), 0x2F8) = D_80B7DE48;
                break;
        }
    }
}
