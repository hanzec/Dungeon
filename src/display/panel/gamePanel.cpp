//
// Created by 陈瀚泽 on 2019-03-14.
//

#include "../../../include/display/panel/gamePanel.h"

int gamePanel::hidePanel() {
    if (this->panel != nullptr){
        bottom_panel(this->panel);
        update_panels();
        doupdate();
        return 0;
    }
    return -1;
}

int gamePanel::displayPanel() {
    if (this->panel != nullptr){
        top_panel(this->panel);
        update_panels();
        doupdate();
        return 0;
    }
    return -1;
}
