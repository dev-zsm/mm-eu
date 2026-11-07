#include "types.h"
#include "m2c_compat.h"
void func_80B47CFC(u8 *a, s32 b);
void func_80B47FEC(u8 *a);

void func_80001C84(u8 *a, s32 b) {
    M2C_FIELD(a, f32 *, 0x218) += 2.0f;
    func_80B47CFC(a, 0x14);
    if (M2C_FIELD(a, u8 *, 0x293) == 0xFF) {
        func_80B47FEC(a);
    }
}
