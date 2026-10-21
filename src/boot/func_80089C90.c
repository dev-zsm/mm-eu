// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_80098020;
extern u8 D_8009D288[];
void func_80089C40(void);
void func_80088070(void *a, void *b, s32 c);

void func_80089C90(void) {
    s32 sp1C;

    if (D_80098020 == 0) {
        func_80089C40();
    }
    func_80088070(D_8009D288, &sp1C, 1);
}
