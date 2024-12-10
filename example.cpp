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


class CharacterEvents : public Events
{
private:
    int changeAffection[3];
public:
    CharacterEvents(int affecOne, int affecTwo, int affecThree, string description, string choicesD);
    
    int charMakeChoices(Player& p);
};

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
            cout << resultOneD1 << endl;
            p.modifyStats(resultOneL1[0], resultOneL1[1], resultOneL1[2], resultOneL1[3], resultOneL1[4], resultOneL1[5]);
            cout << "你的能力值增減為： " << "學科能力" << resultOneL1[0] << "，" << "人緣" << resultOneL1[1] << "，" << "魅力" << resultOneL1[2] << "，" << "體能" << resultOneL1[3] << "，" << "疲勞值" << resultOneL1[4] << "，" << "幸運" << resultOneL1[5] << "。" << endl;
            return changeAffection[0];
            
            break;
        case 2:
            cout << resultTwoD1 << endl;
            p.modifyStats(resultTwoL1[0], resultTwoL1[1], resultTwoL1[2], resultTwoL1[3], resultTwoL1[4], resultTwoL1[5]);
            cout << "你的能力值增減為： " << "學科能力" << resultTwoL1[0] << "，" << "人緣" << resultTwoL1[1] << "，" << "魅力" << resultTwoL1[2] << "，" << "體能" << resultTwoL1[3] << "，" << "疲勞值" << resultTwoL1[4] << "，" << "幸運" << resultTwoL1[5] << "。" << endl;
            return changeAffection[1];
            
            break;
        case 3:
            cout << resultThreeD1 << endl;
            p.modifyStats(resultThreeL1[0], resultThreeL1[1], resultThreeL1[2], resultThreeL1[3], resultThreeL1[4], resultThreeL1[5]);
            cout << "你的能力值增減為： " << "學科能力" << resultThreeL1[0] << "，" << "人緣" << resultThreeL1[1] << "，" << "魅力" << resultThreeL1[2] << "，" << "體能" << resultThreeL1[3] << "，" << "疲勞值" << resultThreeL1[4] << "，" << "幸運" << resultThreeL1[5] << "。" << endl;
            return changeAffection[2];
            
            break;

        default:
            break;
    }
    return 0;
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
        // 取最高好感度的進入結局 第二者當朋友 3 3
        // 若兩者滿100  3
        // 三者都滿100  1
        // 都未達標  1

        bool successfulGuy = false;
        if(score >= 4000)
            successfulGuy = true;

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
            tp.type("\"早安!!\" \n 兩道清爽的聲音問候著剛起床的妳，梓祺和語崴正在廚房煮著健康的protein特餐，妳還是不敢相信在備考的那段時間，有這麼好的兩個人陪著妳 \n")
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
            tp.type("當初妳很猶豫，要選擇誰成為自己的伴侶，但你想起來自己已經不是小孩子了，當然是全都要啦，恭喜妳獲得了'兩位絕世帥哥'");
        }
        else if(characters[0].getAffection() >= 100 && characters[1].getAffection() < 100 && characters[2].getAffection() < 100)
        {
            tp.type("妳趁著學測剛結束的氛圍，勇敢地向愛芬告白\n");
            tp.type("愛芬醬是妳在北醫女認識的好朋友，妳們幾乎無話不談 \n");
            tp.type("彷彿只有在她面前，妳才能盡情的展現妳的自我\n");
            tp.type("無論是驕傲的部分、抑或是懦弱的自己\n");
            tp.type("漸漸的，妳終於意識到自己的情感不僅僅止於友情\n");
            tp.type("\"我喜歡妳\" 妳簡單卻又堅定地說 \n");
            tp.type("愛芬先是面露錯愕，又轉乘不敢置信，\"真的...可以嗎\" 玻璃珠般的眼淚滑過愛芬的臉龐\n");
            tp.type("\"我真的...可以那麼幸福嗎\"，愛芬醬忍不住的跪坐到地上\n");
            tp.type("妳再也忍不住了，淚腺開始潰堤，衝上去抱住了她 \n");
            tp.type("一月的冷空氣雖然讓人窒息，天空卻藍的美麗，妳和愛芬牽著手漫步走向遠方，走向妳們的未來\n");
            tp.type("三年後 \n");
            if(successfulGuy == true)
            {
                tp.type("\"早上好\" \n 妳睡眼惺忪地起床，卻找不著枕邊的那個她，\"妳起床啦\"，甜美又開朗的聲音在呼喚著妳 \n");
                tp.type("妳走到餐桌，擺在眼前的是充滿愛芬醬女子力的的日式早餐，是的，妳和愛芬醬同居了，妳成功地和她維持了穩定的關係\n");
                tp.type("從高中到大學、妳們依舊沒有分開，妳們一起在大學裡體驗到了幸福的學生戀情，恭喜妳破關'深情閨蜜線'");
            }
            else
            {
                tp.type("\"早上好\" \n 妳睡眼惺忪地起床，卻找不著枕邊的那個她，\"妳起床啦\"，甜美又開朗的聲音在呼喚著妳 \n");
                tp.type("妳走到餐桌，擺在眼前的是充滿愛芬醬女子力的的日式早餐，是的，妳和愛芬醬同居了，妳成功地和她維持了穩定的關係\n");
                tp.type("妳學測最後失利，沒有如預期般考到台大大學，妳雖然很失望，但妳知道妳贏得了更重要的東西，恭喜妳破關'深情閨蜜線'");
            }
        }
        else if(characters[1].getAffection() >= 100 && characters[0].getAffection() < 100 && characters[2].getAffection() < 100)
        {
            tp.type("妳趁著學測剛結束的氛圍，勇敢地向梓祺告白\n");
            tp.type("梓祺是妳一起長大的青梅竹馬 \n");
            tp.type("相識的確切日期已經忘記了，彷彿從有意識開始妳們就玩在一起了\n");
            tp.type("也有人曾經開玩笑地問妳們是情侶嗎，但妳們也都會同時一邊大笑一邊否認\n");
            tp.type("但是，在這個痛苦的學測準備期間\n");
            tp.type("一直在妳身邊的是他，在妳崩潰的時候在妳身邊豪不耐煩的遞上紙巾的也是他 \n")
            tp.type("在妳睡不著的夜晚，認真回復妳每則訊息的也是他 \n");
            tp.type("\"我喜歡妳\" 妳終於無法抑制自己內心的情感 \n");
            tp.type("梓祺彷彿不相信自己的耳朵，大力地打著自己的臉，想看看是不是還在夢境\n");
            tp.type("\"我願意!!!!!\"，梓祺大聲的像是要向全世界宣告\n");
            tp.type("\"不要那麼大聲啦!!!\" 妳羞赧的飛踢他的後背\n");
            tp.type("妳們雙雙跌倒在地板上，在撞到地板前，梓祺伸出他的手護住了妳的頭\n");
            tp.type("妳們呈現了一個尷尬的姿勢，四目相對、兩個不同的臉蛋都通紅著 \n");
            tp.type("\"哈哈哈哈哈\" 妳們默契地大笑了起來，然後緊緊地擁抱在一起 \n");
            tp.type("\"他的肩膀好寬\"，妳享受著他擁抱的溫暖");
            tp.type("三年後 \n");
            if(successfulGuy == true)
            {
                tp.type("\"小笨蛋，早安阿\" \n 一個熟悉的臉和聲音出現在妳宿舍門口，\"我上課要遲到啦\" 妳焦急的大喊著\n");
                tp.type("\"來這是給妳的早餐\"，他把妳最愛的豬肉河粉遞給妳，\"謝..謝..謝謝你\" 妳還是無法控制自己的羞澀\n");
                tp.type("\"最慢到系館的是大笨蛋\"，他爽朗的說著依樣幼稚的話，說完就騎著單車衝走了 \n");
                tp.type("\"黃梓祺!!! 你給我站住\"，你不認輸的衝刺，這樣的生活，想必會持續到永遠吧 \n");
                tp.type("恭喜妳破關'青梅竹馬共上台大線'");
            }
            else
            {
                tp.type("\"小笨蛋，晚安\"，黃梓祺溫暖的聲線正盡力的在哄你睡著 \n");
                tp.type("妳學測真的太緊張了，沒能考上理想的大學，但妳愛的黃梓祺理所當然的上了台大 \n");
                tp.type("遠距離的戀愛真的好痛苦，手機永遠無法取代他的溫度 \n");
                tp.type("\"ㄋㄟ 聽我說 期末壓力真的好大\"，\"妳...說...甚麼\"，網路又壞掉了 \n");
                tp.type("妳真的好後悔沒能考進台大 \n");
                tp.type("妳靜靜的用棉被摀住自己的口鼻，怕自己的哭聲吵到了室友，若是能重來..... ");
                tp.type("很遺憾的，妳走到了'遠距離戀愛線'");
            }
        }
        else if(characters[2].getAffection() >= 100 && characters[0].getAffection() < 100 && characters[1].getAffection() < 100)
        {
            tp.type("妳趁著學測剛結束的氛圍，想為自己勇敢一次，向語崴表達異己的心意\n");
            tp.type("語崴原本只是班上那種永遠不會和妳有交集的男生\n");
            tp.type("但因為一些有趣的小意外，妳們漸漸相識、熟絡、最後甚至變得有些曖昧\n");
            tp.type("妳慢慢地了解到，他時常的不乾淨的手是因為他喜歡畫畫\n");
            tp.type("妳也發現他原先的冷酷不過只是天性使然罷了\n");
            tp.type("等妳回過神來，發現自己常在晚自習的空檔花痴地望著他 \n")
            tp.type("朋友常會起鬨，但妳卻躊躇不前，害怕連朋友都做不成 \n");
            tp.type("\"我喜歡妳\" 妳在學測結束後的慶祝會喝得酩酊大醉，連走在路上都把樹木當成告白對象 \n");
            tp.type("\"好啊\"");

            if(successfulGuy == true)
            {
                tp.type("\"怎麼啦\" \n 一個熟悉聲音出現，\"想我啦\" 語崴戲謔地說著\n");
                tp.type("\"我說我喜歡王語崴\"，妳以為自己在作夢於是開始歇斯底里地大吼\n");
                tp.type("王語崴愣了一下，\"太好了，我也是\"，他用一如既往地平靜語氣說著，只有妳注意到他的耳根整個都紅透了 \n");
                tp.type("\"難道...\"妳瞬間酒意全失，慌張地不知該如何是好\n");
                tp.type("\"我可不許妳反悔喔\" 語崴好像也喝醉了\n");
                tp.type("妳們在皎潔的月光下緊緊相擁，並祈禱隔天起來不要忘記這瞬間\n");
                tp.type("===三年後===\n");
                tp.type("恭喜王語崴獲得本年度寶可夢藝術展冠軍，我們有請他發表感言\n");
                tp.type("\"我最感謝的人....\"\n");
                tp.type("是的，後來妳們都清晰地記得此事，隔天也默契地和學校請了假，最後還是忍不住地打電話給了對方確認關係\n");
                tp.type("突然，全場的鎂光燈都聚焦在妳的身上\n");
                tp.type("\"這位就是我引以為傲的妻子，....\"\n");
                tp.type("妳猜得沒錯，妳考上了台大，他上了藝術大學，以'她'這份版畫一炮而紅，當然!!!模特是妳\n");
                tp.type("王語崴因此在國際上很是出名，這是今年她參加的第4765252場頒獎了\n");
                tp.type("\"妳願意 嫁給我嗎\"，妳只顧著旁白，因而被全場的驚呼聲嚇了一跳，\"我...我願意\"\n");
                tp.type("全場歡呼，妳戴上了300克拉的大鑽戒，喜極而泣\n");
                tp.type("恭喜妳通關了'語崴chill guy線'");
            }
            else
            {
                tp.type("妳看見了梓祺在門口壁咚語崴，他好像答應了梓祺的告白n");
                tp.type("他們看起來是如此相愛\n");
                tp.type("\"明明是我先來的.....\"\n");
                tp.type("妳難過地跑走了\n");
                tp.type("\"到底為甚麼.....\"\n");
                tp.type("很遺憾的，妳走到了'白學線'");
            }
        }
    }
    void checkEnding() {
        // 檢查是否達到結局條件
        // 先考試
        int score;
        if(player.getAcademic() >= 300)
            score = collegeTest("easy");
        else if (player.getAcademic() < 300 && player.getAcademic() >= 200)
            score = collegeTest("moderate");
        else score = collegeTest("hard");
        tp.setSpeed(100);
        tp.type("學測中你一共獲得了");
        cout << score << "分\n";
        if(score == 75){
            tp.type("你考上了夢寐以求的台大，家人邀請你左鄰右舍一起來放鞭炮慶祝，\n殊不知台大的期中是你後悔的開始......\n");
        }
        else if (score == 50){
            tp.type("你考上了一所中字山大學，幸好妳的家人不是Asian partents，家人很為你高興，認為你的投入有換來回報， 你愉快地和猴子們跳起了猩猩之舞\n");
        }
        else{
            tp.type("你最終去了小葉大學......在那邊當店神\n");
        }
        // 加權結算總能力值
        score *= 3;
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
            solution[0] = 4;
            solution[1] = 2;
            solution[2] = 2;
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
            solution[0] = 4;
            solution[1] = 3;
            solution[2] = 1;
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
            solution[0] = 4;
            solution[1] = 2;
            solution[2] = 3;
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
    void run() {
        while(true) {
            string inputCommand; // 玩家指令
            displayStatus(); // 展示能操作的選項
            int currentMove = player.getMove(); //現在剩餘行動點等於這個玩家最高行動點上限
            int index1 = 0; // 陳愛芬的主線章節進度
            int index2 = 0; // 黃梓祺的主線章節進度
            int index3 = 0; // 王語崴的主線章節進度
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
                uniform_real_distribution<double> dis(0.0, 1.0);
                if(dis(gen) < 0.04*player.getLucky()) {
                    tp.type("觸發角色事件！\n");
                    uniform_int_distribution<int> number_dis(0, 2); //0 1 2 三個角色選一個觸發
                    // 跑出事件
                    if(number_dis(gen) == 0 && index3 != 12){ // 王語崴
                        characters[3].addAffection(eventsystem.characEvents[index3]->charMakeChoices(player));
                        index3++;
                        
                    }
                    else if(number_dis(gen) == 1 && index1 != 9){ // 陳愛芬
                        characters[0].addAffection(eventsystem.characEvents[index1 + 11]->charMakeChoices(player));
                        index1++;
                    }
                    else if(number_dis(gen) == 1 && index2 != 11){ // 黃梓祺
                        characters[1].addAffection(eventsystem.characEvents[index2 + 19]->charMakeChoices(player));
                        index2++;
                    }

                }
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
    DatingGame game;
    game.setGame();
    game.run();
    return 0;
}
