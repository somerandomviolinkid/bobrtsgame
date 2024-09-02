#pragma once
#include <vector>
#include <filesystem>
#include <string>
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "mathUtil.h"

class state {
public:

	SDL_Window* window;
	SDL_Renderer* renderer;

	std::vector<SDL_Texture*> textures;
	std::vector<TTF_Font*> fonts;
	std::vector<Mix_Music*> musics;
	std::vector<Mix_Chunk*> sounds;

	v2<int> windowRes, windowPos;

	bool running;

	void freeTextures();
	void freeFonts();
	void freeMusics();
	void freeSounds();
	void freeAssets();

	void loadTextures();
	void loadFonts();
	void loadMusics();
	void loadSounds();
	void loadAssets();

	void handleEvents();

	state(v2<int> windowRes, v2<int> windowPos, int audioFreq, int audioBufferSize);
	~state();
};