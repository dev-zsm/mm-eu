// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

typedef struct {
    u8 pad0[0xF4];
    s32 unkF4;
    u8 pad1[0x104 - 0xF8];
    s32 unk104;
    u8 pad2[0x11C - 0x108];
    s32 unk11C;
} Obj800831A4;

extern void func_80082138(void);
extern void func_8008487C(s32 a0, s32 a1, void *a2, ...);
extern s32 func_80081DFC(s32 a0);
extern void func_8008482C(void *a0, ...);
extern void func_80083030(void *a0, void *a1, void *a2);
extern u8 D_80098C10[];
extern u8 D_80098C1C[];
extern u8 D_80098C34[];
extern u8 D_80098C40[];
extern u8 D_80098C4C[];
extern u8 D_800895C0[];

s32 func_800831A4(Obj800831A4 *arg0, s32 arg1) {
    s32 ret;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 s0;
    s32 s3;

    ret = 1;
    sp68 = arg0->unkF4;
    sp64 = arg0->unk104;
    sp60 = arg0->unk11C;
    func_80082138();
    func_8008487C(0x78, 0x10, D_80098C10);
    func_8008487C(0x24, 0x18, D_80098C1C);
    if (sp64 == 0 && sp68 == 0) {
        return ret;
    }
    if (sp60 == (s32)D_800895C0) {
        return ret;
    }
    s3 = arg1 & 1;
    s0 = (ret << 3) + 0x18;
    do {
        func_8008487C(0x24, s0, D_80098C34, sp68, sp60);
        if (s3 != 0) {
            s32 v = func_80081DFC(sp60);
            if (v != 0) {
                func_8008482C(D_80098C40, v);
            }
        } else {
            func_8008482C(D_80098C4C);
        }
        func_80083030(&sp68, &sp60, &sp64);
        s0 += 8;
        if (s0 >= 0xC8) {
            break;
        }
        if (sp64 == 0 && sp68 == 0) {
            break;
        }
    } while (sp60 != (s32)D_800895C0);
}
