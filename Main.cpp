#include "Main.h"

using namespace std;

//Board createBoard(SDL_Renderer* renderer) {
//    Board chessPlayingField(VERT_SQUARES, HORZ_SQUARES);
//    //vector<string> SQUARE_NAMES, int SQwidth,int SQheight, SDL_Surface* screenSurface
//    chessPlayingField.buildPosition(SQUARE_NAMES, WIDTH_OF_SQUARES, HEIGHT_OF_SQUARES, renderer);
//    return chessPlayingField;
//}

auto createTextures() {
    map <string, SDL_Surface*> pieceSurfaces{};
    for (const char* imagePath : IMAGEPATH) {
        //loads bitmap
        SDL_Surface* surface = SDL_LoadBMP(imagePath);

        //retrives name from imagePath
        bool read = false;
        string name{};

        size_t length{ strlen(imagePath) };
        for (int i = 0; i <= length; i++) {
            string character{ imagePath[i] };
            if (character == ".") {
                read = false;
            }
            if (read == true) {
                name.append(character);
            }
            if (character == "/") {
                read = true;
            }

        }

        pieceSurfaces.emplace(name, surface);
    }
    //PIECESURFACES = pieceSurfaces;
    return pieceSurfaces;
}




int main(int argc, char* args[])
{   

    //generates the Piece Surfaces dictionary
    map <string, SDL_Surface*> pieceSurfaces{ createTextures() };

    //Creates surface for game
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
    screenSurface = SDL_GetWindowSurface(window);
    //SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xAF, 0xBF, 0xFF));


    //Begins creating board

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Board chessPlayingField(VERT_SQUARES, HORZ_SQUARES);
    //vector<string> SQUARE_NAMES, int SQwidth,int SQheight, SDL_Surface* screenSurface
    chessPlayingField.buildPosition(SQUARE_NAMES, WIDTH_OF_SQUARES, HEIGHT_OF_SQUARES, renderer);
    SDL_RenderPresent(renderer);
    chessPlayingField.initPieces(pieceSurfaces, renderer);
    //SDL_UpdateWindowSurface(window);




    while (true) {

        //retrive next event to process
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                //SDL_RenderPresent(renderer);
                break;
            }

            SDL_RenderPresent(renderer);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    _CrtDumpMemoryLeaks();
    std::cout << "\n Program Finished!";
    return true;

};