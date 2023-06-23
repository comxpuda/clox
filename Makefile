objects = main.o chunk.o memory.o value.o vm.o compiler.o scanner.o debug.o

clox: $(objects)
	cc -g -O0 -o clox $(objects)

.PHONY: clean
clean:
	-rm clox $(objects)