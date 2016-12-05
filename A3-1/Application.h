#include <SDL2/SDL.h>
#include <iostream>
#include <thread>
#include <chrono> 
namespace my
{
class Application
{
    bool Running = true;

  public:
    Application()
    {
        try
        {
            SDL_Init(SDL_INIT_VIDEO);
        }

        catch (std::runtime_error const &e)
        {
            std::cerr << "Caught exception on initializing Application: " << e.what() << std::endl;
        }
    }
    ~Application() { SDL_Quit(); }
    void run()
    {
        SDL_Event Event;
        while (Running)
        {
            SDL_PollEvent(&Event);
            if (Event.type == SDL_QUIT || Event.type == SDL_WINDOWEVENT_CLOSE)
            {
                std::cout << "exit" << std::endl;
                Running = false;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "no exit" << std::endl;
        }
    }
};
}