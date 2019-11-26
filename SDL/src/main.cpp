#pragma once
#include <iostream>
#include "../headers/game.h"

const int SCREEN_X = 640;
const int SCREEN_Y = 480;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;//divide fps by the number of millisecond in a second

int main(int argc, char* argv[]) {

	Uint32 frameStart, frameTime;

	if ( TheGame::instance()->init( SCREEN_X, SCREEN_Y ) ) {
		while ( TheGame::instance()->getRunning() ) {

			frameStart = SDL_GetTicks();

			TheGame::instance()->handleEvents();
			TheGame::instance()->update();
			TheGame::instance()->render();
			
			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME) {
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}

		}
	} else {
		return -1;
	}

	TheGame::instance()->clean();

	return 0;
}