// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0054.h"

M2C_UNK func_8013F2A4(u8 *, s32);                 /* extern */
M2C_UNK func_80143E74();                            /* extern */
M2C_UNK func_80144924();                            /* extern */
M2C_UNK func_80161E44();                            /* extern */
M2C_UNK func_80174568(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801811F0(u8 *);                      /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
M2C_UNK func_808174F4(u8 *);                      /* extern */
M2C_UNK func_80817500(u8 *);                      /* extern */
extern s32 D_801E6F08;
extern M2C_UNK D_80817438;
extern M2C_UNK D_808174D0;

void DayTelop_Init(void *thisx) {
    func_80174568(thisx, 1);
    func_801811F0(thisx);
    func_80161E44();
    func_8013F2A4((u8 *)thisx + 0xB0, M2C_FIELD(thisx, s32 *, 0));
    M2C_FIELD(thisx, M2C_UNK **, 4) = &D_80817438;
    M2C_FIELD(thisx, M2C_UNK **, 8) = &D_808174D0;
    M2C_FIELD(thisx, s16 *, 0x240) = 0x8C;
    M2C_FIELD(thisx, s16 *, 0x242) = 0;
    if (D_801E6F08 < 9) {
        if (D_801E6F08 == 0) {
            func_80143E74();
        }
        func_80144924();
    }
    func_808174F4(thisx);
    func_80817500(thisx);
    func_8019FF78(0x5808);
}
