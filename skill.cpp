#include "skill.h"
#include <SDL.h>
#include <SDL_image.h>
#include "baseOpject.h"


Skill::Skill()
{
	x_val = 0;
	y_val = 0;
	is_move = false;
	skill_type = -1;
	frameWidth = 30;
	frameHeight = 45;
}

Skill::~Skill()
{
	// to do
}

void Skill::HandleInputAction(SDL_Event event_, SDL_Rect rect_opject)
{
	// to do
}

void Skill::HandleMove(const int x_boder, const int y_border)
{
	// todo
}

void Skill::set_size_frame(const int w, const int h)
{
	frameWidth = w;
	frameHeight = h;
}





