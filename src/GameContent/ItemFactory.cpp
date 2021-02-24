#include <vector>
#include <cstdlib>
#include <unordered_map>
#include "../../include/GameCommon.h"
#include "../../include/GameContant/Item.h"
#include "../../include/GameContant/ItemFactory.h"

ItemFactory::ItemFactory(std::vector<std::unordered_map<std::string, std::string> > attributeList){
    int index = 0;
    this->attributeList = attributeList;
    updateGameItemPool();
}

void ItemFactory::generateNewGameContant(Dungeon * dungeon){
     if (attributeList.size() < 10) {
        updateGameItemPool();
    }

    int randRoam = rand()%(dungeon->rooms.size() - 1);
    int randomX = dungeon->rooms[randRoam].position[curr_x] + rand()%dungeon->rooms.at(randRoam).size[curr_x];
    int randomY = dungeon->rooms[randRoam].position[curr_y] + rand()%dungeon->rooms.at(randRoam).size[curr_y];

    std::unique_ptr<Item> newItemPtr(new Item(contentPool[index]));
    dungeon->map[randomY][randomX].item = std::move(newItemPtr);
    dungeon->map[randomY][randomX].isItemInit = true;
    
    if (contentPool[index]["TYPE"] == "WEAPON")
        dungeon->map[randomY][randomX].item->symbol = '|';
    else if (contentPool[index]["TYPE"] == "OFFHAND")
        dungeon->map[randomY][randomX].item->symbol = '}';
    else if (contentPool[index]["TYPE"] == "RANGED")
        dungeon->map[randomY][randomX].item->symbol = '[';
    else if (contentPool[index]["TYPE"] == "ARMOR")
        dungeon->map[randomY][randomX].item->symbol = ']';
    else if (contentPool[index]["TYPE"] == "HELMET")
        dungeon->map[randomY][randomX].item->symbol = '(';
    else if (contentPool[index]["TYPE"] == "CLOAK")
        dungeon->map[randomY][randomX].item->symbol = '{';
    else if (contentPool[index]["TYPE"] == "GLOVES")
        dungeon->map[randomY][randomX].item->symbol = '\\';
    else if (contentPool[index]["TYPE"] == "BOOTS")
        dungeon->map[randomY][randomX].item->symbol = '=';
    else if (contentPool[index]["TYPE"] == "RING")
        dungeon->map[randomY][randomX].item->symbol = '"';
    else if (contentPool[index]["TYPE"] == "AMULET")
        dungeon->map[randomY][randomX].item->symbol = '_';
    else if (contentPool[index]["TYPE"] == "LIGHT")
        dungeon->map[randomY][randomX].item->symbol = '+';
    else if (contentPool[index]["TYPE"] == "SCROLL")
        dungeon->map[randomY][randomX].item->symbol = '?';
    else if (contentPool[index]["TYPE"] == "FLASK")
        dungeon->map[randomY][randomX].item->symbol = '!';
    else if (contentPool[index]["TYPE"] == "GOLD")
        dungeon->map[randomY][randomX].item->symbol = '$';
    else if (contentPool[index]["TYPE"] == "AMMUNITION")
        dungeon->map[randomY][randomX].item->symbol = '/';
    else if (contentPool[index]["TYPE"] == "FOOD")
        dungeon->map[randomY][randomX].item->symbol = ',';
    else if (contentPool[index]["TYPE"] == "WAND")
        dungeon->map[randomY][randomX].item->symbol = '-';
    else if (contentPool[index]["TYPE"] == "CONTAINER")
        dungeon->map[randomY][randomX].item->symbol = '%';
    else
       dungeon->map[randomY][randomX].item->symbol = '&'; 
}
void ItemFactory::updateGameItemPool(){
    std::unordered_map<std::string, std::string> tmpAttribute;

    for(size_t j = 0; j < 100; j++){
        for(size_t i = 0; i < attributeList.size (); i++){
            tmpAttribute = attributeList.at(i);
            if (rand()%100 < stoi(tmpAttribute["RRTY"])) {
                contentPool.push_back(tmpAttribute);
            }
        } 
    }
    
}
