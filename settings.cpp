#include "settings.h"

settings::settings() {
	std::ifstream settingsFile;
	settingsFile.open("./config/settings.txt");

	int values[ 6 ] = {0};
	int i = 0;
	std::string line;
	while (std::getline(settingsFile, line)) {
		sscanf_s(line.c_str(), "%d", values + i);
		i++;
	}

	settings::windowRes = { values[ 0 ], values[ 1 ] };
	settings::windowPos = { values[ 2 ], values[ 3 ] };
	settings::audioFreq = values[ 4 ];
	settings::audioBufferSize = values[ 5 ];

	settingsFile.close();
}