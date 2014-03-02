#include "StdAfx.h"
#include "Fighter.h"


Fighter::Fighter(vector_2d pPosition, vector_2d pVelocity, ALLEGRO_BITMAP *pSprite)
{
	mPosition = pPosition;
	mVelocity = pVelocity;
	mGrav_force = vector_2d(0, 3); // Positive to move downwards
	mSprite = pSprite;
	mSpeed = 0.3;
	mKeys[0] = false;
	mKeys[1] = false;
	mKeys[2] = false;
	mKeys[3] = false;
	mJumping = false;
}


Fighter::~Fighter(void)
{
	al_destroy_bitmap(mSprite);
}

void Fighter::Update(ALLEGRO_EVENT ev)
{
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch(ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				mKeys[KEY_UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				mKeys[KEY_DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				mKeys[KEY_LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				mKeys[KEY_RIGHT] = true;
				break;
		}
	}
	else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
		switch(ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				mKeys[KEY_UP] = false;
				break;
 
			case ALLEGRO_KEY_DOWN:
				mKeys[KEY_DOWN] = false;
				break;
 
			case ALLEGRO_KEY_LEFT: 
				mKeys[KEY_LEFT] = false;
				break;
 
			case ALLEGRO_KEY_RIGHT:
				mKeys[KEY_RIGHT] = false;
				break;
		}
	}

	if (mKeys[KEY_RIGHT]) {
		mPosition.x += mSpeed;
	}
	else if (mKeys[KEY_LEFT]) {
		mPosition.x -= mSpeed;
	}

	if (mKeys[KEY_UP]) {
		if (!mJumping) {
			Jump();
		}
	}
	if (mJumping)
	{
		mPosition += mVelocity * 0.03;
		mVelocity += mGrav_force * 0.01;
		if (mPosition.y >= 400) {
			mJumping = false;
		}
	}
}

void Fighter::Draw(void)
{
	al_draw_bitmap(mSprite, mPosition.x, mPosition.y, 0);
}

void Fighter::Jump(void)
{
	mVelocity = vector_2d(0, -20); // Negative to move upwards
	mJumping = true;
}