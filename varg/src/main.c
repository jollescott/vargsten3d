#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_MSC_VER)
#define SDL_MAIN_HANDLED
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif // !_MSC_VER

#include "vargsten.h"
#include "wl6.h"

int main(int argc, char* argv)
{
	if (argc < 2) {
		printf("Expected two arguments, received %d", argc);
		return EXIT_FAILURE;
	}

	char* execPathArg = argv[0];
	char* wl6FileArg = argv[1];

	FILE* wl6File = openWl6(execPathArg, wl6FileArg);

	if (!wl6File) {
		printf("Failed to open file %s", wl6FileArg);
		return EXIT_FAILURE;
	}

	long wl6Size;
	char* wl6Data = readWl6(wl6File, &wl6Size);

	enum VSResult result;

	int levelPointer = mapHeaderPointer(wl6Data, 0, &result);
	printf("Level pointer %d \n", levelPointer);

	free(wl6Data);

	fclose(wl6File);

	return EXIT_SUCCESS;
}
