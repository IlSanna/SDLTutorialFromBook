#pragma once
#include "SDLgameObject.h"

class Player : public SDLGameObject {
public:
	Player( const LoaderParams* pParams );
	virtual void draw();
	virtual void update();
	virtual void clean();
};