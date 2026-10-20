// FLAGS: -O2 -g3
#include "types.h"

extern void func_8008487C(s32 a, s32 b, void *c, void *d);
extern u8 D_80098510[];
extern u8 D_80098520[];
extern u8 D_80098534[];
extern u8 D_800998A0[];
extern u8 D_800998AC[];

void func_80081880(void) {
    func_8008487C(0x50, 0xC8, D_80098510, (void *)(*(u32 *)0xA4040010));
    func_8008487C(0x28, 0xB8, D_80098520, D_800998A0);
    func_8008487C(0x38, 0xC0, D_80098534, D_800998AC);
}
