#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0481.h"
void func_80B1CBF0(void);
void func_800B6730(u8 *a);

void func_800008D0(u8 *a) {
    M2C_FIELD(a, s16 *, 0x218) += M2C_FIELD(a, s16 *, 0x21A);
    M2C_FIELD(a, f32 *, 0x68) += M2C_FIELD(a, f32 *, 0x74);
    func_80B1CBF0();
    func_800B6730(a);
}
