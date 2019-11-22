#include "../headers/player.h"


void Player::update() {
	GameObject::update();
	m_x -= 1;
}
