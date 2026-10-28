// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 w0, w4, w8;
    u8 padC[4];
    s32 w10;
    u8 pad14[0x2C];
    s32 w40, w44;
} Obj;

typedef struct {
    u8 pad0[0x300];
    s32 f300, f304, f308, f30C;
    Obj *f310;
    Obj *f314;
} Ctx;

extern char D_801D7918[];
extern char D_801D7924[];
extern char D_801D7938[];
extern char D_801D794C[];
extern char D_801D7978[];
extern void func_8008482C(char *fmt, ...);

void func_80178258(Ctx *c, s32 unused) {
    func_8008482C(D_801D7918, c->f304, c->f30C, c->f300, c->f308);
    func_8008482C(D_801D7924, c->f304, c->f30C);
    func_8008482C(D_801D7938, c->f300, c->f308);
    if (c->f310 != NULL) {
        func_8008482C(D_801D794C, c->f310, c->f310->w0, c->f310->w4, c->f310->w8, c->f310->w10, c->f310->w40, c->f310->w44);
    }
    if (c->f314 != NULL) {
        func_8008482C(D_801D7978, c->f314, c->f314->w0, c->f314->w4, c->f314->w8);
    }
}
