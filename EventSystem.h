#ifndef EVENTSYSTEM_CLASS_H_INCLUDED
#define EVENTSYSTEM_CLASS_H_INCLUDED
# include<iostream>
# include<vector>
#include <string>
#include"Event.h"

class EventSystem{
    public:
        std::vector<Events*> events;
        std::vector<CharacterEvents*> characEvents;
        void setEvents();
        void setCharacEvents();
};
#endif