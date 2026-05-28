#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

/*
This code is Copyright 2026 Doug Mead under the GNU General Public License v3.0 for more info, see "LICENSE".
This code is not easily organized into 3 or 4 sections like the CLI version, and two of the functions are basically completely useless in CLI, but the analyze function remains the same.
*/

using namespace std;

struct resources { //This makes it really easy to clean up the code when we're done.
    SDL_Window *window;
    SDL_Renderer *renderer;
};

void cleanup(resources resources);

int main() {
    resources resources;

    if (!SDL_Init(SDL_INIT_VIDEO)) { //Check if SDL initialized without error. If it did not, show an error box.
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "SDL3 has encountered an error while initializing. Please check that you have in installed correctly, and add an issue if you think its a promblem with the code.", nullptr);
        return 1;
    }

    int width = 1024; //The width of the window
    int height = 512; //The height of the window

    resources.window = SDL_CreateWindow("number-guess", width, height, 0); //Initializing the window
    resources.renderer = SDL_CreateRenderer(resources.window, nullptr); //Initializing the renderer

    if (!resources.window) { //Check if the window exists. If it does not, show an error box.
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "The SDL3 window has failed to initialize. Please look at your code and installation, and then file an issue if it's an error with my code.", resources.window);
        return 1;
    }

    if (!resources.renderer) { //Check if the renderer exists. If it does not, show an error box.
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "The SDL3 renderer has failed to initialize. Please look at your code and installation, and then file an issue if it's an error with my code.", resources.window);
        return 1;
    }

    bool running = true; //The variable that is set to false to exit the loop
    
    while (running) {
        SDL_Event event{0}; //The SDL_Event variable
            while (SDL_PollEvent(&event)) { //Checking for events
                switch (event.type) { //Checking which kind of events
                    case SDL_EVENT_QUIT: { //If it is an SDL_EVENT_QUIT, which means the user has clicked the little "x" and the top of the window, then exit
                        running = false; //Set running to false to exit
                        break; //And end the switch statement
                    }
                }
            }
        SDL_SetRenderDrawColor(resources.renderer, 255, 0, 0, 255); //Set the draw color to red
        SDL_RenderClear(resources.renderer); //Clear the screen with the draw color
        SDL_RenderPresent(resources.renderer); //Present the renderer's image
    }

    cleanup(resources);
}

void cleanup(resources resources) { //The cleanup function. This is pretty self-explanatory.
    SDL_DestroyRenderer(resources.renderer);
    SDL_DestroyWindow(resources.window);
    SDL_Quit();
}