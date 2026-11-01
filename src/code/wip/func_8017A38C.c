#include "types.h"
extern u8 D_1000000[];
extern u8 D_1003400[];
extern u8 D_201A000[];
extern u8 D_801C9E80[][2];
void func_80080CE0(void *dst, void *src, u32 size);
void func_8017A310(void *a);
void func_8017A220(void *a, s32 b, s32 c, s32 d, s32 e, void *f);
void func_80095760(void);
void func_80090000(void *a);
void func_8008B010(s32 a);
void func_8017A38C(void) {
    u8 *buf = (u8 *)0x803DA800;
    u32 p;
    u8 (*q)[2];
    func_80080CE0((void *)0x803D7400, D_201A000, D_1003400 - D_1000000);
    func_8017A310(buf);
    q = D_801C9E80;
    for (p = 0x803D7400; p != 0x803DA800; p += 0x680) {
        func_8017A220(buf, q[0][0], q[0][1], 0x80, 0x1A, (void *)p);
        q++;
    }
    func_80095760();
    func_80090000(buf);
    func_8008B010(0);
}
