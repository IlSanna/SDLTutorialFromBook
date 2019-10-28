#include <SDL.h>
#include <iostream>

const int SCREEN_X = 640;
const int SCREEN_Y = 480;

int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
		std::cout << "failed to load SDL" << std::endl;
	}
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	SDL_CreateWindowAndRenderer(SCREEN_X, SCREEN_Y,0, &_window, &_renderer);
	
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
	SDL_Delay(5000);
	SDL_Quit();

	return 0;
}