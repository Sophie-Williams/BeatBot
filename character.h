#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stddef.h>
#include "baseOpject.h"

const int Frames = 4; // defaut

class Character : public BaseOpject
{
public:
	Character();
	~Character();
	bool loadFromFile(std::string path, SDL_Renderer* gRenderer);
	void freeCharacter();
	void render(int x, int y, SDL_Rect* clip, SDL_Renderer* gRenderer);
	bool loadCharacter(std::string path, SDL_Renderer* gRenderer);
	bool setDead(std::string path, SDL_Renderer* gRenderer, int width, int height);
	bool loadCharacter(std::string path, SDL_Renderer* gRenderer, int width_, int height_);
	void showCharacter(std::string path, SDL_Renderer* gRenderer, int x, int y);
	void setDead2(bool dead);
	void checkDead(const SDL_Rect & rect_player, std::string path, SDL_Renderer * gRenderer, int w_, int h_);
private:
	//SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
	bool isDead;
	SDL_Rect Sclip[Frames];
};