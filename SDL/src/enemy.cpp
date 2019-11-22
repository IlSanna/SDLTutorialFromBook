#include "../headers/enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {

}
void Enemy::draw() {
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update() {
	SDLGameObject::update();
	//m_position.setX(m_position.getX() - 1);
	m_velocity.setX(-1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}
void Enemy::clean() {
}