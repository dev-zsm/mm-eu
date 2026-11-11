#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x144]; void *unk144; void *unk148; u8 pad14C[0x30E]; s16 unk45A; } S_arg0;

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1B24(s16, u8 *);                 /* extern */
M2C_UNK func_80B8F834(u8 *);                      /* extern */
extern M2C_UNK D_80B9283C;

void func_8000363C(S_arg0 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    if (func_800F1984(((s16 *)((u8 *)arg0 + 0x456))[M2C_FIELD(arg0, s16 *, 0x45A)]) != 0) {
        temp_v0 = arg0->unk45A;
        if (temp_v0 == 0) {
            func_800F1B24(M2C_FIELD(((u8 *)arg0 + (temp_v0 * 2)), s16 *, 0x456), arg0->unk144);
        } else {
            func_800F1B24(M2C_FIELD(((u8 *)arg0 + (temp_v0 * 2)), s16 *, 0x456), arg0);
        }
        func_80B8F834(arg0);
        arg0->unk148 = &D_80B9283C;
        return;
    }
    func_800F1944(((s16 *)((u8 *)arg0 + 0x456))[M2C_FIELD(arg0, s16 *, 0x45A)]);
}
