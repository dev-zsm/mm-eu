// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0275.h"

s32 func_800B8254(u8 *, u8 *);                  /* extern */
M2C_UNK func_800B8364(u8 *, u8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80151DF4(u8 *, M2C_UNK, u8 *);     /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_809ABB60;

void func_80001754(Actor *thisx, u8 *arg1) {
    u8 *sp24;

    sp24 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (func_800B8254(thisx, arg1) != 0) {
        if ((((s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5) == 3) && ((s32) M2C_FIELD(&D_801E6EF0, u16 *, 0xC) >= 0x8001)) {
            func_80151DF4(arg1, 0xA36, thisx);
            M2C_FIELD(thisx, s16 *, 0x284) = 0xA36;
        } else {
            func_80151DF4(arg1, 0xA37, thisx);
            M2C_FIELD(thisx, s16 *, 0x284) = 0xA37;
        }
        M2C_FIELD(sp24, s32 *, 0xA6C) = (s32) (M2C_FIELD(sp24, s32 *, 0xA6C) & ~0x20);
        M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & 0xFFFEFFFF);
        M2C_FIELD(thisx, s16 *, 0x280) = 0;
        M2C_FIELD(thisx, s16 *, 0x26A) = 0;
        M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_809ABB60;
        return;
    }
    func_800B8364(thisx, arg1, 0x43FA0000, -1);
}
