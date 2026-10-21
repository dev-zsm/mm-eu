// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_80098090;
extern u8 D_8009E7C8[];
extern void func_8008C330(void);
extern void func_80088070(void *a, void *b, s32 c);

void func_8008C380(void) {
    s32 sp1C;

    if (D_80098090 == 0) {
        func_8008C330();
    }
    func_80088070(D_8009E7C8, &sp1C, 1);
}
