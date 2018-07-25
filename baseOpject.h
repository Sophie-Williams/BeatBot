#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class BaseOpject
{
public:
	BaseOpject();
	~BaseOpject();

	bool LoadImageGame(std::string path, SDL_Renderer* gRenderer);
	void free();
	void setColor(Uint8 red, Uint8 screen, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void SetPos(const int& x, const int& y) { rect_.x = x, rect_.y = y; }
	SDL_Rect GetRect() const { return rect_; }
	void BaseRender(SDL_Renderer* gRenderer, SDL_Rect* clip = NULL);
	SDL_Texture* GetObject() { return mTexture; }

protected:
	SDL_Texture* mTexture;
	SDL_Rect rect_;
	//SDL_Rect Q_skill;
};

