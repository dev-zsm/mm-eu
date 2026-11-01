#include "types.h"
extern u8 D_1000000[];
extern u8 D_1001A00[];
extern u8 D_201E000[];
extern u8 D_801C9E90[];
extern void func_80080CE0(void *, u8 *, s32);
extern void func_8017A310(s32);
extern void func_8017A220(s32, s32, u8, s32, s32, s32);
extern void func_80095760(void);
extern void func_80090000(s32);
extern void func_8008B010(s32);
void func_8017A454(void) {
    s32 p;
    s32 i;
    func_80080CE0((void *)0x803D8E00, D_201E000, D_1001A00 - D_1000000);
    func_8017A310(0x803DA800);
    i = 0;
    p = 0x803D8E00;
    do {
        func_8017A220(0x803DA800, 0x38, D_801C9E90[i], 0xD0, 0x10, p);
        p += 0x680;
        i++;
    } while (p != 0x803DA800);
    func_80095760();
    func_80090000(0x803DA800);
    func_8008B010(0);
}
