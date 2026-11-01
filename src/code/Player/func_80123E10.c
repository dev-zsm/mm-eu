#include "types.h"
#include "code_funcs.h"

extern u8 D_801C0BFC[];

s32 Player_ActionToModelGroup(void *a0, s32 action) {
    s32 group = D_801C0BFC[action];

    if (group == 2) {
        if (Player_IsGoronOrDeku(a0) != 0) {
            return 1;
        }
    }
    return group;
}
