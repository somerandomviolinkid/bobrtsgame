#pragma once
#include <chrono>

#include <SDL.h>
#include <SDL_ttf.h>

#include "mathUtil.h"

enum ALIGN {
	LEFT,
	CENTER,
	RIGHT
};

void drawTexture(SDL_Texture* texture, SDL_Renderer* renderer, v2<int> pos, int scale);

void drawText(TTF_Font* font, SDL_Renderer* renderer, std::string content, SDL_Color color, v2<int> pos, ALIGN align, int scale);

typedef void (*fptr)(char*);

class button {
public:
	v2<int> pos;
	fptr function;
	char* fArgs;
	SDL_Color border, fill, text;
	int xPad, yPad, textScale;
	std::string message;
};

void drawBezier(SDL_Renderer* renderer, v2<int> a, v2<int> b, v2<int> c);