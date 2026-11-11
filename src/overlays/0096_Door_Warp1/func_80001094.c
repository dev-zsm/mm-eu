#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0096.h"

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1B24(s16, M2C_UNK);                /* extern */
M2C_UNK func_808B7B70(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_808B8C6C;

void func_80001094(s32 arg0, u8 *arg1) {

    if (func_800F1984(M2C_FIELD(arg1, s16 *, 0x187AE)) == 0) {
        func_800F1944(M2C_FIELD(arg1, s16 *, 0x187AE));
        return;
    }
    func_800F1B24(M2C_FIELD(arg1, s16 *, 0x187AE), 0);
    func_808B7B70(arg0, &D_808B8C6C);
}
