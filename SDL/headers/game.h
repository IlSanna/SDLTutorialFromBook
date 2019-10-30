#ifndef _GAME_
#define _GAME_

#include <SDL.h>
#include <SDL_surface.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "textureManager.h"

class Game {
public:
	Game();
	~Game();

	void init(int screenX,int screenY); 
	void render(); 
	void update();
	void handleEvents(); 
	void clean(); 
	bool getRunning() const; 

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;
	TextureManager m_textureManager;

	bool m_bRunning;
};

#endif // !_GAME_

