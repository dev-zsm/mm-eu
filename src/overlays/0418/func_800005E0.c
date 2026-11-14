// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_osn.h"

s32 func_800005E0(EnOsn* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if ((gSaveContext.save.saveInfo.inventory.items[SLOT_OCARINA] != ITEM_NONE) &&
    CHECK_QUEST_ITEM(QUEST_SONG_HEALING)) {
        if (this->stateFlags & OSN_STATE_SPECIAL_CONVERSTATION) {
            this->stateFlags |= OSN_STATE_END_CONVERSATION;
            if ((gSaveContext.save.saveInfo.inventory.items[SLOT_OCARINA] != ITEM_NONE) &&
            (INV_CONTENT(ITEM_MASK_DEKU) == ITEM_MASK_DEKU)) {
                if ((gSaveContext.save.day == 3) && (CURRENT_TIME >= CLOCK_TIME(5, 0)) &&
                (CURRENT_TIME < CLOCK_TIME(6, 0))) {
                    return 0x2006;
                }
                return 0x1FCD;
            }
            return 0x1FAF;
        }

        if (player->transformation == PLAYER_FORM_DEKU) {
            if (this->stateFlags & OSN_STATE_MET_DEKU) {
                this->stateFlags |= OSN_STATE_END_CONVERSATION;
                if ((gSaveContext.save.day == 3) && (CURRENT_TIME >= CLOCK_TIME(5, 0)) &&
                (CURRENT_TIME < CLOCK_TIME(6, 0))) {
                    return 0x2006;
                }
                return 0x1FCD;
            }
            this->stateFlags |= OSN_STATE_MET_DEKU;
            return 0x1FC8;
        }

        if (player->transformation == PLAYER_FORM_GORON) {
            if (this->stateFlags & OSN_STATE_MET_GORON) {
                this->stateFlags |= OSN_STATE_END_CONVERSATION;
                if ((gSaveContext.save.day == 3) && (CURRENT_TIME >= CLOCK_TIME(5, 0)) &&
                (CURRENT_TIME < CLOCK_TIME(6, 0))) {
                    return 0x2006;
                } else {
                    return 0x1FCD;
                }
            }
            this->stateFlags |= OSN_STATE_MET_GORON;
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_76_20)) {
                return 0x1FC8;
            } else {
                SET_WEEKEVENTREG(WEEKEVENTREG_76_20);
                return 0x1FCE;
            }
        }

        if (player->transformation == PLAYER_FORM_ZORA) {
            if (this->stateFlags & OSN_STATE_MET_ZORA) {
                this->stateFlags |= OSN_STATE_END_CONVERSATION;
                if ((gSaveContext.save.day == 3) && (CURRENT_TIME >= CLOCK_TIME(5, 0)) &&
                (CURRENT_TIME < CLOCK_TIME(6, 0))) {
                    return 0x2006;
                }
                return 0x1FCD;
            }

            this->stateFlags |= OSN_STATE_MET_ZORA;
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_76_40)) {
                return 0x1FC8;
            }
            SET_WEEKEVENTREG(WEEKEVENTREG_76_40);
            return 0x1FD0;
        }

        if (Player_GetMask(play) == PLAYER_MASK_NONE) {
            if (this->stateFlags & OSN_STATE_MET_HUMAN) {
                this->stateFlags |= OSN_STATE_END_CONVERSATION;
                if ((gSaveContext.save.day == 3) && (CURRENT_TIME >= CLOCK_TIME(5, 0)) &&
                (CURRENT_TIME < CLOCK_TIME(6, 0))) {
                    return 0x2006;
                }
                return 0x1FCD;
            }
            this->stateFlags |= OSN_STATE_MET_HUMAN;
            return 0x1FC8;
        }

        return EnOsn_GetInitialMaskText(this, play);
    }

    this->stateFlags |= OSN_STATE_END_CONVERSATION;
    if ((gSaveContext.save.day == 3) && (CURRENT_TIME >= CLOCK_TIME(5, 0)) && (CURRENT_TIME < CLOCK_TIME(6, 0))) {
        return 0x2004;
    }

    return 0x1FAE;
}
