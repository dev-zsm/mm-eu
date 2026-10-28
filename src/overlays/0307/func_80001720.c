// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80A0E7B0(s32, s32, s32, u8 *);           /* extern */

void func_80001720(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_80A0E7B0(arg1, M2C_FIELD(arg0, s32 *, 0x1C0), M2C_FIELD(arg0, s32 *, 0x1BC), arg0);
    switch (temp_v0) {                              /* irregular */
    case 1:
        M2C_FIELD(arg0, s16 *, 0xC0) = (s16) M2C_FIELD(arg0, s16 *, 0x18);
        return;
    case 2:
        M2C_FIELD(arg0, s16 *, 0xC0) = (s16) (M2C_FIELD(arg0, s16 *, 0x18) + 0x8000);
        return;
    }
}
