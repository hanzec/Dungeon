#include <list>
#include "../../include/GameContant/Monster.h"

class MonsterListUtils
{
private:
    MonsterListUtils(/* args */);
    ~MonsterListUtils();
public:
    static void removeMinMonster(std::list<Monster> * monsters);
    static void insertMonster(std::list<Monster> * monsters, Monster monster);
};