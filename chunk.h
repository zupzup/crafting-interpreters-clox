#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
    OP_RETURN,
    OP_CONSTANT,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_GET_GLOBAL,
    OP_DEFINE_GLOBAL,
    OP_SET_GLOBAL,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_CLOSURE,
    OP_GET_UPVALUE,
    OP_CLASS,
    OP_GET_PROPERTY,
    OP_SET_PROPERTY,
    OP_METHOD,
    OP_CLOSE_UPVALUE,
    OP_INVOKE,
    OP_SET_UPVALUE,
    OP_INHERIT,
    OP_NEGATE,
    OP_GET_SUPER,
    OP_SUPER_INVOKE,
    OP_POP,
    OP_PRINT,
    OP_GET_LOCAL,
    OP_JUMP_IF_FALSE,
    OP_JUMP,
    OP_LOOP,
    OP_CALL,
    OP_SET_LOCAL,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NOT,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
void freeChunk(Chunk* chunk);
int addConstant(Chunk* chunk, Value value);

#endif
