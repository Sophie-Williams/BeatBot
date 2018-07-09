#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stddef.h>

const int Frames = 4; // defaut

class Character
{
public:
	Character();
	~Character();
	bool loadFromFile(std::string path, SDL_Renderer* gRenderer);
	void free();
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void render(int x, int y, SDL_Rect* clip, SDL_Renderer* gRenderer);
	int getWidth();
	int getHeight();
	bool loadCharacter(std::string path, SDL_Renderer* gRenderer);
	bool loadCharacter(std::string path, SDL_Renderer* gRenderer, int width_, int height_);
	void showCharacter(std::string path, SDL_Renderer* gRenderer, bool isDead, int x, int y);
private:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
	SDL_Rect Sclip[Frames];
};