// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_UpdateLightningStrike(PlayState* play) {
    if (play->envCtx.lightningState != LIGHTNING_OFF) {
        switch (gLightningStrike.state) {
            case LIGHTNING_STRIKE_WAIT:
                
                if (Rand_ZeroOne() < 0.1f) {
                    gLightningStrike.delayTimer += 10.0f;
                }

                gLightningStrike.delayTimer += Rand_ZeroOne();

                if (gLightningStrike.delayTimer > 500.0f) {
                    gLightningStrike.flashRed = 200;
                    gLightningStrike.flashGreen = 200;
                    gLightningStrike.flashBlue = 255;
                    gLightningStrike.flashAlphaTarget = 200;

                    gLightningStrike.delayTimer = 0.0f;
                    Environment_AddLightningBolts(
                        play, (u8)((Rand_ZeroOne() * (ARRAY_COUNT(sLightningBolts) - 0.1f)) + 1.0f));
                    sLightningFlashAlpha = 0;
                    gLightningStrike.state++;
                }
                break;

            case LIGHTNING_STRIKE_START:
                gLightningStrike.flashRed = 200;
                gLightningStrike.flashGreen = 200;
                gLightningStrike.flashBlue = 255;

                play->envCtx.adjLightSettings.ambientColor[0] += 80;
                play->envCtx.adjLightSettings.ambientColor[1] += 80;
                play->envCtx.adjLightSettings.ambientColor[2] += 100;

                sLightningFlashAlpha += 100;

                if (sLightningFlashAlpha >= gLightningStrike.flashAlphaTarget) {
                    Audio_SetAmbienceChannelIO(AMBIENCE_CHANNEL_LIGHTNING, CHANNEL_IO_PORT_0, 0);
                    gLightningStrike.state++;
                    gLightningStrike.flashAlphaTarget = 0;
                }
                break;

            case LIGHTNING_STRIKE_END:
                if (play->envCtx.adjLightSettings.ambientColor[0] > 0) {
                    play->envCtx.adjLightSettings.ambientColor[0] -= 10;
                    play->envCtx.adjLightSettings.ambientColor[1] -= 10;
                }

                if (play->envCtx.adjLightSettings.ambientColor[2] > 0) {
                    play->envCtx.adjLightSettings.ambientColor[2] -= 10;
                }

                sLightningFlashAlpha -= 10;

                if (sLightningFlashAlpha <= gLightningStrike.flashAlphaTarget) {
                    play->envCtx.adjLightSettings.ambientColor[0] = 0;
                    play->envCtx.adjLightSettings.ambientColor[1] = 0;
                    play->envCtx.adjLightSettings.ambientColor[2] = 0;

                    gLightningStrike.state = LIGHTNING_STRIKE_WAIT;

                    if (play->envCtx.lightningState == LIGHTNING_LAST) {
                        play->envCtx.lightningState = LIGHTNING_OFF;
                    }
                }
                break;

            default:
                break;
        }
    }

    if (gLightningStrike.state != LIGHTNING_STRIKE_WAIT) {
        Environment_DrawLightningFlash(play, gLightningStrike.flashRed, gLightningStrike.flashGreen,
                                       gLightningStrike.flashBlue, sLightningFlashAlpha);
    }
}
