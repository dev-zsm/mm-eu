#include "types.h"
#include "m2c_compat.h"
s32 func_800F1984(s32 a);
void func_800F1A08(s32 a, u8 *b);
void func_800F1944(s32 a);

s32 func_800009BC(u8 *a, u8 *play) {
    if (func_800F1984(M2C_FIELD(a, s8 *, 0x2B2)) != 0) {
        func_800F1A08(M2C_FIELD(a, s8 *, 0x2B2), M2C_FIELD(play, u8 **, 0x1CCC));
        return 1;
    }
    func_800F1944(M2C_FIELD(a, s8 *, 0x2B2));
    return 0;
}
