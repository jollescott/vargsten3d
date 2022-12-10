#ifndef WL6_H
#define WL6_H

#include <stdio.h>

/**
 * @brief openWl6 Open a WL6 file from the filesystem
 * @param execPathArg The current executable path
 * @param wl6FileArg The WL6 file to open.
 * @return The opened file from the filesystem.
 */
FILE* openWl6(char* execPathArg, char* wl6FileArg);

/**
 * @brief readWl6 Read the contents of the WL6 file.
 * @param wl6File The WL6 file handle.
 * @param wl6Size The size of the file in bytes.
 * @return char buffer of file content.
 */
char* readWl6(FILE* wl6File, long* wl6Size);

#endif // WL6_H
