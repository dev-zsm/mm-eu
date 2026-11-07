// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808B9CE8(DoorWarp1* this, PlayState* play) {
    if (this->unk_203 != 0) {
        if (1) {}
        return;
    }

    if (!Actor_HasParent(&this->dyna.actor, play)) {
        Actor_OfferGetItem(&this->dyna.actor, play,
                           (DoorWarp1_GetRemains(this, play) - DOORWARP1_REMAINS_ODOLWA) + GI_REMAINS_ODOLWA, 30.0f,
                           80.0f);
        return;
    }

    switch (play->sceneId) {
        case SCENE_MITURIN_BS:
            gSaveContext.save.saveInfo.unk_EA8[0] = (((void)0, gSaveContext.save.saveInfo.unk_EA8[0]) & 0xFFFFFF00) |
                                                    (((u8)gSaveContext.save.saveInfo.unk_EA8[1]) & 0xFF);
            break;

        case SCENE_HAKUGIN_BS:
            gSaveContext.save.saveInfo.unk_EA8[0] = (((void)0, gSaveContext.save.saveInfo.unk_EA8[0]) & 0xFFFF00FF) |
                                                    ((((u8)gSaveContext.save.saveInfo.unk_EA8[1]) & 0xFF) << 8);
            break;

        case SCENE_INISIE_BS:
            gSaveContext.save.saveInfo.unk_EA8[0] = (((void)0, gSaveContext.save.saveInfo.unk_EA8[0]) & 0xFF00FFFF) |
                                                    ((((u8)gSaveContext.save.saveInfo.unk_EA8[1]) & 0xFF) << 0x10);
            break;

        case SCENE_SEA_BS:
            gSaveContext.save.saveInfo.unk_EA8[0] = (((void)0, gSaveContext.save.saveInfo.unk_EA8[0]) & 0x00FFFFFF) |
                                                    ((((u8)gSaveContext.save.saveInfo.unk_EA8[1]) & 0xFF) << 0x18);
            break;

        default:
            break;
    }

    gSaveContext.save.saveInfo.unk_EA8[1] = (gSaveContext.save.saveInfo.unk_EA8[1] & 0xFFFFFF00) |
                                            ((((u8)gSaveContext.save.saveInfo.unk_EA8[1]) + 1) & 0xFF);
    Item_Give(play, (DoorWarp1_GetRemains(this, play) - DOORWARP1_REMAINS_ODOLWA) + ITEM_REMAINS_ODOLWA);
    DoorWarp1_SetupAction(this, ref_func_808B9E94);
}
