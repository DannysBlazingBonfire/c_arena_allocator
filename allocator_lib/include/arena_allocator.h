#include<stdint.h>

#ifndef ARENA_ALLOCATOR_H
#define ARENA_ALLOCATOR_H

// Constants
#define ARENA_CAPACITY 1024
#define CHUNK_SIZE 64

// Structs
typedef struct {
    uint8_t *p_current_element;
    uint8_t *p_data; // Pointer to Arenas Memory
} Arena;

typedef struct {
    uint8_t data[CHUNK_SIZE];
    const size_t element_size;
    const size_t size;
} Chunk;

Arena InitArena();
Chunk InitChunk(size_t element_size);
int8_t FreeArena(Arena *p_arena);
void* PushChunk(Arena *pArena, Chunk *pChunk);

#endif

// Restrictions:
// * data type within a chunk must be the same for the entire chunk