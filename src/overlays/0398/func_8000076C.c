#include "types.h"

extern void func_80AA62BC();
extern void func_80AA661C();

typedef struct { u8 pad0[0x270]; s16 unk270; } A;

void func_8000076C(A *this) {
    func_80AA62BC(this);
    if (this->unk270-- == 0) {
        func_80AA661C();
    }
}
