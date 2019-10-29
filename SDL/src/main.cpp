#pragma once
#include <iostream>
#include "../headers/game.h"

const int SCREEN_X = 640;
const int SCREEN_Y = 480;

Game* g_game = 0;

int main(int argc, char* argv[]) {

	g_game = new Game();
	g_game->init(SCREEN_X,SCREEN_Y);
	
	while (g_game->getRunning()) {
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();

	return 0;
}