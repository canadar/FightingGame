#include "StdAfx.h"
#include "Fighter.h"

#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_native_dialog.h>

const int SCREEN_W = 640;
const int SCREEN_H = 480;

int main (int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_BITMAP *background = NULL;
	ALLEGRO_BITMAP *blue_box = NULL;
	bool key[4] = { false, false, false, false };
	bool doexit = false;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_init_image_addon()) {
		printf("Failed to initialize the image addon");
		return -1;
	}

	if (!al_install_keyboard()) {
		printf("Failed to initialize the keyboard!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}

	// Set up the event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		printf("Failed to create event_queue!\n");
		al_destroy_display(display);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	background = al_load_bitmap("forest.png");
	if (!background) {
		printf("Failed to load background");
		al_destroy_display(display);
		return -1;
	}

	blue_box = al_load_bitmap("BlueBox.png");
	if (!blue_box) {
		printf("Failed to load blueBox");
		al_destroy_bitmap(background);
		al_destroy_display(display);
		return -1;
	}

	//al_draw_bitmap(blue_box, 20, 400, 0);
	Fighter fighter = Fighter(vector_2d(20, 400), vector_2d(0, 0), blue_box);
	
	al_flip_display();

	// Game Loop
	while(true)
	{
		ALLEGRO_EVENT ev;
		al_get_next_event(event_queue, &ev);


		// Update
		fighter.Update(ev);


		// Draw
		al_draw_bitmap(background, 0, 0, 0);
		fighter.Draw();
		al_flip_display();
	}

	fighter.~Fighter();
	al_destroy_bitmap(background);
	al_destroy_display(display);

	return 0;
}
