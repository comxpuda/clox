#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"

#define STACK_MAX 1024

typedef struct
{
    Chunk* chunk;
    uint8_t* ip; // instruction pointer

    Value stack[STACK_MAX];
    Value* stackTop;
    Obj* objects;
} VM ;

typedef enum 
{
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

// The “object” module is directly using the global vm variable from the “vm” module, 
// so we need to expose that externally.
extern VM vm;

void initVM();
void freeVM();
// InterpretResult interpret(Chunk* chunk);

void push(Value value);
Value pop();
InterpretResult interpret(const char* source);

#endif