// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/audio_stop_all_sfx.h"

void AudioMgr_StopAllSfxExceptSystem(void) {
    const u8* bankIdPtr;
    s32 dbgVar;

    
    dbgVar = 0;

    if (dbgVar != 2) {
        for (bankIdPtr = &sSfxBankIds[0]; bankIdPtr < (sSfxBankIds + ARRAY_COUNT(sSfxBankIds)); bankIdPtr++) {
            if ((dbgVar != 0) || (*bankIdPtr != BANK_SYSTEM)) {
                AudioSfx_StopByBank(*bankIdPtr);
            }
        }
    }
}
