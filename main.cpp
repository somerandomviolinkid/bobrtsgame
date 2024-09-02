#include "state.h"
#include "player.h"
#include "settings.h"
#include "ui.h"

int main(int argc, char** argv) {
	settings settings;
	state state(settings.windowRes, settings.windowPos, settings.audioFreq, settings.audioBufferSize);
	player player;

	while (state.running) {
		state.handleEvents();
	}

	return 0;
}