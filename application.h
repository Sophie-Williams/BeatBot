#pragma once

#include"commonFunc.h"
#include "baseOpject.h"
#include "character.h"
#include "PlayerObject.h"

class Application
{
public:
	Application();
	~Application();

	// close application
	void close();
	bool init();
	void run();


private:
	SDL_Event app_event_;
	SDL_Renderer* app_renderer_;
	SDL_Window* app_window_;
	BaseOpject app_background_;
	Character app_satan_;
	Character app_fire_;
	PlayerObject app_player_;
	Character app_soi_;
	//PlayerObject soi_;
};
