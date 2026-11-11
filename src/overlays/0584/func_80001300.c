#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0584.h"

s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80147CC4(u8 *);                      /* extern */
M2C_UNK func_80151E7C(u8 *, s32);                 /* extern */
s32 func_801529DC(u8 *);                          /* extern */
M2C_UNK func_80BC2230(u8 *, u8 *);              /* extern */
extern M2C_UNK D_80BC23D4;

void func_80001300(u8 *arg0, u8 *arg1) {
    s32 temp_v0;
    u32 temp_v0_2;

    func_80BC2230(arg0, arg1);
    temp_v0 = func_801529DC(arg1 + 0x4908);
    if (temp_v0 != 2) {
        if ((temp_v0 == 5) && (func_80147B34(arg1) != 0)) {
            temp_v0_2 = M2C_FIELD(arg1, u16 *, 0x16810);
            switch (temp_v0_2) {
                case 0x12E8:
                case 0x12E9:
                case 0x12EC:
                case 0x12ED:
                case 0x12EF:
                case 0x12F1:
                case 0x12F3:
                case 0x12F4:
                case 0x12F5:
                case 0x12F6:
                case 0x12F8:
                case 0x12FA:
                case 0x12FB:
                case 0x12FD:
                case 0x12FF:
                    func_80151E7C(arg1, (temp_v0_2 + 1) & 0xFFFF);
                    return;
                default:
                    func_80147CC4(arg1);
                    return;
            }
        }
    } else {
        M2C_FIELD(arg0, M2C_UNK **, 0x618) = &D_80BC23D4;
    }
}
