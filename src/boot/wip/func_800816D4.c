// FLAGS: -O2 -g3
#include "types.h"

typedef struct {
    u8 pad0[0x60];
    u8 unk60[0x18];
} Obj;

extern void func_80088070(void *a, s32 *b, s32 c);
extern void func_8008161C(Obj *this);
extern void func_8008146C(Obj *this);
extern void func_80081524(Obj *this);
extern void func_800815A0(Obj *this);
extern void func_800815F8(Obj *this);

void func_800816D4(Obj *this) {
    s32 cmd;
    u8 *p;
    s32 done;

    cmd = 0;
    p = this->unk60;
    done = 0;
    while (done == 0) {
        func_80088070(p, &cmd, 1);
        switch (cmd) {
        case 0x29A:
            func_8008161C(this);
            break;
        case 0x29D:
            func_8008146C(this);
            break;
        case 0x29F:
            func_80081524(this);
            break;
        case 0x2A0:
            func_800815A0(this);
            break;
        case 0x2A1:
            func_800815F8(this);
            break;
        }
    }
}
