// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Color_RGBA8_Copy(struct Color_RGBA8 *dst, struct Color_RGBA8 *src) {
    M2C_FIELD(dst, u8 *, 0) = (u8) M2C_FIELD(src, u8 *, 0);
    M2C_FIELD(dst, u8 *, 1) = (u8) M2C_FIELD(src, u8 *, 1);
    M2C_FIELD(dst, u8 *, 2) = (u8) M2C_FIELD(src, u8 *, 2);
    M2C_FIELD(dst, u8 *, 3) = (u8) M2C_FIELD(src, u8 *, 3);
}
