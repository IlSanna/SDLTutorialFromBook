#include "../headers/game.h"

Game* Game::s_pInstance = 0;

Game::Game() {
}

Game::~Game() {
}

bool Game::init(int screenX, int screenY) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init!" << std::endl;
		SDL_CreateWindowAndRenderer(screenX,screenY,0,&m_pWindow,&m_pRenderer);
		SDL_SetRenderDrawColor(m_pRenderer,0, 0, 0, 255);
		
		//load images
		TheTextureManager::Instance()->load("content/caveman.bmp", "animate", m_pRenderer);

		m_gameObjects.push_back(new Player(new LoaderParams( 300, 300, 32, 32, "animate" )));
		m_gameObjects.push_back( new Enemy( new LoaderParams( 150, 150, 32, 32, "animate" ) ) );

		m_bRunning = true;
		return true;
	}
	else {
		m_bRunning = false;
		return false;
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
	for (auto i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}
void Game::render() {
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
	for (auto i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
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

SDL_Renderer* Game::getRenderer() const {
	return m_pRenderer;
}
