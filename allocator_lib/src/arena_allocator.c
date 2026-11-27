#include "arena_allocator.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

Arena InitArena()
{
    Arena arena;
    arena.p_data = (uint8_t*)malloc(ARENA_CAPACITY);
    if(arena.p_data == NULL) {
        perror("Allocation failed");
        exit(EXIT_FAILURE);
    }

    arena.p_current_element = &arena.p_data[0];

    return arena;
}

int8_t FreeArena(Arena *pArena)
{
    if(pArena == NULL || pArena->p_data == NULL) {
        return -1;
    }

    free(pArena->p_data);
    pArena->p_current_element = NULL;
    pArena->p_data = NULL;

    return 0;
}

void* PushChunk(Arena *pArena, Chunk *pChunk)
{
    if(pArena == NULL || pChunk == NULL) {
        errno = EINVAL;
        return NULL;
    }

    ptrdiff_t p_delta = ((pArena->p_current_element - pArena->p_data) + pChunk->size);
    if(p_delta > ARENA_CAPACITY) {
        errno = ENOMEM;
        return NULL;
    }

    size_t element_size = pChunk->element_size;
    if(element_size == 0) {
        errno = EINVAL;
        return NULL;
    }

    uint8_t *temp_current_start_address = pArena->p_current_element;

    // Write Chunk to allocated arena memory
    (void)memcpy(pArena->p_current_element, pChunk->data, pChunk->size);
    pArena->p_current_element += pChunk->size;

    return temp_current_start_address;
}

Chunk InitChunk(size_t element_size) {
    Chunk chunk = {
        .size = CHUNK_SIZE,
        .element_size = element_size,
    };
    return chunk;
}
