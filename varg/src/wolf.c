#include <stdio.h>
#include <stdlib.h>

#include "wolf.h"

int wolfInit()
{
	return 0;
}

void wolfShutdown()
{
}

struct Game* createWolfGame() {
	struct Game* wolfGame = malloc(sizeof(struct Game));

	if (wolfGame == 0) {
		return 0;
	}

	wolfGame->init = &wolfInit;
	wolfGame->shutdown = &wolfShutdown;
	
	return wolfGame;
}