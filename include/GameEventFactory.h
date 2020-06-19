//
// Created by hanzech on 6/8/20.
//

#ifndef DUNGEON_COMS327_F19_GAMEEVENTFACTORY_H
#define DUNGEON_COMS327_F19_GAMEEVENTFACTORY_H

#include "GameEvents.h"
#include "SDL2/SDL_events.h"

/*****************************************************************************
*  The Dungeon Game Custom SDL Event Library                                 *
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
*  @file     GameEventFactory.h                                              *
*  @brief    This is the Factory for custom SDL event.                       *
*  Details.                                                                  *
*                                                                            *
*  @author   Hanze.Chen                                                      *
*  @email    me@hanzec.com                                                   *
*  @version  V0.0.1                                                          *
*  @date     2020/6/8                                                        *
*  @license  GNU General Public License (GPL)                                *
*                                                                            *
*----------------------------------------------------------------------------*
*  Remark         : Description                                              *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>       | <Description>                   *
*----------------------------------------------------------------------------*
*  2020/06/08 | V0.0.1   | Hanze.Chen      | Create file                     *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/

Uint32 sdl_event_id[num_event] = {0};

class GameEventFactory {
public:
    static SDL_UserEvent generateEvent(EventType eventType, Uint32 time_stamp);
private:
    GameEventFactory() noexcept;

};


#endif //DUNGEON_COMS327_F19_GAMEEVENTFACTORY_H
