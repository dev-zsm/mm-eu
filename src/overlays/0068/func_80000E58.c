#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0068.h"

M2C_UNK func_800FEC70(s32, M2C_UNK, M2C_UNK);       /* extern */
s32 func_800FEE3C(s32, f32, M2C_UNK);           /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80879CFC(u8 *);                      /* extern */

void func_80000E58(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    func_80137070(arg0 + 0x144);
    func_800FEC70(arg0 + 0xBC, 0, 0x100);
    func_800FEE3C(arg0 + 0x68, 0, 0x3ECCCCCD);
    if (func_800FEE3C(arg0 + 0x70, 0.0f, 0x3E19999A) != 0) {
        if (M2C_FIELD(arg0, s16 *, 0x190) != 0) {
            M2C_FIELD(arg0, s16 *, 0x190) = (s16) (M2C_FIELD(arg0, s16 *, 0x190) - 1);
        }
        if (M2C_FIELD(arg0, s16 *, 0x190) == 0) {
            func_80879CFC(arg0);
        }
    }
}
