#include "state.h"

void state::freeTextures() {
	for (SDL_Texture*& i : state::textures) {
		SDL_DestroyTexture(i);
	}

	state::textures.clear();
}

void state::freeFonts() {
	for (TTF_Font*& i : state::fonts) {
		TTF_CloseFont(i);
	}

	state::fonts.clear();
}

void state::freeMusics() {
	for (Mix_Music*& i : state::musics) {
		Mix_FreeMusic(i);
	}

	state::musics.clear();
}

void state::freeSounds() {
	for (Mix_Chunk*& i : state::sounds) {
		Mix_FreeChunk(i);
	}

	state::sounds.clear();
}

void state::freeAssets() {
	state::freeTextures();
	state::freeFonts();
	state::freeMusics();
	state::freeSounds();
}

void state::loadTextures() {
	state::freeTextures();

	int fsize = 0;
	for (const auto& entry : std::filesystem::directory_iterator("./assets/textures")) {
		state::textures.push_back(IMG_LoadTexture(state::renderer, entry.path().string().c_str()));
		fsize += entry.file_size();
	}

	printf("Loaded %d textures totaling %d bytes.\n", (int)state::textures.size(), fsize);
}

void state::loadFonts() {
	state::freeFonts();

	int fsize = 0;
	for (const auto& entry : std::filesystem::directory_iterator("./assets/fonts")) {
		state::fonts.push_back(TTF_OpenFont(entry.path().string().c_str(), 16));
		fsize += entry.file_size();
	}

	printf("Loaded %d fonts totaling %d bytes.\n", (int)state::fonts.size(), fsize);
}

void state::loadMusics() {
	state::freeMusics();

	int fsize = 0;
	for (const auto& entry : std::filesystem::directory_iterator("./assets/musics")) {
		state::musics.push_back(Mix_LoadMUS(entry.path().string().c_str()));
		fsize += entry.file_size();
	}

	printf("Loaded %d musics totaling %d bytes.\n", (int)state::musics.size(), fsize);
}

void state::loadSounds() {
	state::freeSounds();

	int fsize = 0;
	for (const auto& entry : std::filesystem::directory_iterator("./assets/sounds")) {
		state::sounds.push_back(Mix_LoadWAV(entry.path().string().c_str()));
		fsize += entry.file_size();
	}

	printf("Loaded %d sounds totaling %d bytes.\n", (int)state::sounds.size(), fsize);
}

void state::loadAssets() {
	state::loadTextures();
	state::loadFonts();
	state::loadMusics();
	state::loadSounds();
}

void state::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				state::running = false;
				break;
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
					SDL_SetRenderDrawColor(state::renderer, 0, 0, 0, 255);
					SDL_RenderClear(state::renderer);
					SDL_RenderPresent(state::renderer);

					SDL_GetWindowSize(state::window, &state::windowRes.x, &state::windowRes.y);
					SDL_GetWindowPosition(state::window, &state::windowPos.x, &state::windowPos.y);
				}
				break;
		}
	}
}

state::state(v2<int> windowRes, v2<int> windowPos, int audioFreq, int audioBufferSize) {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	Mix_OpenAudio(audioFreq, MIX_DEFAULT_FORMAT, 2, audioBufferSize);

	state::window = SDL_CreateWindow("bob", windowPos.x, windowPos.y, windowRes.x, windowRes.y, SDL_WINDOW_RESIZABLE);
	state::renderer = SDL_CreateRenderer(state::window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	state::windowRes = windowRes;
	state::windowPos = windowPos;

	loadAssets();
	state::running = true;
}

state::~state() {
	freeAssets();

	SDL_DestroyRenderer(state::renderer);
	SDL_DestroyWindow(state::window);

	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}