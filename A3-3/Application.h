//
// Created by roberto on 16.12.16.
//

#ifndef SDL_DEMO_APPLICATION_H
#define SDL_DEMO_APPLICATION_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <thread>
#include <list>
#include <vector>
#include "Window.h"
#include "Widget.h"
#include "ImgButton.h"
#include "Canvas.h"
#include "Tile.h"

namespace my {

    void showOffset(SDL_Rect &offset) {
        std::cout << offset.x << ":" << offset.y << ":" << offset.w << ":" << offset.h << std::endl;
    }

    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    //Button constants
    const int BUTTON_CAP = 10;
    const int BUTTON_WIDTH = 50;
    const int BUTTON_HEIGHT = 50;

    int stroke_strength = 10;

    class Application {
    public:
        Application();

        ~Application();

        void run();

        //my::Surface draw(const Canvas &canvas);

    private:
        bool Running = true;

        Canvas buildCanvas();
    };

    Application::Application() {
        try {
            SDL_Init(SDL_INIT_EVERYTHING);
        }

        catch (std::runtime_error const &e) {
            std::cerr << "Caught exception on initializing Application: " << e.what() << std::endl;
        }
    }

    Application::~Application() { SDL_Quit(); }

    void Application::run() {

        Canvas canvas = buildCanvas();

        my::Window win("Mein Window", SCREEN_WIDTH, SCREEN_HEIGHT);

        SDL_Event Event;
        SDL_Rect rect;

        rect.x = 0;
        rect.y = 0;

        makeRaster(canvas, canvas.gap, SCREEN_WIDTH, rect);

        my::Surface sur(SCREEN_WIDTH, SCREEN_HEIGHT);

        while (Running) {

            sur.fill(255, 255, 255, 255);

            draw(canvas, sur);

            win.draw(sur);

            SDL_PollEvent(&Event);

            SDL_Window *window = 0;

            switch (Event.type) {
                case SDL_WINDOWEVENT:
                    // CODE IN QUESTION
                    window = SDL_GetWindowFromID(Event.window.windowID);

                    switch (Event.window.event) {
                        case SDL_WINDOWEVENT_CLOSE:
                            SDL_DestroyWindow(window);
                            break;
                        case SDL_WINDOWEVENT_EXPOSED:
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
                    handleEvent(canvas, Event);
                    break;
            }
        }
    }

    Canvas Application::buildCanvas() {


        // main
        Canvas main(SCREEN_WIDTH, SCREEN_HEIGHT, 100, 100, 100);

        // menu
        Canvas menu(50, SCREEN_HEIGHT, 180, 180, 180);

        // undo
        ImgButton undo("defaultButton", 50, 50);

        undo.onClick([] {
            std::cout << "Undo" << std::endl;
        });

        menu.v.push_back(move(undo));


        /**
         * Canvas
         */
        Canvas canvas(SCREEN_WIDTH, SCREEN_HEIGHT, 255, 255, 255);

        canvas.gap = 0;

        int length = (int) (SCREEN_WIDTH / 50.0 * SCREEN_HEIGHT / 50.0);

        for(int i = 0; i < length; i++){
            Tile t(50,50, "Tile" + std::to_string(i));
            t.onClick([&stroke_strength]() mutable {
                return stroke_strength;
            });
            canvas.v.push_back(move(t));
        }

        ImgButton clear("defaultButton", 50, 50);

        clear.onClick([&main]() mutable{
            clearSurface(main);
        });

        menu.v.push_back(move(clear));

        ImgButton plus("defaultButton", 50, 50);

        int a = 0;

        plus.onClick([&stroke_strength]() mutable {
            if(stroke_strength < 20) stroke_strength++;
            std::cout << stroke_strength << std::endl;
        });

        menu.v.push_back(move(plus));

        ImgButton minus("defaultButton", 50, 50);

        minus.onClick([&stroke_strength]() mutable {
            if(stroke_strength > 1) stroke_strength--;
            std::cout << stroke_strength << std::endl;
        });

        menu.v.push_back(move(minus));

        main.v.push_back(move(menu));
        main.v.push_back(move(canvas));

        return main;
    }


}
#endif //SDL_DEMO_APPLICATION_H
