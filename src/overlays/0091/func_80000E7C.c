#include "types.h"
void func_800FEE3C(u8 *, f32, f32);
s32 func_80137070();
void func_808AFA38();
void func_80000E7C(u8 *this, s32 play) {
    func_800FEE3C(this + 0x70, 0, 0.5f);
    if (func_80137070(this + 0x144) != 0) {
        func_808AFA38(this);
    }
}
