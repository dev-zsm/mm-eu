// FLAGS: -O2 -g0
#include "types.h"
extern u8 D_8009D130;
void osCreateMesgQueue(s32 a, void *b, s32 c);
void ArenaImpl_LockInit(s32 arg0) {
    osCreateMesgQueue(arg0 + 8, &D_8009D130, 1);
}
