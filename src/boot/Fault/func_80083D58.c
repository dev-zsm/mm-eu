// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_HangupFaultClient(const char *exp1, const char *exp2) {
    func_8008198C(D_80098E70, osGetThreadId(NULL));
    func_8008198C(D_80098E88, exp1 != NULL ? exp1 : D_80098E8C);
    func_8008198C(D_80098E94, exp2 != NULL ? exp2 : D_80098E98);
    FaultDrawer_Printf(D_80098EA0, osGetThreadId(NULL));
    FaultDrawer_Printf(D_80098EB8, exp1 != NULL ? exp1 : D_80098EBC);
    FaultDrawer_Printf(D_80098EC4, exp2 != NULL ? exp2 : D_80098EC8);
}
