#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <string>

#if !defined(MYLIB_CONSTANTS_H)
#define MYLIB_CONSTANTS_H 1

//Colors

const std::vector <int> BLACK{ 0,0,0 };
const std::vector <int> WHITE{ 255,255,255 };
const std::vector <int> RED{ 255,0,0 };
const std::vector <int> GREEN{ 0, 255, 0 };	
const std::vector <int> BLUE{ 0,0,255 };

//light Square color
const std::vector <int> LIGHT{ 118,150,86 };
const std::vector <int> DARK{ 238,238,210 };
//directions
//const std::vector <std::string> northeast{ "N","E" };
//const std::vector <std::string> northwest{ "N","W" };
//const std::vector <std::string> southeast{ "S","E" };
//const std::vector <std::string> southwest{ "S","W" };
//const std::vector <std::string> north{ 'N',"" };
//const std::vector <std::string> south{ "S","" };
//const std::vector <std::string> east{ "","E" };
//const std::vector <std::string> west{ "","W" };

const std::string northeast{ "NE" };
const std::string northwest{ "NW" };
const std::string southeast{ "SE" };
const std::string southwest{ "SW" };
const std::string north{ "N " };
const std::string south{ "S " };
const std::string east{ " E" };
const std::string west{ " W" };

//Board
const int WIDTH{ 800 };
const int HEIGHT{ 800 };
const int VERT_SQUARES{ 8 };
const int HORZ_SQUARES{ 8 };
const int WIDTH_OF_SQUARES{ WIDTH / HORZ_SQUARES };
const int HEIGHT_OF_SQUARES{HEIGHT/VERT_SQUARES};


const std::vector <std::string> SQUARE_NAMES
{  "11","12","13","14","15","16","17","18",
   "21","22","23","24","25","26","27","28",
   "31","32","33","34","35","36","37","38",
   "41","42","43","44","45","46","47","48",
   "51","52","53","54","55","56","57","58",
   "61","62","63","64","65","66","67","68",
   "71","72","73","74","75","76","77","78",
   "81","82","83","84","85","86","87","88"};
//letterValues

//Piece
const int circleSize{ HEIGHT / 18 };
//CROWN
const int CROWN_WIDTH{ 45 };
const int CROWN_HEIGHT{ 25 };


//Starting Positions
const std::vector <int> redPromotionSquares{};
const std::vector <int> blackPromotionSquares{};
#endif


//Piece pictures
const std::vector <const char*> IMAGEPATH
{ "Pieces/pawnWhite.bmp","Pieces/pawnBlack.bmp", "Pieces/rookWhite.bmp,","Pieces/rookBlack.bmp",
	"Pieces/bishopWhite.bmp","Pieces/bishopBlack.bmp", "Pieces/knightWhite.bmp","Pieces/knightBlack.bmp",
	"Pieces/queenWhite.bmp", "Pieces/queenBlack.bmp","Pieces/kingWhite.bmp","Pieces/kingBlack.bmp"
	};


//COLOR OF SQUARES:
//
//Here's how you can find out the colour of every single square on a chessboard.
//Firstly assign a number to the letter that the square begins with based on it's position in the alphabet,so A becomes 1,B becomes 2,C becomes 3 and so on.
//Next put that number next to the number that the square has in it.So square a3 becomes 1,3.Square h7 becomes 8,7 and so on.
//If both those numbers are odd or if both those numbers are even the square is black,if not the square is white.
