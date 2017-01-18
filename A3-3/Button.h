//
// Created by roberto on 09.01.17.
//

#ifndef SDL_DEMO_BUTTON_H
#define SDL_DEMO_BUTTON_H

#include <glob.h>
#include <iostream>
#include <SDL2/SDL_quit.h>
#include <vector>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_events.h>
#include "Surface.h"

namespace my {
    class Button {
    public:
        Button(size_t width, size_t heigth);

        ~Button();

        void fill(Uint8 r, Uint8 g, Uint8 b);

        bool isOver = false;
        mutable bool isClicked = false;
        mutable SDL_Rect offset;
        mutable std::vector<Uint8> color = {180, 180, 180};
        std::vector<Uint8> colorNormal = {180, 180, 180};
        std::vector<Uint8> colorOver = {100, 100, 100};
        std::vector<Uint8> colorClick = {255, 0, 0};

    };

    Button::Button(size_t width, size_t heigth) {
        offset.w = width;
        offset.h = heigth;
    }

    Button::~Button() {

    }

    void Button::fill(Uint8 r, Uint8 g, Uint8 b) {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }

    void setPosition(Button const &button, SDL_Rect const &offset) {
        button.offset = offset;
    }

    void handleEvent(Button const &button, SDL_Event &e) {

        if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {

            int x = e.button.x, y = e.button.y;
            //SDL_GetMouseState(&x, &y);

            /*std::cout << "Event x : " << x << std::endl;
            std::cout << "Event y : " << y << std::endl;

            std::cout << "button x : " << button.offset.x << std::endl;
            std::cout << "button y : " << button.offset.y << std::endl;*/

            // Check if mouse is in button
            bool inside = true;

            if (x < button.offset.x) {
                inside = false;
            } else if (x > button.offset.x + button.offset.w) {
                inside = false;
            } else if (y < button.offset.y) {
                inside = false;
            } else if (y > button.offset.y + button.offset.h) {
                inside = false;
            }

            if( !inside )
            {
                button.color = button.colorNormal;
            }else
            {

                if(!button.isClicked)button.color = button.colorOver;
                //Set mouse over sprite
                switch( e.type )
                {

                    case SDL_MOUSEBUTTONDOWN:
                        button.isClicked = true;
                        button.color = button.colorClick;
                        break;

                    case SDL_MOUSEBUTTONUP:
                        button.isClicked = false;
                        button.color = button.colorOver;
                        break;
                    default:

                        break;
                }
            }
        }
    }

    void draw(Button const &button, my::Surface const &sur) {

        my::Surface sur1(button.offset.w, button.offset.h);
        sur1.fill(
                button.color[0],
                button.color[1],
                button.color[2],
                255
        );

        sur1.blit(sur.surface,&button.offset);
    }

    SDL_Rect getPosition(Button const &button){
        return button.offset;
    }

    void clearSurface(Button const &button){
        //tile.surface->fill(0,0,0,0);
    }
}


#endif //SDL_DEMO_BUTTON_H
