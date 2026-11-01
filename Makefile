# Run inside WSL (Ubuntu). See docs/CONTRIBUTING.md.
SEG ?= boot
HOURS ?= 1

.PHONY: setup split verify check fastcheck auto daily progress names clean

setup:            ## one-time: IDO 7.1, splat, m2c, asm-differ (needs binutils-mips-linux-gnu)
	bash tools/split/setup_wsl.sh

split:            ## disassemble boot, code and the overlays into asm/ with splat (make check needs all three)
	. ~/mm-venv/bin/activate && splat split config/boot/splat.yaml && splat split config/code/splat.yaml && python3 tools/split/overlay_split.py

verify:           ## every C function == ROM bytes, and the segment rebuilt from C + asm == ROM
	bash tools/check/verify_all.sh $(SEG)

check:            ## run before every commit: verify boot, code and the overlays against the ROM, then the source style rules
	bash tools/check/verify_all.sh boot && bash tools/check/verify_all.sh code && bash tools/check/verify_overlays.sh && bash tools/check/check_style.sh

fastcheck:        ## same as check, 3-4 times faster when the repository is on the Windows disk (mirrors it to the WSL disk)
	bash tools/check/fastcheck.sh

auto:             ## unattended, like daily but nothing is committed (HOURS=1)
	NO_COMMIT=1 bash tools/run/daily.sh $(HOURS)

daily:            ## unattended, several hours (HOURS=3): permuter, overlay passes, full check, then commit and push
	bash tools/run/daily.sh $(HOURS)

progress:         ## refresh docs/PROGRESS.md and the progress bars in README.md
	python3 tools/check/progress.py boot code

names:            ## check config/*/names.txt and apply names to the sources
	python3 tools/lib/names.py $(SEG) --apply-src

clean:
	rm -rf build/$(SEG)/named build/perm ~/.cache/mm-n64-decomp
