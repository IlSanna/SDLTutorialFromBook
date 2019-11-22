#include "../headers/player.h"

Player::Player( const LoaderParams* pParams ) : SDLGameObject( pParams ) {

}
void Player::draw() {
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update() {
	SDLGameObject::update();
	//m_position.setX(m_position.getX()+1);
	m_velocity.setX(1);
	m_currentFrame = int( ((SDL_GetTicks() / 100) % 4) );
}
void Player::clean() {
}