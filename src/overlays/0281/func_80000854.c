#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1887A]; u16 unk1887A; } S_arg1;
typedef struct { u8 pad0[0x144]; void *unk144; } S_arg0;

M2C_UNK func_8016B084();                      /* extern */
M2C_UNK func_801A6A90();                     /* extern */
M2C_UNK func_801A9868();                     /* extern */
extern s32 D_801EABA0;
extern u16 D_801EABB4;
extern M2C_UNK D_809B23E0;

void func_80000854(S_arg0 *arg0, S_arg1 *arg1) {
    func_801A6A90(0x6F);
    func_801A9868(0xE0000101);
    arg1->unk1887A = 0x54A0U;
    D_801EABB4 = arg1->unk1887A;
    func_8016B084(arg1);
    D_801EABA0 = -2;
    arg0->unk144 = &D_809B23E0;
}
