#include "baseOpject.h"
#include <SDL_image.h>
#include <SDL.h>
#include <string>
#include <stdio.h>
#include <stddef.h>


BaseOpject::BaseOpject()
{
	this->mTexture = NULL;
	rect_.w = 0;
	rect_.h = 0;
}

BaseOpject::~BaseOpject()
{
	free();
}

void BaseOpject::free()
{
	if (mTexture != NULL)
	{
		mTexture = NULL;
		rect_.w = 0;
		rect_.h = 0;
	}
}

void BaseOpject::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void BaseOpject::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void BaseOpject::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void BaseOpject::BaseRender(SDL_Renderer* gRenderer, SDL_Rect* clip /*=NULL*/)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { rect_.x, rect_.y, rect_.w, rect_.h };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}


bool BaseOpject::LoadImageGame(std::string path, SDL_Renderer* gRenderer)
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface != NULL)
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 80, 80, 80));

		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture != NULL)
		{
			rect_.w = loadedSurface->w;
			rect_.h = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}
