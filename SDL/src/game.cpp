#include "../headers/game.h"

Game::Game() {
}

Game::~Game() {
}

void Game::init(int screenX, int screenY) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init!" << std::endl;
		SDL_CreateWindowAndRenderer(screenX,screenY,0,&m_pWindow,&m_pRenderer);
		SDL_SetRenderDrawColor(m_pRenderer,0, 0, 0, 255);

		std::string path = "content/caveman.bmp";
		SDL_Surface* pTempSurface = IMG_Load(path.c_str());
		if (!pTempSurface) {
			std::cout << "failed to load the texture" << std::endl;
		}
		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,pTempSurface);
		SDL_FreeSurface(pTempSurface);
		
		//Querying the texture will allow us to set the width and height of our source rectangle to the exact dimensions needed
		m_sourceRectangle.w = 32;
		m_sourceRectangle.h = 32;
		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;
		

		m_bRunning = true;
	}
	else {
		m_bRunning = false;
	}
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::update() {
	m_sourceRectangle.x = 32 * int((SDL_GetTicks() / 100) % 4);
}
void Game::render() {
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean() {
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

bool Game::getRunning() const {
	return m_bRunning;
}
