#include "Board.h"
using namespace std;

Board::Board(int VERT_SQUARES, int HORZ_SQUARES) {
    //vector <square> squareVector{};

}

void Board::buildPosition(vector<string> nameList, const int& SQwidth, const int& SQheight, SDL_Renderer* renderer) {
    //replace eventually with start screen,asking to start as white.
    SWAP;
    bool swap = SWAP;
    //pieceSurfaces = pSurface;
    for (string name : nameList) {
        int xName{ name[0] - '0'};
        int yName{ name[1] - '0'};
        std::cout << xName << yName << " ";
        //making a rectangle
        SDL_Rect srcrect;
        const SDL_Rect* ptr{ &srcrect };

        srcrect.x = (xName - 1) * SQwidth;
        srcrect.y = (yName - 1) * SQheight;
        srcrect.w = xName * SQwidth;
        srcrect.h = yName * SQheight;

        //color picker
        int c1{0};
        int c2{0};
        int c3{0};

        if (xName % 2 == 0 && yName % 2 == 0 || xName % 2 == 1 && yName % 2 == 1) {
            if (swap) {
                c1 = DARK[0];
                c2 = DARK[1];
                c3 = DARK[2];
            }
            else if (!swap) {
                c1 = LIGHT[0];
                c2 = LIGHT[1];
                c3 = LIGHT[2];
            }
           
        }
        else {
            if (swap) {
                c1 = LIGHT[0];
                c2 = LIGHT[1];
                c3 = LIGHT[2];
            }
            else if (!swap) {
                c1 = DARK[0];
                c2 = DARK[1];
                c3 = DARK[2];
            }

        }
        //draws rectangle to screen
        SDL_SetRenderDrawColor(renderer, c1, c2, c3, 255);
        SDL_RenderDrawRect(renderer,ptr);
        SDL_RenderFillRect(renderer, ptr);

        //adds squares
        //square(string newName, vector <int> newColor, vector <int> newEdge, renderer);
        vector <int> color{ c1,c2,c3 };
        vector <int> newEdge{ srcrect.x,srcrect.y };
        square newSquare(name, color, newEdge);
        squareMap.emplace(name, newSquare);
        std::cout << "pushed!\n";
        squareVector.push_back(newSquare);

    }
    fillGraph(nameList);
}

void Board::initPieces(std::map <string, SDL_Surface*>& surfaceMap, SDL_Renderer* rend) {
    map <string, string> startingPositions{};
    if (SWAP == false) {
        map <string, string> startingPositions
        {
            {"11","whiteRook"},{"21","whiteKnight"},{"31","whiteBishop"},{"41","whiteQueen"},{"51","whiteKing"},
            {"81","whiteRook"},{"71","whiteKnight"},{"61","whiteBishop"},
            {"12","whitePawn"},{"22","whitePawn"},{"32","whitePawn"},{"42","whitePawn"},{"52","whitePawn"},
            {"62","whitePawn"},{"72","whitePawn"},{"82","whitePawn"},
            
            {"18","blackRook"},{"28","blackKnight"},{"38","blackBishop"},{"48","blackQueen"},{"58","blackKing"},
            {"88","blackRook"},{"78","blackKnight"},{"68","blackBishop"},
            {"17","blackPawn"},{"27","blackPawn"},{"37","blackPawn"},{"47","blackPawn"},{"57","blackPawn"},
            {"67","blackPawn"},{"77","blackPawn"},{"87","blackPawn"}
        };
    }
    else {
        //swaps starting pos around, will complete later
    }
    for (string sqName : STARTSON) {
        string pieceType{ startingPositions[sqName] };
        SDL_Surface* surf = surfaceMap[pieceType];
        SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, surf);
        if (!texture) {
            cout << "texture not created properly";
        }
    
        vector <int> loc = squareMap[sqName].getLocation();
        SDL_Rect dstrect = { loc[0], loc[1], 60, 60};
        SDL_RenderCopy(rend, texture, NULL, &dstrect);
    }

}


void Board::fillGraph(vector<string> nameList) {
    for (string name : nameList) {
        boardGraph.addNode(name);
    }

    for (string name : nameList) {
        //turns string into integer
        int xName{ name[0] - '0' };
        int yName{ name[1] - '0' };
        //moves target square to top left square, then iterates 

        //goes through x values
        for (int x{ 1 }; x >= -1; --x) {


            //goes through y  values
            for (int y{ 1 }; y >= -1; --y) {
                int xPointer{ xName - x};
                int yPointer{ yName - y};

                string pointerName{ to_string(xPointer) };
                pointerName.append(to_string(yPointer));
                //finds if pointer name != current name and is in the list
                bool exists{ false };
                for (string pNames : nameList) {
                    if (pNames == pointerName) {
                        exists = true;
                    }
                }
                if (pointerName != name && exists) {
                    boardGraph.simpleConnect(name,pointerName);

                    //sets the direction from init square to pointer square
                    string direction{ "  " };
                    if (y == 1) {
                        direction[0] = 'N';
                    }
                    else if(y == - 1) {
                        direction[0] = 'S';
                    }

                    if (x == 1) {
                        direction[1] = 'W';
                    }
                    else if (x == -1) {
                        direction[1] = 'E';
                    }

                    vector<string> connection{ name,direction};

                    //prints this new direction made
                    directory.emplace(connection,pointerName);
                    std::cout << "(" << name << ", " << direction << ")";
                    for (char value : directory[connection]) {
                        std::cout << "[" << value << "] ";
                    }
                    std::cout << "\n";
                }
            }
        }
        boardGraph.print(name);

        

    }
}

auto Board::getBoardGraph() {
    //return boardGraph;
}



auto Board::getSquareGraph() {
    return squareVector;
}
