objects = main.o chunk.o memory.o value.o object.o vm.o compiler.o scanner.o table.o debug.o

clox: $(objects)
	cc -g -O0 -o clox $(objects)

.PHONY: clean
clean:
	-rm clox $(objects)