#include "../headers/SDLgameObject.h"
#include "../headers/game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) :
	GameObject(pParams), 
	m_position(pParams->getX(), pParams->getY()),
	m_velocity(0,0) {

	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 1;

}
void SDLGameObject::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height,
		m_currentRow, m_currentFrame, TheGame::instance()->getRenderer());
}

void SDLGameObject::update() {
	m_position += m_velocity;
}

void SDLGameObject::clean() {
}
