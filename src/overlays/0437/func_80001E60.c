#include "types.h"

extern s32 func_8013E684();
extern void func_80AD30A4();

typedef struct { u8 pad0[0x312]; s16 unk312; } A;

void func_80001E60(A *this, s32 play) {
    if (func_8013E684(this, this->unk312, 0x7C, 0) != 0) {
        func_80AD30A4(this, play);
    }
}
