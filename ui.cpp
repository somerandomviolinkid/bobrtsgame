#include "ui.h"

void drawTexture(SDL_Texture* texture, SDL_Renderer* renderer, v2<int> pos, int scale) {
	int rx, ry;
	SDL_QueryTexture(texture, NULL, NULL, &rx, &ry);
	rx *= scale; ry *= scale;
	SDL_Rect r = { pos.x - (rx / 2), pos.y - (ry / 2), rx, ry };
	SDL_RenderCopy(renderer, texture, NULL, &r);
};

void drawText(TTF_Font* font, SDL_Renderer* renderer, std::string content, SDL_Color color, v2<int> pos, ALIGN align, int scale) {
	uint16_t* text = (uint16_t*)malloc((content.length() + 1) * 2);
	int i = 0;
	for (char& c : content) {
		*(text + i) = c;
		i++;
	}

	*(text + i) = 0x0000;

	SDL_Surface* surface = TTF_RenderUNICODE_Solid_Wrapped(font, text, color, 0);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	int rx, ry;
	SDL_QueryTexture(texture, NULL, NULL, &rx, &ry);
	SDL_Rect r;
	r.w = rx * scale; r.h = ry * scale;
	r.y = pos.y - (r.h / 2);

	switch (align) {
		case LEFT:
			r.x = pos.x;
			break;
		case CENTER:
			r.x = pos.x - (r.w / 2);
			break;
		case RIGHT:
			r.x = pos.x - r.w;
			break;
	}

	SDL_RenderCopy(renderer, texture, NULL, &r);

	free(text);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void drawBezier(SDL_Renderer* renderer, v2<int> a, v2<int> b, v2<int> c) {
	SDL_Point p[100];
	for (int t = 0; t < 100; t++) {
		v2<int> i = bezier(a, b, c, (float)t / 100.0f);
		p[t] = {i.x, i.y};
	}
	SDL_RenderDrawLines(renderer, p, 100);
}