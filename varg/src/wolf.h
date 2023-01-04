#ifndef WOLF_H
#define WOLF_H

#include "vargsten.h"

/**
 * @brief init logic for Wolfenstein 3D game. 
 */
int wolfInit();

/**
 * @brief shutdown logic for Wolfenstein 3D game.
*/
void wolfShutdown();

/**
 * @brief create a new Wolfenstein 3D game struct.
 */
struct Game* createWolfGame();

#endif