//
// Created by roberto on 09.01.17.
//

#ifndef SDL_DEMO_BUTTON_H
#define SDL_DEMO_BUTTON_H

#include <glob.h>
#include <iostream>
#include <SDL2/SDL_quit.h>
#include <vector>
#include "Surface.h"

namespace my {
    class Button {
    public:
        Button(size_t width, size_t heigth);

        ~Button();

        my::Surface draw() const;

        void fill(Uint8 r,Uint8 g,Uint8 b);

        void onMouseOver(bool b) const;
        void onMouseClick(bool b) const;

    private:
        size_t w;
        size_t h;
        std::vector<Uint8> color = {180,180,180};
        std::vector<Uint8> colorOver = {100,100,100};
        std::vector<Uint8> colorClick = {255,0,0};
        mutable bool isOver = false;
        mutable bool isClicked = false;
    };

    Button::Button(size_t width, size_t heigth) : w(width), h(heigth) {}

    Button::~Button() {

    }

    my::Surface Button::draw() const {
        my::Surface sur(w, h);

        if(isClicked){
            sur.fill(colorClick[0],colorClick[1],colorClick[2]);
        }else if(isOver){
            sur.fill(colorOver[0],colorOver[1],colorOver[2]);
        }else{
            sur.fill(color[0],color[1],color[2]);
        }

        return sur;
    }

    void Button::fill(Uint8 r, Uint8 g, Uint8 b) {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }

    void Button::onMouseOver(bool b) const {
        isOver = b;
    }

    void Button::onMouseClick(bool b) const {
        isClicked = b;
    }

}

#endif //SDL_DEMO_BUTTON_H
