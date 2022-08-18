#pragma once
#include "Piece.h"
 
class Pawn : public piece
{
private:
	std::string direction;



public:
	Pawn(void);
	Pawn(std::string nameIn, std::string typeIn, std::string colorIn, std::vector <int> locIn,
		std::map <std::string, square>* squareMapPTR, std::string directionIn)
		//piece constructor, as Pawn "is a" piece
		:piece{ nameIn,typeIn,colorIn,locIn, squareMapPTR}
		//sets direction to directionIn
		, direction{ directionIn }
	{
	}
};

