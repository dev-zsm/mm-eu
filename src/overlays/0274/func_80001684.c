#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0274.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(s32, u8 *, f32, f32, f32, s32); /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
f32 func_8017A844(f32);                         /* extern */
M2C_UNK func_809A96FC(u8 *);                      /* extern */

void func_80001684(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2BA);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x2BA) = (s16) (temp_v0 - 1);
    }
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x2BC);
    if (temp_v0_2 != 0) {
        M2C_FIELD(arg0, s16 *, 0x2BC) = (s16) (temp_v0_2 - 1);
    }
    func_80137070(arg0 + 0x144);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    func_809A96FC(arg0);
    func_800B64E0(arg0, 0x41A00000);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x284)(arg0, arg1);
    func_800B680C(arg0);
    func_800FFCBC(arg0 + 0x28A, M2C_FIELD(arg0, s16 *, 0x290), 1, 0x1388, 0);
    func_800FFCBC(arg0 + 0x288, M2C_FIELD(arg0, s16 *, 0x28E), 1, 0x3E8, 0);
    if (M2C_FIELD(arg0, s16 *, 0x2F2) == 0) {
        M2C_FIELD(arg0, s16 *, 0x2F0) = (s16) (M2C_FIELD(arg0, s16 *, 0x2F0) + 1);
        if (M2C_FIELD(arg0, s16 *, 0x2F0) >= 3) {
            M2C_FIELD(arg0, s16 *, 0x2F0) = 0;
            M2C_FIELD(arg0, s16 *, 0x2F2) = (s16) ((s32) func_8017A844(6.0e+01f) + 0x14);
        }
    }
    func_800B763C(arg1, arg0, 2.0e+01f, 2.0e+01f, 50.0f, 0x1D);
}
