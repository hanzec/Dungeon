#ifndef DUNGEON_COMS327_F19_GAMECONTENT_H
#define DUNGEON_COMS327_F19_GAMECONTENT_H

#include <map>
#include <string>
#include <unordered_map>

#include "rapidjson/reader.h"
#include "../../GameCommon.h"

using namespace std;
using namespace rapidjson;

class GameContent: public BaseReaderHandler<UTF8<>, GameContent> {
protected:
public:
    int color,range;
    string description, name,speed, damage;

    GameContent();

    //imported from rapid Json
    bool Null();
    bool Bool(bool b);
    bool Int(int i);
    bool Uint(unsigned i);
    bool Int64(int64_t i);
    bool Uint64(uint64_t i);
    bool Double(double d);
    bool RawNumber(const char* str, SizeType length, bool copy);
    bool String(const char* str, SizeType length, bool copy);
    bool StartObject();
    bool Key(const char* str, SizeType length, bool copy);
    bool EndObject(SizeType memberCount);
    bool StartArray();
    bool EndArray(SizeType elementCount);

    //used for gaminbg
    int itemID;
    string getName();
    double getSpeed();
    double getRange();
    double getDamage();
    string getDescription();
    static double diceToDouble(const string str);
    GameContent(unordered_map<string, string> base);

private:
    char symbol_;
    uint32_t id_;
};
#endif