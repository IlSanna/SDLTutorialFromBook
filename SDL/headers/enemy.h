#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "gameobject.h"

class Enemy : public GameObject {
public:
	void update(){
		GameObject::update();
		m_y += 1;
		m_x += 1;
	}
};
#endif // !_ENEMY_H_
