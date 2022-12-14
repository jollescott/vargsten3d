#ifndef VARGSTEN_H
#define VARGSTEN_H

/**
 * @brief Used to indicate results of operations within vargsten.
 */
enum VSResult { VSOK, VSFAIL };

/**
  * @brief used to provide game specific behavior
  */
struct Game
{
	int(*init)();
	void(*shutdown)();
};

/**
 * @brief deCarmackize Decompress data under Carmack compression.
 * @param original The original compressed data.
 * @param size The size of the compressed data.
 * @param success Set to TRUE if decompression was successfull, else FALSE.
 * @return The uncompressed data. frees data and returns null in case of failure.
 */
char* deCarmackize(const char* original, const long size, enum VSResult* result);

/**
 * @brief mapHeaderLookup retrieve the chunks pointer for a given level.
 * @param header header byte data.
 * @param level the level to retrieve pointer for.
 * @param result
 * @return the point to the level
 */
int mapHeaderPointer(const char* header, const char level, enum VSResult* result);

#endif // VARGSTEN_H
