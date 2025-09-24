src := $(shell find src -name '*.c')
include := -Iinclude

.SILENT:
all:
	@echo

	@mkdir -p build bin

	@for f in $(src); do \
		echo "[Compiling]: $$f"; \
		gcc -c $$f $(include) -o build/$$(basename $$f .c).o; \
	done

	echo "[Linking]: bin/wireframe"
	gcc build/*.o -lncurses -o bin/wireframe

	@echo
	@echo "Done!"
	@echo
