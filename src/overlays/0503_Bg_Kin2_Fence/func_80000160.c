#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0503.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800E090C(s32, u8 *);                 /* extern */
M2C_UNK func_800E0C20(s32, u8 *, u8 *, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_800E7D4C(s32, u8 *);                 /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_8018142C(f32, f32, s32, M2C_UNK);      /* extern */
M2C_UNK func_801826E0(f32, f32, s32, u8 *);       /* extern */
M2C_UNK func_80B5380C(u8 *);                      /* extern */
M2C_UNK func_80B53A60(u8 *);                      /* extern */
extern M2C_UNK D_6000908;
extern M2C_UNK D_80B53BA0;
extern M2C_UNK D_80B53C18;

void func_80000160(Actor *thisx, PlayState *play) {
    u8 *this = thisx;
    s32 var_s0;
    u8 *temp_s3;

    func_800FF8DC(this, &D_80B53C18);
    func_800CABA0(this, 0);
    func_800CABC4(play, this, &D_6000908);
    temp_s3 = this + 0x15C;
    func_800E090C(play, temp_s3);
    func_800E0C20(play, temp_s3, thisx, &D_80B53BA0, (u8 *)thisx + 0x17C);
    func_801826E0(M2C_FIELD(thisx, f32 *, 0x24), M2C_FIELD(thisx, f32 *, 0x28), M2C_FIELD(thisx, s32 *, 0x2C), (u8 *)thisx + 0xBC);
    func_8018142C(M2C_FIELD(thisx, f32 *, 0x58), M2C_FIELD(thisx, f32 *, 0x5C), M2C_FIELD(thisx, s32 *, 0x60), 1);
    var_s0 = 0;
    do {
        func_800E7D4C(var_s0, temp_s3);
        var_s0 += 1;
    } while (var_s0 != 4);
    if (func_800B5B20(play, M2C_FIELD(thisx, s16 *, 0x1C) & 0x7F) != 0) {
        func_80B53A60(thisx);
        return;
    }
    func_80B5380C(thisx);
}
