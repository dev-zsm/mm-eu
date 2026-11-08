// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct E {
    /* 0x0 */ s8 unk0;
    /* 0x1 */ u8 pad1[3];
    /* 0x4 */ f32 unk4;
} E;

f32 func_8008704C();

s8 func_80001FD0(E *arg0, s32 arg1) {
    f32 r = func_8008704C();
    s32 i = 0;
    E *p = arg0;

    arg1 -= 1;
    if (arg1 > 0) {
        do {
            if (r <= p->unk4) {
                break;
            }
            i++;
            p++;
        } while (i != arg1);
    }
    return *(s8 *)(i * 8 + (s32)arg0);
}
