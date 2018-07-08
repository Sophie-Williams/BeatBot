

#ifndef PLAYER_OBJECT_H_
#define PLAYER_OBJECT_H_
#include "commonFunc.h"
#include "baseOpject.h"

class PlayerObject : public BaseOpject
{
public:
	PlayerObject();
	~PlayerObject();

	void Show(SDL_Renderer* screen);
	void HandleInputAction(SDL_Event);
	void Move();
	void set_clips();
private:
	int frame_;
	int x_val_; 
	int y_val_;

	int status_;
	SDL_Rect right_clip_[4];

};


#endif // PLAYER_OBJECT_H_
