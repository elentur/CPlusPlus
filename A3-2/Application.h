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

    using Canvas = std::vector<my::Widget>;

    class Application {
    public:
        Application();

        ~Application();

        void run();

        my::Surface draw(const Canvas &canvas);

    private:
        bool Running = true;

        Canvas drawCanvas();

        void mouseMoveEventHandler(Canvas vector, SDL_MouseMotionEvent event);

        void mouseClickEventHandler(Canvas vector, SDL_MouseButtonEvent event, bool clicked);

        std::vector<SDL_Rect> raster;

        void makeRaster(Canvas vector);

        const int WIDTH = 640;
        const int HEIGTH = 480;
        const int GAP = 10;
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

        Canvas can = drawCanvas();

        //canvas.push_back(move(can));

        SDL_Event Event;

        my::Window win("Mein Window", WIDTH, HEIGTH);

        while (Running) {

            my::Surface sur = draw(canvas);

            my::Surface sur2 = draw(can);

            SDL_Rect rect ;
            rect.x = sur.size().w;
            rect.y= sur.size().h;

            sur.blit(sur2.surface,&rect);

            win.draw(sur);
            win.draw(sur2);

            SDL_PollEvent(&Event);

            SDL_Window *window = 0;

            switch (Event.type) {
                case SDL_MOUSEBUTTONDOWN:
                    mouseClickEventHandler(canvas, Event.button,true);
                    break;
                case SDL_MOUSEBUTTONUP:
                    mouseClickEventHandler(canvas, Event.button,false);
                    break;
                case SDL_MOUSEMOTION:
                    mouseMoveEventHandler(canvas, Event.motion);
                    break;
                case SDL_WINDOWEVENT:
                    // CODE IN QUESTION
                    window = SDL_GetWindowFromID(Event.window.windowID);

                    switch (Event.window.event) {
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

    my::Surface Application::draw(const Canvas &canvas) {
        my::Surface sur(640, 240);
        sur.fill(255, 255, 255);

        int counter = 0;

        makeRaster(canvas);

        for (const auto &e : canvas) {
            SDL_Rect offset;
            offset.x = raster[counter].x;
            offset.y = raster[counter].y;

            getSurface(e).blit(sur.surface, &offset);
            counter++;
        }

        return sur;

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

    void Application::mouseMoveEventHandler(Canvas canvas, SDL_MouseMotionEvent event) {
        int counter = 0;
        for (const SDL_Rect &e : raster) {
            canvas[counter].onMouseOver(canvas[counter], event.x >= e.x && event.x <= e.x + e.w && event.y >= e.y && event.y <= e.y + e.h);
            counter++;
        }
    }

    void Application::mouseClickEventHandler(Canvas canvas, SDL_MouseButtonEvent event, bool clicked) {
        int counter = 0;
        for (const SDL_Rect &e : raster) {
            if(clicked){
                canvas[counter].onMouseClick(canvas[counter], event.x >= e.x && event.x <= e.x + e.w && event.y >= e.y && event.y <= e.y + e.h);
            }else{
                canvas[counter].onMouseClick(canvas[counter], false);
            }

            counter++;
        }
    }

    void Application::makeRaster(Canvas canvas) {

        raster.clear();

        int counterX = 0;
        int counterY = 0;
        int width = 0;
        int heigth = 0;
        int currentHeigth = 0;

        for (const auto &e : canvas) {

            my::Surface sur = getSurface(e);

            SDL_Rect size = sur.size();

            SDL_Rect rect;

            rect.x = width;
            rect.y = heigth;
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

            raster.push_back(rect);
            counterX++;
        }


    }
}

#endif //SDL_DEMO_APPLICATION_H
