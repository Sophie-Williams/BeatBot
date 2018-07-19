#include "commonFunc.h"
#include <SDL_mixer.h>



/*
bool  SDLCommonFunc::loadMusic()
{
	bool success = true;

	//Load music
	app_music_menu = Mix_LoadMUS("music/Action.mid");

	if (app_music_menu == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	//Load sound effects

	selectSound = Mix_LoadWAV("music/select.wav");
	if (selectSound == NULL)
	{
		printf("Failed to load select sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	satanDead = Mix_LoadWAV("music/satanDead.wav");
	if (satanDead == NULL)
	{
		printf("Failed to load satan dead sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}


	gScratch = Mix_LoadWAV("music/scratch.wav");
	if (gScratch == NULL)
	{
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gHigh = Mix_LoadWAV("music/high.wav");
	if (gHigh == NULL)
	{
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gMedium = Mix_LoadWAV("music/medium.wav");
	if (gMedium == NULL)
	{
		printf("Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gLow = Mix_LoadWAV("music/low.wav");
	if (gLow == NULL)
	{
		printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	return success;
}

*/