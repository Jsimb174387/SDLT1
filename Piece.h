#pragma once
#include <string>
#include <SDL.h>
#include <vector>

class Piece {
private:
	std::string name;
	std::string color;
	bool king = false;
	SDL_Renderer* renderer;
	std::vector <int> center;
public:
	Piece(std::string nameIn, std::string colorIn, SDL_Renderer* newRenderer, std::vector <int> centerIn);

	std::string getColor();

	std::string getName();
	bool getKing();

	void turnKing();
	auto getDirection();
	void setLocation(std::vector<int> newCenter);

	auto getLocationSquare();

	auto renderPiece();
};
