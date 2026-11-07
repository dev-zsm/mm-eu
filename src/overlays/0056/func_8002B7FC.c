#include "types.h"
typedef struct { u8 pad0[0x138]; s32 a138; } Q;
typedef struct { u8 pad0[0xBE]; s16 aBE; u8 pad1[0x2D8]; Q* a398; u8 pad2[0x394]; Q* a730; } A;
s16 func_8083BD04();
void func_8002B7FC(A *this) {
    Q *t = this->a398;
    if (t == NULL || t->a138 == 0) {
        this->a398 = NULL;
        t = NULL;
    }
    this->a730 = t;
    if (t != NULL) {
        this->aBE = func_8083BD04(this, 0);
    }
}
