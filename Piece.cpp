#include "Piece.h"
using namespace std;
	Piece::Piece(string nameIn, string colorIn, SDL_Renderer* newRenderer, vector <int> centerIn){
		name = nameIn;
		color = colorIn;
		renderer = newRenderer;
		center = centerIn;
		

		//write direction here
	}
	string Piece::getColor() {
		return color;
	}
	string Piece::getName() {
		return name;
	}
	bool Piece::getKing() {
		return king;
	}
	
	void Piece::turnKing() {
		king = true;
		//changes direction
	}
	auto Piece::getDirection() {
		//returns direction
	}
	void Piece::setLocation(vector<int> newCenter) {
		center = newCenter;
	}

	auto Piece::getLocationSquare() {
		//look through board to find square center is in.
	}

	auto Piece::renderPiece() {
		SDL_Surface* image = SDL_LoadBMP("pawnWhite.png");
	};