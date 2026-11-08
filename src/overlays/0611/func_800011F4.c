// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0611.h"

s32 func_800B8254(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B8398(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_801244EC(M2C_UNK);                         /* extern */
M2C_UNK func_80151DF4(M2C_UNK, M2C_UNK, u8 *);    /* extern */
s32 func_80BE0A18(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80BE0AF4(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80BE13A8;

void func_800011F4(Actor *thisx, s32 arg1) {
    func_80BE0AF4(thisx, arg1);
    if (func_800B8254(thisx, arg1) != 0) {
        M2C_FIELD(thisx, M2C_UNK **, 0x430) = &D_80BE13A8;
        if (func_801244EC(arg1) == 0xE) {
            func_80151DF4(arg1, 0x2925, thisx);
            return;
        }
        func_80151DF4(arg1, 0x2924, thisx);
        return;
    }
    if (func_80BE0A18(thisx, arg1) != 0) {
        func_800B8398(thisx, arg1, 0x42F00000);
    }
}
