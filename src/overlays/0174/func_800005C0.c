#include "types.h"
typedef struct { u8 pad0[0x1C]; s16 params; } A;
void func_800B5B64();
void func_8093F560();
void func_800005C0(A *thisx, s32 play) {
    A *this = thisx;
    s32 t = this->params & 0x7F;
    if (t < 0x7F) {
        func_800B5B64(play, t);
    }
    func_8093F560(this);
}
