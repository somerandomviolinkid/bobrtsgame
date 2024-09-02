#pragma once
#include <fstream>
#include <string>

#include "mathUtil.h"

class settings {
public:
	v2<int> windowRes, windowPos;
	int audioFreq, audioBufferSize;
	settings();
};