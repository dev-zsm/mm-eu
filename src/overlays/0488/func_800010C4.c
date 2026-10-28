// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80147CC4(u8 *);                      /* extern */
s32 func_801529DC(u8 *);                          /* extern */
s32 func_80B25B84(u8 *);                          /* extern */
M2C_UNK func_80B25C18(u8 *, u8 *);              /* extern */
M2C_UNK func_80B260F8(u8 *);                      /* extern */
M2C_UNK func_80B2636C(u8 *, u8 *);              /* extern */
extern M2C_UNK D_80B26588;

void func_800010C4(u8 *arg0, u8 *arg1) {
    u16 temp_v0;

    func_80B2636C(arg0, arg1);
    if ((M2C_FIELD(arg0, s16 *, 0x2E4) <= 0) && !(M2C_FIELD(arg0, u16 *, 0x29C) & 2) && (func_80B25B84(arg0) == 0) && (func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0) && ((temp_v0 = M2C_FIELD(arg1, u16 *, 0x16810), (temp_v0 == 0xC4E)) || (temp_v0 == 0xC4F))) {
        func_80147CC4(arg1);
        M2C_FIELD(arg0, s16 *, 0x116) = 0xC4F;
        func_80B260F8(arg0);
        func_800F1944(M2C_FIELD(arg0, s16 *, 0x2DE));
        M2C_FIELD(arg0, M2C_UNK **, 0x304) = &D_80B26588;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~0x100);
    }
    func_80B25C18(arg0, arg1);
}
