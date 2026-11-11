#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0437.h"

M2C_UNK func_8013E578(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80AD189C;
extern M2C_UNK D_80AD4598;

void func_800006AC(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, u8 *, 0x3CC) = 0xFF;
    M2C_FIELD(arg0, f32 *, 0x2DC) = 0.0f;
    func_8013E578(arg0 + 0x144, &D_80AD4598, 0, arg0 + 0x2D4);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AD189C;
}
