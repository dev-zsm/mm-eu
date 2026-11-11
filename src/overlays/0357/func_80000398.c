#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0357.h"

f32 func_8008704C();                                /* extern */
s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6002B6C;
extern M2C_UNK D_80A4CA6C;
extern f32 D_80A4D3D4;
extern f32 D_80A4D3D8;

void func_80000398(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_6002B6C, 0x3F800000, 0, (f32) func_80134AE8(&D_6002B6C), 2, -10.0f);
    M2C_FIELD(arg0, s16 *, 0x224) = func_800FF250(1, 3);
    M2C_FIELD(arg0, f32 *, 0x23C) = (f32) D_80A4D3D4;
    if (func_8008704C() < 0.5f) {
        M2C_FIELD(arg0, f32 *, 0x23C) = (f32) D_80A4D3D8;
    }
    M2C_FIELD(arg0, s16 *, 0x21A) = 0xA;
    M2C_FIELD(arg0, s16 *, 0x21C) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x20C) = &D_80A4CA6C;
}
