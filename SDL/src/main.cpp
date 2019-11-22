#pragma once
#include <iostream>
#include "../headers/game.h"

const int SCREEN_X = 640;
const int SCREEN_Y = 480;

int main(int argc, char* argv[]) {

	if ( TheGame::instance()->init( SCREEN_X, SCREEN_Y ) ) {
		while ( TheGame::instance()->getRunning() ) {
			TheGame::instance()->handleEvents();
			TheGame::instance()->update();
			TheGame::instance()->render();
			SDL_Delay( 10 );
		}
	} else {
		return -1;
	}

	TheGame::instance()->clean();

	return 0;
}