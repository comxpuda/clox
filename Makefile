objects = main.o chunk.o memory.o value.o debug.o

clox: $(objects)
	cc -g -o clox $(objects)

.PHONY: clean
clean:
	-rm clox $(objects)