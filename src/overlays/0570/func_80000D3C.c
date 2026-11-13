#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80BB6344(u8 *, s32);                     /* extern */
M2C_UNK func_80BB6504(u8 *);                      /* extern */
M2C_UNK func_80BB6AD0(u8 *, s32);                 /* extern */
extern M2C_UNK D_80BB6B58;

void func_80000D3C(u8 *arg0, s32 arg1) {

    func_80BB6504(arg0);
    if (M2C_FIELD(arg0, s16 *, 0xBE) != M2C_FIELD(arg0, s16 *, 0x16)) {
        func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x16), 2, 0x1000, 0x200);
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    }
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x330) = &D_80BB6B58;
        func_80BB6AD0(arg0, arg1);
        return;
    }
    if (func_80BB6344(arg0, arg1) != 0) {
        func_800B8398(arg0, arg1, 0x42F00000);
    }
}
