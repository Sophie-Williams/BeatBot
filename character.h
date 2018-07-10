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
	bool loadCharacter(std::string path, SDL_Renderer* gRenderer, int width_, int height_);
	void showCharacter(std::string path, SDL_Renderer* gRenderer, bool isDead, int x, int y);
private:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
	SDL_Rect Sclip[Frames];
};