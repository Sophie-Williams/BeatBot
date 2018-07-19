#pragma once

#include"commonFunc.h"
#include "baseOpject.h"
#include "character.h"
#include "PlayerObject.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "text.h"
#include <SDL_mixer.h>
#include <vector>


class Application
{
public:
	Application();
	~Application();

	// close application
	void close();
	bool init();
	//bool LoadBot();
	bool loadMusic();
	void run();
	bool initBot();
	void loadBot();
	void checkDead();


private:

	SDL_Event app_event_;
	SDL_Renderer* app_renderer_;
	SDL_Window* app_window_;
	TTF_Font *app_font;


	BaseOpject app_background_;
	BaseOpject Menu;
	Character hell;



	
	//The music that will be played
	Mix_Music *app_music_menu;
	Mix_Music *gameBackground;

	//The sound effects
	Mix_Chunk *selectSound;
	Mix_Chunk *gScratch;
	Mix_Chunk *gHigh ;
	Mix_Chunk *gMedium ;
	Mix_Chunk *gLow;
	Mix_Chunk *satanDead;
	Mix_Chunk *walk;
	Mix_Chunk *skill;

	
	Character app_soi_; 
	

	PlayerObject app_player_; // main main player


	///// test list

	std::vector<Character*> bot_list_;



	/////////////// item

	BaseOpject item[10];

	//////////////////

	//PlayerObject soi_;

	// text ............

	Text text[10];

};
