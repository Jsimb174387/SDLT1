#include "Piece.h"
using namespace std;
piece::piece(void)
	:name{ NULL },
	 color{NULL},
	squareMapPTR{ nullptr },
	location{ NULL },
	movementStyle{ NULL },
	type{ NULL }
{
}
piece::piece(std::string nameIn, std::string typeIn, std::string colorIn, std::vector <int> locIn,
	std::map <std::string, square>* sqMap)
	{
		name = nameIn;
		color = colorIn;
		location = locIn;
		type = typeIn;
		squareMapPTR = sqMap;
		//write direction here
	}
	string piece::getColor() {
		return color;
	}
	string piece::getName() {
		return name;
	}

	void piece::setLocation(vector<int> loc) {
		location = loc;
	}

	auto piece::getLocationSquare() {
		//look through board to find square center is in.
		for (auto& sq : *squareMapPTR) {
			
		}
	}
