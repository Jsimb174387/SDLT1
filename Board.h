#pragma once
#include <vector>
#include <SDL.h>
#include <string>
#include "Graph.h"
#include "Square.h"
#include "Settings.h"

class Board
{
private:

public:
	graph boardGraph;
	std::vector <square> squareVector;
	//map <string, square> redPieces;
	//map <string, square> blackPieces;

	Board(int VERT_SQUARES, int HORZ_SQUARES);

	//draws squares that makes up the board
	void buildPosition(std::vector<std::string> SQUARE_NAMES, int SQwidth, int SQheight, SDL_Renderer* renderer);

	void initPieces();

	auto getBoardGraph();

	auto getSquareGraph();

	void fillGraph(std::vector<std::string> nameList);
};


