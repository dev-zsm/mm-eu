// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0613.h"

M2C_UNK func_8011489C(M2C_UNK, u8);                 /* extern */
extern u8 D_801C2D61;
extern u8 D_801C2D62;
extern u8 D_801C2D63;
extern u8 D_801C2D64;
extern u8 D_801C2D66;
extern u8 D_801C2D67;

s32 func_80000154(s32 arg0) {
    switch (arg0) {
    case 0x2D:
        func_8011489C(0x2F, D_801C2D67);
        break;
    case 0x2F:
        func_8011489C(0x2A, D_801C2D62);
        break;
    case 0x30:
        func_8011489C(0x2B, D_801C2D63);
        break;
    case 0x31:
        func_8011489C(0x2C, D_801C2D64);
        break;
    case 0x2B:
        func_8011489C(0x29, D_801C2D61);
        break;
    case 0x33:
        func_8011489C(0x2E, D_801C2D66);
        break;
    }
    return 0;
}
