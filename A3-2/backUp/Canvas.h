//
// Created by roberto on 19.12.16.
//

#ifndef SDL_DEMO_CANVAS_H
#define SDL_DEMO_CANVAS_H

#include <vector>
#include "Widget.h"
#include "Window.h"
#include "Surface.h"


namespace my {
    class Canvas : public Widget {
    public:
        Canvas(int w, int h);

        ~Canvas();

        void add(Widget widget);

        std::vector<Widget> get();

        Surface draw(my::Window window);

    private:
        std::vector<my::Widget> widgets;
        SDL_Surface* canvas_surface;
        SDL_Texture* canvas_texture;
        SDL_Renderer* canvas_renderer;
    };

    Canvas::Canvas(int w, int h) : my::Widget(w,h,0,0,0) {}

    Canvas::~Canvas() {
        widgets.clear();
    }

    void Canvas::add(my::Widget widget) {
        widgets.push_back(widget);
    }

    std::vector<my::Widget> Canvas::get() {
       return widgets;
    }

    my::Surface Canvas::draw(my::Window window) {


        my::Surface sur(w,h);

        sur.fill(100,100,100);

        SDL_Rect rect = sur.size();


        canvas_renderer = SDL_CreateRenderer(window.window, -1, 0);
        canvas_surface = sur.surface;
        canvas_texture = SDL_CreateTextureFromSurface(canvas_renderer, canvas_surface);
        SDL_RenderCopy(canvas_renderer, canvas_texture, &rect, NULL);
        SDL_RenderPresent(canvas_renderer);



        for (int i = 0; i < widgets.size(); i++) {

            widgets[i].draw(window, rect);
        }

        SDL_RenderPresent(canvas_renderer);

        return sur;
    }
}


#endif //SDL_DEMO_CANVAS_H
