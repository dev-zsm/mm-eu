// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_PrintThreadContext(OSThread *thread) {
    s16 causeStrIdx = (thread->context.cause >> 2) & 0x1F;
    __OSThreadContext *ctx;

    if (causeStrIdx == 0x17) {
        causeStrIdx = 0x10;
    }
    if (causeStrIdx == 0x1F) {
        causeStrIdx = 0x11;
    }
    ctx = &thread->context;
    FaultDrawer_FillScreen();
    FaultDrawer_SetCharPad(-2, 4);
    FaultDrawer_SetCursor(22, 20);
    FaultDrawer_Printf(D_800988C4, thread->id, causeStrIdx, D_80096D20[causeStrIdx]);
    FaultDrawer_SetCharPad(-1, 0);
    FaultDrawer_Printf(D_800988D8, (u32)ctx->pc, (u32)ctx->sr, (u32)ctx->badvaddr);
    FaultDrawer_Printf(D_800988F4, LOW_WORD(ctx->at), LOW_WORD(ctx->v0), LOW_WORD(ctx->v1));
    FaultDrawer_Printf(D_80098910, LOW_WORD(ctx->a0), LOW_WORD(ctx->a1), LOW_WORD(ctx->a2));
    FaultDrawer_Printf(D_8009892C, LOW_WORD(ctx->a3), LOW_WORD(ctx->t0), LOW_WORD(ctx->t1));
    FaultDrawer_Printf(D_80098948, LOW_WORD(ctx->t2), LOW_WORD(ctx->t3), LOW_WORD(ctx->t4));
    FaultDrawer_Printf(D_80098964, LOW_WORD(ctx->t5), LOW_WORD(ctx->t6), LOW_WORD(ctx->t7));
    FaultDrawer_Printf(D_80098980, LOW_WORD(ctx->s0), LOW_WORD(ctx->s1), LOW_WORD(ctx->s2));
    FaultDrawer_Printf(D_8009899C, LOW_WORD(ctx->s3), LOW_WORD(ctx->s4), LOW_WORD(ctx->s5));
    FaultDrawer_Printf(D_800989B8, LOW_WORD(ctx->s6), LOW_WORD(ctx->s7), LOW_WORD(ctx->t8));
    FaultDrawer_Printf(D_800989D4, LOW_WORD(ctx->t9), LOW_WORD(ctx->gp), LOW_WORD(ctx->sp));
    FaultDrawer_Printf(D_800989F0, LOW_WORD(ctx->s8), LOW_WORD(ctx->ra), LOW_WORD(ctx->lo));
    Fault_PrintFPCSR(ctx->fpcsr);
    FaultDrawer_Printf(D_80098A10);
    Fault_PrintFReg(0, &ctx->fp0.f.f_even);
    Fault_PrintFReg(2, &ctx->fp2.f.f_even);
    FaultDrawer_Printf(D_80098A14);
    Fault_PrintFReg(4, &ctx->fp4.f.f_even);
    Fault_PrintFReg(6, &ctx->fp6.f.f_even);
    FaultDrawer_Printf(D_80098A18);
    Fault_PrintFReg(8, &ctx->fp8.f.f_even);
    Fault_PrintFReg(10, &ctx->fp10.f.f_even);
    FaultDrawer_Printf(D_80098A1C);
    Fault_PrintFReg(12, &ctx->fp12.f.f_even);
    Fault_PrintFReg(14, &ctx->fp14.f.f_even);
    FaultDrawer_Printf(D_80098A20);
    Fault_PrintFReg(16, &ctx->fp16.f.f_even);
    if (thread == NULL && thread == NULL && thread == NULL) { /* matching: dead check */
    }
    Fault_PrintFReg(18, &ctx->fp18.f.f_even);
    FaultDrawer_Printf(D_80098A24);
    Fault_PrintFReg(20, &ctx->fp20.f.f_even);
    Fault_PrintFReg(22, &ctx->fp22.f.f_even);
    FaultDrawer_Printf(D_80098A28);
    Fault_PrintFReg(24, &ctx->fp24.f.f_even);
    Fault_PrintFReg(26, &ctx->fp26.f.f_even);
    FaultDrawer_Printf(D_80098A2C);
    Fault_PrintFReg(28, &ctx->fp28.f.f_even);
    Fault_PrintFReg(30, &ctx->fp30.f.f_even);
    FaultDrawer_Printf(D_80098A30);
    FaultDrawer_SetCharPad(0, 0);
    if (D_8009C224 != 0.0f) {
        FaultDrawer_DrawText(160, 216, D_80098A34, D_8009C224);
    }
}
