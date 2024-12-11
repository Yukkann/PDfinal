#ifndef EVENTSYSTEM_CLASS_H_INCLUDED
#define EVENTSYSTEM_CLASS_H_INCLUDED
# include<iostream>
# include<vector>
#include <string>
#include"Event.h"

class EventSystem{
    public:
        std::vector<Events*> events; // 30個日常事件
        std::vector<CharacterEvents*> characEvents; // 3種角色的日常、主線事件
        // Setters
        void setEvents();
        void setCharacEvents();
};
#endif