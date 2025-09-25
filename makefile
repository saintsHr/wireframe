src := $(shell find src -name '*.c')
include := -Iinclude

.SILENT:
all:
	@echo

	@mkdir -p build lib

	@for f in $(src); do \
		echo "[Compiling]: $$f"; \
		gcc -c $$f $(include) -o build/$$(basename $$f .c).o; \
	done

	@echo
	echo "[Linking]: lib/libwireframe.a"
	ar rcs lib/libwireframe.a -lncurses build/*.o

	@echo
	@echo "Done!"
	@echo
