#pragma once
#include <string>

enum Sizes {
	Small,
	Medium,
	Big,
};

std::string GetSizeAsString(const int size);
