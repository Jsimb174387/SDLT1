#pragma once
#include <vector>
#include <SDL.h>
#include <string>
#include "Graph.h"
#include "Square.h"
#include "Settings.h"
#include "Pawn.h"
#include <memory>
class Board
{
private:
	void fillGraph(std::vector<std::string> nameList);
	//map <string, SDL_Surface*>& pieceSurfacesPTR;
	
public:
	graph boardGraph;
	std::map <std::string, square> squareMap;
	//directory - maps init square, direction to move as a vector, and connects it with the 'new' square.
	std::map <std::vector<std::string>, std::string>  directory;
	std::map <std::string, piece> whitePieces;
	std::map <std::string, piece> blackPieces;


	Board(void);
	Board(int VERT_SQUARES, int HORZ_SQUARES);

	//draws squares that makes up the board
	void buildPosition(std::vector<std::string> SQUARE_NAMES, const int& SQwidth, const int& SQheight, SDL_Renderer* renderer);

	void initPieces(std::map <std::string, SDL_Surface*>& ref, SDL_Renderer* ptr);

	auto getBoardGraph();

	auto getSquareGraph();

	auto getSquareMap();
};


