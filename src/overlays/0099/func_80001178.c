#include "types.h"
#include "generated/overlays/0099.h"
void func_800FEE3C(u8 *, f32, f32);
s32 func_80137070();
void func_808BDB64();
void func_80001178(u8 *this, s32 play) {
    func_800FEE3C(this + 0x70, 0, 1.0f);
    if (func_80137070(this + 0x144) != 0) {
        func_808BDB64(this);
    }
}
