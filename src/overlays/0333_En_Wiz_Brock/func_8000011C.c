// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0333.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800FFBF8(u8 *, f32, f32, f32);       /* extern */
M2C_UNK func_800FFC68(u8 *, f32, f32);            /* extern */
extern u8 *D_801EB7E0;
extern f32 D_80A2E348;
extern f32 D_80A2E34C;
extern f32 D_80A2E350;
extern f32 D_80A2E354;
extern f32 D_80A2E358;
extern f32 D_80A2E35C;
extern f32 D_80A2E360;

void EnWizBrock_UpdateStatus(EnWizBrock *this, PlayState *play) {
    u8 temp_v0;

    if (M2C_FIELD(this, s16 *, 0x1AA) == 0) {
        temp_v0 = M2C_FIELD(this, u8 *, 0xB7);
        if (temp_v0 != 3) {
            M2C_FIELD(this, s16 *, 0x1AA) = (s16) temp_v0;
        }
    }
    if (M2C_FIELD(this, u8 *, 0xB7) == 0) {
        M2C_FIELD(this, s16 *, 0x1A4) = (s16) (M2C_FIELD(this, s16 *, 0x1A4) + 1);
        if ((M2C_FIELD(D_801EB7E0, s16 *, 0x1336) + 0x1E) < M2C_FIELD(this, s16 *, 0x1A4)) {
            func_800FFC68((u8 *)this + 0x5C, ((f32) M2C_FIELD(D_801EB7E0, s16 *, 0x1338) / 10.0f) + D_80A2E348, ((f32) M2C_FIELD(D_801EB7E0, s16 *, 0x133A) / D_80A2E34C) + D_80A2E350);
            func_800FFC68((u8 *)this + 0x1AC, ((f32) M2C_FIELD(D_801EB7E0, s16 *, 0x133C) / 10.0f) + 1.0f, ((f32) M2C_FIELD(D_801EB7E0, s16 *, 0x133E) / 10.0f) + 35.0f);
            func_800FFBF8((u8 *)this + 0x58, ((f32) M2C_FIELD(D_801EB7E0, s16 *, 0x1340) / 100.0f) + D_80A2E354, ((f32) M2C_FIELD(D_801EB7E0, s16 *, 0x1342) / 100.0f) + D_80A2E358, ((f32) M2C_FIELD(D_801EB7E0, s16 *, 0x1344) / 1000.0f) + D_80A2E35C);
            M2C_FIELD(this, f32 *, 0x60) = (f32) M2C_FIELD(this, f32 *, 0x58);
            if (M2C_FIELD(this, f32 *, 0x5C) < D_80A2E360) {
                func_800B6490(this);
            }
        }
    }
}
