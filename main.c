#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"


int main(int argc, const char* argv[]) 
{
    initVM();
    Chunk chunk;
    initChunk(&chunk);

    // test for stack size
    // for (size_t i = 0; i < 318; i++)
    // {
    //     uint16_t constant = addConstant(&chunk,i);
    //     if (i > 255) {
    //         writeChunk(&chunk,OP_CONSTANT_LONG,i);
    //         writeChunk(&chunk,constant >> 8 & 0x00FF ,i); // break constant to 2 byte
    //         writeChunk(&chunk,constant & 0x00FF,i);
    //     } 
    //     else {
    //         writeChunk(&chunk,OP_CONSTANT,i);
    //         writeChunk(&chunk,constant,i);
    //     }
    // }
    
    
    // 1 * 2 + 3
    int constant = addConstant(&chunk,1);
    writeChunk(&chunk,OP_CONSTANT,123);
    writeChunk(&chunk,constant,123);

    constant = addConstant(&chunk,2);
    writeChunk(&chunk,OP_CONSTANT,123);
    writeChunk(&chunk,constant,123);

    writeChunk(&chunk,OP_MULTIPLY,123);

    constant = addConstant(&chunk,3);
    writeChunk(&chunk,OP_CONSTANT,123);
    writeChunk(&chunk,constant,123);
    writeChunk(&chunk,OP_ADD,123);
    // 1 + 2 * 3
    constant = addConstant(&chunk,2);
    writeChunk(&chunk,OP_CONSTANT,123);
    writeChunk(&chunk,constant,123);
    constant = addConstant(&chunk,3);
    writeChunk(&chunk,OP_CONSTANT,123);
    writeChunk(&chunk,constant,123);
    writeChunk(&chunk,OP_MULTIPLY,123);


    constant = addConstant(&chunk,1);
    writeChunk(&chunk,OP_CONSTANT,123);
    writeChunk(&chunk,constant,123);
    writeChunk(&chunk,OP_ADD,123);

    // 1 + 2 * 3 - 4 / -5

    writeChunk(&chunk,OP_RETURN,123);
    disassembleChunk(&chunk, "test chunk");
    interpret(&chunk);

    freeVM();
    freeChunk(&chunk);

    return 0;
}