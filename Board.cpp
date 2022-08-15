#include "Board.h"
using namespace std;

Board::Board(int VERT_SQUARES, int HORZ_SQUARES) {
    vector <square> squareVector{};

}

void Board::buildPosition(vector<string> nameList, int SQwidth, int SQheight, SDL_Renderer* renderer) {


    for (string name : nameList) {
        int xName{ name[0] - '0'};
        int yName{ name[1] - '0'};
        cout << xName << yName << " ";
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
            c1 = LIGHT[0];
            c2 = LIGHT[1];
            c3 = LIGHT[2];
        }
        else {
            c1 = DARK[0];
            c2 = DARK[1];
            c3 = DARK[2];
        }
        //draws rectangle to screen
        SDL_SetRenderDrawColor(renderer, c1, c2, c3, 255);
        SDL_RenderDrawRect(renderer,ptr);
        SDL_RenderFillRect(renderer, ptr);

        //adds squares
        //square(string newName, vector <int> newColor, vector <int> newEdge, renderer);
        vector <int> color{ c1,c2,c3 };
        vector <int> newEdge{ srcrect.x,srcrect.y };
        square newSquare(name, color, newEdge, renderer);
        cout << "pushed!\n";
        squareVector.push_back(newSquare);

    }
    fillGraph(nameList);


}

void Board::initPieces() {

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
