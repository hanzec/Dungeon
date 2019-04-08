#include <sstream>
#include <GameContent.h>

    GameContent::GameContent(std::unordered_map<std::string, std::string> base){
        this->name = base["NAME"];
        this->description = base["DESC"];
        this->damage = this->diceToDouble(base["DAM"]);
        this->speed = this->diceToDouble(base["SPEED"]);
    }

    double GameContent::diceToDouble(const std::string diceString){
        double result;
        int dice,size;
        std::string tmpString;
        srand (time(NULL));
        std::istringstream iss(diceString);

        std::getline(iss,tmpString,'+');
        result = std::stoi(tmpString);
        std::getline(iss,tmpString,'d');
        dice = std::stoi(tmpString);
        std::getline(iss,tmpString,'\0');
        size = std::stoi(tmpString);

        for (int i = 0; i < dice; ++i)
            result += rand()%(size + 1);
        return result;
    }

    double GameContent::getSpeed(){return this->speed;}

    double GameContent::getRange(){return this->range;}

    double GameContent::getDamage(){return this->damage;}

    std::string GameContent::getName(){ return this->name;}
    
    std::string GameContent::getDescription(){return this->description;}
