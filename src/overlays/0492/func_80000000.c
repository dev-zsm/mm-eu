#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800BBED8(s32, s32, u8 *, M2C_UNK);   /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
s32 func_800F1E2C();                                /* extern */
M2C_UNK func_80136E1C(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80B3F584(u8 *);                      /* extern */
extern M2C_UNK D_600005C;
extern M2C_UNK D_6001398;
extern M2C_UNK D_800B3F30;
extern s32 D_80B3FF20;
extern M2C_UNK D_80B3FF44;
extern M2C_UNK D_80B3FF64;

void func_80000000(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0xB6) = 0xA;
    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41980000);
    func_80136E1C(arg1, arg0 + 0x144, &D_6001398, &D_600005C, arg0 + 0x188, arg0 + 0x1C4, 0xA);
    M2C_FIELD(arg0, s8 *, 0xB7) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0xA0) = &D_80B3FF44;
    M2C_FIELD(arg0, s8 *, 0x1F) = 6;
    func_800E1134(arg1, arg0 + 0x23C, arg0, &D_80B3FF64);
    M2C_FIELD(arg0, s32 *, 0x218) = (s32) D_80B3FF20;
    D_80B3FF20 += 1;
    M2C_FIELD(arg0, f32 *, 0xCC) = 12.0f;
    if (func_800F1E2C() != -1) {
        func_800BBED8(arg1, arg1 + 0x1CA0, arg0, 7);
    }
    M2C_FIELD(arg0, s8 *, 0x11F) = 0xC;
    func_80B3F584(arg0);
}
