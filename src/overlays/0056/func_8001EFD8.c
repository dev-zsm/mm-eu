#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

M2C_UNK func_800FFCBC(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80136480(M2C_UNK, u8 *);                 /* extern */
s16 func_80181190(f32, f32);                        /* extern */
M2C_UNK func_8082D210(M2C_UNK, u8 *, M2C_UNK *);  /* extern */
M2C_UNK func_8082E814(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808331C8(M2C_UNK, u8 *, M2C_UNK, M2C_UNK, f32, s32, s32); /* extern */
M2C_UNK func_808361EC(M2C_UNK, u8 *, M2C_UNK);    /* extern */
s32 func_80840124(M2C_UNK, u8 *, u8 *, f32); /* extern */
extern M2C_UNK D_400E3D8;

void func_8001EFD8(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s32 *, 0xA70) = (s32) (M2C_FIELD(arg0, s32 *, 0xA70) | 0x20);
    if (func_80136480(arg1, arg0 + 0x240) != 0) {
        func_8082D210(arg1, arg0, &D_400E3D8);
    }
    func_800FFCBC(arg0 + 0xB88, 0, 6, 0x7D0, 0x190);
    if (func_80840124(arg1, arg0, arg0 + 0xAD0, 0) == 0) {
        if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
            if (M2C_FIELD(arg0, s16 *, 0xAAA) >= 0x36B1) {
                M2C_FIELD(arg0, s8 *, 0xB8) = 0x10;
                func_808331C8(arg1, arg0, 1, 0x40800000, 5.0f, (s32) M2C_FIELD(arg0, s16 *, 0xBE), 0x14);
                return;
            }
            func_808361EC(arg1, arg0, 0x40800000);
            return;
        }
        M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
        M2C_FIELD(arg0, s16 *, 0xAAA) = func_80181190(M2C_FIELD(arg0, f32 *, 0x70), -M2C_FIELD(arg0, f32 *, 0x68));
        func_8082E814(arg0, 0x10);
    }
}
