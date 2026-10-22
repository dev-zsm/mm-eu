# Run inside WSL (Ubuntu). See docs/CONTRIBUTING.md.
SEG ?= boot

.PHONY: setup split verify progress names clean

setup:            ## one-time: IDO 7.1, splat, m2c, asm-differ (needs binutils-mips-linux-gnu)
	bash tools/setup_wsl.sh

split:            ## disassemble boot and code into asm/ with splat
	. ~/mm-venv/bin/activate && splat split config/boot.yaml && splat split config/code.yaml

verify:           ## every C function == ROM bytes, and the segment rebuilt from C + asm == ROM
	bash tools/verify_all.sh $(SEG)

progress:         ## refresh docs/PROGRESS.md and the progress bars in README.md
	python3 tools/progress.py boot code

names:            ## check config/*.names.txt and apply names to the sources
	python3 tools/names.py $(SEG) --apply-src

clean:
	rm -rf build/$(SEG)/fn build/$(SEG)/named build/perm
