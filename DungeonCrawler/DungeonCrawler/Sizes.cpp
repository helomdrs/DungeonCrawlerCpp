#include "Sizes.h"

std::string GetSizeAsString(const int size)
{
	switch (size)
	{
	case 0:
		return "Small";
	case 1:
		return "Medium";
	case 2:
		return "Big";
	default:
		return "Invalid";
	}
}