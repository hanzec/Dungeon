#ifndef DUNGEON_COMS327_F19_GAMECONTENT_H
#define DUNGEON_COMS327_F19_GAMECONTENT_H

#include <string>
#include <unordered_map>
#include "rapidjson/reader.h"
#include "rapidjson/error/en.h"
#include "../../GameCommon.h"

using namespace std;

typedef enum{
    kStartReadObject
}State;

class GameContent : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>, GameContent> {
protected:
public:
    int color,range;
    string description, name,speed, damage;

    GameContent(uint32_t id) :  id_(id), state_(kStartReadObject){}

    //imported from rapid Json
    bool Null();
    bool Bool(bool b);
    bool Int(int i);
    bool Uint(unsigned i);
    bool Int64(int64_t i);
    bool Uint64(uint64_t i);
    bool Double(double d);
    bool RawNumber(const Ch* str, rapidjson::SizeType length, bool copy);
    bool String(const Ch* str, rapidjson::SizeType length, bool copy);
    bool StartObject();
    bool Key(const Ch* str, rapidjson::SizeType length, bool copy);
    bool EndObject(rapidjson::SizeType memberCount);
    bool StartArray();
    bool EndArray(rapidjson::SizeType elementCount);

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
    State state_;
    uint32_t id_;

};
#endif