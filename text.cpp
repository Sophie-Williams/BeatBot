#include "text.h"


Text::Text()
{
	mWidth = 0;
	mHeight = 0;
}

Text::~Text()
{
	// to do
}

void Text::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}


bool Text::loadFromRenderedText(std::string textureText, SDL_Renderer *app_renderer,
	TTF_Font *app_font, SDL_Color textColor)
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(app_font, textureText.c_str(), textColor);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(app_renderer, textSurface);
		if (mTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	//Return success
	return mTexture != NULL;
}


void Text::render(SDL_Renderer* app_renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL,
	SDL_RendererFlip flip = SDL_FLIP_NONE)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(app_renderer, mTexture, clip, &renderQuad, angle, center, flip);
}

bool Text::loadText(TTF_Font *gFont, std::string textToLoad, SDL_Renderer* app_renderer ,int size, int red, int green, int blue)
{
	//Loading success flag
	bool success = true;

	//Open the font
	gFont = TTF_OpenFont("pixel.ttf", size);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		//Render text
		SDL_Color textColor = { red, green, blue }; // default
		if (!this->loadFromRenderedText(textToLoad,app_renderer,gFont, textColor ))
		{
			printf("Failed to render text texture!\n");
			success = false;
		}
	}

	return success;
}

void Text::close()
{
	// to do
}

