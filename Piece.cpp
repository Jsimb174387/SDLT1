#include "Piece.h"
#include "Settings.h"
#include "Square.h"
using namespace std;
	Piece::Piece(string nameIn, string typeIn, string colorIn, SDL_Renderer* newRenderer, vector <int> centerIn){
		name = nameIn;
		color = colorIn;
		renderer = newRenderer;
		center = centerIn;
		type = typeIn;

		//write direction here
	}
	string Piece::getColor() {
		return color;
	}
	string Piece::getName() {
		return name;
	}

	void Piece::setLocation(vector<int> newCenter) {
		center = newCenter;
	}

	//auto Piece::getLocationSquare(std::vector <square> sVector) {
	//	//look through board to find square center is in.
	//	for (square sq : sVector) {
	//		if (sq.getLocation()[0] <= center[0] <= sq.getLocation()[1] && 
	//			sq.getLocation()[1] <= center[1] <= sq.getLocation()[1]) 
	//		{
	//			return sq;
	//		}
	//	}
	//}
