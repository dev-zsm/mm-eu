#include "types.h"
extern s32 func_80B287CC();
extern void func_80B287A4();
s32 func_80000100(void) {
    s32 v = func_80B287CC();
    if (v < 12) {
        v++;
        func_80B287A4(v);
    }
    return v;
}
