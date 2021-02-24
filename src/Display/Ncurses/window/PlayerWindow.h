//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_CHARACTERINFO_H
#define DUNGEON_COMS327_F19_CHARACTERINFO_H

#include <memory>
#include "Player.h"
#include "../displayCommon.h"
#include "../CursesWindow.h"

using namespace std;

/*****************************************************************************
*  The Dungeon Game Display Library - Ncurses                                *
*  Copyright (C) 2021 Hanze.Chen  me@hanzec.com                              *
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
*  @file     PlayerWindow.h                                                  *
*  @brief    This file include header of Player Window                       *
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
*  2019/03/14 | V0.0.1   | Hanze.Chen      | Create file                     *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/

class PlayerWindow : public CursesWindow{
private:
    shared_ptr<Player> playerPtr = nullptr;

public:
    PlayerWindow(shared_ptr<Player> player);

    void onUpdate();
};


#endif //DUNGEON_COMS327_F19_CHARACTERINFO_H
