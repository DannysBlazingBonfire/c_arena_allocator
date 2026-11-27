#include "arena_allocator.h"
#include <stdio.h>
#include <string.h>

int main()
{
    Arena arena = InitArena();
    Chunk chunk = InitChunk(sizeof(float));

    // Store values for half of the chunk
    float j = 1.00;
    float arr[(CHUNK_SIZE / sizeof(float)) / 2];
    for(size_t i = 0; i < (CHUNK_SIZE / sizeof(float)) / 2; i++) {
        arr[i] = j;
        j += 1.25;
    }

    (void)memcpy(chunk.data, arr, sizeof(arr)); // Put data in chunk

    for(size_t i = 0; i < 16; i++) { // Allocating 16 chunks of 64 Bytes (1024 Bytes)
        if(PushChunk(&arena, &chunk) == NULL) {
            perror("Allocation failed due too");
        }
    }

    float value = 0;
    for(size_t i = 0; i < 128; i += sizeof(float)) { // Print 2 pushed chunks from the arena
        value = 0;
        (void)memcpy(&value, &arena.p_data[i], sizeof(float));
        printf("Arena Byte: %f\n", value);
    }

    FreeArena(&arena);

    return 0;
}
