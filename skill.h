#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "baseOpject.h"

class Skill : public BaseOpject
{
public:
	enum SkillType
	{
		NONE,
		LIGHTNING,
		FIRE
	};
	Skill();
	~Skill();
	void HandleInputAction(SDL_Event event_, SDL_Rect rect_opject);
	void HandleMove(const int x_boder, const int y_border);
	int get_type() { return skill_type; }
	void set_tyoe(const int skill_type_) { skill_type = skill_type_; }
	int get_move() { return is_move; }
	void set_move(bool is_move_) { is_move = is_move_; }
	void set_size_frame(const int w, const int h);


private:
	int frameWidth;
	int frameHeight;
	int x_val;
	int y_val;
	bool is_move;
	int skill_type;
};
