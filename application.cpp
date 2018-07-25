

#include "application.h"
#include "commonFunc.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <cmath>
#include <SDL_mixer.h>
#include <vector>
#include <stdio.h>

#define nBOT = 5

//The music that will be played

Application::Application()
{
	app_renderer_ = NULL;
	app_window_ = NULL;

	
	//The music that will be played
	app_music_menu = NULL;
	gameBackground = NULL;
	selectSound = NULL;
	gScratch = NULL;
	gHigh = NULL;
	gMedium = NULL;
	gLow = NULL;
	satanDead = NULL;
	
}
Application::~Application()
{
	// todo
}


bool Application::init()
{
	bool success = false;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return false;
	}

	this->app_window_ = SDL_CreateWindow("UET", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (app_window_ != NULL)
	{
		//Create renderer for window
		app_renderer_ = SDL_CreateRenderer(app_window_, -1, SDL_RENDERER_ACCELERATED);
		if (app_renderer_ != NULL)
		{
			//Initialize renderer color
			SDL_SetRenderDrawColor(app_renderer_, 0xFF, 0xFF, 0xFF, 0xFF);

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;

			success = true;

			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}

			//Initialize SDL_ttf font
			if ( TTF_Init() == -1)
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				success = false;
			}
			/// intialize misic
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			{
				printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
				success = false;
			}

		}
	}
	return success;
}


void Application::close()
{
	SDL_DestroyWindow(this->app_window_);
	this->app_window_ = NULL;

	SDL_DestroyRenderer(this->app_renderer_);
	this->app_renderer_ = NULL;
}

void Application::run()
{
	if (!this->init())
	{
		printf("could not init application \n");
		return;
	}


	//Clear screen
	


	///// testing load bot in vector


	if (!initBot())
	{
		printf("could not init bot \n");
		return;
	}
	loadBot();


	/// end
	// opject tinh
	app_background_.SetPos(0, 0);

	if (!app_background_.LoadImageGame("image/bg.png", app_renderer_))
	{
		printf("could not load opject \n");
		return;
	}
	
	/*
	if (!app_soi_.loadCharacter("image/cho_soi.png", app_renderer_,64,33))
	{
		std::cout << "Load cho soi failed";
		return;
	}
	*/
	hell.SetPos(180, 180);
	if (!hell.loadCharacter("image/hell.png", app_renderer_, 50, 30))
	{
		std::cout << "Load cho soi failed";
		return;
	}

	//Create Player
	app_player_.LoadImageGame("image/player3.png", app_renderer_);
	app_player_.SetPos(350, 480);
	app_player_.set_clips();

	// load menu

	Menu.SetPos(0, 0);
	Menu.LoadImageGame("image/menu.png", app_renderer_);

	loadText();
	loadMusic();

	bool is_quit = false;
	

	/////////////////////// game menu

	while (!is_quit)
	{

		if (Mix_PlayingMusic() == 0)
		{
			//Play the music
			if (Mix_PlayMusic(app_music_menu, -1) == -1)
			{
				return;
			}
		}
		
		while (SDL_PollEvent(&app_event_) != 0)
		{

			//User requests quit
			if (app_event_.type == SDL_QUIT)
			{
				is_quit = true;
			}
			else if (app_event_.type == SDL_MOUSEBUTTONDOWN)
			{
				Mix_PlayChannel(-1, selectSound, 0);
				is_quit = true;
			}

		}

		SDL_SetRenderDrawColor(app_renderer_,
			RENDER_DRAW_COLOR,
			RENDER_DRAW_COLOR,
			RENDER_DRAW_COLOR,
			RENDER_DRAW_COLOR);
		SDL_RenderClear(app_renderer_);

		Menu.BaseRender(app_renderer_ );

		/// top

		
		text[0].render(app_renderer_, 250, 50, NULL, 0.0, NULL, SDL_FLIP_NONE);

		
		text[6].render(app_renderer_, 250, 70, NULL, 0.0, NULL, SDL_FLIP_NONE);



	
		text[4].render(app_renderer_, 100, 50, NULL, 0.0, NULL, SDL_FLIP_NONE);

		text[7].render(app_renderer_, 100, 70, NULL, 0.0, NULL, SDL_FLIP_NONE);


	
		text[5].render(app_renderer_, 480, 50, NULL, 0.0, NULL, SDL_FLIP_NONE);
	
		text[8].render(app_renderer_, 480, 70, NULL, 0.0, NULL, SDL_FLIP_NONE);


		///// logo in here

	
		text[9].render(app_renderer_, 220, 210, NULL, 0.0, NULL, SDL_FLIP_NONE);

		hell.showCharacter(app_renderer_);


		// conten


		text[1].render(app_renderer_, 250, 330, NULL, 0.0, NULL, SDL_FLIP_NONE);


		text[2].render(app_renderer_, 250, 360, NULL, 0.0, NULL, SDL_FLIP_NONE);
		///

		/// bottom


		text[3].render(app_renderer_, 220, 530, NULL, 0.0, NULL, SDL_FLIP_NONE);
		SDL_RenderPresent(app_renderer_);
	}


	is_quit = false;

	/// pause backgound menu game
	Mix_PauseMusic();
	/// end

	//////////////////////// game running
	
	while (!is_quit)
	{
		while (SDL_PollEvent(&app_event_) != 0)
		{
			//User requests quit
			if (app_event_.type == SDL_QUIT)
			{
				is_quit = true;
			}

			app_player_.HandleInputAction(app_event_, app_renderer_,walk, skill);
		}


		// Reset and clear
		SDL_SetRenderDrawColor(app_renderer_, 
							   RENDER_DRAW_COLOR, 
							   RENDER_DRAW_COLOR,
							   RENDER_DRAW_COLOR,
							   RENDER_DRAW_COLOR);
		SDL_RenderClear(app_renderer_);




		//Show background
		app_background_.BaseRender(app_renderer_);

		// new bot in vector
		 
		// info player

		text[11].loadText(app_font, std::to_string( app_player_.getScore() ) , app_renderer_, 25, 225, 255, 255);
		text[11].render(app_renderer_, 600, 530, NULL, 0.0, NULL, SDL_FLIP_NONE);

		/// end
		for (int i = 0; i < bot_list_.size(); ++i)
		{
			bot_list_.at(i)->showCharacter(app_renderer_);
		}

		for (int i = 0; i < item_list_.size(); ++i)
		{
			item_list_.at(i)->BaseRender(app_renderer_);
		}
		//bot_list_[0]->showCharacter(app_renderer_, 120, 260);
		//bot_list_[1]->showCharacter(app_renderer_, 260 , 130);
		//bot_list_[2]->showCharacter(app_renderer_, 170 , 90);
		//bot_list_[3]->showCharacter(app_renderer_, 130, 445);
		//bot_list_[4]->showCharacter(app_renderer_, 260, 280);

		


		app_player_.Move();
		
		app_player_.Show(app_renderer_);

		/* test position */

		SDL_Rect temp = app_player_.GetRect();
		printf("toa do player: %d %d \n", temp.x, temp.y); 


		checkDead();

		SDL_RenderPresent(app_renderer_);

		is_quit = app_player_.isDead();
	}




	//////////////////////// game over

	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		if (Mix_PlayMusic(app_music_menu, -1) == -1)
		{
			return;
		}
	}

	SDL_SetRenderDrawColor(app_renderer_,
		RENDER_DRAW_COLOR,
		RENDER_DRAW_COLOR,
		RENDER_DRAW_COLOR,
		RENDER_DRAW_COLOR);
	SDL_RenderClear(app_renderer_);

	/*Menu.BaseRender(app_renderer_);
	text[10].render(app_renderer_, 250, 50, NULL, 0.0, NULL, SDL_FLIP_NONE);*/

	is_quit = false;

	while (!is_quit)
	{

		while (SDL_PollEvent(&app_event_) != 0)
		{
			//User requests quit
			if (app_event_.type == SDL_QUIT)
			{
				is_quit = true;
			}
		}

		bool is_dead = app_player_.isDead();
		if (is_dead == true)
		{
			Menu.BaseRender(app_renderer_);
			text[10].render(app_renderer_, 250, 50, NULL, 0.0, NULL, SDL_FLIP_NONE);
			SDL_RenderPresent(app_renderer_);

		}
	}
	close();
}

void Application::checkDead()
{
	bool is_check_q = app_player_.get_check_q();

	if (is_check_q)
	{

		for (int i = 0; i < bot_list_.size(); ++i)
		{

			bot_list_.at(i)->checkDead(app_player_, "image/quy_dead.png", app_renderer_, 45, 30);
			if (bot_list_.at(i)->GetIsDead() == true)
			{
				bot_list_.erase(bot_list_.begin() + i);
			}
		}

		app_player_.set_check_q(false);
	}

	return;
}

void Application::loadText()
{
	text[0].loadText(app_font, "HI-SCORE", app_renderer_, 25, 255, 0, 0);

	text[6].loadText(app_font, "0000", app_renderer_, 25, 255, 255, 255);

	text[4].loadText(app_font, "1UP", app_renderer_, 25, 255, 0, 0);

	text[7].loadText(app_font, "00", app_renderer_, 25, 225, 255, 255);


	text[5].loadText(app_font, "2UP", app_renderer_, 25, 255, 0, 0);
	
	text[8].loadText(app_font, "00", app_renderer_, 25, 225, 255, 255);
	


	///// logo in here

	text[9].loadText(app_font, "Game Logo", app_renderer_, 40, 253, 254, 254);
	text[10].loadText(app_font, "Game Over", app_renderer_, 40, 253, 254, 254);


	// conten

	text[1].loadText(app_font, "PlayGame", app_renderer_, 30, 253, 254, 254);
	

	text[2].loadText(app_font, "Exit", app_renderer_, 30, 253, 254, 254);


	text[3].loadText(app_font, "© Summer 2018 Vuong Xuan", app_renderer_, 18, 253, 254, 254);
	
	//text[11].loadText(app_font,"")

}




bool Application::loadMusic()
{
	bool success = true;

	//Load music
	app_music_menu = Mix_LoadMUS("music/loadmenu.wav");

	if (app_music_menu == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	//Load sound effects
	selectSound = Mix_LoadWAV("music/select.wav");
	if (selectSound == NULL)
	{
		printf("Failed to load  selectSound sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	satanDead = Mix_LoadWAV("music/satanDead.wav");
	if (satanDead == NULL)
	{
		printf("Failed to load satan dead sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	
	walk = Mix_LoadWAV("music/walk.wav");
	if (walk == NULL)
	{
		printf("Failed to load walk sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	skill = Mix_LoadWAV("music/skill.wav");
	if (skill == NULL)
	{
		printf("Failed to load skill sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	return success;
}



bool Application::initBot()
{
	/// bot
	BaseOpject* item1 = new BaseOpject(); // binh hp 1
	item1->SetPos(200, 400);

	item_list_.push_back(item1);

	Character* bot1 = new Character(260, 130);

	Character* bot2 = new Character(170, 90);

	Character* bot3 = new Character(130, 445);

	Character* bot4 = new Character(490, 310);

	Character* bot5 = new Character(20, 200);

	bot_list_.push_back(bot1);
	bot_list_.push_back(bot2);
	bot_list_.push_back(bot3);
	bot_list_.push_back(bot4);
	bot_list_.push_back(bot5);


	return true;
}

void Application::loadBot()
{ 


	/// load bot
	if (!bot_list_[0]->loadCharacter("image/quy.png", app_renderer_))
	{
		printf("load bot eror \n");
		return;
	}
	if (!bot_list_[1]->loadCharacter("image/chem.png", app_renderer_,25,30))
	{
		printf("load bot eror \n");
		return;
	}

	if (!bot_list_[2]->loadCharacter("image/lemda.png", app_renderer_,25,30))
	{
		printf("load bot eror \n");
		return;
	}
	
	if (!bot_list_[3]->loadCharacter("image/bancung.png", app_renderer_, 30, 30))
	{
		printf("load bot eror \n");
		return;
	}
	if (!bot_list_[4]->loadCharacter("image/cho_soi.png", app_renderer_, 64, 33))
	{
		printf("load bot eror \n");
		return;
	}


	if (!item_list_[0]->LoadImageGame("image/hp.png", app_renderer_))
	{
		printf("can't not load item 1 \n");
		return;
	}



}
