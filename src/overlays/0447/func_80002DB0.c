// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(M2C_UNK, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_8013CD14(u8 *, M2C_UNK, s32, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80ADC8DC(u8 *);                      /* extern */
M2C_UNK func_80ADCB9C(u8 *);                      /* extern */
M2C_UNK func_80ADCC98(u8 *, M2C_UNK);             /* extern */
s32 func_80ADD420(u8 *, M2C_UNK);                 /* extern */
s32 func_80ADD4F4(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80ADD7F8(u8 *);                      /* extern */
M2C_UNK func_80ADDB04(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80ADF454(u8 *, M2C_UNK);             /* extern */

void func_80002DB0(u8 *arg0, M2C_UNK arg1) {
    if ((func_80ADD420(arg0, arg1) == 0) && (func_80ADD4F4(arg0, arg1) != 0)) {
        func_80ADF454(arg0, arg1);
        func_80ADCB9C(arg0);
        func_80ADD7F8(arg0);
        return;
    }
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x188)(arg0, arg1);
    func_80ADC8DC(arg0);
    if (M2C_FIELD(arg0, u8 *, 0x258) != 0) {
        func_80ADDB04(arg0, arg1);
        func_80ADCB9C(arg0);
        func_80ADD7F8(arg0);
        func_8013CD14(arg0, arg1, M2C_FIELD(arg0, s32 *, 0x368), 0x41F00000, M2C_FIELD(arg0, s32 *, 0x394), M2C_FIELD(arg0, u16 *, 0x356) & 7);
        func_800B680C(arg0);
        func_800B763C(arg1, arg0, 0x41F00000, 0x41400000, 0.0f, 4);
        func_80ADCC98(arg0, arg1);
    }
}
