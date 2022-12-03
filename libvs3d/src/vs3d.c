#include "vs3d.h"
#include <stdio.h>
#include <stdlib.h>

char* deCarmackize(const char* original, long size)
{
    const short numBytes = original[1] << 8 | original[0];
    printf("Carmack compression: %hi bytes \n", numBytes);

    char* buffer = malloc(numBytes);

    for(int i = 0; i < size - 2; i++) {
        const unsigned char data = original[i];

        switch(data) {
        case 0xA7:
        {
            const unsigned char repeat = original[i-1];
            const unsigned char offset = original[i+1];

            for(int j = 0; j < repeat; j++) {
                buffer[i] = buffer[i - offset + j];
            }

            break;
        }
        case 0xA8:
            break;
        default:
            buffer[i] = data;
        }
    }

    return buffer;
}
