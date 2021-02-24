#ifndef DUNGEON_COMS327_F19_CURSESWINDOW_H
#define DUNGEON_COMS327_F19_CURSESWINDOW_H

#include <string>
#include <ncurses.h>

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
*  @file     CursesWindow.h                                                  *
*  @brief    This file include Abstract Interface of CursesWindow            *
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

class CursesWindow{
private:
    string windowName;
    int currentWidth = 0, currentHeight = 0;
protected:
    WINDOW * windowPtr = nullptr;

    /**
    * @brief getter for currentHeight 
    * @details getter for currentHeight
    * @return value of currentHeight
    */
    int getCurrentWidth(){ return currentWidth;}

    /**
    * @brief setter for currentHeight 
    * @details setter for currentHeight
    * @param newWidth new value for currentWidth
    */
    void setNewWidth(int newWidth){ this->currentWidth = newWidth;}

    /**
    * @brief getter for currentHeight 
    * @details getter for currentHeight
    * @return value of currentHeight
    */
    int getCurrentHeight(){ return currentHeight;}

    /**
    * @brief setter for currentHeight  
    * @details setter for currentHeight 
    * @param newHeight new value for currentHeight
    */
    void setNewHeight(int newHeight){ this->currentHeight = newHeight;}

public:
    /**
    * @brief Constructor for CursesWindow
    * @details this will create a new Ncurses window with specific Height and Width from specific location
    * @param windowName the name of the window
    * @param height the height of the window
    * @param length the length of the window
    * @param xPos the LEFT CONNOR x position
    * @param xPos the LEFT CONNOR y position
    */
    CursesWindow(string windowName, int height, int width, int yPos, int xPos)
        :windowName(windowName),currentWidth(width),currentHeight(height){
        this->windowPtr = newwin(height, width, yPos, xPos);
    }

    /**
    * @brief Handler when window on Resized
    * @details will call once on every time when base window is resized
    * @note This method will not handle size change on X asix by default
    * @param newWidth the new window Width
    * @param newHeight the new window Length
    */
    void onResizeWindow(int newWidth, int newHeight){
        this->setNewWidth(newWidth);
        wresize(this->windowPtr, this->getCurrentWidth(), newWidth);
    };

    /**
    * @brief Handler when window need Update content
    * @details will call once on every time when this window need refresh
    */
    virtual void onUpdate() = 0;
};

#endif //DUNGEON_COMS327_F19_CURSESWINDOW_H
