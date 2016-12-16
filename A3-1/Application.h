//
// Created by roberto on 16.12.16.
//

#ifndef SDL_DEMO_APPLICATION_H
#define SDL_DEMO_APPLICATION_H

#include <SDL2/SDL.h>
#include <stdlib.h>

namespace my {
    class Application {

    public:
        Application();
        ~Application();
        void run();

    private:

        SDL_Event Events;
    };

    Application::Application() {
        if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) {
            printf("Could not initialize SDL: %s.\n", SDL_GetError());
            exit(-1);
        }
    }

    Application::~Application() {  SDL_Quit(); }

    void Application::run() {
        while (SDL_PollEvent(&Events))
        {
            if (Events.type == SDL_QUIT) break;
        }
    }
}

#endif //SDL_DEMO_APPLICATION_H
