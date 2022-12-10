#include "vargsten.h"
#include <stdio.h>
#include <stdlib.h>

char* deCarmackize(const char* original, long size, enum VSResult* success)
{
    // First word will be the size of bytes of the uncompressed data.
    const unsigned short numBytes = original[1] << 8 | original[0];
    int rB = 0;

    printf("Carmack compression: %hi bytes \n", numBytes);

    // Allocate buffer to expand compressed data in to.
    char* buffer = malloc(numBytes);

    for(int i = 0; i < size - 2; i++) {        
        // Retreive the signal byte.
        const unsigned char data = original[i];
        switch(data) {
        case 0xA7:
        {
            // Bytes to repeat (in words)
            const unsigned char repeat = original[i-1] * 2;
            // Offset to start at (in words)
            const unsigned char offset = original[i+1] * 2;

            for(int j = 0; j < repeat; j++) {
                buffer[rB + j] = buffer[rB - offset + j];
            }

            rB += repeat;
            i++;

            break;
        }
        case 0xA8: {
            // Bytes to repeat (int words)
            const unsigned char repeat = original[i-1];

            // Offset to start at (int words)
            // Stored as a ushort.
            const unsigned char loffset = original[i+1];
            const unsigned char hoffset = original[i+2];

            const unsigned short offset = (hoffset << 8 | loffset) * 2;

            for(int j = 0; j < repeat; j++) {
                buffer[rB + j] = buffer[rB - offset + j];
            }

            rB += repeat;
            i+=2;

            break;
        }
        default:
            buffer[rB] = data;
            rB++;
        }
    }

    if(rB == numBytes) {
        *success = VSOK;
    } else {
        *success = VSFAIL;
        free(buffer);
        buffer = NULL;
    }

    return buffer;
}


int mapHeaderPointer(const char *header, const char level, enum VSResult *result)
{
    unsigned short magic = header[1] << 8 | header[0];

    if(magic == 0xABCD) {
        printf("RLEW compression active!");
    }

    unsigned char pointerBuffer[4];
    pointerBuffer[0] = header[level + 2];
    pointerBuffer[1] = header[level + 3];
    pointerBuffer[2] = header[level + 4];
    pointerBuffer[3] = header[level + 5];

    int* pointer = (int*)pointerBuffer;
    return *pointer;
}
