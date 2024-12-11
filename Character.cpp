#include "Character.h" 

Character::Character(std::string n) : name(n), affection(0) {}

void Character::addAffection(int n) {
    affection += n;
}

int Character::getAffection() {
    return affection;
}

void Character::setAffection(int affection) {
    this->affection = affection; 
}