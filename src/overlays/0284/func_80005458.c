// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0284.h"

M2C_UNK func_800BE404(u8 **, u8 *, u8 *, M2C_UNK, f32, f32, f32, s32); /* extern */
M2C_UNK func_800FFC68(f32 *, M2C_UNK, M2C_UNK);     /* extern */
s32 func_8012C100(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_8012C73C(u8 *);                      /* extern */
M2C_UNK func_8012C78C(u8 *);                      /* extern */
M2C_UNK func_801342C8(u8 **, s32, s32, u8, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
s32 func_80167228(u8 **, s32);                    /* extern */
M2C_UNK func_809B55CC(M2C_UNK, s32, M2C_UNK *);     /* extern */
M2C_UNK func_809B9ECC(u8 *, u8 **);             /* extern */
M2C_UNK func_809BACE4(s32, u8 *, u8 **);        /* extern */
M2C_UNK func_809BAD9C(s32, u8 *, u8 **);        /* extern */
M2C_UNK func_809BC104(u8 **);                     /* extern */
extern M2C_UNK D_809BA2B4;
extern M2C_UNK D_809BA2FC;
extern M2C_UNK D_809BCBD0;
extern f32 D_809BD764;

void func_80005458(u8 *arg0, u8 **arg1) {
    s32 pad[4];
    s32 sp38;
    s32 temp_v1;
    u8 *temp_s2;
    u8 *temp_v0;

    temp_v0 = *arg1;
    temp_v1 = M2C_FIELD(temp_v0, s32 *, 0x2B4) - 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x2B4) = temp_v1;
    temp_s2 = *arg1;
    sp38 = temp_v1;
    func_809B55CC(2, arg0 + 0x468, &D_809BCBD0);
    func_8012C73C(*arg1);
    func_8012C78C(*arg1);
    if (M2C_FIELD(arg0, s16 *, 0x15E) & 1) {
        M2C_FIELD(temp_s2, s32 *, 0x2B0) = func_8012C100(M2C_FIELD(temp_s2, s32 *, 0x2B0), 0xFF, 0, 0, 0xFF, 0x384, 0x44B);
    }
    func_801342C8(arg1, M2C_FIELD(arg0, s32 *, 0x168), M2C_FIELD(arg0, s32 *, 0x184), M2C_FIELD(arg0, u8 *, 0x166), &D_809BA2B4, &D_809BA2FC, arg0);
    M2C_FIELD(temp_s2, s32 *, 0x2B0) = func_80167228(arg1, M2C_FIELD(temp_s2, s32 *, 0x2B0));
    func_809BACE4(sp38, arg0, arg1);
    func_809BAD9C(sp38, arg0, arg1);
    if (D_809BD764 > 0.0f) {
        func_809B9ECC(arg0, arg1);
        func_800FFC68(&D_809BD764, 0x3F800000, 0x42480000);
    }
    func_800BE404(arg1, arg0, arg0 + 0x928, 0xF, M2C_FIELD(arg0, f32 *, 0xACC), M2C_FIELD(arg0, f32 *, 0xAD0), M2C_FIELD(arg0, f32 *, 0xAD4), (s32) M2C_FIELD(arg0, u8 *, 0xAD8));
    func_809BC104(arg1);
}
