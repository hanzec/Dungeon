//
// Created by chen_ on 2019/1/31.
//

//WINDOW *menu  todo: menu need to add;


int closeScreen(baseScreen_t * screen){
    destroy_win(screen->pcInfoWindow);
    destroy_win(screen->statusWindow);
    destroy_win(screen->dungeonWindow);
    return 0;
}

int updatePCLocation(baseScreen_t * screen,npc_t * pc){
    updatePc(screen->dungeonWindow,pc);
    wrefresh(screen->dungeonWindow);
}

int updateMonsterLocation(baseScreen_t * screen, monster_t * monster){
    updateMonster(screen->dungeonWindow,monster);
    wrefresh(screen->dungeonWindow);
}

int updateDungeonScreen(baseScreen_t * screen, dungeon_t *dungeon){
    updateDungeon(screen->dungeonWindow,dungeon);
    wrefresh(screen->dungeonWindow);
}

int showDiedScreen(baseScreen_t * screen){
    //closeScreen(screen);
    DiedScreen();
    endwin();
}

