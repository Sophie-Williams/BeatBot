

#ifndef PLAYER_OBJECT_H_
#define PLAYER_OBJECT_H_

#include "commonFunc.h"
#include "baseOpject.h"
#include "skill.h"

class PlayerObject : public BaseOpject
{
public:
	PlayerObject();
	~PlayerObject();
	void Show(SDL_Renderer* screen);
	void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
	void Move();
	void set_clips();
	void set_clips2();
	bool get_check_q() const { return  is_check_q_; }
	void set_check_q(bool cq) { is_check_q_ = cq; }
private:
	int frame_;
	int x_val_; 
	int y_val_;

	int status_;
	SDL_Rect right_clip_[4];
	Skill Lightning_q;
	bool is_check_q_;
	//SDL_Rect Skill_lightning[4];

};


#endif // PLAYER_OBJECT_H_
