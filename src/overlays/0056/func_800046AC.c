#include "types.h"

typedef struct {
    u8 pad0[0x748];
    void *unk748;
} S;

extern u8 D_8084A378[];
extern u8 D_8084A5E0[];

s32 func_800046AC(S *s) {
    return D_8084A378 == s->unk748 || D_8084A5E0 == s->unk748;
}
