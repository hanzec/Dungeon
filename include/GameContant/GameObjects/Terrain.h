//
// Created by hanzech on 6/8/20.
//

#ifndef DUNGEON_COMS327_F19_TERRAIN_H
#define DUNGEON_COMS327_F19_TERRAIN_H

#include <string>
#include "GameContent.h"
#include "SDL2/SDL_surface.h"

class Terrain : public GameContent{
public:
    const char * getTerrainName();
    SDL_Surface * getTerrainImagine();
};

#endif //DUNGEON_COMS327_F19_TERRAIN_H
