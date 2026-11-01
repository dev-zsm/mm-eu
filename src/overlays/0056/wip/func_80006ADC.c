// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad[0xBB]; u8 b; } S;
extern s32 func_80833BE4();

s32 func_80006ADC(s32 a0, S *a1) {
    if (a1->b != 1) {
        return 0;
    }
    return func_80833BE4();
}
