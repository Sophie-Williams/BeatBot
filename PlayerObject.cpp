
#include "PlayerObject.h"



const int PLAYER_WIDTH = 30;
const int PLAYER_HEIGHT = 45;


PlayerObject::PlayerObject()
{
	frame_ = 0;
	x_val_ = 0;
	y_val_ = 0;
	status_ = -1;
	is_check_q_ = false;
}


PlayerObject::~PlayerObject()
{
	// 
}

void PlayerObject::Show(SDL_Renderer* screen)
{
	if (status_ == 8)
	{
		for (int i = 0; i < 4; i++)
		{
			SDL_Rect* currentClip = &right_clip_[i];
			BaseRender(screen, currentClip);
		}
		status_ = 0;
		LoadImageGame("nhanvat/player3.png", screen);
		set_clips();
	}
	else
	{
		if (status_ != -1)
		{
			frame_++;
		}
		else
		{
			frame_ = 0;
		}

		if (frame_ >= 4)
		{
			frame_ = 0;
		}

		SDL_Rect* currentClip = &right_clip_[frame_];
		BaseRender(screen, currentClip);
	}
	
}

void PlayerObject::Move()
{
	if (x_val_ != 0)
	{
		if (rect_.x + x_val_ >= SCREEN_WIDTH)
		{
			rect_.x = SCREEN_WIDTH - rect_.w;
			x_val_ = 0;
		}

		if (rect_.x < 0)
		{
			rect_.x = 0;
			x_val_ = 0;
		}

		rect_.x += x_val_;
	}
	
	if (y_val_ != 0)
	{

		if (rect_.y + y_val_ >= SCREEN_HEIGHT)
		{
			rect_.y = SCREEN_HEIGHT - rect_.h;
			y_val_ = 0;
		}

		if (rect_.y < 0)
		{
			rect_.y = 0;
			y_val_ = 0;
		}

		rect_.y += y_val_;
	}
	
	// to do
}


void PlayerObject::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
{
	if (events.type == SDL_KEYDOWN) // am
	{
		switch (events.key.keysym.sym)
		{
			case SDLK_RIGHT:
			{
				status_ = 0;
				x_val_ = 10;
				break;
			}
			case SDLK_LEFT:
			{
				status_ = 1;
				x_val_ = -10;
				break;
			}
			case SDLK_UP:
			{
				status_ = 2;
				y_val_= -10;
				break;
			}
			case SDLK_DOWN:
			{
				status_ = 3;
				y_val_ = 10;
				break;
			}
			case 113:
			{
				LoadImageGame("nhanvat/main_skill.png", screen);
				set_clips2();
				is_check_q_ = true;
				//this->Q_skill = rect_;
				status_ = 8; // Press Q
				break;
			}
		}
	}


	else if (events.type == SDL_KEYUP)
	{

		switch (events.key.keysym.sym)
		{
			status_ = -1;
			case SDLK_RIGHT:
			case SDLK_LEFT:
			{
				x_val_ = 0;
				break;
			}
			case SDLK_UP:
			case SDLK_DOWN:
			{
				y_val_ = 0;
				break;
			}
		}
	}
}

void PlayerObject::set_clips()
{
	//Clip the sprites
	right_clip_[0].x = 0;            
	right_clip_[0].y = 0;               
	right_clip_[0].w = PLAYER_WIDTH;
	right_clip_[0].h = PLAYER_HEIGHT;

	right_clip_[1].x = PLAYER_WIDTH;
	right_clip_[1].y = 0;            
	right_clip_[1].w = PLAYER_WIDTH;  
	right_clip_[1].h = PLAYER_HEIGHT;
	    
	right_clip_[2].x = PLAYER_WIDTH * 2;
	right_clip_[2].y = 0;              
	right_clip_[2].w = PLAYER_WIDTH;   
	right_clip_[2].h = PLAYER_HEIGHT;   
	                                         
	right_clip_[3].x = PLAYER_WIDTH * 3;
	right_clip_[3].y = 0;                  
	right_clip_[3].w = PLAYER_WIDTH;    
	right_clip_[3].h = PLAYER_HEIGHT;    
}

void PlayerObject::set_clips2()
{
	//Ensure that, LoadImage Function must be called before
	int width_ = rect_.w/4;
	int height_ = rect_.h;

	if (width_ > 0 && height_ > 0)
	{
		right_clip_[0].x = 0;
		right_clip_[0].y = 0;
		right_clip_[0].w = width_;
		right_clip_[0].h = height_;

		right_clip_[1].x = width_;
		right_clip_[1].y = 0;
		right_clip_[1].w = width_;
		right_clip_[1].h = height_;

		right_clip_[2].x = width_ * 2;
		right_clip_[2].y = 0;
		right_clip_[2].w = width_;
		right_clip_[2].h = height_;

		right_clip_[3].x = width_ * 3;
		right_clip_[3].y = 0;
		right_clip_[3].w = width_;
		right_clip_[3].h = height_;
	}
}