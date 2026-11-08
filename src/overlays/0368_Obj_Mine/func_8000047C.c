// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0368.h"

u8 *func_801812C4();                              /* extern */

void ObjMine_SetMatrixTranslation(Vec3f *translation) {
    u8 *temp_v0;

    temp_v0 = func_801812C4();
    M2C_FIELD(temp_v0, f32 *, 0x30) = (f32) M2C_FIELD(translation, f32 *, 0);
    M2C_FIELD(temp_v0, f32 *, 0x34) = (f32) M2C_FIELD(translation, f32 *, 4);
    M2C_FIELD(temp_v0, f32 *, 0x38) = (f32) M2C_FIELD(translation, f32 *, 8);
}
