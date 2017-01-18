//
// Created by roberto on 09.01.17.
//

#ifndef SDL_DEMO_TILE_H
#define SDL_DEMO_TILE_H

#include <glob.h>
#include <iostream>
#include <SDL2/SDL_quit.h>
#include <vector>
#include <SDL2/SDL_rect.h>
#include <functional>
#include <SDL2/SDL_events.h>
#include "Surface.h"
#include "Application.h"
#include <string>

namespace my {
    class Tile {
    public:
        Tile(size_t width, size_t heigth, std::string str);

        ~Tile();

        mutable my::Surface *surface;

        void fill(Uint8 r, Uint8 g, Uint8 b);

        bool isOver = false;
        mutable bool isClicked = false;
        mutable SDL_Rect offset;
        mutable std::vector<Uint8> color = {180, 180, 180};
        std::vector<Uint8> colorNormal = {180, 180, 180};
        std::vector<Uint8> colorOver = {100, 100, 100};
        std::vector<Uint8> colorClick = {255, 0, 0};

        std::function<int()> callBack = []() -> int {};

        template<typename T>
        void onClick(T c);

        std::string name;


    };

    Tile::Tile(size_t width, size_t heigth, std::string str) : surface(new my::Surface(width, heigth)) {
        offset.w = width;
        offset.h = heigth;
        name = str;
        //surface->fill(255, 255, 255, 255);
    }

    Tile::~Tile() {

    }

    void Tile::fill(Uint8 r, Uint8 g, Uint8 b) {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }

    template<typename T>
    void Tile::onClick(T c) {
        callBack = c;
    }

    void setPosition(Tile const &tile, SDL_Rect const &offset) {
        tile.offset = offset;
    }

    bool isInside(const Tile &tile, int x, int y);

    void handleEvent(Tile const &tile, SDL_Event &e) {

        if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {

            int x = e.button.x, y = e.button.y;

            switch (e.type) {

                case SDL_MOUSEBUTTONDOWN:
                    tile.isClicked = true;
                    //std::cout << "is clicked" << std::endl;
                    break;

                case SDL_MOUSEBUTTONUP:
                    //if (tile.isClicked)tile.callBack();
                    tile.isClicked = false;
                    //std::cout << "is not clicked" << std::endl;
                    break;
                default:
                    break;
            }

            // Check if mouse is in tile
            bool inside = true;

            inside = isInside(tile, x, y);

            if (!inside) {
                //tile.isClicked = false;
            } else {
                if (tile.isClicked) {
                    int strength = tile.callBack();
                    int realX = x - tile.offset.x - strength / 2;
                    int realY = y - tile.offset.y - strength / 2;

                    std::cout << x << ":xy " << y << std::endl;
                    std::cout << tile.offset.x << ":o " << tile.offset.y << std::endl;
                    std::cout << realX << ":r " << realY << std::endl;
                    std::cout << tile.name << std::endl;

                    /*realX = 25;
                    realY = 43 + 5;*/

                    for (int i = 0; i < strength; i++) {
                        for (int j = 0; j < strength; j++) {
                            //if(isInside(tile, realX + j, realY + i))
                            {
                                tile.surface->set_pixel(realX + j, realY + i, 255, 0, 0, 255);
                            }
                        }
                    }
                }
            }
        }
    }

    bool isInside(const Tile &tile, int x, int y) {
        bool inside = true;
        if (x < tile.offset.x) {
                inside = false;
            } else if (x > tile.offset.x + tile.offset.w) {
                inside = false;
            } else if (y < tile.offset.y) {
                inside = false;
            } else if (y > tile.offset.y + tile.offset.h) {
                inside = false;
            }
        return inside;
    }

    void draw(Tile const &tile, my::Surface const &sur) {
        tile.surface->blit(sur.surface, &tile.offset);
    }

    SDL_Rect getPosition(Tile const &tile) {
        return tile.offset;
    }
}


#endif //SDL_DEMO_TILE_H
