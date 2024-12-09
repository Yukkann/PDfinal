#ifndef EVENT_CLASS_H_INCLUDED
#define EVENT_CLASS_H_INCLUDED

# include<iostream>
# include<vector>
#include <string>
#include "Player.h"
#include "Typewriter.h"
class Events{ // events in general
private:
    Typewriter tp;
protected:
    std::string description; //e.g. “上學快遲到時在路上遇到老阿伯，快紅燈了他卻還在慢慢過馬路...你會...”
    std::string choicesD; //e.g. “1. 扶著他快速通過 2. murmur：「真是馬路三寶」 3. 當作沒看到快去趕課“
    int resultOneL1 [6];
    int resultOneL2 [6];
    int resultTwoL1 [6];
    int resultTwoL2 [6];
    int resultThreeL1 [6];
    int resultThreeL2 [6];
    int standardOne [2];
    int standardTwo [2];
    int standardThree [3];
    std::string resultOneD1;
    std::string resultOneD2;
    std::string resultTwoD1;
    std::string resultTwoD2;
    std::string resultThreeD1;
    std::string resultThreeD2;
    
public:
    Events(std::string description = "", std::string choicesD = "");
    void setResultOne1(int a, int b, int c, int d, int e, int f, std::string resultOneD1, int stdIndex, int stdThreshold);
    void setResultOne2(int a, int b, int c, int d, int e, int f, std::string resultOneD2);
    void setResultTwo1(int a, int b, int c, int d, int e, int f, std::string resultTwoD1, int stdIndex, int stdThreshold);
    void setResultTwo2(int a, int b, int c, int d, int e, int f, std::string resultTwoD2);
    void setResultThree1(int a, int b, int c, int d, int e, int f, std::string resultThreeD1, int stdIndex, int stdThreshold);
    void setResultThree2(int a, int b, int c, int d, int e, int f, std::string resultThreeD2);
    virtual bool checkThreshold(Player& p, int week);
    void makeChoices(Player& p, int week);
    virtual ~Events() {}
};
#endif