#ifndef DUNGEON_V1_01_DISPLAY_H
#define DUNGEON_V1_01_DISPLAY_H

#include <panel.h>
#include "Player.h"
#include "GameCommon.h"

/*****************************************************************************
*  The Dungeon Game Display Library                                          *
*  Copyright (C) 2020 Hanze.Chen  me@hanzec.com                              *
*                                                                            *
*  This file is part of The Dungeon Game                                     *
*                                                                            *
*  This program is free software; you can redistribute it and/or modify      *
*  it under the terms of the GNU General Public License version 3 as         *
*  published by the Free Software Foundation.                                *
*                                                                            *
*  You should have received a copy of the GNU General Public License         *
*  along with OST. If not, see <http://www.gnu.org/licenses/>.               *
*                                                                            *
*  Unless required by applicable law or agreed to in writing, software       *
*  distributed under the License is distributed on an "AS IS" BASIS,         *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
*  See the License for the specific language governing permissions and       *
*  limitations under the License.                                            *
*                                                                            *
*  @file     Display.h                                                       *
*  @brief    This is the API for Game Display Library.                       *
*  Details.                                                                  *
*                                                                            *
*  @author   Hanze.Chen                                                      *
*  @email    me@hanzec.com                                                   *
*  @version  V0.0.1                                                          *
*  @date     2020/6/5                                                        *
*  @license  GNU General Public License (GPL)                                *
*                                                                            *
*----------------------------------------------------------------------------*
*  Remark         : Description                                              *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>       | <Description>                   *
*----------------------------------------------------------------------------*
*  2020/06/05 | V0.0.1   | Hanze.Chen      | Create file                     *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/


/**
 * @brief Display API
 */
class Display{
private:
    atomic<Player*> player{nullptr};
    atomic<Dungeon*> dungeon{nullptr}; 
    atomic<Display*> instance{ nullptr };

    static int initDisplayEnv();

public:
    /**
    * @brief Constructor for display subsystem
    * @details todo TBL
    *
    * @param dungeon_t the map structure for dungeon game
    * @note todo TBL
    * @attention todo TBL
    * @warning todo TBL
    * @throw std::runtime_error thrown if sdl not start correctly
    */
    Display(Dungeon * dungeon);

    /**
    * @brief de-constructor for display subsystem
    * @details todo TBL
    *
    * @note todo TBL
    * @attention todo TBL
    * @warning todo TBL
    */
    ~Display();

    static int closeDislaySystem();
    static int initDisplaySystem(Dungeon * dungeon);

    //spectcial game mode
    static void setFOWStatus(bool flag);
    static void setTeleportStatus(bool flag);

    //special screen function
    static int showDiedScreen();

    //panel realated Function
    static int showMonsterList();

    //update screen function
    static void updateDungeonMap();
    static void updatePlayer(location_t location);
    static void updateGameContent(location_t location);
};
#endif //DUNGEON_V1_01_DISPLAY_H
