// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0634.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
M2C_UNK func_80BF8DD0(u8 *);                      /* extern */
extern u16 D_801E6EFC;
extern M2C_UNK D_80BF9DD0;

void func_80000560(Actor *thisx, s32 arg1) {
    if (func_800B8254(thisx, arg1) != 0) {
        M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & 0xFFFEFFFF);
        if ((((s32) D_801E6EFC >= 0x2AAB) && ((s32) D_801E6EFC < 0x4AAA)) || (((s32) D_801E6EFC >= 0xAAAB) && ((s32) D_801E6EFC < 0xCAAA))) {
            func_800BD9E0((u8 *)thisx + 0x190, &D_80BF9DD0, 2);
            func_80151DF4(arg1, 0x1094, thisx);
            M2C_FIELD(thisx, s16 *, 0x300) = 0x1094;
        } else {
            func_800BD9E0((u8 *)thisx + 0x190, &D_80BF9DD0, 1);
            func_80151DF4(arg1, 0x1098, thisx);
            M2C_FIELD(thisx, s16 *, 0x300) = 0x1098;
        }
        func_80BF8DD0(thisx);
        return;
    }
    func_800B8398(thisx, arg1, 0x447A0000);
}
