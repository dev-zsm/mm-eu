// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/su_mtx.h"

void Mtx_SetTranslateScaleMtx(Mtx* mtx, f32 scaleX, f32 scaleY, f32 scaleZ, f32 translateX, f32 translateY,
                              f32 translateZ) {
    struct {
        u16 intPart[4][4];
        u16 fracPart[4][4];
    }* mu = (void*)mtx;
    s32 fixedPoint;

    mtx->m[0][1] = 0;                                     
    mtx->m[2][1] = 0;                                     
    mtx->m[0][3] = 0;                                     
    mtx->m[2][3] = 0;                                     
    mtx->m[1][0] = 0;                                     
                                                          
    fixedPoint = scaleX * 0x10000;                        
    mtx->m[0][0] = fixedPoint;                            
    mu->intPart[0][1] = 0;                                
    mtx->m[2][0] = (u32)fixedPoint << 16;                 
                                                          
    fixedPoint = scaleY * 0x10000;                        
    mtx->m[0][2] = (u32)fixedPoint >> 16;                 
    mtx->m[2][2] = fixedPoint & 0xFFFF;                   
                                                          
    fixedPoint = scaleZ * 0x10000;                        
    mtx->m[1][1] = fixedPoint;                            
    mu->intPart[2][3] = 0;                                
    mtx->m[3][1] = (u32)fixedPoint << 16;                 
                                                          
    mtx->m[3][0] = 0;                                     
                                                          
    fixedPoint = translateX * 0x10000;                    
    mu->intPart[3][0] = ((u32)fixedPoint >> 16) & 0xFFFF; 
    mu->fracPart[3][0] = fixedPoint & 0xFFFF;             
                                                          
    fixedPoint = translateY * 0x10000;                    
    mu->intPart[3][1] = ((u32)fixedPoint >> 16) & 0xFFFF; 
    mu->fracPart[3][1] = fixedPoint & 0xFFFF;             
                                                          
    fixedPoint = translateZ * 0x10000;                    
    mu->intPart[3][2] = ((u32)fixedPoint >> 16) & 0xFFFF; 
    mu->intPart[3][3] = 1;                                
    mtx->m[3][3] = (u32)fixedPoint << 16;                 

    
    
    
    
    
    
    
    
    
    
}
