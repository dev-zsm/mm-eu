// FLAGS: -O1 -g3 -mips2
#include "types.h"

extern u8 D_80096CC4;
extern s32 D_80096D00;
extern void func_8008B010(s32 a);
extern void func_80095AA0(f32 a);

// Pushes the D_80096CC4 flag to func_8008B010 (1 or 0). If D_80096D00 is mode 2,
// also calls func_80095AA0(1.0f). Mode and flag meanings are not known.
void func_80080778(void) {
    if (*(u8 *)&D_80096CC4 != 0) {
        func_8008B010(1);
    } else {
        func_8008B010(0);
    }
    if (*(s32 *)&D_80096D00 == 2) {
        func_80095AA0(1.0f);
    }
}
