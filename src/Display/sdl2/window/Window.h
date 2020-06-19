//
// Created by hanzech on 6/6/20.
//

#ifndef DUNGEON_COMS327_F19_WINDOW_H
#define DUNGEON_COMS327_F19_WINDOW_H

#include "SDL2/SDL.h"
#include "window/AbstractWindow.h"

class Window : public AbstractWindow<SDL_Window>{
public:
    SDL_Window * getWindowPtr();
    SDL_Renderer * getRendererPtr();
private:
    SDL_Window * base_window;
    SDL_Renderer * base_renderer;
};


#endif //DUNGEON_COMS327_F19_WINDOW_H
