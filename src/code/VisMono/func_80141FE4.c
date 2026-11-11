// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_vismono.h"

Gfx* VisMono_DesaturateDList(Gfx* gfx) {
    s32 y;
    s32 height = VISMONO_CFBFRAG_HEIGHT;
    u16* cfbFrag = ref_D_0F000000;

    gDPPipeSync(gfx++);
    
    gDPSetOtherMode(gfx++,
                    G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_POINT | G_TT_IA16 | G_TL_TILE |
                        G_TD_CLAMP | G_TP_NONE | G_CYC_2CYCLE | G_PM_1PRIMITIVE,
                    G_AC_NONE | G_ZS_PRIM | GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1) | G_RM_CLD_SURF2);
    
    
    
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL1_ALPHA, TEXEL0, 0, 0, 0, 1, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0,
                      0, 0, PRIMITIVE);

    for (y = 0; y <= SCREEN_HEIGHT - height; y += height) {
        
        gDPLoadTextureBlock(gfx++, cfbFrag, G_IM_FMT_CI, G_IM_SIZ_8b, SCREEN_WIDTH * 2, height, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        
        
        gDPSetTile(gfx++, G_IM_FMT_CI, G_IM_SIZ_8b, SCREEN_WIDTH * 2 * G_IM_SIZ_8b_LINE_BYTES / 8, 0x0, G_TX_RENDERTILE,
                   0, G_TX_NOMIRROR | G_TX_CLAMP, 0, 0, G_TX_NOMIRROR | G_TX_CLAMP, 0, 0);
        gDPSetTileSize(gfx++, G_TX_RENDERTILE, 2 << 2, 0, (SCREEN_WIDTH * 2 + 1) << 2,
                       (VISMONO_CFBFRAG_HEIGHT - 1) << 2);

        
        
        
        
        gDPSetTile(gfx++, G_IM_FMT_CI, G_IM_SIZ_8b, SCREEN_WIDTH * 2 * G_IM_SIZ_8b_LINE_BYTES / 8, 0x0, 1, 1,
                   G_TX_NOMIRROR | G_TX_CLAMP, 0, 0, G_TX_NOMIRROR | G_TX_CLAMP, 0, 0);
        gDPSetTileSize(gfx++, 1, 1 << 2, 0, (SCREEN_WIDTH * 2) << 2, (VISMONO_CFBFRAG_HEIGHT - 1) << 2);

        
        
        

        
        
        

        
        

        
        
        
        
        

        
        

        gSPTextureRectangle(gfx++, 0, y << 2, SCREEN_WIDTH << 2, (y + height) << 2, G_TX_RENDERTILE, 2 << 5, 0, 2 << 10,
                            1 << 10);
        cfbFrag += SCREEN_WIDTH * height;
    }

    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
    return gfx;
}
