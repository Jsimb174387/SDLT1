#pragma once
#include <vector>
#include <SDL.h>
#include <string>
#include "Settings.h"
class square {
private:
	std::string name;
	std::vector <int> color;
	//location = top left edge of square
	std::vector <int> location;
	std::vector <int> middle;
	//Piece* holdingPointer;

public:
	//initial constructor
	square(void);
	square(std::string newName, std::vector <int> newColor, std::vector <int> loc);
	//deletion constructor
	~square(void);
	std::vector <int> getLocation();

	std::vector<int> getMiddle();

	//void setPointer(Piece* pointer);
};