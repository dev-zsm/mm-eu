// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern s32 *D_80098010;
s32 func_8008FE80(s32 *arg0) {
    if (arg0 == NULL) {
        arg0 = D_80098010;
    }
    return arg0[1];
}
