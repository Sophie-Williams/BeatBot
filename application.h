#pragma once

#include"commonFunc.h"
#include "baseOpject.h"
#include "character.h"
#include "PlayerObject.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "text.h"

class Application
{
public:
	Application();
	~Application();

	// close application
	void close();
	bool init();
	void run();
	void checkDead();


private:


	SDL_Event app_event_;
	SDL_Renderer* app_renderer_;
	SDL_Window* app_window_;
	TTF_Font *app_font;

	/////

	BaseOpject app_background_;
	BaseOpject Menu;
	BaseOpject app_bag1; // bag 1
	Character app_satan_; // bot satan 1
	Character app_satan_1; // bot satan 2
	Character app_fire_; // fire 1
	PlayerObject app_player_; // main main player
	Character app_soi_; // 
	//PlayerObject soi_;

	// text ............

	Text text[10];

};
