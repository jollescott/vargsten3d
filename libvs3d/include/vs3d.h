#ifndef VS3D_H
#define VS3D_H

/**
 * @brief decompress carmackized compression of game data.
 * @param original carmackized compressed data to decompress.
 * @param size of the compressed data.
 * @return the compressed data.
 */
char* deCarmackize(const char* original, long size);

#endif // VS3D_H
