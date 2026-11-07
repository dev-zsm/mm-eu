// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_wood02.h"

void EnWood02_SpawnOffspring(EnWood02* this, PlayState* play) {
    EnWood02* child;
    s32 extraRot;
    Vec3f childPos;
    s32 unk;
    s32 i;
    s16 childParams;

    for (i = 4; i >= 0; i--) {
        extraRot = 0;
        if (!(this->unk_14A[i] & 0x7F)) {
            if (this->actor.params == WOOD_BUSH_GREEN_LARGE_SPAWNER) {
                extraRot = 0x4000;
            }

            sWood02SpawnCos = Math_CosS(sWood02SpawnAngle[i] + this->actor.world.rot.y + extraRot);
            sWood02SpawnSin = Math_SinS(sWood02SpawnAngle[i] + this->actor.world.rot.y + extraRot);

            childPos.x = (sWood02SpawnDistance[i] * sWood02SpawnSin) + this->actor.home.pos.x;
            childPos.y = this->actor.home.pos.y;
            childPos.z = (sWood02SpawnDistance[i] * sWood02SpawnCos) + this->actor.home.pos.z;

            if (EnWood02_SpawnZoneCheck(this, play, &childPos)) {
                if (this->unk_14A[i] & 0x80) {
                    unk = 0;
                } else {
                    unk = this->actor.home.rot.z;
                }

                childParams = ((this->unk_144 << 8) & 0xFF00) | (this->actor.params + 1);
                child = (EnWood02*)Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_EN_WOOD02, childPos.x,
                                                      childPos.y, childPos.z, this->actor.world.rot.x,
                                                      sWood02SpawnAngle[i], unk, childParams);
                if (child != NULL) {
                    child->unk_14A[0] = i;
                    this->unk_14A[i] |= 1;
                    child->actor.projectedPos = this->actor.projectedPos;
                } else {
                    this->unk_14A[i] &= 0x80;
                }
            }
        }
    }
}
