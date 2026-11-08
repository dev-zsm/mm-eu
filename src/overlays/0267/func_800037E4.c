// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0267.h"

void func_800B6490();
extern u8 *D_809A3D00;
extern u8 *D_809A3D04;
extern u8 *D_809A3D08;

void func_800037E4(u8 *arg0, s32 arg1) {
    if (arg0 == D_809A3D00 && M2C_FIELD(arg0, s16 *, 0x14A) == 0) {
        func_800B6490(arg0);
        func_800B6490(D_809A3D04);
        func_800B6490(D_809A3D08);
    }
}
