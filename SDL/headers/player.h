#pragma once
#include "gameobject.h"

class Player : public GameObject {
public:
	using GameObject::GameObject;
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
};