#include <string>
#include <vector>
#include <map>
#include <random>
#include <functional>
#include <fstream>
#include <iostream>
#include "TypeWriter.h"
#ifdef _WIN32
    #include <windows.h> // Windows 平台專屬
    #define SLEEP(ms) Sleep(ms)
#else
    #include <unistd.h> // Mac 專屬
    #define SLEEP(ms) usleep(ms * 1000)
#endif
// #include "TypewriterEffect.h" //這是打字效果處理器 用TypewriterEffect printer; 建立一個物件再用 printer.printText()印東西
using namespace std;

void showTXT(const string& filename){
        Typewriter tp;
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            tp.setSpeed(10);
            while (getline(file, line)) {
                tp.type(line);
                tp.type("\n");
            }
            file.close();
        }
    }
// 狀態效果
struct Status {
    string name;
    int duration;
    function<void(class Player&)> effect;
};

// 主角類別
class Player {
private:
    string playerName;
    int academic;      // 學科能力
    int popularity;    // 人緣
    int charm;        // 魅力
    int stamina;       // 體能
    int fatigue;      // 疲勞值
    int lucky;      // 幸運值
    int move;       // 行動點數上限
    vector<Status> statuses;  // 狀態效果
    map<string, bool> flags;  // 劇情標記

public:
    
    Player() : academic(0), popularity(0), charm(0), stamina(0),fatigue(0), lucky(5), move(30){}
    void setPlayer(const string& playerName, const int& type){
        this->playerName = playerName;
        if(type == 1){
            cout << "你大概是一個 NERD\n";
            academic = 100;
            stamina = 20;
            popularity = 50;
            charm = 10;
        }
        else if (type == 2){
            cout << "你是一個 Social Queen\n";
            academic = 20;
            stamina = 50;
            popularity = 100;
            charm = 20;
        }
        else if (type == 3){
            cout << "你是一個 陽光少女\n";
            academic = 20;
            stamina = 50;
            popularity = 100;
            charm = 20;
        }
        else if (type == 4){
            cout << "你是一個 Genius\n";
            academic = 200;
            stamina = 0;
            popularity = 100;
            charm = 50;
            move = 60;
            lucky = 100;
        }
        else if (type == 5){
            cout << "你是一個 Indian chill guy\n";
            academic = 150;
            stamina = 50;
            popularity = 200;
            charm = 0;
            move = 60;
            lucky = 100;
        }
    }
        // Getters and setters
    void modifyStats(int aca, int pop, int chr, int fat, int sta, int luc) {
        academic += aca;
        popularity += pop;
        charm += chr;
        fatigue += fat;
        stamina += sta;
        lucky += luc
    }
    bool successfullGuy(int score)
    {
        if(score == 75)
            return true;
        else if(score < 50)
            return false;
        else
        {
            int averageScore = academic + popularity * 2.5 + charm * 2 + stamina * 1.5 - fatigue * 2;

            if(averageScore > 600)
                return true;
            else
                return false;
        }
    }

    int getAcademic() const{return academic;};
    int getStamina() const{return stamina;};
    int getPopularity()const{return popularity;};    // 人緣
    int getCharm()const{return charm;};        // 魅力
    int getFatigue()const{return fatigue;};      // 疲勞值
    string getName() const{return playerName;};
    int getMove()const{return move;};
    int getLucky()const{return lucky;};
};

// NPC角色類別
class Character {
private:
    string name;
    int affection;     // 好感度
    vector<pair<int, string>> dialogues;  // 好感度門檻與對應對話
    map<int, function<void(Player&)>> specialEvents;  // 特殊事件

public:
    Character(string n) : name(n), affection(0) {}
    
    void addDialogue(int threshold, string text) {
        dialogues.push_back({threshold, text});
    }
    
    void addSpecialEvent(int threshold, function<void(Player&)> event) {
        specialEvents[threshold] = event;
    }
    
    string getCurrentDialogue() const {
        string current;
        for(const auto& d : dialogues) {
            if(affection >= d.first) {
                current = d.second;
            }
        }
        return current;
    }
    int getAffection(){return affection;};
    void setAffection(int affection){this->affection = affection;};
};


// 事件系統
class Events // events in general
{
protected:
    string description; //e.g. “上學快遲到時在路上遇到老阿伯，快紅燈了他卻還在慢慢過馬路...你會...”
    string choicesD; //e.g. “1. 扶著他快速通過 2. murmur：「真是馬路三寶」 3. 當作沒看到快去趕課“
    int resultOneL1 [6];
    int resultOneL2 [6];
    int resultTwoL1 [6];
    int resultTwoL2 [6];
    int resultThreeL1 [6];
    int resultThreeL2 [6];
    int standardOne [2];
    int standardTwo [2];
    int standardThree [3];
    string resultOneD1;
    string resultOneD2;
    string resultTwoD1;
    string resultTwoD2;
    string resultThreeD1;
    string resultThreeD2;
    
public:
    Events(string description = "", string choicesD = "");
    void setResultOne1(int a, int b, int c, int d, int e, int f, string resultOneD1, int stdIndex, int stdThreshold);
    void setResultOne2(int a, int b, int c, int d, int e, int f, string resultOneD2);
    void setResultTwo1(int a, int b, int c, int d, int e, int f, string resultTwoD1, int stdIndex, int stdThreshold);
    void setResultTwo2(int a, int b, int c, int d, int e, int f, string resultTwoD2);
    void setResultThree1(int a, int b, int c, int d, int e, int f, string resultThreeD1, int stdIndex, int stdThreshold);
    void setResultThree2(int a, int b, int c, int d, int e, int f, string resultThreeD2);
    virtual bool checkThreshold(Player& p, int week);
    void makeChoices(Player& p, int week);
};

Events::Events(string description, string choicesD):description(description), choicesD(choicesD) {}

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
            resultTwoL1[i] = temp[i];
        }
    this->resultThreeD1 = resultThreeD1;
    this->standardThree[0] = stdIndex;
    this->standardThree[1] = stdThreshold;
}
void Events::setResultThree2(int a, int b, int c, int d, int e, int f, string resultThreeD2){
    int temp[] = {a, b, c, d, e, f};
        for (int i = 0; i < 6; ++i) {
            resultTwoL2[i] = temp[i];
        }
    this->resultThreeD2 = resultThreeD2;
}

void Events::makeChoices(Player& p, int week){ //the process where event happens and player react to get result
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
                playerPoints[i] = p.getFatigue();
                break;
            case 5:
                playerPoints[i] = p.getLucky();
                break;
                
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

class TimeTriggerEvents : public Events
{
private:
    int week;
public:
    TimeTriggerEvents(int week, string description, string choicesD):Events::Events(description, choicesD), week(week){};
    bool checkWeek(int currentDay);
};

bool TimeTriggerEvents::checkWeek(int currentDay){
    if (this->week == currentDay) {
        return true;
    }
    return false;
}

class LevelTriggerEvents : public Events
{
private:
    int threshold[7];
    bool triggered; //有些事件trigger一次就好
public:
    LevelTriggerEvents(int academic, int popularity, int charm, int stamina, int fatigue, int lucky, string description, string choicesD);
    bool checkThreshold(Player& p, int week);
};


LevelTriggerEvents::LevelTriggerEvents(int academic, int popularity, int charm, int stamina, int fatigue, int lucky, string description, string choicesD) :Events::Events(description, choicesD){
    int temp[] = {academic, popularity, charm, stamina, fatigue, lucky};
    for (int i = 0; i < 6; ++i) {
        threshold[i] = temp[i];
    }
}

bool LevelTriggerEvents::checkThreshold(Player& p, int week){ // check whether pass threshold
    int temp[6] = {p.getAcademic(), p.getPopularity(), p.getCharm(), p.getStamina(), p.getFatigue(), p.getLucky()};
    for (int i=0; i<6; i++) {
        if (temp[i] < threshold[i]*week) {
            return false;
        }
    }
    return true;
}


// 遊戲主體
class DatingGame {
private:
    Player player;
    Character* characters;
    int currentDay;
    string currentLocation;
    EventSystem eventSystem;
    map<string, int> endings;  // 結局條件

public:
    Typewriter tp;
    DatingGame() : currentDay(1) {
        // 初始化角色
        Character* characters[] = {new Character("陳愛芬"), new Character("黃梓祺"), new Character("王語崴")}; // 初始化角色列表
        characters[0]->setAffection(50); // 閨密福利
        characters[1]->setAffection(20); // 青梅竹馬
        characters[2]->setAffection(0); // 最難追的
        // 設定隨機事件
        setupRandomEvents();
    }
    void setGame(){ // 遊戲前導
        string playerName;
        int type;
        cout << ">>遊戲簡介：一名學測剩30週的高中美少女，要在短短的30週內出奇蹟";
        pause();
        cout <<">>期間會遇到許多出其不意的事情，合理的運用時間才能獲得理想的目標！考上台大吧！\\(^w^)/ " << "\n";
        showTXT("C:/Users/Jolie/Jolie's doc/C++/final/rule.txt");

        while (true) {
            cout << "請輸入你的名字: ";
            getline(cin, playerName);
            
            // 移除字串前後的空白
            playerName.erase(0, playerName.find_first_not_of(" \t\n\r\f\v"));
            playerName.erase(playerName.find_last_not_of(" \t\n\r\f\v") + 1);
            
            if (playerName.empty()) {
                cout << "名字不能為空！請重新輸入。\n";
            } else {
                cout << ">>你叫" << playerName << "嗎?  酷喔，聽起來就是電神的名字 \n";
                pause();
                break;
            }
        }

        cout << "你可以選擇成為這幾種類型的女主人翁：\n=====類型一：斯文書生=====\n       初始能力：\n學科值：100\n體能：20\n"
            <<"人緣：50\n魅力:10\n幸運:5";
        cout <<"\n=====類型二：社交花花=====\n       初始能力：\n學科值：20\n體能：50\n"
            <<"人緣：100\n魅力:20\n幸運:5";
        cout <<"\n=====類型三：排球少女=====\n       初始能力：\n學科值：50\n體能：100\n"
            <<"人緣：20\n魅力:15\n幸運:5\n";
        cout <<"(輸入想要類型的數字)：";

        while (true){
            cin >> type;
            if (type == 1 || type == 2 || type == 3 || type == 4 || type == 5) {
                cout << "你選擇了類型：" << type << "\n";
                break; // 輸入正確，跳出循環"
            } else {
                cout << "請重新輸入一次。不要玩我" << endl;
            }
        }
        cout << "學測";
        for (int i = 0; i < 6; ++i) {
            cout << "." << flush; // 輸出點並立即刷新緩衝區
           SLEEP (500); // 延遲 500 毫秒; // 延遲 0.5 秒
        } cout << "啟動";
        for (int i = 0; i < 3; ++i) {
            cout << "!" << flush; // 輸出點並立即刷新緩衝區
            SLEEP(250); // 延遲 500 毫秒; // 延遲 0.5 秒
        }
        player.setPlayer(playerName, type);
    }
    
    void displayEndings() {
        // 設定各種角色結局條件
    }
    
    void setupRandomEvents() {
        // 添加隨機事件
        eventSystem.addRandomEvent(
            [](const Player& p) { return true; },  // 條件
            [](Player& p) {
                cout << "觸發隨機事件！\n";
                p.modifyStats(0, 0, 0, 0, 0);
            }
        );
    }
    void checkLoveEnding(int score){ // 確認有沒有在一起
        // 取最高好感度的進入結局 第二者當朋友
        // 若兩者滿100  3
        // 三者都滿100  1
        // 都未達標  1

        //BE
        if(characters[0].getAffection() < 100 && characters[1].getAffection() < 100 && characters[2].getAffection() < 100)
        {
            tp.type("妳趁著學測剛結束的氛圍，勇敢地分別向愛芬、梓祺和語崴告白 \n");
            tp.type("\"我喜歡你\" 妳如是說 \n");
            tp.type("\"我把你當作朋友\" 、 \"我只喜歡金冬天\"、\"額.... 妳是個好人\"，三人分別露出尷尬臉色\\n");
            tp.type("天涯何處無芳草，妳的魅力只配獲得三張好人卡，很遺憾地請你回去山洞裡好好當個哥布林吧，小心不要再被冒險者騙出來了!!");
        }
        else if(characters[0].getAffection() >= 100 && characters[1].getAffection() >= 100 && characters[2].getAffection() >= 100)
        {
            tp.type("妳趁著學測剛結束的氛圍，勇敢地分別向愛芬、梓祺和語崴告白 \n");
            tp.type("\"我喜歡你\" 妳如是說 \n");
            tp.type("一顆三顆透明的淚珠分別從三張美麗無比的臉上滑落 \n")
            tp.type("我也是!!! 喜極而泣的愛芬、梓祺和語崴衝上來將妳一把抱住 \n")
            tp.type("恭喜妳成功和妳所愛的三個人開始了幸福生活，法律限制了婚姻，卻限制不了妳 \n")
            tp.type("妳的心碎成了很多塊、平分給了妳愛的每個人")
            tp.type("三年後")
            tp.type("你左擁著梓祺、右抱著語崴，更親切的和愛芬醬說著早安，恭喜你成功突破了世俗的限制，成為了每個人稱羨的對象，後世都稱送你為後宮王");
        }
        else if(characters[0].getAffection() >= 100 && characters[1].getAffection() >= 100 && characters[2].getAffection() < 100)
        {
            tp.type("妳趁著學測剛結束的氛圍，勇敢地分別向愛芬、梓祺告白\n");
            tp.type("\"我喜歡你\" 妳如是說 \n");
            tp.type("\"我願意\" 梓祺率先回答 \n")
            tp.type("\"我可是妳的閨蜜阿\" 愛芬醬仍舊在逃避著自己壓抑已久的情感 \n")
            tp.type("妳二話不說抱了上去，用擁抱代替言語，這個寒冷的冬天，妳獲得了兩份美好的愛情 \n")
            tp.type("\"早上好\" \n梓其是妳眼睛睜開後第一個看到的人，妳摸了摸他的頭 \n突然 你聞到到一股香味，原來是愛芬醬在廚房煮著香噴噴的味噌湯，妳還是不敢相信你在備考的那段時間，有這麼好的兩個人陪著妳 \n")
            tp.type("當初妳很猶豫，要選擇誰成為自己的伴侶，但你想起來自己已經不是小孩子了，當然是全都要啦，恭喜妳獲得了'閨蜜帥哥丼");
        }
        else if(characters[1].getAffection() >= 100 && characters[2].getAffection() >= 100 && characters[0].getAffection() < 100)
        {
            tp.type("妳趁著學測剛結束的氛圍，勇敢地分別向梓祺、語崴告白\n");
            tp.type("\"我喜歡你\" 妳如是說 \n");
            tp.type("\"我願意\" 梓祺和語崴異口同聲地說 \n")
            tp.type("妳要選擇誰...兩人用焦急的語氣詢問妳 \n")
            tp.type("三年後 \n")
            tp.type("\"早上好\" \n 兩道清爽的聲音問候著剛起床的妳，梓祺和語崴正在廚房煮著健康的protein特餐，妳還是不敢相信在備考的那段時間，有這麼好的兩個人陪著妳 \n")
            tp.type("當初妳很猶豫，要選擇誰成為自己的伴侶，但你想起來自己已經不是小孩子了，當然是全都要啦，恭喜妳獲得了'兩位絕世帥哥");
        }
        else if(characters[0].getAffection() >= 100 && characters[2].getAffection() >= 100 && characters[1].getAffection() < 100)
        {
            tp.type("妳趁著學測剛結束的氛圍，勇敢地分別向愛芬、語崴告白\n");
            tp.type("\"我喜歡你\" 妳如是說 \n");
            tp.type("\"那我就勉為其難的答應妳吧\" 語崴悶騷又傲驕的的說\n")
            tp.type("愛芬像是既驚訝又害羞的站在原地，最後還是忍不住的哭了出來\n")
            tp.type("妳抱著他們兩個，在下雪的冬天裡打轉")
            tp.type("三年後 \n")
            tp.type("\"早上好\" \n 兩道清爽的聲音問候著剛起床的妳，梓祺和語崴正在廚房煮著健康的protein特餐，妳還是不敢相信在備考的那段時間，有這麼好的兩個人陪著妳 \n")
            tp.type("當初妳很猶豫，要選擇誰成為自己的伴侶，但你想起來自己已經不是小孩子了，當然是全都要啦，恭喜妳獲得了'兩位絕世帥哥");
        }
    }
    void checkEnding() {
        // 檢查是否達到結局條件
        // 先考試
        int score;
        if(player.getAcademic() >= 600)
            score = collegeTest("easy");
        else if (player.getAcademic() < 600 && player.getAcademic() >= 450)
            score = collegeTest("moderate");
        else score = collegeTest("hard");
        tp.setSpeed(100);
        tp.type("學測中你一共獲得了");
        cout << score << "分\n";
        if(score == 75){
            tp.type("你考上了夢寐以求的台大，家人邀請你左鄰右舍一起來放鞭炮慶祝，殊不知台大的期中是他後悔的開始......\n");
        }
        else if (score == 50){
            tp.type("你考上了一所中字山大學，幸好妳的家人不是Asian partents，家人很為你高興，認為你的投入有換來回報， 你愉快地和猴子們跳起了猩猩之舞\n");
        }
        else{
            tp.type("你最終去了小葉大學......在那邊當店神\n");
        }
        checkLoveEnding(score);
    }
    int collegeTest(string level){
        tp.type("今天是大考的日子......");
        pause();
        tp.type("考卷：！注意！以錯誤格式輸入導致無法辨識者，計為零分。");
        int score = 0;
        int answer[3] = {};
        int solution[3]={0}; // 未完成
        if(level == "easy"){
            tp.type("第一題： \n (自然題)");
            showTXT("final/easy_test1.txt");
            tp.type("請作答：");
            cin >> answer[0];
            tp.type("第二題： \n (國文題)");
            showTXT("final/easy_test2.txt");
            tp.type("請作答：");
            cin >> answer[1];
            tp.type("第三題： \n (加分題)");
            showTXT("final/easy_test3.txt");
            tp.type("請作答：");
            cin >> answer[2];

        }
        else if(level == "hard"){
            tp.type("第一題： \n (數學題)");
            showTXT("final/hard_test1.txt");
            tp.type("請作答：");
            cin >> answer[0];
            tp.type("第二題： \n (常識題)");
            showTXT("final/hard_test2.txt");
            tp.type("請作答：");
            cin >> answer[1];
            tp.type("第三題： \n (加分題)");
            showTXT("final/hard_test3.txt");
            tp.type("請作答：");
            cin >> answer[2];
        }
        else{
            tp.type("第一題： \n (社會題)");
            showTXT("final/test1.txt");
            tp.type("請作答：");
            cin >> answer[0];
            tp.type("第二題： \n (數學題)");
            showTXT("final/test2.txt");
            tp.type("請作答：");
            cin >> answer[1];
            tp.type("第三題： \n (加分題)");
            showTXT("final/test3.txt");
            tp.type("請作答：");
            cin >> answer[2];
        }
        for(int i; i < 3; i++){ // 對答案
            if(i == solution[i]){
                score += 25;
            }
        }
        return score;
    }
    void run(vector<TimeTriggerEvents*>& timeEvents, vector<LevelTriggerEvents*>& levelEvents, vector<Events*>& randomEvents) {
        while(true) {
            string inputCommand; // 玩家指令
            displayStatus(); // 展示能操作的選項
            int currentMove = player.getMove(); //現在剩餘行動點等於這個玩家最高行動點上限
            while(currentMove > 0){
                getline(cin, inputCommand);

                int commandCode = processCommand(inputCommand);

                if(commandCode == 1){ // study
                    if(currentMove < 6){
                        tp.type("你的行動值不夠！");
                    }
                    else{
                        currentMove -= 6;
                        //觸發學習事件//
                        player.modifyStats(12, -4, 4, 10, -5);
                        tp.type("剩餘行動值：");
                        cout << currentMove << "\n";
                    }
                }
                else if(commandCode == 2){ // exercise
                    if(currentMove < 6){
                        tp.type("你的行動值不夠！");
                    }
                    else{
                        currentMove -= 6;
                        //觸發運動事件//
                        player.modifyStats(0, 5, 5, 12, 15);
                        tp.type("剩餘行動值：");
                        cout << currentMove << "\n";
                    }
                }
                else if(commandCode == 3){ // social
                    if(currentMove < 6){
                        tp.type("你的行動值不夠！");
                    }
                    else{
                        currentMove -= 6;
                        //觸發社交事件//
                        player.modifyStats(-4, 8, 14, 4, 0);
                        tp.type("剩餘行動值：");
                        cout << currentMove << "\n";
                    }
                }
                else if(commandCode == 4){ // eat
                    if(currentMove < 4){
                        tp.type("你的行動值不夠！");
                    }
                    else{
                        currentMove -= 4;
                        //觸發吃飯事件//
                        player.modifyStats(0, 0, 2, -8, -5);
                        tp.type("剩餘行動值：");
                        cout << currentMove << "\n";
                    }
                }
                else if(commandCode == 5){ // sleep
                    //觸發睡覺事件//
                    if(currentMove >= player.getFatigue())
                        player.modifyStats(0, 0, 0, -player.getFatigue(), 0);
                    else
                        player.modifyStats(0, 0, 0, -currentMove, 0);
                    currentMove = 0;
                    tp.type("剩餘行動值：");
                    cout << currentMove << "\n";
                }
                else if(commandCode == 6){
                    goto exit_loop; // 切到雙層迴圈外 結束遊戲
                }
                else{
                    tp.type("看清楚選項！請輸入一個數字後直接按下Enter");
                }
                //processCommand(command);
                //commandCode.clear();

                }
                currentDay ++;
                if(currentDay == 30){
                    checkEnding();
                    break;
            }
        }
        exit_loop:;
    }

    void displayStatus() {
        // TypewriterEffect printer;
        cout << "=== Day " << currentDay << " ===\n";
        
        // 顯示其他狀態
        tp.type("倒數");
        cout << 30 - currentDay;
        tp.type("週了...... 今天做點甚麼好呢？\n");
        
        if(player.getFatigue() > 50)
            tp.type("好累喔......不想念書了，這破書愛讀誰讀\n");
        else if (player.getFatigue() > 100){
            tp.type("破防了");
        }
        // 現在能力 可以選的選項 1. 
        tp.setSpeed(30);
        tp.type("           <目前狀態>          \n");
        cout <<"學科值： "<<player.getAcademic() << " 體能： " << player.getStamina() << " 魅力: " << player.getCharm() << " 幸運: " << player.getLucky() << " 疲勞值: " << player.getFatigue()<< " 行動點數上限: "<< player.getMove() << "\n";
        tp.type("你可以選擇做這些事情：");
        tp.type("1.study(消耗6點行動值), 2.exercise(消耗6點行動值), 3.social(消耗6點行動值), 4.eat(消耗4點行動值，減少一點點疲勞), 5.sleep(清空所有行動值，減少疲勞值)\n");
        
    }

    int processCommand(const string& inputCommand)
    {
        if(inputCommand.length() != 1)
            return - 1;
        char trueCommand;
        bool Valid = false;
        for(int i = 0; i < inputCommand.length(); i++)//
            {
                if(inputCommand[i] == 'Q')
                {
                    trueCommand = 'Q';
                    Valid = true;
                    break;
                }
                if(isdigit(inputCommand[i]))
                {
                    int commandDigit = inputCommand[i] - '0';
                    if(commandDigit >= 1 && commandDigit <= 5)
                    {
                        trueCommand = inputCommand[i];
                        Valid = true;
                        break;
                    }
                    else
                        continue;
                }
            }
        if(Valid == false)
            return -1;
        else
        {
            if(trueCommand != 'Q')
                return trueCommand - '0';
            else
                return 6;
        }
    }
    void pause() { // press Enter to continue
    string dummy;
    getline(cin, dummy);  // 不管輸入什麼，只要按 Enter 就會繼續
    }
};

int main() {
    // SetConsoleOutputCP(65001)
    vector<Events*> randomEvents;
    vector<TimeTriggerEvents*> timeEvents;
    vector<LevelTriggerEvents*> levelEvents;
    
    DatingGame game;
    game.setGame();
    game.run(vector<TimeTriggerEvents*>& timeEvents, vector<LevelTriggerEvents*>& levelEvents, vector<Events*>& randomEvents);
    return 0;
}
