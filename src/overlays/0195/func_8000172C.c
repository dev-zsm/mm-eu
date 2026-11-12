#include "types.h"
#include "m2c_compat.h"

s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80147CC4(u8 *);                      /* extern */
M2C_UNK func_80151E7C(u8 *, s32);                 /* extern */
s32 func_801529DC(u8 *);                          /* extern */
M2C_UNK func_809596F8(u8 *, u8 *);              /* extern */
extern M2C_UNK D_8095A460;

void func_8000172C(u8 *arg0, u8 *arg1) {
    s32 temp_v0;

    func_809596F8(arg0, arg1);
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        temp_v0 = M2C_FIELD(arg1, u16 *, 0x16810);
        switch (temp_v0) {
            case 0x904:
            case 0x905:
            case 0x906:
            case 0x908:
            case 0x910:
            case 0x911:
            case 0x912:
            case 0x914:
                func_80151E7C(arg1, (temp_v0 + 1) & 0xFFFF);
                return;
            default:
                func_80147CC4(arg1);
                M2C_FIELD(arg0, M2C_UNK **, 0x2F0) = &D_8095A460;
                break;
        }
    }
}
