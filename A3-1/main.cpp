#include <SDL2/SDL.h>
#include "Application.h"


using namespace std;

#undef main

int main() {
    my::Application app;

    my::Window win("Mein Window", 640, 480);
    win.draw(my::Surface("/home/roberto/Documents/WS16/CPlusPlus/A3-1/robot.bmp"));
    win.set_pos(50,50);
    win.update();

    my::Window win2("Mein nächstes Window", 640, 480);


    app.run();
    return 0;
}