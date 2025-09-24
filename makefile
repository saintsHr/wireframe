src := $(shell find src -name '*.c')
include = -Iinclude
flags = -o

all:
	gcc $(src) $(include) $(flags) wireframe