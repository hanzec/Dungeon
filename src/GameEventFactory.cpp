//
// Created by hanzech on 6/8/20.
//


#include "../include/GameEventFactory.h"

GameEventFactory::GameEventFactory() noexcept = default;

SDL_UserEvent GameEventFactory::generateEvent(EventType eventType,Uint32 time_stamp) {
    SDL_UserEvent new_event;


    if(sdl_event_id[eventType] == 0)
        sdl_event_id[eventType] = SDL_RegisterEvents(1);

    SDL_zero(new_event);
    new_event.timestamp = time_stamp;
    new_event.type = sdl_event_id[eventType];

    return new_event;
}
