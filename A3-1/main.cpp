#include <SDL2/SDL.h>
#include <iostream>
#include "Application.h"


using namespace std;

#undef main

int main()
{
   
   try
   {
      my::Application app;

      app.run();
      return 0;
   }

   catch ( std::runtime_error const& e )
   {
      std::cerr << "Caught exception: " << e.what() << std::endl;
   }
}
