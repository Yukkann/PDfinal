#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <functional>
#include <fstream>
#include "TypeWriter.h"
#include "EventSystem.h"
#include "Event.h"
#include "Player.h"
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



class TimeTriggerEvents : public Events
{
private:
    int week;
public:
    TimeTriggerEvents(int week, string description, string choicesD):Events::Events(description, choicesD), week(week){};
    bool checkWeek(int currentWeek);
};

bool TimeTriggerEvents::checkWeek(int currentWeek){
    if (this->week == currentWeek) {
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
    int currentWeek;
    EventSystem eventsystem;

public:
    Typewriter tp;
    DatingGame() : currentWeek(1) {
        // 初始化角色
        Character* characters[] = {new Character("陳愛芬"), new Character("黃梓祺"), new Character("王語崴")}; // 初始化角色列表
        characters[0]->setAffection(50); // 閨密福利
        characters[1]->setAffection(20); // 青梅竹馬
        characters[2]->setAffection(0); // 最難追的
        // 初始化事件
        eventsystem.setEvents();

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
            
            /*// 移除字串前後的空白
            playerName.erase(0, playerName.find_first_not_of(" \t\n\r\f\v"));
            playerName.erase(playerName.find_last_not_of(" \t\n\r\f\v") + 1);*/
            
            if (playerName.empty()) {
                cout << "名字不能為空！請重新輸入。\n";
            } else {
                cout << ">>你叫" << playerName << "嗎?  酷喔，聽起來就是電神的名字 \n";
                tp.type("按下Enter以繼續");
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
    void checkLoveEnding(int score){ // 確認有沒有在一起
        // 取最高好感度的進入結局 第二者當朋友
        // 若兩者滿100
        // 三者都滿100
        // 都未達標
        //BE
        if(characters[0].getAffection() < 100 && characters[1].getAffection() < 100 && characters[2].getAffection() < 100)
        {
            tp.type("天涯何處無芳草，你的魅力只配獲得三張好人卡，很遺憾地請你回去山洞裡好好當個哥布林吧，小心不要再被冒險者騙出來了");
        }
        else if(characters[0].getAffection() >= 100 && characters[1].getAffection() >= 100 && characters[2].getAffection() >= 100)
        {
            tp.type("法律限制了婚姻，卻限制不了你，你左擁著梓祺、右抱著語崴，更親切的和愛芬醬說著早安，恭喜你成功突破了世俗的限制，成為了每個人稱羨的對象，後世都稱送你為後宮王");
        }
        else if(characters[0].getAffection() >= 100 && characters[1].getAffection() >= 100 && characters[2].getAffection() < 100)
        {
            tp.type("\"早上好\" \n梓其是妳眼睛睜開後第一個看到的人，妳摸了摸他的頭 \n突然 你聞到到一股香味，原來是愛芬醬在廚房煮著香噴噴的味噌湯，妳還是不敢相信你在備考的那段時間，有這麼好的兩個人陪著妳 \n");
            tp.type("當初妳很猶豫，要選擇誰成為自己的伴侶，但你想起來自己已經不是小孩子了，當然是全都要啦，恭喜妳獲得了'兩位絕世佳人");
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
            tp.type("你考上了夢寐以求的台大，家人邀請你左鄰右舍一起來放鞭炮慶祝，\n殊不知台大的期中是他後悔的開始......\n");
        }
        else if (score == 50){
            tp.type("你考上了一所中字山大學，幸好妳的家人不是Asian partents，家人很為你高興，認為你的投入有換來回報， 你愉快地和猴子們跳起了猩猩之舞\n");
        }
        else{
            tp.type("你最終去了小葉大學......在那邊當店神\n");
        }
        // 加權結算總能力值
        score += player.getAcademic() * 2 + player.getCharm() * 5 + player.getPopularity() * 5 + player.getStamina() * 5 + player.getLucky() * 5;
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
            while(currentMove > 0){ // 當還有行動值就會一直繼續
                innerloop:
                player.checkSick(); // 確認是否生病
                if(player.getSick())
                    tp.type("好像感冒了......要不休息一陣子？ 或吃點好吃的？\n");

                getline(cin, inputCommand); // 輸入指令
                int commandCode = processCommand(inputCommand);

                if(commandCode == 1){ // study
                    if(currentMove < 6){
                        tp.type("你的行動值不夠！\n");
                        goto innerloop; // 回到開始選項的地方
                    }
                    else{
                        currentMove -= 6;
                        //觸發學習事件//
                        if(player.getSick()){
                            player.modifyStats(6, -8, 2, 20, -10, 0);
                            tp.type("妳病懨懨的念書，效果似乎不是很好\n");
                            cout << "妳的能力值增減為： " << "學科能力" << 6 << "，" << "人緣" << -8 << "，" << "魅力" << 2 << "，" << "疲勞值" << 20 << "，" << "體能" << -10 << "，" << "幸運" << 0 << "。" << endl;
                        }
                        else{
                            player.modifyStats(12, -4, 4, 10, -5, 0);
                            tp.type("妳努力卷了一波\n");
                            cout << "妳的能力值增減為： " << "學科能力" << 12 << "，" << "人緣" << -4 << "，" << "魅力" << 4 << "，" << "疲勞值" << 10 << "，" << "體能" << -5 << "，" << "幸運" << 0 << "。" << endl;
                        }
                        tp.type("剩餘行動值：");
                        cout << currentMove << "\n";
                    }
                }
                else if(commandCode == 2){ // exercise
                    if(currentMove < 6){
                        tp.type("你的行動值不夠！\n");
                        goto innerloop; // 回到開始選項的地方
                    }
                    else{
                        currentMove -= 6;
                        //觸發運動事件//
                        if(player.getSick()){
                            tp.type("妳邊流著鼻涕邊流汗運動，病情似乎加重了\n");
                            player.modifyStats(0, 2, 2, 24, 8, 0);
                            cout << "妳的能力值增減為： " << "學科能力" << 0 << "，" << "人緣" << 2 << "，" << "魅力" << 2 << "，" << "疲勞值" << 24 << "，" << "體能" << 8 << "，" << "幸運" << 0 << "。" << endl;
                        }
                        else{
                            tp.type("妳快樂打球，交到了很多球友\n");
                            player.modifyStats(0, 5, 5, 12, 15, 0);
                            cout << "妳的能力值增減為： " << "學科能力" << 0 << "，" << "人緣" << 5 << "，" << "魅力" << 5 << "，" << "疲勞值" << 12 << "，" << "體能" << 15 << "，" << "幸運" << 0 << "。" << endl;
                        }
                        
                        tp.type("剩餘行動值：");
                        cout << currentMove << "\n";
                    }
                }
                else if(commandCode == 3){ // social
                    if(currentMove < 6){
                        tp.type("你的行動值不夠！");
                        goto innerloop; // 回到開始選項的地方
                    }
                    else{
                        currentMove -= 6;
                        //觸發社交事件//
                        if(player.getSick()){
                            tp.type("妳戴著口罩，別人都聽不清楚妳在說什麼\n");
                            player.modifyStats(-8, 4, 7, 8, 0, 0);
                            cout << "妳的能力值增減為： " << "學科能力" << -8 << "，" << "人緣" << 4 << "，" << "魅力" << 7 << "，" << "疲勞值" << 8 << "，" << "體能" << 0 << "，" << "幸運" << 0 << "。" << endl;
                        }
                        else{
                            tp.type("成功地和別人找到共通話題，聊得不亦樂乎\n");
                            player.modifyStats(-4, 8, 14, 4, 0, 0);
                            cout << "妳的能力值增減為： " << "學科能力" << -4 << "，" << "人緣" << 8 << "，" << "魅力" << 14 << "，" << "疲勞值" << 4 << "，" << "體能" << 0 << "，" << "幸運" << 0 << "。" << endl;
                        }
                        
                        tp.type("剩餘行動值：");
                        cout << currentMove << "\n";
                    }
                }
                else if(commandCode == 4){ // eat
                    if(currentMove < 4){
                        tp.type("你的行動值不夠！");
                        goto innerloop; // 回到開始選項的地方
                    }
                    else{
                        currentMove -= 4;
                        //觸發吃飯事件//
                        if(player.getSick()){
                            tp.type("生病導致喉嚨很痛，吃不太下飯\n");
                            player.modifyStats(0, 0, 4, -4, -10, 0);
                            cout << "妳的能力值增減為： " << "學科能力" << 0 << "，" << "人緣" << 0 << "，" << "魅力" << 4 << "，" << "疲勞值" << -4 << "，" << "體能" << -10 << "，" << "幸運" << 0 << "。" << endl;
                        }
                        else{
                            tp.type("Yum Yum Yum Yum 真好吃~");
                            player.modifyStats(0, 0, 2, -8, -5, 0);
                            cout << "妳的能力值增減為： " << "學科能力" << 0 << "，" << "人緣" << 0 << "，" << "魅力" << 2 << "，" << "疲勞值" << -8 << "，" << "體能" << -5 << "，" << "幸運" << 0 << "。" << endl;
                        }
                        
                        tp.type("剩餘行動值：");
                        cout << currentMove << "\n";
                    }
                }
                else if(commandCode == 5){ // sleep
                    //觸發睡覺事件//
                    tp.type("睡覺皇帝大，睡覺就是好\n");
                    if(currentMove >= player.getFatigue()){
                        player.modifyStats(0, 0, 0, -player.getFatigue(), 0, 0);
                        cout << "疲勞值減少了" << player.getFatigue();
                    }
                    else{
                        player.modifyStats(0, 0, 0, -currentMove * 2, 0, 0);
                        cout << "疲勞值減少了" << currentMove * 2;
                    }
                        
                    currentMove = 0;
                    tp.type("剩餘行動值：");
                    cout << currentMove << "\n";
                }
                else if(commandCode == 6){
                    goto exit_loop; // 切到雙層迴圈外 結束遊戲
                }
                else{
                    tp.type("看清楚選項！請輸入一個數字後直接按下Enter\n");
                    goto innerloop; // 回到開始選項的地方
                }

                random_device rd;  // 用來產生種子
                mt19937 gen(rd()); // Mersenne Twister 生成器
                // 建立均勻分布的隨機浮點數生成器 (0.0 到 1.0)
                uniform_real_distribution<double> dis(0.0, 1.0);
                // 生成隨機數並判斷是否中獎 (10% 機率)
                if(dis(gen) < 0.04*player.getLucky()) {
                    tp.type("觸發隨機事件！\n");
                    uniform_int_distribution<int> number_dis(0, 29); //編號0~29的事件
                    // 跑出事件
                    eventsystem.events[number_dis(gen)]->makeChoices(player, currentWeek);
                }
                // 再抽一次看能不能有角色共通事件
                // 檢查天數是不是特別的一天
                // 檢查角色好感度是否達標
            }
            currentWeek ++;
            if(currentWeek == 30){
                checkEnding();
                break;
        }
    }
    exit_loop:;
}
    void displayStatus() {
        // TypewriterEffect printer;
        cout << "=== Week " << currentWeek << " ===\n";
        // 顯示其他狀態
        tp.type("倒數");
        cout << 30 - currentWeek;
        tp.type("週了...... 今天做點甚麼好呢？\n");
        
        if(player.getFatigue() > 50)
            tp.type("好累喔......不想念書了，這破書愛讀誰讀\n");
        else if (player.getFatigue() > 100){
            tp.type("破防了");
        }
        // 現在能力 可以選的選項 1. 
        tp.setSpeed(30);
        tp.type("           <目前狀態>          \n");
        cout <<"學科值： "<<player.getAcademic() << " 體能： " << player.getStamina() << " 人緣: " << player.getPopularity() << " 魅力: " << player.getCharm() << " 幸運: " << player.getLucky() << " 疲勞值: " << player.getFatigue()<< " 行動點數上限: "<< player.getMove() << "\n";
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
    game.run(timeEvents,levelEvents,randomEvents);
    return 0;
}