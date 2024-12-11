#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <functional>
#include <fstream>
#include <stdexcept>
#include "TypeWriter.h"
#include "EventSystem.h"
#include "Event.h"
#include "Player.h"
#include "Character.h"
#ifdef _WIN32
    #include <windows.h> // Windows 平台專屬
    #define SLEEP(ms) Sleep(ms)
#else
    #include <unistd.h> // Mac 專屬
    #define SLEEP(ms) usleep(ms * 1000)
#endif
using namespace std;
// 自訂例外
class GameInitializationError : public runtime_error {
    public:
        GameInitializationError(const string& message) : runtime_error(message) {}
};

class GameRuntimeError : public runtime_error {
    public:
        GameRuntimeError(const string& message) : runtime_error(message) {}
};
// 讀取寫好的文字檔
void showTXT(const string& filename){
        Typewriter tp;
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            tp.setSpeed(25);
            while (getline(file, line)) {
                tp.type(line);
                tp.type("\n");
            }
            file.close();
        }
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
        characters = new Character[3] {
            Character("陳愛芬"),
            Character("黃梓祺"),
            Character("王語崴")
        };
        characters[0].setAffection(50); // 閨密福利
        characters[1].setAffection(20); // 青梅竹馬
        characters[2].setAffection(0);  // 最難追的
        // 初始化事件
        eventsystem.setEvents();
        eventsystem.setCharacEvents();

    }
    ~DatingGame() {
    delete[] characters;  // 釋放角色陣列的記憶體
    }
    void setGame(){ // 遊戲前導
        string playerName;
        int type;
        cout << ">>遊戲簡介：一名學測剩30週的高中美少女，要在短短的30週內出奇蹟";
        pause();
        cout <<">>期間會遇到許多出其不意的事情，合理的運用時間才能獲得理想的目標！考上台大吧！\\(^w^)/ " << "\n";
        showTXT("../final/rule.txt");

        while (true) {
            cout << "請輸入你的名字(使用英文或阿拉伯數字): ";
            getline(cin, playerName);

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
        outloop:
        while (true) {
            cout << "請輸入類型 (1-5): ";
            if (!(cin >> type)) {
                // 清除錯誤狀態
                cin.clear();
                // 清空輸入緩衝區
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "請輸入數字" << endl;
                continue;
            }
            
            if (type >= 1 && type <= 5) {
                cout << "你選擇了類型：" << type << "\n";
                break;
            } else {
                cout << "請輸入 1-5 之間的數字" << endl;
                // 清空輸入緩衝區
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        // 都未達標
        bool successfulGuy = player.successfullGuy(score);
        //BE
        if(characters[0].getAffection() < 100 && characters[1].getAffection() < 100 && characters[2].getAffection() < 100){
            showTXT("../final/none.txt");
        }
        // 三者都滿好感
        else if(characters[0].getAffection() >= 100 && characters[1].getAffection() >= 100 && characters[2].getAffection() >= 100){
            showTXT("../final/all.txt");
        }
        // 若兩者滿100
        else if(characters[0].getAffection() >= 100 && characters[1].getAffection() >= 100 && characters[2].getAffection() < 100)
        {
            showTXT("../final/two1.txt");
        }
        else if(characters[1].getAffection() >= 100 && characters[2].getAffection() >= 100 && characters[0].getAffection() < 100)
        {
            showTXT("../final/two2.txt");
        }
        else if(characters[0].getAffection() >= 100 && characters[2].getAffection() >= 100 && characters[1].getAffection() < 100)
        {
            showTXT("../final/two3.txt");
        }
        // 進入單人結局
        else if(characters[0].getAffection() >= 100 && characters[1].getAffection() < 100 && characters[2].getAffection() < 100)
        {
            if(successfulGuy == true)
            {
                showTXT("../final/aifenGE.txt");
            }
            else
            {
                showTXT("../final/aifenNE.txt");
            }
        }
        else if(characters[1].getAffection() >= 100 && characters[0].getAffection() < 100 && characters[2].getAffection() < 100)
        {
            if(successfulGuy == true)
            {
                showTXT("../final/tzuchiGE.txt");
            }
            else
            {
                showTXT("../final/tzuchiNE.txt");
            }
        }
        else if(characters[2].getAffection() >= 100 && characters[0].getAffection() < 100 && characters[1].getAffection() < 100)
        {
            if(successfulGuy == true)
            {
                showTXT("../final/yuweiGE.txt");
            }
            else
            {
                showTXT("../final/yuweiNE.txt");
            }
        }
    }
    void checkEnding() {
        // 檢查是否達到結局條件
        // 先考試
        int score;
        if(player.getAcademic() >= 600)
            score = collegeTest("easy");
        else if (player.getAcademic() < 600 && player.getAcademic() >= 500)
            score = collegeTest("moderate");
        else score = collegeTest("hard");
        tp.setSpeed(100);
        tp.type("學測中你一共獲得了");
        cout << score << "級分\n";
        if(score == 75){
            tp.type("你考上了夢寐以求的台大，家人邀請你左鄰右舍一起來放鞭炮慶祝，\n殊不知台大的期中是後悔的開始......\n");
        }
        else if (score == 50){
            tp.type("你考上了一所中字山大學，幸好你的家人不是Asian partents，家人很為你高興，認為你的投入有換來回報， 你愉快地和猴子們跳起了猩猩之舞\n");
        }
        else{
            tp.type("你最終去了小葉大學......在那邊當店神\n");
        }
        // 加權結算總能力值
        score *= 3;
        score += player.getAcademic() * 2 + player.getCharm() * 5 + player.getPopularity() * 5 + player.getStamina() * 5 + player.getLucky() * 5;
        checkLoveEnding(score);
    }
    int collegeTest(string level){ // 考試系統
        tp.type("今天是大考的日子......");
        pause();
        tp.type("考卷：！注意！以錯誤格式輸入導致無法辨識者，計為零分。");
        int score = 0;
        int answer[3] = {0,0,0};
        int solution[3]={0,0,0};
        if(level == "easy"){
            solution[0] = 4;
            solution[1] = 1;
            solution[2] = 2;
            tp.type("第一題： \n (自然題)");
            showTXT("../final/easy_test1.txt");
            tp.type("請作答：");
            cin >> answer[0];
            tp.type("第二題： \n (國文題)");
            showTXT("../final/easy_test2.txt");
            tp.type("請作答：");
            cin >> answer[1];
            tp.type("第三題： \n (加分題)");
            showTXT("../final/easy_test3.txt");
            tp.type("請作答：");
            cin >> answer[2];

        }
        else if(level == "hard"){
            solution[0] = 4;
            solution[1] = 3;
            solution[2] = 1;
            tp.type("第一題： \n (數學題)");
            showTXT("../final/hard_test1.txt");
            tp.type("請作答：");
            cin >> answer[0];
            tp.type("第二題： \n (常識題)");
            showTXT("../final/hard_test2.txt");
            tp.type("請作答：");
            cin >> answer[1];
            tp.type("第三題： \n (加分題)");
            showTXT("../final/hard_test3.txt");
            tp.type("請作答：");
            cin >> answer[2];
        }
        else{
            solution[0] = 4;
            solution[1] = 2;
            solution[2] = 3;
            tp.type("第一題： \n (社會題)");
            showTXT("../final/test1.txt");
            tp.type("請作答：");
            cin >> answer[0];
            tp.type("第二題： \n (數學題)");
            showTXT("../final/test2.txt");
            tp.type("請作答：");
            cin >> answer[1];
            tp.type("第三題： \n (加分題)");
            showTXT("../final/test3.txt");
            tp.type("請作答：");
            cin >> answer[2];
        }
        for(int i = 0; i < 3; i++){ // 對答案
            if(answer[i] == solution[i]){
                score += 25;
            }
        }
        return score;
    }
    void run() {
        int index1 = 0; // 陳愛芬的主線章節進度
        int index2 = 0; // 黃梓祺的主線章節進度
        int index3 = 0; // 王語崴的主線章節進度
        cin.ignore();
        while(true) {
            displayStatus(); // 展示能操作的選項
            string inputCommand; // 玩家指令
            bool eventHappen = false;
            bool charEventHappen = false;
            int currentMove = player.getMove(); //現在剩餘行動點等於這個玩家最高行動點上限

            innerloop:
            while(currentMove > 0){ // 當還有行動值就會一直繼續
                player.displayPlayer();
                player.print();
                player.checkSick(); // 確認是否生病
                if(player.getSick())
                    tp.type("好像感冒了......要不休息一陣子？ 或吃點好吃的？\n");

                getline(cin, inputCommand); // 輸入指令
                int commandCode = processCommand(inputCommand);

                if(commandCode == 1){ // study
                    if(currentMove <10){
                        tp.type("你的行動值不夠！\n");
                        goto innerloop; // 回到開始選項的地方
                    }
                    else{
                        currentMove -= 10;
                        //觸發學習事件//
                        if(player.getSick()){
                            player.modifyStats(6, -8, 2, 20, -10, 0);
                            tp.type("你病懨懨的念書，效果似乎不是很好\n");
                            cout << "你的能力值增減為： " << "學科能力+" << 6 << "，" << "人緣" << -8 << "，" << "魅力+" << 2 << "，" << "疲勞值+" << 20 << "，" << "體能" << -10 << "，" << "幸運+" << 0 << "。" << endl;
                        }
                        else{
                            player.modifyStats(12, -4, 4, 10, -5, 0);
                            tp.type("你努力卷了一波\n");
                            cout << "你的能力值增減為： " << "學科能力+" << 12 << "，" << "人緣" << -4 << "，" << "魅力+" << 4 << "，" << "疲勞值+" << 10 << "，" << "體能" << -5 << "，" << "幸運+" << 0 << "。" << endl;
                        }
                        player.displayPlayer();
                        tp.type("剩餘行動值：");
                        cout << currentMove << "\n";
                    }
                }
                else if(commandCode == 2){ // exercise
                    if(currentMove < 10){
                        tp.type("你的行動值不夠！\n");
                        goto innerloop; // 回到開始選項的地方
                    }
                    else{
                        currentMove -= 10;
                        //觸發運動事件//
                        if(player.getSick()){
                            tp.type("你邊流著鼻涕邊流汗運動，病情似乎加重了\n");
                            player.modifyStats(0, 2, 2, 24, 8, 0);
                            cout << "你的能力值增減為： " << "學科能力+" << 0 << "，" << "人緣+" << 2 << "，" << "魅力+" << 2 << "，" << "疲勞值+" << 24 << "，" << "體能+" << 8 << "，" << "幸運+" << 0 << "。" << endl;
                        }
                        else{
                            tp.type("你快樂打球，交到了很多球友\n");
                            player.modifyStats(0, 5, 5, 12, 15, 0);
                            cout << "你的能力值增減為： " << "學科能力+" << 0 << "，" << "人緣+" << 5 << "，" << "魅力+" << 5 << "，" << "疲勞值+" << 12 << "，" << "體能+" << 15 << "，" << "幸運+" << 0 << "。" << endl;
                        }
                        player.displayPlayer();
                        tp.type("剩餘行動值：");
                        cout << currentMove << "\n";
                    }
                }
                else if(commandCode == 3){ // social
                    if(currentMove < 10){
                        tp.type("你的行動值不夠！");
                        goto innerloop; // 回到開始選項的地方
                    }
                    else{
                        currentMove -= 10;
                        //觸發社交事件//
                        if(player.getSick()){
                            tp.type("你戴著口罩，別人都聽不清楚你在說什麼\n");
                            player.modifyStats(-8, 4, 7, 8, 0, 0);
                            cout << "你的能力值增減為： " << "學科能力" << -8 << "，" << "人緣+" << 4 << "，" << "魅力+" << 7 << "，" << "疲勞值+" << 8 << "，" << "體能+" << 0 << "，" << "幸運+" << 0 << "。" << endl;
                        }
                        else{
                            tp.type("成功地和別人找到共通話題，聊得不亦樂乎\n");
                            player.modifyStats(-4, 8, 14, 4, 0, 0);
                            cout << "你的能力值增減為： " << "學科能力" << -4 << "，" << "人緣+" << 8 << "，" << "魅力+" << 14 << "，" << "疲勞值+" << 4 << "，" << "體能+" << 0 << "，" << "幸運+" << 0 << "。" << endl;
                        }
                        player.displayPlayer();
                        tp.type("剩餘行動值：");
                        cout << currentMove << "\n";
                    }
                }
                else if(commandCode == 4){ // eat
                    if(currentMove < 5){
                        tp.type("你的行動值不夠！");
                        goto innerloop; // 回到開始選項的地方
                    }
                    else{
                        currentMove -= 5;
                        //觸發吃飯事件//
                        if(player.getSick()){
                            tp.type("生病導致喉嚨很痛，吃不太下飯\n");
                            player.modifyStats(0, 0, 4, -4, -10, 0);
                            cout << "你的能力值增減為： " << "學科能力+" << 0 << "，" << "人緣+" << 0 << "，" << "魅力+" << 4 << "，" << "疲勞值" << -4 << "，" << "體能" << -10 << "，" << "幸運+" << 0 << "。" << endl;
                        }
                        else{
                            tp.type("Yum Yum Yum Yum 真好吃~");
                            player.modifyStats(0, 0, 2, -8, -5, 0);
                            cout << "你的能力值增減為： " << "學科能力+" << 0 << "，" << "人緣+" << 0 << "，" << "魅力+" << 2 << "，" << "疲勞值" << -8 << "，" << "體能" << -5 << "，" << "幸運+" << 0 << "。" << endl;
                        }
                        player.displayPlayer();
                        tp.type("剩餘行動值：");
                        cout << currentMove << "\n";
                    }
                }
                else if(commandCode == 5){//pray
                    //觸發拜拜事件//
                    if(currentMove < 10){
                        tp.type("你的行動值不夠！\n");
                        goto innerloop; // 回到開始選項的地方
                    }
                    else{
                        currentMove -= 10;
                        tp.type("請阿彌陀佛、阿拉、真主、耶穌、聖母、恆河及偉大的祖靈保佑我 \n");
                        if(player.getSick())
                        {
                            tp.type("你有點生病了、土地公請你好好保重身體\n");
                            player.modifyStats(0, 0, 0, 0, 0, 7);
                            cout << "你的能力值增減為： " << "學科能力" << 0 << "，" << "人緣" << 0 << "，" << "魅力" << 0 << "，" << "疲勞值" << 0 << "，" << "體能" << 0 << "，" << "幸運" << 7 << "。" << endl;
                        }
                        else 
                        {
                            tp.type("上帝會心一笑、讚嘆你的虔誠\n");
                            player.modifyStats(0, 0, 0, 0, 0, 14);
                            cout << "你的能力值增減為： " << "學科能力+" << 0 << "，" << "人緣+" << 0 << "，" << "魅力+" << 0 << "，" << "疲勞值+" << 0 << "，" << "體能+" << 0 << "，" << "幸運+" << 14 << "。" << endl;
                        }
                        player.displayPlayer();
                        tp.type("剩餘行動值：");
                        cout << currentMove << "\n";
                    }
                }
                else if(commandCode == 6){ // sleep
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
                    player.displayPlayer();
                    tp.type("剩餘行動值：");
                    cout << currentMove << "\n";
                }
                
                else if(commandCode == 7){
                    goto exit_loop; // 切到雙層迴圈外 結束遊戲
                }
                else{
                    tp.type("看清楚選項！請輸入一個數字後直接按下Enter\n");
                    goto innerloop; // 回到開始選項的地方
                }

                // 角色劇情事件檢查
                if (!charEventHappen){
                    random_device rdStory;
                    mt19937 genStory(rdStory());
                    uniform_real_distribution<double> disStory(0.0, 1.0);
                    if(disStory(genStory) < 0.04 * player.getLucky()) {
                        charEventHappen = true;
                        tp.type("觸發角色事件！\n");
                        uniform_int_distribution<int> charIndex(0, 2);
                        int character = charIndex(genStory);
                        
                        if(character == 0 && index3 != 10) { // 王語崴
                            characters[2].addAffection(eventsystem.characEvents[index3]->charMakeChoices(player));
                            index3 += 1;
                        }
                        else if(character == 1 && index1 != 18) { // 陳愛芬
                            characters[0].addAffection(eventsystem.characEvents[index1 + 10]->charMakeChoices(player));
                            index1 += 1;
                        }
                        else if(character == 2 && index2 != 28) { // 黃梓祺
                            characters[1].addAffection(eventsystem.characEvents[index2 + 18]->charMakeChoices(player));
                            index2 += 1;
                        }
                        goto innerloop; // 使每次行動只有一個事件
                    }
                }
                // 角色日常事件檢查
                if(!eventHappen){
                    random_device rdDaily;
                    mt19937 genDaily(rdDaily());
                    uniform_real_distribution<double> disDaily(0.0, 1.0);
                    if(disDaily(genDaily) < 0.04 * player.getLucky()) {
                        eventHappen = true;
                        tp.type("觸發角色日常事件！\n");
                        uniform_int_distribution<int> charIndex(0, 2);
                        int character = charIndex(genDaily);
                        uniform_int_distribution<int> eventIndex(29, 31);
                        
                        if(character == 0) { // 王語崴
                            characters[2].addAffection(eventsystem.characEvents[eventIndex(genDaily)]->charMakeChoices(player));
                        }
                        else if(character == 1) { // 陳愛芬
                            characters[0].addAffection(eventsystem.characEvents[eventIndex(genDaily)]->charMakeChoices(player));
                        }
                        else if(character == 2) { // 黃梓祺
                            characters[1].addAffection(eventsystem.characEvents[eventIndex(genDaily)]->charMakeChoices(player));
                        }
                        goto innerloop; // 使每次行動只有一個事件
                    }
                }
                // 隨機事件檢查
                random_device rdRandom;
                mt19937 genRandom(rdRandom());
                uniform_real_distribution<double> disRandom(0.0, 1.0);
                if(disRandom(genRandom) < 0.04 * player.getLucky()) {
                    tp.type("觸發隨機事件！\n");
                    uniform_int_distribution<int> eventIndex(0, 29);
                    eventsystem.events[eventIndex(genRandom)]->makeChoices(player, currentWeek);
                    goto innerloop; // 使每次行動只有一個事件
                }
            }
            currentWeek ++;
            if(currentWeek == 3){
                checkEnding();
                break;
            }
            
    }
    exit_loop:;
}
    void displayStatus() {// 展示角色狀態和時間
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
    }

    int processCommand(const string& inputCommand)// 輸入的精細化處理
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
                    if(commandDigit >= 1 && commandDigit <= 6)
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
                return 7;
        }
    }
    void pause() { // press Enter to continue
    string dummy;
    getline(cin, dummy);  // 不管輸入什麼，只要按 Enter 就會繼續
    }
};
int main() {
    // SetConsoleOutputCP(65001)
    try {
        DatingGame game;
        
        // Game initialization
        try {
            game.setGame();
        } catch (const std::invalid_argument& e) {
            throw GameInitializationError("Failed to initialize game: " + std::string(e.what()));
        } catch (const std::exception& e) {
            throw GameInitializationError("Unexpected error during game initialization: " + std::string(e.what()));
        }

        // Game runtime
        try {
            game.run();
        } catch (const std::runtime_error& e) {
            throw GameRuntimeError("Game runtime error: " + std::string(e.what()));
        } catch (const std::bad_alloc& e) {
            throw GameRuntimeError("Memory allocation failed during game runtime: " + std::string(e.what()));
        } catch (const std::exception& e) {
            throw GameRuntimeError("Unexpected error during game runtime: " + std::string(e.what()));
        }

        return 0;
    } catch (const GameInitializationError& e) {
        std::cerr << "Game Initialization Error: " << e.what() << std::endl;
        return 1;
    } catch (const GameRuntimeError& e) {
        std::cerr << "Game Runtime Error: " << e.what() << std::endl;
        return 2;
    } catch (const std::exception& e) {
        std::cerr << "Unhandled Exception: " << e.what() << std::endl;
        return 3;
    } catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 4;
    }
    return 0;
}
