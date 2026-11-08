// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0069.h"

extern s16 D_80888768[];
extern s16 D_80888772;
extern s16 D_80888774;

void func_80005678(s32 arg0, s32 arg1, s32 arg2, s16 *arg3) {
    s16 *p = &D_80888768[arg0];

    *arg3 = *p;
    if (arg2 == 1) {
        if (p == &D_80888772) {
            *arg3 = 4;
            return;
        }
        if (p == &D_80888774) {
            *arg3 = 3;
        }
    }
}
