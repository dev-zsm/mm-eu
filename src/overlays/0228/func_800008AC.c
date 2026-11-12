#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x30]; s16 unk30; u8 pad32[0x36]; f32 unk68; u8 pad6C[0x24]; u16 unk90; u8 pad92[0x2A]; s16 unkBC; u8 padBE[0x8E]; s16 unk14C; u8 pad14E[0x24]; u8 unk172; } S_arg0;

M2C_UNK func_80968878();                            /* extern */
M2C_UNK func_8096923C();                      /* extern */

void func_800008AC(S_arg0 *arg0, M2C_UNK arg1) {
    arg0->unkBC = (s16) (arg0->unkBC + arg0->unk30);
    if (arg0->unk68 < 0.0f) {
        arg0->unk172 = (u8) (arg0->unk172 | 1);
        if (arg0->unk90 & 1) {
            func_80968878();
            arg0->unk14C = 0x28;
            func_8096923C(arg0);
        }
    }
}
