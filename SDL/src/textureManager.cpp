#include "../headers/textureManager.h"

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer * pRenderer) {

	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture) {//this is not optimal because can load the same texture twice
		m_textureMap[id] = pTexture;
		return true;
	}
	return false;
}
//draw a single sprite
void TextureManager::draw(std::string id, int x, int y, int width, int height,
	SDL_Renderer * pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
//draw an animation
void TextureManager::drawFrame(std::string id, int x, int y, int width, int height,
	int currentRow, int currentFrame, SDL_Renderer * pRenderer, SDL_RendererFlip flip) {

	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
