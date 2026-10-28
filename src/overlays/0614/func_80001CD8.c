// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFBF8(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80BE3234(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80BE33FC(u8 *);                      /* extern */
extern M2C_UNK D_80BE4CF4;
extern s32 D_80BE5790;

void func_80001CD8(u8 *arg0, M2C_UNK arg1) {
    func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x2DC), 1, 0x1388, 0);
    func_800FFBF8(arg0 + 0x24, M2C_FIELD(arg0, s32 *, 0x2A4), 0x3E99999A, 0x40800000);
    func_800FFBF8(arg0 + 0x2C, M2C_FIELD(arg0, s32 *, 0x2AC), 0x3E99999A, 0x40800000);
    if (D_80BE5790 >= 0x64) {
        if (M2C_FIELD(arg0, s16 *, 0x2E4) != 4) {
            func_80BE3234(arg0, 0xF, 0x3F800000);
            M2C_FIELD(arg0, s16 *, 0x2DC) = 0;
            func_80BE33FC(arg0);
            M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_80BE4CF4;
            return;
        }
        func_800FFCBC(arg0 + 0x290, 0x2710, 1, 0x1388, 0);
        if (D_80BE5790 >= 0x67) {
            M2C_FIELD(arg0, s16 *, 0x2DC) = 0;
            func_80BE3234(arg0, 0xF, 0x3F800000);
            func_80BE33FC(arg0);
            M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_80BE4CF4;
        }
    }
}
