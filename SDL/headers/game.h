#ifndef _GAME_
#define _GAME_

#include <SDL.h>
#include <SDL_surface.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

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

	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle; // the first rectangle
	SDL_Rect m_destinationRectangle; // another rectangle

	bool m_bRunning;
};

#endif // !_GAME_

