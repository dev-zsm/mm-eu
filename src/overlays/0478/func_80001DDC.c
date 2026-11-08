// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x1EC];
    /* 0x1EC */ u8 unk1EC;
} Ea;

s32 func_80001DDC(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4, Ea *arg5) {
    switch (arg5->unk1EC) {
        case 1:
            if (arg1 != 1 && arg1 != 3 && arg1 != 4) {
                *arg2 = 0;
            }
            break;
        case 2:
            if (arg1 != 1 && arg1 != 3) {
                *arg2 = 0;
            }
            break;
    }
    return 0;
}
