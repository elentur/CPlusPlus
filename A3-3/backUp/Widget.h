//
// Created by roberto on 19.12.16.
//

#ifndef SDL_DEMO_WIDGET_H
#define SDL_DEMO_WIDGET_H

#include "Surface.h"
#include "Window.h"

namespace my {
    class Widget {
    public:
        Widget(int w, int h, int red, int green, int blue);

        virtual ~Widget();

        virtual void draw(my::Window window,SDL_Rect rect);

    protected:
        int w;
        int h;
        int r;
        int g;
        int b;
        SDL_Surface* widget_surface;
        SDL_Texture* widget_texture;
        SDL_Renderer* widget_renderer;
    };

    Widget::Widget(int w, int h, int red = 255, int green = 255, int blue = 255) : w(w), h(h), r(red), g(green),
                                                                                         b(blue) {
    }

    Widget::~Widget() {

    }

    void Widget::draw(my::Window window,SDL_Rect rect ) {
        widget_renderer = SDL_CreateRenderer(window.window, -1, 0);
        widget_surface = SDL_LoadBMP("Play.bmp");
        widget_texture = SDL_CreateTextureFromSurface(widget_renderer, widget_surface);
        SDL_RenderCopy(widget_renderer, widget_texture, &rect, NULL);
        SDL_RenderPresent(widget_renderer);
    }
}
#endif //SDL_DEMO_WIDGET_H
