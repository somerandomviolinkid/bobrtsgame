#pragma once
#include <chrono>
#include <vector>
#include <string>
#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>

#include "mathUtil.h"

enum ALIGN {
	LEFT,
	CENTER,
	RIGHT
};

void drawTexture(SDL_Texture* texture, SDL_Renderer* renderer, v2<int> pos, int scale);

SDL_Texture* getTextTexture(TTF_Font* font, SDL_Renderer* renderer, std::string content, SDL_Color color);

void drawText(SDL_Texture* textTexture, SDL_Renderer* renderer, v2<int> pos, ALIGN align, int scale);

void drawBezier(SDL_Renderer* renderer, v2<int> a, v2<int> b, v2<int> c);

typedef void (*fptr)(char*);

void f(char* args);

class button {
public:
	v2<int> pos;
	fptr function;
	char* args;
	SDL_Color border, fill, text;
	int xPad, yPad, textScale;
	TTF_Font* font;
	std::string message;

	void draw(SDL_Renderer* renderer);

	button(v2<int> pos, fptr function, char* args, SDL_Color border, SDL_Color fill, SDL_Color text, int xPad, int yPad, int textScale, TTF_Font* font, std::string message);
};

class mapView {
public:
	v2<float> pos;
	float zoom;

	mapView();
};

class ui {
public:
	std::vector<button> buttons;
};