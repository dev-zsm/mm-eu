// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_LineVsCube(Vec3f* min, Vec3f* max, Vec3f* a, Vec3f* b) {
    static Vec3f sTriVtx0;
    static Vec3f sTriVtx1;
    static Vec3f sTriVtx2;
    static Vec3f sIntersectPoint;
    s32 flags[2];

    flags[0] = flags[1] = 0;
    flags[0] = Math3D_PointRelativeToCubeFaces(a, min, max);
    if (!flags[0]) {
        return true;
    }

    flags[1] = Math3D_PointRelativeToCubeFaces(b, min, max);
    if (!flags[1]) {
        return true;
    }

    if (flags[0] & flags[1]) {
        return false;
    }

    flags[0] |= (Math3D_PointRelativeToCubeEdges(a, min, max) << 8);
    flags[1] |= (Math3D_PointRelativeToCubeEdges(b, min, max) << 8);
    if (flags[0] & flags[1]) {
        return false;
    }

    flags[0] |= (Math3D_PointRelativeToCubeVertices(a, min, max) << 0x18);
    flags[1] |= (Math3D_PointRelativeToCubeVertices(b, min, max) << 0x18);
    if (flags[0] & flags[1]) {
        return false;
    }

    
    sTriVtx0.x = min->x;
    sTriVtx0.y = min->y;
    sTriVtx0.z = min->z;
    sTriVtx1.x = min->x;
    sTriVtx1.y = min->y;
    sTriVtx1.z = max->z;
    sTriVtx2.x = min->x;
    sTriVtx2.y = max->y;
    sTriVtx2.z = max->z;
    if (Math3D_TriLineIntersect(&sTriVtx0, &sTriVtx1, &sTriVtx2, -1.0f, 0.0f, 0.0f, min->x, a, b, &sIntersectPoint,
                                0)) {
        return true;
    }

    sTriVtx1.x = min->x;
    sTriVtx1.y = max->y;
    sTriVtx1.z = max->z;
    sTriVtx2.x = min->x;
    sTriVtx2.y = max->y;
    sTriVtx2.z = min->z;
    if (Math3D_TriLineIntersect(&sTriVtx0, &sTriVtx1, &sTriVtx2, -1.0f, 0.0f, 0.0f, min->x, a, b, &sIntersectPoint,
                                0)) {
        return true;
    }

    
    sTriVtx0.x = min->x;
    sTriVtx0.y = max->y;
    sTriVtx0.z = max->z;
    sTriVtx1.x = min->x;
    sTriVtx1.y = min->y;
    sTriVtx1.z = max->z;
    sTriVtx2.x = max->x;
    sTriVtx2.y = max->y;
    sTriVtx2.z = max->z;
    if (Math3D_TriLineIntersect(&sTriVtx0, &sTriVtx1, &sTriVtx2, 0.0f, 0.0f, 1.0f, -max->z, a, b, &sIntersectPoint,
                                0)) {
        return true;
    }
    sTriVtx0.x = max->x;
    sTriVtx0.y = max->y;
    sTriVtx0.z = max->z;
    sTriVtx2.x = max->x;
    
    sTriVtx1.y = min->y;
    sTriVtx2.z = max->z;
    if (Math3D_TriLineIntersect(&sTriVtx0, &sTriVtx1, &sTriVtx2, 0.0f, 0.0f, 1.0f, -max->z, a, b, &sIntersectPoint,
                                0)) {
        return true;
    }

    
    sTriVtx1.x = min->x;
    sTriVtx1.y = max->y;
    sTriVtx1.z = min->z;
    sTriVtx2.x = min->x;
    sTriVtx2.y = max->y;
    sTriVtx2.z = max->z;
    if (Math3D_TriLineIntersect(&sTriVtx0, &sTriVtx1, &sTriVtx2, 0.0f, 1.0f, 0.0f, -max->y, a, b, &sIntersectPoint,
                                0)) {
        return true;
    }
    sTriVtx1.x = max->x;
    sTriVtx1.y = max->y;
    sTriVtx1.z = min->z;
    sTriVtx2.x = min->x;
    sTriVtx2.y = max->y;
    sTriVtx2.z = min->z;
    if (Math3D_TriLineIntersect(&sTriVtx0, &sTriVtx1, &sTriVtx2, 0.0f, 1.0f, 0.0f, -max->y, a, b, &sIntersectPoint,
                                0)) {
        return true;
    }

    
    sTriVtx0.x = min->x;
    sTriVtx0.y = min->y;
    sTriVtx0.z = min->z;
    sTriVtx1.x = min->x;
    sTriVtx1.y = max->y;
    sTriVtx1.z = min->z;
    sTriVtx2.x = max->x;
    sTriVtx2.y = max->y;
    sTriVtx2.z = min->z;
    if (Math3D_TriLineIntersect(&sTriVtx0, &sTriVtx1, &sTriVtx2, 0.0f, 0.0f, -1.0f, min->z, a, b, &sIntersectPoint,
                                0)) {
        return true;
    }
    sTriVtx1.x = max->x;
    sTriVtx1.y = max->y;
    sTriVtx1.z = min->z;
    sTriVtx2.x = max->x;
    sTriVtx2.y = min->y;
    sTriVtx2.z = min->z;

    
    if (Math3D_TriLineIntersect(&sTriVtx0, &sTriVtx1, &sTriVtx2, 0.0f, 0.0f, -1.0f, min->z, a, b, &sIntersectPoint,
                                0)) {
        return true;
    }
    sTriVtx1.x = max->x;
    sTriVtx1.y = min->y;
    sTriVtx1.z = min->z;
    sTriVtx2.x = max->x;
    sTriVtx2.y = min->y;
    sTriVtx2.z = max->z;
    if (Math3D_TriLineIntersect(&sTriVtx0, &sTriVtx1, &sTriVtx2, 0.0f, -1.0f, 0.0f, min->y, a, b, &sIntersectPoint,
                                0)) {
        return true;
    }
    sTriVtx1.x = max->x;
    sTriVtx1.y = min->y;
    sTriVtx1.z = max->z;
    sTriVtx2.x = min->x;
    sTriVtx2.y = min->y;
    sTriVtx2.z = max->z;

    
    if (Math3D_TriLineIntersect(&sTriVtx0, &sTriVtx1, &sTriVtx2, 0.0f, -1.0f, 0.0f, min->y, a, b, &sIntersectPoint,
                                0)) {
        return true;
    }
    sTriVtx0.x = max->x;
    sTriVtx0.y = max->y;
    sTriVtx0.z = max->z;
    sTriVtx1.x = max->x;
    sTriVtx1.y = min->y;
    sTriVtx1.z = min->z;
    sTriVtx2.x = max->x;
    sTriVtx2.y = max->y;
    sTriVtx2.z = min->z;
    if (Math3D_TriLineIntersect(&sTriVtx0, &sTriVtx1, &sTriVtx2, 1.0f, 0.0f, 0.0f, -max->x, a, b, &sIntersectPoint,
                                0)) {
        return true;
    }
    sTriVtx1.x = max->x;
    sTriVtx1.y = min->y;
    sTriVtx1.z = max->z;
    sTriVtx2.x = max->x;
    sTriVtx2.y = min->y;
    sTriVtx2.z = min->z;
    if (Math3D_TriLineIntersect(&sTriVtx0, &sTriVtx1, &sTriVtx2, 1.0f, 0.0f, 0.0f, -max->x, a, b, &sIntersectPoint,
                                0)) {
        return true;
    }

    return false;
}
