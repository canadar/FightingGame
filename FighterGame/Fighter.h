#pragma once
#include "vector_2d.h"

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

class Fighter
{
private:
	vector_2d mPosition;
	vector_2d mVelocity;
	vector_2d mGrav_force;
	ALLEGRO_BITMAP *mSprite;
	float mSpeed;
	bool mKeys[4];
	bool mJumping;

	void Jump();

public:
	Fighter(vector_2d pPosition, vector_2d pVelocity, ALLEGRO_BITMAP *pSprite);
	~Fighter(void);
	void Update(ALLEGRO_EVENT ev);
	void Draw();
};

