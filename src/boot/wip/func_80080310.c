// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_80096D00;
extern u8 D_80098430[];
extern u8 D_8009A2C0[];
extern u8 D_8009A7C0[];
extern u8 D_8009B390[];

void func_80085390(u8 *a, u8 *b, u8 *c, s32 d, s32 e, u8 *f);
void func_800817A4(u8 *a, u8 *b, s32 c, s32 d);
void func_80080D5C(void);
void func_80080260(void);
void func_80175DB0(s32 a);
void func_80080E50(void);

void func_80080310(s32 arg0) {
    func_80085390(D_8009A7C0, D_8009A2C0, D_8009A7C0, 0, 0x100, D_80098430);
    func_800817A4(D_8009B390, D_8009A7C0, 0x12, 1);
    if (D_80096D00 == 0) {
        func_80080D5C();
        func_80080260();
        func_80175DB0(arg0);
        func_80080E50();
    }
}
