// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skin.h"

void Skin_UpdateVertices(MtxF* mtx, SkinVertex* skinVertices, SkinLimbModif* modifEntry, Vtx* vtxBuf, Vec3f* pos) {
    SkinVertex* vertexEntry;
    Vtx* vtx;
    Vec3f wTemp;
    Vec3f normal;
    Vec3f sp44;

    wTemp.x = mtx->xw;
    wTemp.y = mtx->yw;
    wTemp.z = mtx->zw;

    mtx->xw = 0.0f;
    mtx->yw = 0.0f;
    mtx->zw = 0.0f;

    for (vertexEntry = skinVertices; vertexEntry < &skinVertices[modifEntry->vtxCount]; vertexEntry++) {
        vtx = &vtxBuf[vertexEntry->index];

        vtx->n.ob[0] = pos->x;
        vtx->n.ob[1] = pos->y;
        vtx->n.ob[2] = pos->z;

        sp44.x = vertexEntry->normX;
        sp44.y = vertexEntry->normY;
        sp44.z = vertexEntry->normZ;

        SkinMatrix_Vec3fMtxFMultXYZ(mtx, &sp44, &normal);

        vtx->n.n[0] = normal.x;
        vtx->n.n[1] = normal.y;
        vtx->n.n[2] = normal.z;
    }

    mtx->xw = wTemp.x;
    mtx->yw = wTemp.y;
    mtx->zw = wTemp.z;
}
