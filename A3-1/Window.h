//
// Created by roberto on 16.12.16.
//

#ifndef SDL_DEMO_WINDOW_H
#define SDL_DEMO_WINDOW_H

#include <iostream>
#include <SDL2/SDL_video.h>
#include <stdlib.h>
#include "Surface.h"

namespace my {

    class Window {
    public:
        Window(char *title, int width, int height);
        ~Window();
        void update();
        SDL_Point pos();
        void draw(Surface surface);
        void set_pos(int x,int y);

    private:
        SDL_Window *window;
        SDL_Point position;
    };

    Window::Window(char *title, int width, int height) {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
                                  SDL_WINDOW_OPENGL);
        if (window == NULL) {
            std::cerr << "Coud not create Window with width: " << width << " and heigth: " << height << " :"
                      << SDL_GetError() << std::endl;
            exit(1);
        }
    }

    Window::~Window() {
        SDL_DestroyWindow(window);
    }

    void Window::update() {
        SDL_UpdateWindowSurface(window);
    }

    SDL_Point Window::pos() {
        SDL_GetWindowPosition(window,&position.x,&position.y);
        return position;
    }

    void Window::set_pos(int x, int y) {
        SDL_SetWindowPosition(window,x,y);
    }

    void Window::draw(Surface surface){
        surface.blit(SDL_GetWindowSurface(window));
    }
}

#endif //SDL_DEMO_WINDOW_H
