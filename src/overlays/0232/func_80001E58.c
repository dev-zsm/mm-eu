// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0232.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_8096DE80(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
M2C_UNK func_8096E708(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_8096F1A8;
extern M2C_UNK D_8097109C;

void func_80001E58(Actor *thisx, s32 arg1) {
    if (M2C_FIELD(thisx, u16 *, 0x90) & 1) {
        func_8096DE80((u8 *)thisx + 0x14C, &D_8097109C, 2, thisx);
        M2C_FIELD(thisx, M2C_UNK **, 0x144) = &D_8096F1A8;
    }
    func_800B680C(thisx);
    func_8096E708(thisx, 0x40400000);
}
