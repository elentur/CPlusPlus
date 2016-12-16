//
// Created by roberto on 16.12.16.
//

#ifndef SDL_DEMO_WINDOW_H
#define SDL_DEMO_WINDOW_H

#include <SDL2/SDL_video.h>

namespace my {
    class Window {
        Window(const char *title, int width, int heigth);
        ~Window();
        void set_pixel(int x, int y, int r, int g, int b);
    private:
        SDL_Window *window;
    };

    Window::Window(const char *title, int width, int heigth) {
        window = SDL_CreateWindow(
                title,                  // window title
                SDL_WINDOWPOS_UNDEFINED,           // initial x position
                SDL_WINDOWPOS_UNDEFINED,           // initial y position
                width,                               // width, in pixels
                heigth,                               // height, in pixels
                SDL_WINDOW_OPENGL                  // flags - see below
        );

        if (window == NULL) {
            // In the case that the window could not be made...
            printf("Could not create window: %s\n", SDL_GetError());
            exit(1);
        }
    }

    void Window::set_pixel(int x, int y, int r, int g, int b) {

    }


    Window::~Window() {
        SDL_DestroyWindow(window);
    }


}

#endif //SDL_DEMO_WINDOW_H
