#include "types.h"

typedef struct {
    u8 pad0[0x32F];
    u8 unk32F;
} Struct_801774E8;
extern s32 D_80096D00;
extern void func_80080600(s32 arg0);
extern void func_80177440(s32 arg0);
void func_801774E8(Struct_801774E8 *arg0, s32 arg1) {
    s32 *flag = &D_80096D00;
    flag += 0;
    if (arg0->unk32F != 0) {
        arg0->unk32F = 0;
        if ((*flag) == 0) {
            func_80080600(0);
        }
    }
    func_80177440(arg1);
}
