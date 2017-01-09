//
// Created by roberto on 16.12.16.
//

#ifndef SDL_DEMO_APPLICATION_H
#define SDL_DEMO_APPLICATION_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <thread>
#include <list>
#include "Window.h"

namespace my {
    class Application {
    public:
        Application();
        ~Application();
        void run();
        void addWindow();

    private:
        bool Running = true;
    };

    Application::Application() {
        try
        {
            SDL_Init(SDL_INIT_EVERYTHING);
        }

        catch (std::runtime_error const &e)
        {
            std::cerr << "Caught exception on initializing Application: " << e.what() << std::endl;
        }
    }

    Application::~Application() {SDL_Quit();}

    void Application::run() {
        SDL_Event Event;
        while (Running)
        {
            SDL_PollEvent(&Event);

            SDL_Window* window = 0;
            Window* winptr = 0;

            switch (Event.type)
            {
                case SDL_WINDOWEVENT:
                    // CODE IN QUESTION
                    window = SDL_GetWindowFromID(Event.window.windowID);

                    switch(Event.window.event)
                    {
                        case SDL_WINDOWEVENT_CLOSE:
                            SDL_DestroyWindow(window);
                            break;
                        case SDL_WINDOWEVENT_EXPOSED:
                            //
                            break;
                        default:
                            break;
                    }
                    break;

                case SDL_QUIT:
                    SDL_DestroyWindow(window);
                    Running = false;
                    break;
                default:
                    break;
            }
        }
    }

    void Application::addWindow() {

    }
}

#endif //SDL_DEMO_APPLICATION_H
