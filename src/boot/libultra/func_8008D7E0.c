// FLAGS: -O1 -g0 -mips2
#include "types.h"

typedef struct {
    s32 a;
    s32 b;
} BootEntry;

s32 __osDisableInt(void);
void __osRestoreInt(s32 a0);
void osSendMesg(s32 a0, s32 a1, s32 a2);

extern BootEntry D_8009E8E0[];
extern s32 D_8009804C;
extern s32 D_80098100;

void osSetEventMesg(s32 a0, s32 a1, s32 a2) {
    register s32 v;
    BootEntry *entry;

    v = __osDisableInt();
    entry = &D_8009E8E0[a0];
    entry->a = a1;
    entry->b = a2;
    if (a0 == 0xE) {
        if (D_8009804C != 0 && D_80098100 == 0) {
            osSendMesg(a1, a2, 0);
        }
        D_80098100 = 1;
    }
    __osRestoreInt(v);
}
