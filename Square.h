#pragma once
#include <vector>
#include <SDL.h>
#include <string>

class square {
private:
	std::string name;
	std::vector <int> color;
	//location = top left edge of square
	std::vector <int> location;
	SDL_Renderer* rend;



public:

	square(std::string newName, std::vector <int> newColor, std::vector <int> loc, SDL_Renderer* renderer) {
		name = newName;
		color = newColor;
		location = loc;
		rend = renderer;
	}

	std::vector <int> getLocation() {
		return location;
	}

};