#pragma once
#include <SDL.h>
#include <SDL_surface.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include "textureManager.h"
#include "loaderParams.h"
#include "gameobject.h"
#include "player.h"
#include "enemy.h"

class Game {
public:
	static Game* instance() {
		if ( s_pInstance == 0 ) {
			s_pInstance = new Game();
			return s_pInstance;
		} else {
			return s_pInstance;
		}
	}
	
	~Game();

	bool init(int screenX,int screenY); 
	void render(); 
	void update();
	void handleEvents(); 
	void clean(); 

	bool getRunning() const; 
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	Game();
	static Game* s_pInstance;

	std::vector<GameObject*> m_gameObjects;

	int m_currentFrame;
	bool m_bRunning;
};
typedef Game TheGame;


