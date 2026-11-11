#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0228.h"

M2C_UNK func_800FEE3C(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8096923C(u8 *);                      /* extern */
M2C_UNK func_80969ECC(u8 *);                      /* extern */

void func_800010D4(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0x1C) == 0xA) {
        func_80969ECC(arg0);
        return;
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x14A);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x14A) = (s16) (temp_v0 - 1);
        if (M2C_FIELD(arg0, s16 *, 0x14A) == 0) {
            M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
            M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
            M2C_FIELD(arg0, f32 *, 0x70) = 1.0f;
            M2C_FIELD(arg0, f32 *, 0x68) = 12.0f;
            M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
        }
        func_800FEE3C(arg0 + 0x58, 0x3E3851EB, 0x3C23D70B);
        func_800FEE3C(arg0 + 0x5C, 0x3D4CCCCD, 0x3C23D70B);
        goto block_10;
    }
    if (M2C_FIELD(arg0, f32 *, 0x68) > 0.0f) {
        func_800FEE3C(arg0 + 0x58, 0x3DC28F5C, 0x3CA3D70B);
        func_800FEE3C(arg0 + 0x5C, 0x3DDB22D2, 0x3CA3D70B);
        goto block_10;
    }
    func_800FEE3C(arg0 + 0x58, 0x3E3851EB, 0x3B449BA6);
    func_800FEE3C(arg0 + 0x5C, 0x3D4CCCCD, 0x3B449BA6);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        func_8096923C(arg0);
        return;
    }
    block_10:
    M2C_FIELD(arg0, f32 *, 0x60) = (f32) M2C_FIELD(arg0, f32 *, 0x58);
}
