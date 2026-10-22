// FLAGS: -O1 -g3 -mips2
#include "types.h"

typedef struct {
    s32 a;
    s32 b;
} BootEntry;

s32 func_80091C00(void);
void func_80091C70(s32 a0);
void func_80087CB0(s32 a0, s32 a1, s32 a2);

extern BootEntry D_8009E8E0[];
extern s32 D_8009804C;
extern s32 D_80098100;

void func_8008D7E0(s32 a0, s32 a1, s32 a2) {
    BootEntry *entry;
    register s32 v;

    v = func_80091C00();
    entry = &D_8009E8E0[a0];
    entry->a = a1;
    entry->b = a2;
    if (a0 == 0xE) {
        if (D_8009804C != 0 && D_80098100 == 0) {
            func_80087CB0(a1, a2, 0);
        }
        D_80098100 = 1;
    }
    func_80091C70(v);
}
