#pragma once
#include <string>
#include <SDL.h>
#include <vector>
#include "Square.h"
#include "Settings.h"

class piece {
private:
	std::string name;
	std::string color;
	std::vector <int> location;
	std::string type;
	std::string movementStyle;
	std::map <std::string, square>* squareMapPTR;
public:
	piece(void);
	piece(std::string nameIn, std::string typeIn, std::string colorIn, std::vector <int> centerIn,
		std::map <std::string, square>* squareMap);

	std::string getColor();

	std::string getName();



	void setLocation(std::vector<int> newCenter);

	auto getLocationSquare();
};
