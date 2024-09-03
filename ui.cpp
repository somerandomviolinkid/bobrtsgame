#include "ui.h"

void drawTexture(SDL_Texture* texture, SDL_Renderer* renderer, v2<int> pos, int scale) {
	int rx, ry;
	SDL_QueryTexture(texture, NULL, NULL, &rx, &ry);
	rx *= scale; 
	ry *= scale;

	SDL_Rect r = { pos.x - (rx / 2), pos.y - (ry / 2), rx, ry };
	SDL_RenderCopy(renderer, texture, NULL, &r);
};

SDL_Texture* getTextTexture(TTF_Font* font, SDL_Renderer* renderer, std::string content, SDL_Color color) {
	uint16_t* text = (uint16_t*)malloc((content.length() + 1) * 2);

	int i = 0;
	for (char& c : content) {
		*(text + i) = c;
		i++;
	}

	*(text + i) = 0x0000;

	SDL_Surface* surface = TTF_RenderUNICODE_Solid_Wrapped(font, text, color, 0);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	free(text);
	SDL_FreeSurface(surface);

	return texture;
}

void drawText(SDL_Texture* textTexture, SDL_Renderer* renderer, v2<int> pos, ALIGN align, int scale) {
	int rx, ry;
	SDL_QueryTexture(textTexture, NULL, NULL, &rx, &ry);

	SDL_Rect r;
	r.w = rx * scale; 
	r.h = ry * scale;
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

	SDL_RenderCopy(renderer, textTexture, NULL, &r);
	SDL_DestroyTexture(textTexture);
}

void drawBezier(SDL_Renderer* renderer, v2<int> a, v2<int> b, v2<int> c) {
	SDL_Point p[ 100 ];
	for (int t = 0; t < 100; t++) {
		v2<int> i = bezier(a, b, c, (float)t / 100.0f);
		p[ t ] = { i.x, i.y };
	}

	SDL_RenderDrawLines(renderer, p, 100);
}

void f(char* args) {
	printf("bob");
};

button::button(v2<int> pos, fptr function, char* args, SDL_Color border, SDL_Color fill, SDL_Color text, int xPad, int yPad, int textScale, TTF_Font* font, std::string message) {
	button::pos = pos;
	button::function = function;
	button::args = args;
	button::border = border;
	button::fill = fill;
	button::text = text;
	button::xPad = xPad;
	button::yPad = yPad;
	button::font = font;
	button::textScale = textScale;
	button::message = message;
}

void button::draw(SDL_Renderer* renderer) {
	SDL_Texture* textTexture = getTextTexture(button::font, renderer, button::message, button::text);
	int tx, ty;
	SDL_QueryTexture(textTexture, NULL, NULL, &tx, &ty);

	tx *= button::textScale;
	ty *= button::textScale;

	int w = tx + (button::xPad * 2);
	int h = ty + (button::yPad * 2);

	SDL_Color c;
	SDL_Rect r = { button::pos.x, button::pos.y, w, h };

	c = button::fill;
	SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
	SDL_RenderFillRect(renderer, &r);

	c = button::border;
	SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
	SDL_RenderDrawRect(renderer, &r);

	drawText(textTexture, renderer, { button::pos.x + button::xPad, button::pos.y + button::yPad + (button::textScale * 8) }, LEFT, button::textScale);
}

mapView::mapView() {
	mapView::pos = { 0.0f, 0.0f };
	mapView::zoom = 0.0f;
}