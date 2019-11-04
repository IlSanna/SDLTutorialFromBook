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

		TheTextureManager::Instance()->load("content/caveman.bmp", "animate", m_pRenderer);
		//m_textureManager.load("content/caveman.bmp", "animate", m_pRenderer);

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

void Game::update() {//missing elapsed time
	m_currentFrame = int((SDL_GetTicks() / 100) % 4);
	std::cout << m_currentFrame << std::endl;
}
void Game::render() {
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
	TheTextureManager::Instance()->draw("animate", 0, 0, 32, 32, m_pRenderer);
	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 32, 32, 1,m_currentFrame,m_pRenderer);
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
