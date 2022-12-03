#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vs3d.h"

FILE* openWl6(char* execPathArg, char* wl6FileArg)
{
    char execPath[strlen(execPathArg)];
    char wl6Name[strlen(wl6FileArg)];

    strcpy(execPath, execPathArg);
    strcpy(wl6Name, wl6FileArg);

    char* execPart = strrchr(execPath, '/');

    long execLoc = execPart - execPath;
    char wl6Path[execLoc + strlen(wl6FileArg) + 1];

    strncpy(wl6Path, execPath, execLoc);

    strcat(wl6Path, "/");
    strcat(wl6Path, wl6Name);

    printf("Decompressing %s ...\n", wl6Name);

    FILE* wl6File = fopen(wl6Path, "rb");

    return wl6File;
}

char* readWl6(FILE* wl6File, long* wl6Size) {
    fseek(wl6File, 0, SEEK_END);
    long size = ftell(wl6File);
    fseek(wl6File, 0, SEEK_SET);

    char* buffer = malloc(sizeof(char) * size);

    for(int i = 0; i < size; i++) {
        const unsigned char c = fgetc(wl6File);
        buffer[i] = c;
    }

    *wl6Size = size;

    return buffer;
}

int main(int argc, char* argv[])
{
    if(argc < 2) {
        printf("Expected two arguments, received %d", argc);
        return EXIT_FAILURE;
    }

    char* execPathArg = argv[0];
    char* wl6FileArg = argv[1];

    FILE* wl6File = openWl6(execPathArg, wl6FileArg);

    if(!wl6File) {
        printf("Failed to open file %s", wl6FileArg);
        return EXIT_FAILURE;
    }

    long wl6Size;
    char* wl6Data = readWl6(wl6File, &wl6Size);

    char* uncompressedData = deCarmackize(wl6Data, wl6Size);

    free(wl6Data);
    free(uncompressedData);

    fclose(wl6File);

    return EXIT_SUCCESS;
}
