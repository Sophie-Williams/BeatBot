

#ifndef PLAYER_OBJECT_H_
#define PLAYER_OBJECT_H_

#include "commonFunc.h"
#include "baseOpject.h"
#include "skill.h"
#include <SDL_mixer.h>
class PlayerObject : public BaseOpject
{
public:
	PlayerObject();
	~PlayerObject();
	void Show(SDL_Renderer* screen);
	void HandleInputAction(SDL_Event events, SDL_Renderer* screen, Mix_Chunk* walk, Mix_Chunk* skill);
	void Move();
	void set_clips();
	void set_clips2();
	bool get_check_q() const { return  is_check_q_; }
	void set_check_q(bool cq) { is_check_q_ = cq; }
	void setHP(int hp_) { hp = hp_; }
	int getHP() { return hp; }
	bool isDead() { return playerDead; }
	void setDead() { playerDead = true; }
	void addScore() { score += 1; }
	int getScore() { return score; }
private:
	int frame_;
	int x_val_; 
	int y_val_;
	int status_;
	int hp;
	int mana;
	SDL_Rect right_clip_[4];
	SDL_Rect left_clip_[4];
	Skill Lightning_q;
	bool is_check_q_;
	bool playerDead;
	int score;
	//SDL_Rect Skill_lightning[4];

};


#endif // PLAYER_OBJECT_H_
