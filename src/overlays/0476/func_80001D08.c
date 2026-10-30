#include "types.h"

extern void func_80B12B28();
extern void func_800B6490();

typedef struct { u8 pad0[0x197]; u8 unk197; } A;

void func_80001D08(A *this, s32 play) {
    func_80B12B28(this, -13);
    if (this->unk197 == 0) {
        func_800B6490(this);
    }
}
