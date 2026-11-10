#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1681C]; s32 unk1681C; u8 pad16820[0x116]; u16 unk16936; } S_arg1;
typedef struct { u8 pad0[0x304]; s16 unk304; u8 pad306[0xE]; void *unk314; } S_arg0;

s32 func_801529DC(u8 *);                          /* extern */
M2C_UNK func_80B84584(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80B8460C(u8 *);                      /* extern */
M2C_UNK func_80B84A10(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80B84B7C;
extern M2C_UNK D_80B84BBC;

void func_800008EC(S_arg0 *arg0, S_arg1 *arg1) {
    func_80B8460C(arg0);
    if (arg1->unk16936 == 3) {
        arg1->unk1681C = 0;
        arg0->unk314 = &D_80B84B7C;
        func_80B84A10(arg0, 0);
        return;
    }
    if (func_801529DC((u8 *)arg1 + 0x4908) == 0xB) {
        arg1->unk1681C = 0;
        arg0->unk314 = &D_80B84BBC;
        arg0->unk304 = 3;
        func_80B84584(arg0, 5, 2);
        func_80B84A10(arg0, 0);
    }
}
