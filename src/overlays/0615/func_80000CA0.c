#include "types.h"

typedef struct {
    u8 pad0[0x284];
    void *unk284;
    u8 pad288[0x42];
    s16 unk2CA;
} Ovl0615Actor;

extern void func_80BE6080();
extern u8 D_80BE6914[];

void func_80000CA0(Ovl0615Actor *a) {
    func_80BE6080(a);
    a->unk2CA = 0;
    a->unk284 = D_80BE6914;
}
