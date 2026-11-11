#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80B93470;

void func_800003C4(u8 *arg0) {
    u16 temp_t6;
    u8 *temp_v0;
    u8 *temp_v0_2;
    u8 *temp_v0_3;

    switch ((M2C_FIELD(arg0, u16 *, 0x1E8))) {
        case 0x29E5:
            M2C_FIELD(arg0, s32 *, 0x450) = 1;
            func_800BD9E0(arg0 + 0x150, &D_80B93470, 1, arg0);
            return;
        case 0x29E9:
            temp_v0 = M2C_FIELD(arg0, u8 **, 0x144);
            M2C_FIELD(temp_v0, u16 *, 0x44E) = (u16) (M2C_FIELD(temp_v0, u16 *, 0x44E) | 0x100);
            return;
        case 0x29EA:
            temp_v0_2 = M2C_FIELD(arg0, u8 **, 0x144);
            M2C_FIELD(temp_v0_2, u16 *, 0x44E) = (u16) (M2C_FIELD(temp_v0_2, u16 *, 0x44E) | 0x200);
            return;
        case 0x29EB:
            temp_v0_3 = M2C_FIELD(arg0, u8 **, 0x144);
            M2C_FIELD(temp_v0_3, u16 *, 0x44E) = (u16) (M2C_FIELD(temp_v0_3, u16 *, 0x44E) | 0x40);
            return;
        case 0x29EC:
            M2C_FIELD(arg0, s32 *, 0x450) = 7;
            func_800BD9E0(arg0 + 0x150, &D_80B93470, 7, arg0);
            return;
        case 0x29ED:
            M2C_FIELD(arg0, s32 *, 0x450) = 1;
            func_800BD9E0(arg0 + 0x150, &D_80B93470, 1, arg0);
            /* fallthrough */
        default:
            return;
    }
}
