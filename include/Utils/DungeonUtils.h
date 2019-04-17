#include <list>
#include "../../include/GameContant/Monster.h"

namespace DungeonUtils {
    class OrderedList{
    private:
        OrderedList(/* args */);
        ~OrderedList();
    public:
        static std::shared_ptr<Monster> pop_min(std::list<std::shared_ptr<Monster> > * monsters);
        static void push(std::list<std::shared_ptr<Monster> > * monsters, std::shared_ptr<Monster> monster);
    };

    class Path{
    private:
        Path();
        ~Path();
    public:
        static void dijkstra_tunnelling(dungeon_t *dungeon, location_t playerLocation);
        static void dijkstra_no_tunnelling(dungeon_t *dungeon, location_t playerLocation);
    };
}