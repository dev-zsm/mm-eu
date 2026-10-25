# Run inside WSL (Ubuntu). See docs/CONTRIBUTING.md.
SEG ?= boot
HOURS ?= 1

.PHONY: setup split verify check auto progress names clean

setup:            ## one-time: IDO 7.1, splat, m2c, asm-differ (needs binutils-mips-linux-gnu)
	bash tools/setup_wsl.sh

split:            ## disassemble boot and code into asm/ with splat
	. ~/mm-venv/bin/activate && splat split config/boot.yaml && splat split config/code.yaml

verify:           ## every C function == ROM bytes, and the segment rebuilt from C + asm == ROM
	bash tools/verify_all.sh $(SEG)

check:            ## run before every commit: verify boot and code against the ROM, then the source style rules
	bash tools/verify_all.sh boot && bash tools/verify_all.sh code && bash tools/check_style.sh

auto:             ## unattended: permuter queue for HOURS (default 1), tidy the wins, then names and the full check
	bash tools/auto_loop.sh $(HOURS)

progress:         ## refresh docs/PROGRESS.md and the progress bars in README.md
	python3 tools/progress.py boot code

names:            ## check config/*.names.txt and apply names to the sources
	python3 tools/names.py $(SEG) --apply-src

clean:
	rm -rf build/$(SEG)/named build/perm ~/.cache/mm-n64-decomp
