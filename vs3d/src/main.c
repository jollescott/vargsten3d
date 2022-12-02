#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if(argc < 2) {
        printf("Expected two arguments, received %d", argc);
        return EXIT_FAILURE;
    }

    char execPath[strlen(argv[0]) + strlen(argv[1]) + 1];
    char wl6Name[strlen(argv[1])];

    strcpy(execPath, argv[0]);
    strcpy(wl6Name, argv[1]);

    char* execPart = strrchr(execPath, '/');
    printf("%s", execPart);

    char* execLoc = strstr(execPath, execPart);
    printf("%td", execLoc - execPath);

    printf("Decompressing %s ...\n", wl6Name);

    strcat(execPath, "/");
    strcat(execPath, wl6Name);

    FILE* wl6File = fopen(execPath, "r");

    if(!wl6File) {
        printf("Failed to open file %s", wl6Name);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
