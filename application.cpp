

#include "application.h"
#include "commonFunc.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <cmath>


Application::Application()
{
	app_renderer_ = NULL;
	app_window_ = NULL;
	app_font = NULL;
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

			//Initialize SDL_ttf
			if ( TTF_Init() == -1)
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
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


	/// testing text

	test.loadText(app_font, "vuong xuan", app_renderer_, 50,253,254,254);


	/// end testing text



	//Clear screen
	
	// opject tinh
	app_background_.SetPos(0, -587);
	app_bag1.SetPos(420,320);
	if (!app_background_.LoadImageGame("map2.png", app_renderer_))
	{
		printf("could not load opject \n");
		return;
	}
	if (!app_bag1.LoadImageGame("nhanvat/bag.png", app_renderer_))
	{
		printf("coult not load bag1 \n");
		return;
	}
	if (!app_satan_.loadCharacter("quy.png", app_renderer_))
	{
		std::cout << "Load bot failed";
		return;
	}
	if (!app_satan_1.loadCharacter("quy1.png", app_renderer_,30,45))
	{
		std::cout << "Load bot? failed";
		return;
	}
	
	if (!app_fire_.loadCharacter("nhanvat/lua2.png", app_renderer_))
	{	
		std::cout << "Load lua failed";
		return;
	}

	if (!app_soi_.loadCharacter("nhanvat/cho_soi.png", app_renderer_,64,33))
	{
		std::cout << "Load cho soi failed";
		return;
	}

	//Create Player
	app_player_.LoadImageGame("nhanvat/player3.png", app_renderer_);
	app_player_.SetPos(290, 480);
	app_player_.set_clips();


	bool is_quit = false;
	
	while (!is_quit)
	{
		while (SDL_PollEvent(&app_event_) != 0)
		{
			//User requests quit
			if (app_event_.type == SDL_QUIT)
			{
				is_quit = true;
			}

			app_player_.HandleInputAction(app_event_, app_renderer_);
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
		app_bag1.BaseRender(app_renderer_);


		test.render(app_renderer_, 290, 480, NULL, 0.0, NULL, SDL_FLIP_NONE);

		//Show bot
		app_satan_.showCharacter("quy.png", app_renderer_,120,260);
		app_satan_1.showCharacter("quy1.png", app_renderer_, 290, 20);
		app_fire_.showCharacter("nhanvat/lua2.png", app_renderer_,350,470);
		app_soi_.showCharacter("nhanvat/cho_soi.png", app_renderer_, 220, 80);
		


		app_player_.Move();
		
		app_player_.Show(app_renderer_);

		/* test position */

		SDL_Rect temp = app_player_.GetRect();
		printf("%d %d \n", temp.x, temp.y); 


		checkDead();

		SDL_RenderPresent(app_renderer_);
	}

	close();
}

void Application::checkDead()
{
	bool is_check_q = app_player_.get_check_q();

	if (is_check_q)
	{
		SDL_Rect rect_player = app_player_.GetRect();
		printf("qskill: %d %d \n", rect_player.x, rect_player.y);
		app_satan_.checkDead(rect_player, "nhanvat/quy_dead.png", app_renderer_, 45, 30);

		app_player_.set_check_q(false);
	}
	return;
}
