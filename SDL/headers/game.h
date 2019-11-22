#ifndef _GAME_
#define _GAME_

#include <SDL.h>
#include <SDL_surface.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include "textureManager.h"
#include "player.h"
#include "enemy.h"

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
	
	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;

	std::vector<GameObject*> m_gameObjects;

	int m_currentFrame;
	bool m_bRunning;
};

#endif // !_GAME_

