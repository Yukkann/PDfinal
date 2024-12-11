#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
private:
    std::string name;  
    int affection = 0; // 好感度

public:
    // constructor 
    Character(std::string n);

    // 修改好感度
    void addAffection(int n);
    
    // 取得好感度
    int getAffection();
    
    // 設定好感度
    void setAffection(int affection);
};

#endif