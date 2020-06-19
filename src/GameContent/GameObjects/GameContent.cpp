#include <sstream>
#include <ncurses.h>
#include "../../../include/GameContant/GameObjects/GameContent.h"

    GameContent::GameContent(std::unordered_map<std::string, std::string> base){
        this->name = base["NAME"];
        this->description = base["DESC"];
        this->damage = base["DAM"];
        this->speed = base["SPEED"];

        if (base["COLOR"] == "RED")
            this->color = 5;
        else if (base["COLOR"] == "BLUE") 
            this->color = 6;
        else if (base["COLOR"] == "CYAN") 
            this->color = 7;
        else if (base["COLOR"] == "GREEN") 
            this->color = 8;
        else if (base["COLOR"] == "WHITE") 
            this->color = 9;
        else if (base["COLOR"] == "BLACK") 
            this->color = 10;
        else if (base["COLOR"] == "YELLOW") 
            this->color = 11;
        else
            this->color = 12;   
    }

    double GameContent::diceToDouble(const std::string diceString){
        double result;
        int dice,size;
        std::string tmpString;
        srand (time(NULL));
        std::istringstream iss(diceString);
        
        printf("%s",tmpString.c_str());
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

    double GameContent::getRange(){return this->range;}

    std::string GameContent::getName(){ return this->name;}

    double GameContent::getSpeed(){return diceToDouble(this->speed);}

    double GameContent::getDamage(){return diceToDouble(this->damage);}
    
    std::string GameContent::getDescription(){return this->description;}
