//
// Created by hanzech on 6/6/20.
//

#include "Window.h"

SDL_Window *Window::getWindowPtr() {
    return this->base_window;
}

SDL_Renderer *Window::getRendererPtr() {
    return this->base_renderer;
}
