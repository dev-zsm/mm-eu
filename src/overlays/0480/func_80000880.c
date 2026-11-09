#include "types.h"
typedef struct { u8 p[0x116]; u16 v; } A;
s32 func_80000880(A *this) {
    switch (this->v) {
        case 0xCE5:
            return 0xCE6;
        case 0xCE6:
            return 0xCE8;
        case 0xCE8:
            return 0xCE9;
        case 0xCE9:
            return 0xCEC;
        case 0xCEC:
            return 0xCED;
        default:
            return 0;
    }
}
