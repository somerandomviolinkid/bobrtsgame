#pragma once
#include <vector>
#include <string>

#include "mathUtil.h"

class improvement {
public:
	int type;
};

class industry {
public:
	int type;
};

class city {
public:
	std::string name;
	int population;
	v2<float> pos;
	std::vector<industry> industries;

	city(std::string name, int population, v2<float> pos, std::vector<industry> industries);
};

class player {
public:
	std::string name;

	std::vector<city> cities;
	std::vector<improvement> improvements;

	player();
	~player();
};