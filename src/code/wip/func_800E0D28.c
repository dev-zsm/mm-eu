#include "types.h"
typedef struct { u8 pad[0x18]; s32 count; u8 *arr; } Jnt;
void Collider_ResetATBase(void *);
void func_800E08A0(void *, u8 *);
s32 Collider_ResetJntSphAT(void *play, Jnt *j) {
    u8 *p;
    Collider_ResetATBase(play);
    p = j->arr;
    if (p < p + j->count * 0x40) {
        do {
            func_800E08A0(play, p);
            p += 0x40;
        } while (p < j->arr + j->count * 0x40);
    }
    return 1;
}
