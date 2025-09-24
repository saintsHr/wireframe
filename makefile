src := $(shell find src -name '*.c')
include := -Iinclude

.SILENT:
all:
	@echo

	@mkdir -p build bin

	@for f in $(src); do \
		echo "[Compiling]: $$f"; \
		gcc -c $$f -o build/$$(basename $$f .c).o $(include); \
	done

	echo "[Linking]: bin/wireframe"
	gcc build/*.o -o bin/wireframe

	@echo
	@echo "Done!"
	@echo
