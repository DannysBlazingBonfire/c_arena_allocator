This was a small fun project made in C called an Arena allocator. This allocator allocates 1KiB Arena on the heap. The arena can then have chunks of 64-Bytes pushed onto it.
This means that the lifetime of these different chunks aren't managed by the individual chunks themselves but by the arena. When memory is supposed to be freed
the arena calls a free function which frees memory from all of the pushed chunks.

The `main.c` file contains an example of floats being stored on half filled chunks which are then pushed onto the arena.
It then prints out the first two chunks from the arenas memory.

You can build this project with CMake by following these steps:

Step 1 Create a build folder
From project `root` Run: `mkdir build` then `cd build`

Step 2 Build with CMake:
From `build/` run `cmake -G Ninja` then `ninja` to compile

Step 3 Execute:
run `./allocator/main.exe`
you should see printouts of the float values pushed onto the arena.
