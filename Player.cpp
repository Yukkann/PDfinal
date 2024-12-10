#include <iostream>
#include "Player.h"
Player::Player() : academic(0), popularity(0), charm(0), stamina(0), 
                    fatigue(0), lucky(5), move(30), sick(0) {}

void Player::setPlayer(const std::string& playerName, const int& type) {
    this->playerName = playerName;
    
    if(type == 1) {
        std::cout << "你大概是一個 NERD\n";
        academic = 100;
        stamina = 20;
        popularity = 50;
        charm = 10;
    }
    else if (type == 2) {
        std::cout << "你是一個 Social Queen\n";
        academic = 20;
        stamina = 50;
        popularity = 100;
        charm = 20;
    }
    else if (type == 3) {
        std::cout << "你是一個 陽光少女\n";
        academic = 20;
        stamina = 50;
        popularity = 100;
        charm = 20;
    }
    else if (type == 4) {
        std::cout << "你是一個 Genius\n";
        academic = 200;
        stamina = 0;
        popularity = 100;
        charm = 50;
        move = 60;
        lucky = 100;
    }
    else if (type == 5) {
        std::cout << "你是一個 Indian chill guy\n";
        academic = 150;
        stamina = 50;
        popularity = 200;
        charm = 0;
        move = 60;
        lucky = 100;
    }
}

void Player::modifyStats(int aca, int pop, int chr, int fat, int sta, int luc) {
    academic += aca;
    popularity += pop;
    charm += chr;
    fatigue += fat;
    stamina += sta;
    lucky += luc;
}

bool Player::successfullGuy(int score) {
    if(score == 75)
        return true;
    else if(score < 50)
        return false;
    else {
        int averageScore = academic + popularity * 2.5 + charm * 2 + stamina * 1.5 - fatigue * 2 + lucky * 3;
        if(averageScore > 2500)
            return true;
        else
            return false;
    }
}

// Getter implementations
int Player::getAcademic() const { return academic; }
int Player::getStamina() const { return stamina; }
int Player::getPopularity() const { return popularity; }
int Player::getCharm() const { return charm; }
int Player::getFatigue() const { return fatigue; }
std::string Player::getName() const { return playerName; }
int Player::getMove() const { return move; }
int Player::getLucky() const { return lucky; }
bool Player::getSick() const {return sick;};
void Player::displayPlayer(){
    std::cout << "<" << playerName << "的目前狀態> 學科能力：" << academic << " 人緣：" << popularity << " 魅力：" << charm << " 疲勞值：" << fatigue << " 體能：" << stamina << " 幸運：" << lucky << "。" << std::endl;
}
void Player::print(){
    std::cout << "你可以選擇做這些事情：";
    std::cout <<"1.study(消耗10點行動值), 2.exercise(消耗10點行動值), 3.social(消耗10點行動值), 4.eat(消耗5點行動值，減少一點點疲勞), 5.pray (消耗10點行動值，可增加幸運值，洗除妳的罪孽), 6.sleep(清空所有行動值，減少疲勞值)\n";
}
// check if fatigue is too high
void Player::checkSick(){
    if(fatigue >= 100){
        sick = true;
    }
    else{
        sick = false;
    }

}