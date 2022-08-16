#pragma once
#include <string>
#include <SDL.h>
#include <vector>
#include "Square.h"
class Piece {
private:
	std::string name;
	std::string color;
	bool king = false;
	SDL_Renderer* renderer;
	std::vector <int> center;
	std::string type;

public:
	Piece(std::string nameIn, std::string typeIn, std::string colorIn, SDL_Renderer* newRenderer, std::vector <int> centerIn);

	std::string getColor();

	std::string getName();



	void setLocation(std::vector<int> newCenter);

	//square getLocationSquare(std::vector <square> sVector);
};
