#ifndef LOX_CHUNK_H
#define LOX_CHUNK_H

#include "common.h"
#include "value.h"

typedef enum {
	OP_RETURN,
} OpCode;

typedef struct {
	int count;	// number of items
	int capacity;	// current max no of items
	uint8_t *code;
	ValueArray constants;
} Chunk;

void init_chunk(Chunk *chunk);
void free_chunk(Chunk *chunk);
void write_chunk(Chunk *chunk, uint8_t byte);
int add_constant(Chunk *chunk, Value value);

#endif
