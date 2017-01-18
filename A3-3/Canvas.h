//
// Created by roberto on 16.01.17.
//

#ifndef A3_3_CANVAS_H
#define A3_3_CANVAS_H

#include <glob.h>
#include <iostream>
#include <SDL2/SDL_quit.h>
#include <vector>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_events.h>
#include "Surface.h"
#include "Widget.h"

namespace my {

    class Canvas {
    public:
        Canvas(size_t width, size_t heigth, Uint8 r, Uint8 g, Uint8 b);

        ~Canvas();

        void fill(Uint8 r, Uint8 g, Uint8 b);

        std::vector<my::Widget> v;

        bool isOver = false;
        mutable bool isClicked = false;
        mutable SDL_Rect offset;

        mutable std::vector<Uint8> color = {255, 255, 255};
        std::vector<Uint8> colorNormal = {180, 180, 180};
        std::vector<Uint8> colorOver = {100, 100, 100};
        std::vector<Uint8> colorClick = {255, 0, 0};

        int gap = 3;

    };

    Canvas::Canvas(size_t width, size_t heigth, Uint8 r, Uint8 g, Uint8 b) {
        offset.x = 0;
        offset.y = 0;
        offset.w = width;
        offset.h = heigth;

        color = {r, g, b};
    }

    Canvas::~Canvas() {

    }

    void Canvas::fill(Uint8 r, Uint8 g, Uint8 b) {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }

    void makeRaster(Canvas const &canvas, int GAP, int WIDTH, SDL_Rect offset) {

        int counterX = 0;
        int counterY = 0;
        int width = 0;
        int heigth = 0;
        int currentHeigth = 0;

        for (const auto &e : canvas.v) {


            SDL_Rect rect;

            SDL_Rect size = getPosition(e);

            rect.x = width;// + offset.x;
            rect.y = heigth;// + offset.y;
            rect.w = size.w;
            rect.h = size.h;

            width += size.w + GAP;

            currentHeigth = (size.h + GAP > currentHeigth) ? size.h + GAP : currentHeigth;

            if (rect.x + rect.w >= WIDTH - offset.x) {
                counterX = 0;
                counterY++;
                width = 0;
                heigth += currentHeigth;
            }

            setPosition(e, rect);

            counterX++;
        }
    }

    void setPosition(Canvas const &canvas, SDL_Rect const &offset) {
        canvas.offset = offset;
        makeRaster(canvas, canvas.gap, canvas.offset.w, offset);
    }

    void handleEvent(Canvas const &canvas, SDL_Event e) {

        e.button.x -= canvas.offset.x;
        e.button.y -= canvas.offset.y;

        for (const auto &elm : canvas.v) {
            handleEvent(elm,e);
        }
    }

    void clearSurface(Canvas const &canvas){
        for (const auto &e : canvas.v) {
            clearSurface(e);
        }
    }

    void draw(Canvas const &canvas, my::Surface const &sur) {

        my::Surface sur1(canvas.offset.w, canvas.offset.h);

        sur1.fill(
                canvas.color[0],
                canvas.color[1],
                canvas.color[2],
                255
        );

        for (const auto &e : canvas.v) {
            draw(e, sur1);
        }

        SDL_Rect r;

        r.x = canvas.offset.x;
        r.y = canvas.offset.y;
        r.w = canvas.offset.w;
        r.h = canvas.offset.h;

        sur1.blit(sur.surface, &r);

        canvas.offset.x = r.x;
        canvas.offset.y = r.y;
        canvas.offset.w = r.w <= 0 ?  canvas.offset.w : r.w;
        canvas.offset.h = r.h <= 0 ?  canvas.offset.h : r.h;

    }

    SDL_Rect getPosition(Canvas const &canvas) {
        return canvas.offset;
    }
}


#endif //A3_3_CANVAS_H
