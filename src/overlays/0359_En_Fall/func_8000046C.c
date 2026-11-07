// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_Setup(EnFall* this, PlayState* play) {
    Actor* moon;

    if (Object_IsLoaded(&play->objectCtx, this->objectSlot)) {
        this->actor.objectSlot = this->objectSlot;
        this->actionFunc = EnFall_Moon_PerformDefaultActions;
        switch (EN_FALL_TYPE(&this->actor)) {
            case EN_FALL_TYPE_TITLE_SCREEN_MOON:
                this->actor.draw = EnFall_Moon_Draw;
                this->actionFunc = EnFall_ClockTowerOrTitleScreenMoon_PerformCutsceneActions;
                Actor_SetScale(&this->actor, this->scale);
                break;

            case EN_FALL_TYPE_STOPPED_MOON_CLOSED_MOUTH:
                this->actor.draw = EnFall_Moon_Draw;
                this->actionFunc = EnFall_StoppedClosedMouthMoon_PerformCutsceneActions;
                Actor_SetScale(&this->actor, this->scale * 3.0f);
                if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_25_02)) {
                    Actor_Kill(&this->actor);
                }
                break;

            case EN_FALL_TYPE_CLOCK_TOWER_MOON:
                this->actionFunc = EnFall_ClockTowerOrTitleScreenMoon_PerformCutsceneActions;
                Actor_SetScale(&this->actor, this->scale * 3.0f);
                this->actor.draw = EnFall_Moon_Draw;
                if (CHECK_WEEKEVENTREG(WEEKEVENTREG_25_02)) {
                    Actor_Kill(&this->actor);
                }
                break;

            case EN_FALL_TYPE_CRASHING_MOON:
                this->actor.draw = EnFall_Moon_Draw;
                Actor_SetScale(&this->actor, this->scale * 5.3999996f);
                this->actionFunc = EnFall_CrashingMoon_PerformCutsceneActions;
                break;

            case EN_FALL_TYPE_CRASH_FIRE_BALL:
                this->actor.update = EnFall_Fireball_Update;
                this->actor.draw = EnFall_Fireball_Draw;
                this->scale = 1.0f;
                this->actor.shape.rot.z = 0;
                this->fireballIntensity = 0.0f;
                this->fireballAlpha = 100;
                this->actor.shape.rot.x = this->actor.shape.rot.z;
                break;

            case EN_FALL_TYPE_CRASH_RISING_DEBRIS:
                this->actor.update = EnFall_RisingDebris_Update;
                this->actor.draw = EnFall_RisingDebris_Draw;
                this->scale = 1.0f;
                EnFall_RisingDebris_ResetEffects(this);
                Actor_SetScale(&this->actor, 1.0f);
                this->actor.shape.rot.x = 0;
                break;

            case EN_FALL_TYPE_LODMOON_NO_LERP:
                this->actor.draw = EnFall_LodMoon_DrawWithoutLerp;
                this->dayStartTime = CLOCK_TIME(6, 0);
                this->currentDay = CURRENT_DAY;
                EnFall_Moon_AdjustScaleAndPosition(this, play);
                break;

            case EN_FALL_TYPE_LODMOON:
            case EN_FALL_TYPE_LODMOON_INVERTED_STONE_TOWER:
                this->actor.draw = EnFall_LodMoon_DrawWithLerp;
                this->dayStartTime = CLOCK_TIME(6, 0);
                this->currentDay = CURRENT_DAY;
                EnFall_Moon_AdjustScaleAndPosition(this, play);
                break;

            case EN_FALL_TYPE_MOONS_TEAR:
                this->actor.update = EnFall_Update;
                this->actor.draw = NULL;
                this->actionFunc = EnFall_MoonsTear_Fall;
                Actor_SetScale(&this->actor, 0.02f);
                if (!(play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON)) {
                    Actor_Kill(&this->actor);
                }
                moon = EnFall_MoonsTear_GetTerminaFieldMoon(play);
                this->actor.child = moon;
                if (moon == NULL) {
                    Actor_Kill(&this->actor);
                }
                break;

            case EN_FALL_TYPE_STOPPED_MOON_OPEN_MOUTH:
                this->actor.draw = NULL;
                this->actionFunc = EnFall_StoppedOpenMouthMoon_PerformCutsceneActions;
                Actor_SetScale(&this->actor, this->scale * 3.0f);
                break;

            case EN_FALL_TYPE_CRASH_FIRE_RING:
                this->actor.update = EnFall_FireRing_Update;
                this->actor.draw = EnFall_FireRing_Draw;
                Actor_SetScale(&this->actor, 0.2f);
                break;

            default:
                
                this->actor.draw = EnFall_Moon_Draw;
                this->dayStartTime = CLOCK_TIME(6, 0);
                this->currentDay = CURRENT_DAY;
                EnFall_Moon_AdjustScaleAndPosition(this, play);
                break;
        }
    }
}
