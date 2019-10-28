#include <SDL.h>
#include <iostream>
#include "main.h"

SDL_Window* _window;
SDL_Renderer* _renderer;

const int SCREEN_X = 640;
const int SCREEN_Y = 480;

bool init(int screenX, int screenY) {
	SDL_CreateWindowAndRenderer(SCREEN_X, SCREEN_Y, 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, "SDL Works!");
	return _window ? true : false;
}

void render() {
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
}

int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
		std::cout << "failed to load SDL" << std::endl;
	}

	bool running = false;

	if (init(SCREEN_X, SCREEN_Y)) {
		running = true;
	}

	while (running) {
		render();
	}
	
	SDL_Quit();

	return 0;
}