#pragma once
#include "baseOpject.h"
#include <string>
#include <SDL_ttf.h>

class Text : public BaseOpject
{
public:
	Text();
	~Text();
	void free();
	// load images game
	bool loadFromRenderedText(std::string textureText, SDL_Renderer *app_renderer, 
		TTF_Font *gFont, SDL_Color textColor);
	void render(SDL_Renderer* app_renderer, int x, int y, SDL_Rect* clip , double angle , SDL_Point* center ,
		SDL_RendererFlip flip);
	bool loadText(TTF_Font *gFont, std::string textToLoad, SDL_Renderer* app_renderer, int size, int red, int green, int blue);
	void close();
private:
	int mWidth;
	int mHeight;
};