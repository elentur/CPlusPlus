//
// Created by roberto on 09.01.17.
//

#ifndef SDL_DEMO_IMGBUTTON_H
#define SDL_DEMO_IMGBUTTON_H

#include <glob.h>
#include <iostream>
#include <SDL2/SDL_quit.h>
#include <vector>
#include "Surface.h"

namespace my {
    class ImgButton {
    public:
        ImgButton(string path, size_t width, size_t heigth);

        ~ImgButton();

        void fill(Uint8 r, Uint8 g, Uint8 b);

        my::Surface * surNormal;
        my::Surface * surHover;
        my::Surface * surClicked;
        mutable my::Surface * surCurrent;

        bool isOver = false;
        mutable bool isClicked = false;
        mutable SDL_Rect offset;
        mutable std::vector<Uint8> color = {180, 180, 180};
        std::vector<Uint8> colorNormal = {180, 180, 180};
        std::vector<Uint8> colorOver = {100, 100, 100};
        std::vector<Uint8> colorClick = {255, 0, 0};

        mutable char * _suffix = (char *) "_normal.bmp";

        std::function<void()> callBack =[]{};

        template<typename T>
        void onClick(T c);


    };

    ImgButton::ImgButton(string path, size_t width, size_t heigth) : surNormal(new my::Surface(path +  "_normal.bmp")), surHover(new my::Surface(path +  "_hover.bmp")), surClicked(new my::Surface(path +  "_clicked.bmp")) , surCurrent(surNormal) {
        offset.w = width;
        offset.h = heigth;
    }

    ImgButton::~ImgButton() {

    }

    void ImgButton::fill(Uint8 r, Uint8 g, Uint8 b) {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }

    template<typename T>
    void ImgButton::onClick(T c) {
        callBack = c;
    }

    void setPosition(ImgButton const &button, SDL_Rect const &offset) {
        button.offset = offset;
    }

    void handleEvent(ImgButton const &button, SDL_Event &e) {

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
                button.surCurrent = button.surNormal;
            }else
            {

                if(!button.isClicked)button.surCurrent = button.surHover;
                //Set mouse over sprite
                switch( e.type )
                {

                    case SDL_MOUSEBUTTONDOWN:
                        button.isClicked = true;
                        button.surCurrent = button.surClicked;
                        break;

                    case SDL_MOUSEBUTTONUP:
                        if(button.isClicked)button.callBack();
                        button.isClicked = false;
                        button.surCurrent = button.surHover;
                        break;
                    default:

                        break;
                }
            }
        }
    }

    void draw(ImgButton const &button, my::Surface const &sur) {
        button.surCurrent->blit(sur.surface,&button.offset);
    }

    SDL_Rect getPosition(ImgButton const &button){
        return button.offset;
    }

    void clearSurface(ImgButton const &button){
        //button.surface->fill(0,0,0,0);
    }
}


#endif //SDL_DEMO_IMGBUTTON_H
