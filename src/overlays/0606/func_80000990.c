#include "types.h"
typedef struct { u8 p[0x298]; u8 v; } A;
void func_80BD6024(A *, s32);
s32 func_80000990(A *this, s32 play) {
    switch (this->v) {
        case 3:
            func_80BD6024(this, 0);
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
            func_80BD6024(this, 2);
            break;
    }
    return 1;
}
