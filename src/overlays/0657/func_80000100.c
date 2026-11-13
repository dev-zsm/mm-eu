// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Act {
    u8 pad0[0x254];
    void (*unk254)(struct Act *, void *);
} Act;

void func_800B680C(Act *);
void func_800B763C(void *, Act *, f32, f32, f32, s32);

void func_80000100(Act *this, void *play) {
    this->unk254(this, play);
    func_800B680C(this);
    func_800B763C(play, this, 20.0f, 20.0f, 50.0f, 0x1D);
}
