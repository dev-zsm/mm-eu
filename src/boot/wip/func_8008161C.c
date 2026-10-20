// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Obj {
    u8 pad0[0x278];
    u64 unk278;
} Obj;

extern u64 D_80096D10[1];
extern s32 D_80096D18[1];
extern u64 func_800905C0(void);
extern void func_800813B8(Obj *a, Obj *b);

void func_8008161C(Obj *arg0) {
    u64 t;

    if (D_80096D10[0] == 0) {
        if (arg0->unk278 == 0) {
            arg0->unk278 = func_800905C0();
        } else {
            t = func_800905C0();
            D_80096D10[0] = t - arg0->unk278;
        }
    }
    D_80096D18[0] += 1;
    func_800813B8(arg0, arg0);
}
