# include<iostream>
#include"Event.h"
using namespace std;
Events::Events(string description, string choicesD):description(description), choicesD(choicesD) {}
bool Events::checkThreshold(Player& p, int week){
    return true;
}
void Events::setResultOne1(int a, int b, int c, int d, int e, int f, string resultOneD1, int stdIndex, int stdThreshold){
    int temp[] = {a, b, c, d, e, f};
        for (int i = 0; i < 6; ++i) {
            resultOneL1[i] = temp[i];
        }
    this->resultOneD1 = resultOneD1;
    this->standardOne[0] = stdIndex;
    this->standardOne[1] = stdThreshold;
}
void Events::setResultOne2(int a, int b, int c, int d, int e, int f, string resultOneD2){
    int temp[] = {a, b, c, d, e, f};
        for (int i = 0; i < 6; ++i) {
            resultOneL2[i] = temp[i];
        }
    this->resultOneD2 = resultOneD2;
}
void Events::setResultTwo1(int a, int b, int c, int d, int e, int f, string resultTwoD1, int stdIndex, int stdThreshold){
    int temp[] = {a, b, c, d, e, f};
        for (int i = 0; i < 6; ++i) {
            resultTwoL1[i] = temp[i];
        }
    this->resultTwoD1 = resultTwoD1;
    this->standardTwo[0] = stdIndex;
    this->standardTwo[1] = stdThreshold;
}
void Events::setResultTwo2(int a, int b, int c, int d, int e, int f, string resultTwoD2){
    int temp[] = {a, b, c, d, e, f};
        for (int i = 0; i < 6; ++i) {
            resultTwoL2[i] = temp[i];
        }
    this->resultTwoD2 = resultTwoD2;
}
void Events::setResultThree1(int a, int b, int c, int d, int e, int f, string resultThreeD1, int stdIndex, int stdThreshold){
    int temp[] = {a, b, c, d, e, f};
        for (int i = 0; i < 6; ++i) {
            resultThreeL1[i] = temp[i];
        }
    this->resultThreeD1 = resultThreeD1;
    this->standardThree[0] = stdIndex;
    this->standardThree[1] = stdThreshold;
}
void Events::setResultThree2(int a, int b, int c, int d, int e, int f, string resultThreeD2){
    int temp[] = {a, b, c, d, e, f};
        for (int i = 0; i < 6; ++i) {
            resultThreeL2[i] = temp[i];
        }
    this->resultThreeD2 = resultThreeD2;
}

void Events::makeChoices(Player& p, int week){ //the process where event happens and player react to get result
    tp.setSpeed(20);
    tp.type(description);
    cout << endl;
    tp.type(choicesD);
    cout << endl;
    int choice = 0;
    while(true){
        cin >> choice;
        cin.ignore();
        if (choice == 1 || choice == 2 || choice == 3) {
            break;
        }
        else{
            tp.type("請輸入1到3 再直接按下Enter");
        }
    }
    
    int playerPoints[] = {standardOne[0], standardTwo[0], standardThree[0]};
    for (int i = 0; i < 3; i++) {
        switch (playerPoints[i]) {
            case 1:
                playerPoints[i] = p.getAcademic();
                break;
            case 2:
                playerPoints[i] = p.getPopularity();
                break;
            case 3:
                playerPoints[i] = p.getCharm();
                break;
            case 4:
                playerPoints[i] = p.getStamina();
                break;
            case 5:
                playerPoints[i] = p.getFatigue();
                break;
            case 6:
                playerPoints[i] = p.getLucky()
            
            default:
                break;
        }
    }
    
    switch (choice) {
        case 1:
            if (playerPoints[0] >= standardOne[1]*week) {
                cout << resultOneD1 << endl;
                p.modifyStats(resultOneL1[0], resultOneL1[1], resultOneL1[2], resultOneL1[3], resultOneL1[4], resultOneL1[5]);
                cout << "你的能力值增減為： " << "學科能力" << resultOneL1[0] << "，" << "人緣" << resultOneL1[1] << "，" << "魅力" << resultOneL1[2] << "，" << "體能" << resultOneL1[3] << "，" << "疲勞值" << resultOneL1[4] << "，" << "幸運" << resultOneL1[5] << "。" << endl;
            }
            else{
                cout << resultOneD2 << endl;
                p.modifyStats(resultOneL2[0], resultOneL2[1], resultOneL2[2], resultOneL2[3], resultOneL2[4], resultOneL2[5]);
                cout << "你的能力值增減為： " << "學科能力" << resultOneL2[0] << "，" << "人緣" << resultOneL2[1] << "，" << "魅力" << resultOneL2[2] << "，" << "體能" << resultOneL2[3] << "，" << "疲勞值" << resultOneL2[4] << "，" << "幸運" << resultOneL2[5] << "。" << endl;
            }
            break;
        case 2:
            if (playerPoints[1] >= standardTwo[1]*week) {
                cout << resultTwoD1 << endl;
                p.modifyStats(resultTwoL1[0], resultTwoL1[1], resultTwoL1[2], resultTwoL1[3], resultTwoL1[4], resultTwoL1[5]);
                cout << "你的能力值增減為： " << "學科能力" << resultTwoL1[0] << "，" << "人緣" << resultTwoL1[1] << "，" << "魅力" << resultTwoL1[2] << "，" << "體能" << resultTwoL1[3] << "，" << "疲勞值" << resultTwoL1[4] << "，" << "幸運" << resultTwoL1[5] << "。" << endl;
            }
            else{
                cout << resultTwoD2 << endl;
                p.modifyStats(resultTwoL2[0], resultTwoL2[1], resultTwoL2[2], resultTwoL2[3], resultTwoL2[4], resultTwoL2[5]);
                cout << "你的能力值增減為： " << "學科能力" << resultTwoL2[0] << "，" << "人緣" << resultTwoL2[1] << "，" << "魅力" << resultTwoL2[2] << "，" << "體能" << resultTwoL2[3] << "，" << "疲勞值" << resultTwoL2[4] << "，" << "幸運" << resultTwoL2[5] << "。" << endl;
            }
            break;
        case 3:
            if (playerPoints[2] >= standardThree[1]*week) {
                cout << resultThreeD1 << endl;
                p.modifyStats(resultThreeL1[0], resultThreeL1[1], resultThreeL1[2], resultThreeL1[3], resultThreeL1[4], resultThreeL1[5]);
                cout << "你的能力值增減為： " << "學科能力" << resultThreeL1[0] << "，" << "人緣" << resultThreeL1[1] << "，" << "魅力" << resultThreeL1[2] << "，" << "體能" << resultThreeL1[3] << "，" << "疲勞值" << resultThreeL1[4] << "，" << "幸運" << resultThreeL1[5] << "。" << endl;
            }
            else{
                cout << resultThreeD2 << endl;
                p.modifyStats(resultThreeL2[0], resultThreeL2[1], resultThreeL2[2], resultThreeL2[3], resultThreeL2[4], resultThreeL2[5]);
                cout << "你的能力值增減為： " << "學科能力" << resultThreeL2[0] << "，" << "人緣" << resultThreeL2[1] << "，" << "魅力" << resultThreeL2[2] << "，" << "體能" << resultThreeL2[3] << "，" << "疲勞值" << resultThreeL2[4] << "，" << "幸運" << resultThreeL2[5] << "。" << endl;
            }
            break;

        default:
            break;
    }
}

//角色相關事件
CharacterEvents::CharacterEvents(int affecOne, int affecTwo, int affecThree, string description, string choicesD) :Events::Events(description, choicesD){
    int temp [] = {affecOne, affecTwo, affecThree};
    for (int i=0; i<3; i++) {
        this->changeAffection[i] = temp[i];
    }
}

int CharacterEvents::charMakeChoices(Player& p){
    cout << description << endl;
    cout << choicesD << endl;
    int choice = 0;
    while(true){
        cin >> choice;
        if (choice == 1 || choice == 2 || choice == 3) {
            break;
        }
        else{
            cout << "是不是就叫你輸入1到3 再玩一次試試看啊";
        }
    }
    
    switch (choice) {
        case 1:
            cout << resultOneD2 << endl;
            p.modifyStats(resultOneL2[0], resultOneL2[1], resultOneL2[2], resultOneL2[3], resultOneL2[4], resultOneL2[5]);
            cout << "你的能力值增減為： " << "學科能力" << resultOneL2[0] << "，" << "人緣" << resultOneL2[1] << "，" << "魅力" << resultOneL2[2] << "，" << "體能" << resultOneL2[3] << "，" << "疲勞值" << resultOneL2[4] << "，" << "幸運" << resultOneL2[5] << "。" << endl;
            return changeAffection[0];
            break;
        case 2:
            cout << resultTwoD2 << endl;
            p.modifyStats(resultTwoL2[0], resultTwoL2[1], resultTwoL2[2], resultTwoL2[3], resultTwoL2[4], resultTwoL2[5]);
            cout << "你的能力值增減為： " << "學科能力" << resultTwoL2[0] << "，" << "人緣" << resultTwoL2[1] << "，" << "魅力" << resultTwoL2[2] << "，" << "體能" << resultTwoL2[3] << "，" << "疲勞值" << resultTwoL2[4] << "，" << "幸運" << resultTwoL2[5] << "。" << endl;
            return changeAffection[1]
            break;
        case 3:
            cout << resultThreeD2 << endl;
            p.modifyStats(resultThreeL2[0], resultThreeL2[1], resultThreeL2[2], resultThreeL2[3], resultThreeL2[4], resultThreeL2[5]);
            cout << "你的能力值增減為： " << "學科能力" << resultThreeL2[0] << "，" << "人緣" << resultThreeL2[1] << "，" << "魅力" << resultThreeL2[2] << "，" << "體能" << resultThreeL2[3] << "，" << "疲勞值" << resultThreeL2[4] << "，" << "幸運" << resultThreeL2[5] << "。" << endl;
            return changeAffection[2];

            break;

        default:
            break;
    }
    return 0;
}


