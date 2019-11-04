#include "../headers/player.h"


void Player::update() {
	m_x -= 1;
}

void Player::draw(SDL_Renderer* pRenderer) {
	GameObject::draw(pRenderer);
}