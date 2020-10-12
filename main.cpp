//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surfice contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

bool init(){
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initalize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    } else {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if( gWindow == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow);
        }
    }
    return success;
}

bool loadMedia(){
    //Loading success flag
    bool success = true;

    //Load splash image
    gHelloWorld = IMG_Load("/Img/world1-1.png");
    if( gHelloWorld == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", "world1-1.png", SDL_GetError());
        success =  false;
    }
    return success;
}

void close(){
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld);
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow);
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Start SDL and create a window
    if ( !init()) {
        printf("Filed to initialize!\n");
    } else {
        //Load media
        if( !loadMedia()) {
            printf("Failed to load Media!\n");
        } else{
            //Apply the image
            SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface( gWindow);

            //Wait two seconds
            SDL_Delay(10000);
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}	
  
