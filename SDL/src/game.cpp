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
		
		//load images
		TheTextureManager::Instance()->load("content/caveman.bmp", "animate", m_pRenderer);

		m_go = new GameObject();
		m_player = new Player();
		m_enemy = new Enemy();

		m_go->load(100, 100, 32, 32, "animate");
		m_player->load(300, 300, 32, 32, "animate");
		m_enemy->load( 150, 150, 32, 32, "animate" );

		m_gameObjects.push_back(m_go);
		m_gameObjects.push_back(m_player);
		m_gameObjects.push_back( m_enemy );

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
	for (auto i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}
void Game::render() {
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
	for (auto i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw(m_pRenderer);
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
