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
#include "Button.h"

namespace my {

    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    //Button constants
    const int BUTTON_CAP = 10;
    const int BUTTON_WIDTH = 50;
    const int BUTTON_HEIGHT = 50;

    using Canvas = std::vector<my::Widget>;

    void makeRaster(Canvas canvas, int GAP, int WIDTH, SDL_Rect offset) {


        std::cout << offset.x << std::endl;
        std::cout << offset.y << std::endl;

        int counterX = 0;
        int counterY = 0;
        int width = 0;
        int heigth = 0;
        int currentHeigth = 0;

        for (const auto &e : canvas) {


            SDL_Rect rect;

            SDL_Rect size = getPosition(e);

            rect.x = width + offset.x;
            rect.y = heigth + offset.y;
            rect.w = size.w;
            rect.h = size.h;

            width += size.w + GAP;

            currentHeigth = (size.h + GAP > currentHeigth) ? size.h + GAP : currentHeigth;

            if (rect.x + rect.w >= WIDTH) {
                counterX = 0;
                counterY++;
                width = 0;
                heigth += currentHeigth;
            }


            std::cout << rect.x << ":" << rect.y << std::endl;

            setPosition(e, rect);

            counterX++;
        }
    }


    class Application {
    public:
        Application();

        ~Application();

        void run();

        //my::Surface draw(const Canvas &canvas);

    private:
        bool Running = true;

        Canvas drawCanvas();
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

        Canvas canvas = drawCanvas();

        Canvas canvas1 = drawCanvas();

        canvas.push_back(move(canvas1));

        SDL_Event Event;

        my::Window win("Mein Window", SCREEN_WIDTH, SCREEN_HEIGHT);

        SDL_Rect rect;

        rect.x = 0;
        rect.y = 0;


        makeRaster(canvas, 10, SCREEN_WIDTH, rect);

        while (Running) {

            my::Surface sur(SCREEN_WIDTH, SCREEN_HEIGHT);
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

    Canvas Application::drawCanvas() {

        Canvas canvas;

        canvas.push_back(Button(90, 50));
        canvas.push_back(Button(50, 50));
        canvas.push_back(Button(50, 50));
        canvas.push_back(Button(50, 80));
        canvas.push_back(Button(50, 50));
        canvas.push_back(Button(50, 50));
        canvas.push_back(Button(50, 50));
        canvas.push_back(Button(50, 50));
        canvas.push_back(Button(50, 50));
        canvas.push_back(Button(50, 50));
        canvas.push_back(Button(50, 50));
        canvas.push_back(Button(50, 50));
        canvas.push_back(Button(50, 50));
        canvas.push_back(Button(50, 50));

        return canvas;
    }

    void setPosition(Canvas const &canvas, SDL_Rect const &o) {
        makeRaster(canvas, BUTTON_CAP, SCREEN_WIDTH, o);
    }

    void draw(Canvas const &canvas, my::Surface const &sur) {

        for (const auto &e : canvas) {
            draw(e,sur);
        }
    }

    void handleEvent(Canvas const &canvas, SDL_Event evt) {
        for (const auto &e : canvas) {
            handleEvent(e, evt);
        }
    }

    SDL_Rect getPosition(Canvas const &canvas) {

        SDL_Rect rect;
        rect.x = 0;
        rect.y = 0;

        return rect;
    }
}
#endif //SDL_DEMO_APPLICATION_H
