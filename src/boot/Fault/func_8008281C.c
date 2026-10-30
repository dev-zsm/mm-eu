// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_LogThreadContext(OSThread *thread) {
    s16 causeStrIdx = (thread->context.cause >> 2) & 0x1F;
    __OSThreadContext *ctx;

    if (causeStrIdx == 0x17) {
        causeStrIdx = 0x10;
    }
    if (causeStrIdx == 0x1F) {
        causeStrIdx = 0x11;
    }
    ctx = &thread->context;
    func_8008198C(D_80098A40);
    func_8008198C(D_80098A44, thread->id, causeStrIdx, D_80096D20[causeStrIdx]);
    func_8008198C(D_80098A5C, (u32)ctx->pc, (u32)ctx->sr, (u32)ctx->badvaddr);
    func_8008198C(D_80098A7C, (u32)ctx->at, (u32)ctx->v0, (u32)ctx->v1);
    func_8008198C(D_80098A9C, (u32)ctx->a0, (u32)ctx->a1, (u32)ctx->a2);
    func_8008198C(D_80098ABC, (u32)ctx->a3, (u32)ctx->t0, (u32)ctx->t1);
    func_8008198C(D_80098ADC, (u32)ctx->t2, (u32)ctx->t3, (u32)ctx->t4);
    if (thread == NULL && thread == NULL && thread == NULL) { /* matching: dead check */
    }
    func_8008198C(D_80098AFC, (u32)ctx->t5, (u32)ctx->t6, (u32)ctx->t7);
    func_8008198C(D_80098B1C, (u32)ctx->s0, (u32)ctx->s1, (u32)ctx->s2);
    func_8008198C(D_80098B3C, (u32)ctx->s3, (u32)ctx->s4, (u32)ctx->s5);
    func_8008198C(D_80098B5C, (u32)ctx->s6, (u32)ctx->s7, (u32)ctx->t8);
    func_8008198C(D_80098B7C, (u32)ctx->t9, (u32)ctx->gp, (u32)ctx->sp);
    func_8008198C(D_80098B9C, (u32)ctx->s8, (u32)ctx->ra, (u32)ctx->lo);
    func_8008198C(D_80098BBC);
    Fault_LogFPCSR(ctx->fpcsr);
    func_8008198C(D_80098BC0);
    Fault_LogFReg(0, &ctx->fp0.f.f_even);
    Fault_LogFReg(2, &ctx->fp2.f.f_even);
    func_8008198C(D_80098BC4);
    Fault_LogFReg(4, &ctx->fp4.f.f_even);
    Fault_LogFReg(6, &ctx->fp6.f.f_even);
    func_8008198C(D_80098BC8);
    Fault_LogFReg(8, &ctx->fp8.f.f_even);
    Fault_LogFReg(10, &ctx->fp10.f.f_even);
    func_8008198C(D_80098BCC);
    Fault_LogFReg(12, &ctx->fp12.f.f_even);
    Fault_LogFReg(14, &ctx->fp14.f.f_even);
    func_8008198C(D_80098BD0);
    Fault_LogFReg(16, &ctx->fp16.f.f_even);
    Fault_LogFReg(18, &ctx->fp18.f.f_even);
    func_8008198C(D_80098BD4);
    Fault_LogFReg(20, &ctx->fp20.f.f_even);
    Fault_LogFReg(22, &ctx->fp22.f.f_even);
    func_8008198C(D_80098BD8);
    Fault_LogFReg(24, &ctx->fp24.f.f_even);
    Fault_LogFReg(26, &ctx->fp26.f.f_even);
    func_8008198C(D_80098BDC);
    Fault_LogFReg(28, &ctx->fp28.f.f_even);
    Fault_LogFReg(30, &ctx->fp30.f.f_even);
    func_8008198C(D_80098BE0);
}
