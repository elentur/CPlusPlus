//
// Created by roberto on 16.12.16.
//

#ifndef SDL_DEMO_SURFACE_H
#define SDL_DEMO_SURFACE_H

#include <stdlib.h>

namespace my {

    class Surface {

    public:
        Surface(const char *path);

        Surface(size_t width, size_t height);

        ~Surface();

        SDL_Rect size();

        void fill(Uint8 r, Uint8 g, Uint8 b);

        void set_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);

        void blit(SDL_Surface *screen, SDL_Rect *offset);

        SDL_Surface *surface;
    };

    Surface::Surface(const char *file) {

        surface = SDL_LoadBMP(file);

        if (surface == NULL) {
            std::cerr << "Coud not create Surface with Image path: " << SDL_GetError() << std::endl;
            exit(1);
        }
    }

    Surface::Surface(size_t width, size_t height) {
        surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
        if (surface == NULL) {
            std::cerr << "Coud not create Surface with width: " << width << " and heigth: " << height << " :"
                      << SDL_GetError() << std::endl;
            exit(1);
        }
    }

    SDL_Rect Surface::size() {
        return surface->clip_rect;
    }

    void Surface::fill(Uint8 r, Uint8 g, Uint8 b) {
        if (SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, r, g, b)) < 0) {
            std::cerr << "Coud not create Surface with Color " << r << " " << g << " " << b << ": " << SDL_GetError()
                      << std::endl;
            exit(1);
        }
    }

    void Surface::set_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
        Uint32 color = SDL_MapRGB(surface->format, r, g, b);
        Uint8 *pixel = (Uint8 *) surface->pixels;
        pixel += (y * surface->pitch) + (x * sizeof(Uint32));
        *((Uint32 *) pixel) = color;
    }

    void Surface::blit(SDL_Surface *screen, SDL_Rect *offset) {
        if (screen == nullptr) {
            std::cerr << "Screen can't be null!" << std::endl;
            exit(1);
        }

        SDL_BlitSurface(surface, NULL, screen, offset);
    }

    Surface::~Surface() {
        SDL_FreeSurface(surface);
    }
}

#endif //SDL_DEMO_SURFACE_H
