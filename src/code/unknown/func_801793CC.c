// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/su_mtx.h"

void Mtx_SetRotationMtx(Mtx* mtx, s32 angle, f32 axisX, f32 axisY, f32 axisZ) {
    
    f32 tempX;
    f32 tempZ;
    f32 tempY;
    f32 sin = Math_SinS(angle);
    f32 cos = Math_CosS(angle);
    f32 tempXX;
    f32 tempYY;
    f32 tempZZ;

    s32 fixedPoint;

    mtx->m[1][2] = 0; 
    mtx->m[1][3] = 1; 
    mtx->m[3][2] = 0; 
    mtx->m[3][3] = 0; 

    tempXX = axisX * axisX;
    tempX = (axisY * axisZ) * (1.0f - cos);

    
    fixedPoint = (((1.0f - tempXX) * cos) + tempXX) * 0x10000;
    mtx->intPart[0][0] = ((u32)fixedPoint >> 0x10) & 0xFFFF;
    mtx->fracPart[0][0] = fixedPoint & 0xFFFF;

    tempZ = ((axisX * axisY) * (1.0f - cos));
    tempZZ = axisZ * axisZ;

    
    fixedPoint = (tempX - (axisX * sin)) * 0x10000;
    mtx->intPart[2][1] = ((u32)fixedPoint >> 0x10) & 0xFFFF;
    mtx->fracPart[2][1] = fixedPoint & 0xFFFF;

    tempY = (axisZ * axisX) * (1.0f - cos);
    tempYY = axisY * axisY;

    
    fixedPoint = (tempX + (axisX * sin)) * 0x10000;
    mtx->m[0][3] = fixedPoint; 
    mtx->intPart[1][3] = 0;    
    mtx->m[2][3] = fixedPoint << 0x10;

    
    fixedPoint = ((((1.0f - tempYY) * cos) + tempYY) * 0x10000);
    mtx->intPart[1][1] = ((u32)fixedPoint >> 0x10) & 0xFFFF;
    mtx->fracPart[1][1] = fixedPoint & 0xFFFF;

    
    
    
    fixedPoint = (tempY - (axisY * sin)) * 0x10000;
    mtx->intPart[2][0] = ((u32)fixedPoint >> 0x10) & 0xFFFF;
    mtx->fracPart[2][0] = fixedPoint & 0xFFFF;

    
    fixedPoint = (tempY + (axisY * sin)) * 0x10000;
    mtx->m[0][1] = fixedPoint; 
    mtx->intPart[0][3] = 0;    
    mtx->m[2][1] = fixedPoint << 0x10;

    
    fixedPoint = ((((1.0f - tempZZ) * cos) + tempZZ) * 0x10000);
    mtx->m[1][1] = fixedPoint; 
    mtx->intPart[2][3] = 0;    
    mtx->m[3][1] = fixedPoint << 0x10;

    
    fixedPoint = (tempZ - axisZ * sin) * 0x10000;
    mtx->intPart[1][0] = ((u32)fixedPoint >> 0x10) & 0xFFFF;
    mtx->fracPart[1][0] = fixedPoint & 0xFFFF;

    
    fixedPoint = (tempZ + axisZ * sin) * 0x10000;
    mtx->intPart[0][1] = ((u32)fixedPoint >> 0x10) & 0xFFFF;
    mtx->fracPart[0][1] = fixedPoint & 0xFFFF;
}
