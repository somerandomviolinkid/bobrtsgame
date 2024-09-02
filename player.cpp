#include "player.h"

city::city(std::string name, int population, v2<float> pos, std::vector<industry> industries) {
	city::name = name;
	city::population = population;
	city::pos = pos;
	city::industries = industries;
}

player::player() {
	city c("Capitol", 10000, { 0.0f, 0.0f }, {});
	player::cities.push_back(c);
}

player::~player() {

}