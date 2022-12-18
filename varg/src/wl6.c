#include <stdlib.h>
#include "wl6.h"

FILE* openWl6(char* execPathArg, char* wl6FileArg)
{
    char* execPath = malloc(strlen(execPathArg));
    char* wl6Name = malloc(strlen(wl6FileArg));

    strcpy(execPath, execPathArg);
    strcpy(wl6Name, wl6FileArg);

    char* execPart = strrchr(execPath, '/');

    long execLoc = execPart - execPath;
    char* wl6Path = malloc(execLoc + strlen(wl6FileArg) + 1);

    strncpy(wl6Path, execPath, execLoc);

    strcat(wl6Path, "/");
    strcat(wl6Path, wl6Name);

    printf("Decompressing %s ...\n", wl6Name);

    free(execPath);
    free(wl6Name);

    FILE* wl6File = fopen(wl6Path, "rb");
    free(wl6Path);

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
