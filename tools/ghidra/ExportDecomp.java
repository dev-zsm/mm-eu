// Ghidra headless postScript: write <outdir>/<program>.c with the pseudo-C of every function.
// usage: analyzeHeadless ... -postScript ExportDecomp.java <outdir>
import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import java.io.*;

public class ExportDecomp extends GhidraScript {
    @Override
    public void run() throws Exception {
        File out = new File(getScriptArgs()[0], currentProgram.getName().replace(".elf", "") + ".c");
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        int ok = 0, fail = 0;
        try (PrintWriter w = new PrintWriter(new FileWriter(out))) {
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                DecompileResults r = di.decompileFunction(f, 60, monitor);
                w.println("// " + f.getEntryPoint() + " size " + f.getBody().getNumAddresses());
                if (r.decompileCompleted()) { w.println(r.getDecompiledFunction().getC()); ok++; }
                else { w.println("// FAILED: " + r.getErrorMessage() + "\n"); fail++; }
            }
        }
        di.dispose();
        println("ExportDecomp: " + ok + " ok, " + fail + " failed -> " + out);
    }
}
