// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_vismono.h"

void VisMono_DesaturateTLUT(u16* tlut) {
    s32 i;

    for (i = 0; i < 256; i++) {
        
        

        
        

        
        

        

        tlut[i] = GPACK_IA16(
            (((i >> 3) & 0x1F) * VISMONO_FAC_RED + ((i << 2) & 0x1F) * VISMONO_FAC_GREEN) * 255 / VISMONO_FAC_NORM,
            (((i >> 6) & 0x1F) * VISMONO_FAC_GREEN + ((i >> 1) & 0x1F) * VISMONO_FAC_BLUE) * 255 / VISMONO_FAC_NORM);
    }
}
