//
// Created by hanzech on 6/6/20.
//

#ifndef DUNGEON_COMS327_F19_RESOURCESMANAGER_H
#define DUNGEON_COMS327_F19_RESOURCESMANAGER_H

/*****************************************************************************
*  The Dungeon Game Resources Manger                                         *
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
*  @file     ResourcesManager.h                                              *
*  @brief    This file is use to loading necessary resources to memory.      *
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
#include <string>
#include <vector>
#include "../../include/GameContant/GameObjects/GameContent.h"

namespace Resource{

    static const char * terrain_folder = "terrain/"; ///< sub-folder for storage terrain

    static const char * game_object_folder = "object/"; ///< sub-folder for storage in-game object

    /**
    * @brief Resources Management API
    */
    class ResourcesManager {
    public:
        ~ResourcesManager();

        /**
        * @brief Constructor for Resource management subsystem
        * @details todo TBL
        *
        * @param std::string location for recourse folder, default value is [./resources/]
        * @note todo TBL
        * @attention todo TBL
        * @warning todo TBL
        * @throw std::runtime_error thrown if folder not exists
        */
        explicit ResourcesManager(const std::string& recourseFolder = std::string("resources/"));

    private:

        std::vector<GameContent> strVector;
    };
}



#endif //DUNGEON_COMS327_F19_RESOURCESMANAGER_H
