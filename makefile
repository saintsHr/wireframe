src := $(shell find src -name '*.c')
include := -Iinclude
debflags := -g3 -O0 -ggdb -Wall -Wextra -Wshadow -Wformat -Wconversion -DDEBUG -fsanitize=address,undefined -fno-omit-frame-pointer
disflags := -O3 -flto -funroll-loops -finline-functions -fomit-frame-pointer -fno-strict-aliasing -fno-common -fwrapv -ffast-math -fprefetch-loop-arrays -fmerge-all-constants -ffunction-sections -fdata-sections -Wl,--gc-sections -fno-exceptions -DNDEBUG

.SILENT:
all:
	@echo
	@echo "Compiling in Debug Mode!"
	@echo

	@mkdir -p build lib

	@for f in $(src); do \
		echo "[Compiling]: $$f"; \
		gcc -c $$f $(include) $(debflags) -o build/$$(basename $$f .c).o; \
	done

	@echo
	echo "[Linking]: lib/libwireframe.a"
	ar rcs lib/libwireframe.a -lncurses build/*.o

	@echo
	@echo "Done!"
	@echo

.SILENT:
dis:
	@echo
	@echo "Compiling in Distribution Mode!"
	@echo

	@mkdir -p build lib

	@for f in $(src); do \
		echo "[Compiling]: $$f"; \
		gcc -c $$f $(include) $(disflags) -o build/$$(basename $$f .c).o; \
	done

	@echo
	echo "[Linking]: lib/libwireframe.a"
	ar rcs lib/libwireframe.a -lncurses build/*.o

	@echo
	@echo "Done!"
	@echo