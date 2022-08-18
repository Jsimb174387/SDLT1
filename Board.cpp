#include "Board.h"
using namespace std;

Board::Board(void)
{   
    //graph boardGraph{};
    //std::vector <square> squareVector{NULL};
    //std::map <std::string, square> squareMap{NULL,NULL};
    //std::map <std::vector<std::string>, std::string>  directory {NULL,NULL};



}

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
        startingPositions =
        {
            {"11","rookWhite"},{"21","knightWhite"},{"31","bishopWhite"},{"41","queenWhite"},{"51","kingWhite"},
            {"81","rookWhite"},{"71","knightWhite"},{"61","bishopWhite"},
            {"12","pawnWhite"},{"22","pawnWhite"},{"32","pawnWhite"},{"42","pawnWhite"},{"52","pawnWhite"},
            {"62","pawnWhite"},{"72","pawnWhite"},{"82","pawnWhite"},
            
            {"18","rookBlack"},{"28","knightBlack"},{"38","bishopBlack"},{"48","queenBlack"},{"58","kingBlack"},
            {"88","rookBlack"},{"78","knightBlack"},{"68","bishopBlack"},
            {"17","pawnBlack"},{"27","pawnBlack"},{"37","pawnBlack"},{"47","pawnBlack"},{"57","pawnBlack"},
            {"67","pawnBlack"},{"77","pawnBlack"},{"87","pawnBlack"}
        };
    }
    for (auto conn : startingPositions) {
        cout << conn.first << "-> " << conn.second << "\n";
    }
    for (auto conn : startingPositions) {
        //SDL_Surface* surf = surfaceMap[conn.second];
        string surf{ conn.second };
        cout << conn.second << "\n";
        SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, surfaceMap[surf]);
        if (!texture) {
            cout << "texture not created properly \n";
        }
        vector <int> loc = squareMap[conn.first].getLocation();
        cout << loc[0] <<" " << loc[1] << "this is location \n";
        SDL_Rect dstrect = { loc[0] + WIDTH_OF_SQUARES/6, loc[1] +HEIGHT_OF_SQUARES/6, 60, 60};
        SDL_RenderCopy(rend, texture, NULL, &dstrect);
        cout << "added to rend \n";
    }
    SDL_RenderPresent(rend);

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

auto Board::getSquareMap() {
    return squareMap;
}