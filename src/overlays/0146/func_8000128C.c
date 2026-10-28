// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B763C(M2C_UNK, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_8013CD14(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_809110B0(u8 *);                      /* extern */
M2C_UNK func_809111EC(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8091135C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80911424(u8 *);                      /* extern */
s32 func_809115C0(u8 *, M2C_UNK);                 /* extern */
s32 func_80911688(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_809120D8(u8 *, M2C_UNK);             /* extern */

void func_8000128C(u8 *arg0, M2C_UNK arg1) {
    if ((func_809115C0(arg0, arg1) == 0) && (func_80911688(arg0, arg1) != 0)) {
        func_809120D8(arg0, arg1);
        func_80137070(arg0 + 0x144);
        func_809110B0(arg0);
        return;
    }
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x188)(arg0, arg1);
    func_80137070(arg0 + 0x144);
    func_80911424(arg0);
    func_8091135C(arg0, arg1);
    func_800B763C(arg1, arg0, 0x41F00000, 0x41400000, 0.0f, 4);
    func_8013CD14(arg0, arg1, 0x42A00000, 0x42200000, 0, M2C_FIELD(arg0, u16 *, 0x2C6) & 7);
    func_800B64E0(arg0, 0x42080000);
    func_809111EC(arg0, arg1);
    func_809110B0(arg0);
}
