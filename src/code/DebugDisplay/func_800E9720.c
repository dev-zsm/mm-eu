// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_debug_display.h"

Gfx* DebugDisplay_PathDisplayList(GraphicsContext* gfxCtx, Path* path) {
    Gfx* gfxHead;
    Gfx* gfx;
    Vtx* curVtx;
    Vtx* curBaseVtx;  
    Vtx* prevBaseVtx; 
    Vec3s* curPoint;
    s32 segment; 

    if (path != NULL) {
        
        gfx = GRAPH_ALLOC(gfxCtx, ((path->count - 1) * 4 + 1) * sizeof(Gfx));
        curVtx = GRAPH_ALLOC(gfxCtx, path->count * 6 * sizeof(Vtx));

        gfxHead = gfx;
        curBaseVtx = curVtx;
        curPoint = Lib_SegmentedToVirtual(path->points);

        for (segment = 0; segment < path->count; segment++, curPoint++) {
            s32 i;
            s32 j;

            prevBaseVtx = curBaseVtx;
            curBaseVtx = curVtx;

            
            for (i = 0; i < ARRAY_COUNT(sDebugPathVtxOffsets); i++) {
                for (j = 0; j < ARRAY_COUNT(sDebugPathVtxOffsets[0]); j++) {
                    curVtx->v.ob[0] = curPoint->x + (s32)(sDebugPathVtxOffsets[i][j].x * R_DRAW_PATH_SCALE);
                    curVtx->v.ob[1] = curPoint->y + (s32)(sDebugPathVtxOffsets[i][j].y * R_DRAW_PATH_SCALE);
                    curVtx->v.ob[2] = curPoint->z + (s32)(sDebugPathVtxOffsets[i][j].z * R_DRAW_PATH_SCALE);
                    curVtx->v.flag = 0;
                    curVtx->v.tc[0] = 0;
                    curVtx->v.tc[1] = 0;
                    curVtx->v.cn[0] = 128 + R_DRAW_PATH_RED;
                    curVtx->v.cn[1] = 128 + R_DRAW_PATH_GREEN;
                    curVtx->v.cn[2] = 128 + R_DRAW_PATH_BLUE;
                    curVtx->v.cn[3] = 128 + R_DRAW_PATH_ALPHA;
                    curVtx++;
                }
            }

            
            
            if (R_DRAW_PATH_SEGMENT == 0) {
                if (segment > 0) {
                    gSPVertex(gfx++, prevBaseVtx, 12, 0);
                    gSP2Triangles(gfx++, 0, 7, 1, 0, 0, 6, 7, 0);
                    gSP2Triangles(gfx++, 2, 3, 8, 0, 3, 9, 8, 0);
                    gSP2Triangles(gfx++, 4, 11, 10, 0, 4, 5, 11, 0);
                }
            } else {
                if ((segment > 0) && (segment == R_DRAW_PATH_SEGMENT)) {
                    gSPVertex(gfx++, prevBaseVtx, 12, 0);
                    gSP2Triangles(gfx++, 0, 7, 1, 0, 0, 6, 7, 0);
                    gSP2Triangles(gfx++, 2, 3, 8, 0, 3, 9, 8, 0);
                    gSP2Triangles(gfx++, 4, 11, 10, 0, 4, 5, 11, 0);
                }
            }
        }

        gSPEndDisplayList(gfx++);
    } else {
        
        gfx = gfxHead = GRAPH_ALLOC(gfxCtx, sizeof(Gfx));
        gSPEndDisplayList(gfx++);
    }
    return gfxHead;
}
