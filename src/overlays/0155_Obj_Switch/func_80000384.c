// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_FloorSwitchSnapPlayerToSwitchEdge(ObjSwitch* this, PlayState* play) {
    s32 pad;
    Player* player;
    f32 centerDisplacement;
    s16 yaw;
    f32 cos;

    if (play->actorCtx.flags & ACTORCTX_FLAG_7) {
        player = GET_PLAYER(play);
        
        yaw = BINANG_SUB(this->dyna.actor.yawTowardsPlayer, this->dyna.actor.shape.rot.y);

        
        yaw += 0x2000;
        yaw &= 0x3FFF;
        yaw -= 0x2000;

        
        
        centerDisplacement = OBJ_SWITCH_GET_TYPE(&this->dyna.actor) == OBJSWITCH_TYPE_FLOOR ? 24.0f : 48.0f;

        cos = Math_CosS(yaw);
        if (fabsf(cos) > 0.01f) {
            
            centerDisplacement /= cos;
            
            if (centerDisplacement < this->dyna.actor.xzDistToPlayer) {
                player->actor.world.pos.x =
                    Math_SinS(this->dyna.actor.yawTowardsPlayer) * centerDisplacement + this->dyna.actor.world.pos.x;
                player->actor.world.pos.z =
                    Math_CosS(this->dyna.actor.yawTowardsPlayer) * centerDisplacement + this->dyna.actor.world.pos.z;
            }
            player->speedXZ = 0.0f;
        }
    }
}
