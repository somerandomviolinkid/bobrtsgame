#include "state.h"
#include "player.h"
#include "settings.h"
#include "ui.h"

int main(int argc, char** argv) {
	settings settings;
	state state(settings.windowRes, settings.windowPos, settings.audioFreq, settings.audioBufferSize);
	player player;

	char* nullchar = (char*)malloc(1);
	button b({100, 100}, f, nullchar, {255, 255, 255, 255}, {255, 255, 255, 255}, {0, 0, 0, 255}, 4, 4, 2, state.fonts[0], "bob");
	b.draw(state.renderer);
	SDL_RenderPresent(state.renderer);

	while (state.running) {
		state.handleEvents();
	}

	return 0;
}