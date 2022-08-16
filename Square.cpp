#include "Square.h"
using namespace std;



square::square(void)
{
	std::string name{NULL};
	std::vector <int> color{NULL};
	std::vector <int> location{NULL};
	std::vector <int> middle{NULL};
}

square::square(string newName, vector <int> newColor, vector <int> loc) {
	name = newName;
	color = newColor;
	location = loc;

	int x{ location[0] + WIDTH_OF_SQUARES / 2 };
	int y{ location[1] + HEIGHT_OF_SQUARES / 2 };
	middle = vector <int> {x, y};
}

square::~square(void)
{
}

std::vector <int> square::getLocation() {
	return location;
}
std::vector <int> square::getMiddle() {
	return middle;
}
/*void square::setPointer(Piece* pointer) {
	holdingPointer = pointer;
}*/