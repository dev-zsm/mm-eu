#include "types.h"

typedef struct {
    u16 id;
    u16 cmdType;
} SeqCmd;
extern s32 D_801E6F08;
extern u16 D_801EC5C0;
extern void func_801A331C(s32, s32);
extern u16 AudioSeq_GetActiveSeqId(s32);
extern void Audio_PlaySceneSequence(u16, u8);
void CutsceneCmd_ModifySequence(s32 arg0, u8 *state, SeqCmd *cmd) {
    short new_var;
    u16 new_var2;
    u8 idx;
    u16 seq;
    if (cmd->cmdType == (*((u16 *) (state + 0x10)))) {
        idx = D_801E6F08 - 1;
        if (idx >= 3) {
            idx = 0;
        }
        switch (cmd->id) {
            case 1:
                func_801A331C(0 & 0xFFFF, 1);
                break;

            case 2:
                func_801A331C(0, 0);
                break;
                goto dummy_label_519791; dummy_label_519791: ;

            case 3:
                func_801A331C(0 & 0xFFFF, 2);
                break;

            case 4:
            func_801A331C(4, 1); break;
            case 5:
                func_801A331C(4, 0);
                break;

            case 6:
                func_801A331C(4, 2);
                break;

            case 7:
                D_801EC5C0 = AudioSeq_GetActiveSeqId(0);
                break;

            case 8:
                new_var2 = D_801EC5C0;
                seq = new_var2;
                if (seq != 0xFFFF) {
                D_801EC5C0 = (new_var = seq);
                Audio_PlaySceneSequence(seq, idx);
            }
                break;

        }

    }
}
