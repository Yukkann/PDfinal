#include "EventSystem.h"
using namespace std;
void EventSystem::setEvents(){
    int n = 5;
    // 學力 人緣 魅力 耐力 疲勞 運氣 || 敘述 
    events.push_back(new Events(
        "你父母要求你和他們一起出門拜拜，你會選...?",
        "1. 開心的出門和他們拜拜/2. 覺得這就是迷信，到底他媽三小/3. 跟他們說老子就是文昌帝君，不用拜"
    ));
    events[0]->setResultOne1(0,3*n,2*n,0,0,5*n,"你是個懂得讀空氣的人",3,10);
    events[0]->setResultOne2(n,3*n,2*n,0,0,4*n,"有拜有保庇");
    events[0]->setResultTwo1(2*n,-2*n,-2*n,0,0,-n,"雖然書讀得多，但也不能白目...",1,15);
    events[0]->setResultTwo2(0,-2*n,-2*n,0,0,-n,"你這白目鬼...");
    events[0]->setResultThree1(n,-2*n,-5*n,0,0,-n,"今天文昌帝君開心，沒有給妳很大懲罰...",6,20);
    events[0]->setResultThree2(n,-2*n,-5*n,0,0,-n,"今天運氣不好，文章帝君生氣了，給你下降頭...");

    //event2
    events.push_back(new Events(
        "期中考在即，你打算如何應考...?",
        "1. 專心準備，提升在校成績有助於升學/2. 都要學測了，當然是準備學測，誰跟你在那邊期中考/3. 反正我這輩子就這樣了，躺平比較快"
    ));
    events[1]->setResultOne1(3*n, 0, 0, 0, 3*n, 0, "你習慣爆讀了，效果顯著", 4, 15);
    events[1]->setResultOne2(2*n, 0, 0, 0, 4*n, 0, "你還沒習慣爆讀，你感覺有點累...");
    events[1]->setResultTwo1(2*n,0,-n,2*n,0,0,"你讀了好多學測範圍，已經沒什麼好進步的了",1,20);
    events[1]->setResultTwo2(3*n,0,-n,3*n,0,0,"你進步了許多！但也感到有些疲累");
    events[1]->setResultThree1(-n,2*n,3*n,2*n,0,0,"你帶動了躺平風潮，但太頹廢使你學歷下滑",2,10);
    events[1]->setResultThree2(-n,n,n,2*n,0,0,"沒什麼人跟你一起躺平，但依然有迴響...");

    //event3
    events.push_back(new Events(
        "要學測了，但你還是克制不住原始衝動交往了，在過程中，他/她要你跟他出去玩，你會...?",
        "1. 玩啊，學測爆了還能再考一次，但伴侶沒了很難找第二個/2. 不出門玩，專心準備學測/3. 跟他/她說這個週末有事，但是陪另一個人出去玩"
    ));
    events[2]->setResultOne1(-n, n, 2*n, 0, n, -n, "你已經讀很多書了，玩一下問題不大，而且提升好感度了！", 1, 15);
    events[2]->setResultOne2(-2*n, n, 2*n, 0, n, -n, "都不讀書還玩，學力下降了齁...");
    events[2]->setResultTwo1(3*n, -n, -2*n, 0, 0, 0, "幸好他對你好感度高，在不被討厭的情況下你學了許多", 2, 13);
    events[2]->setResultTwo2(3*n, -2*n, -4*n, 0, 0, 0, "男人，只會影響我做題的速度（妳似乎被討厭了）");
    events[2]->setResultThree1(2*n, 0, n, 0, 0, 2*n, "運氣不錯，他沒有不高興，反而因為你會規劃時間而覺得妳很棒", 6, 15);
    events[2]->setResultThree2(2*n, 0, -n, 0, 0, 0, "可惜了，他今天不是很開心，但有給理由他覺得合理");

    // event4
    events.push_back(new Events(
        "在路上遇到推銷股票的店員，他說有一個剛上市的新創公司要你參考看看，你會...?",
        "1. 讀書啊，不要搞那些有的沒的/2. 忽略他然後去找朋友玩/3. 老子賭狗，不試試怎麼知道，本金allin!!"
    ));
    events[3]->setResultOne1(2*n, 0, -n, 0, 0, n, "你認真讀書不碰股票，心情穩定，但被推銷員暗中討厭", 1, 20);
    events[3]->setResultOne2(n, 0, 0, -n, 0, n, "推銷員有點不喜歡你...");
    events[3]->setResultTwo1(0, 0, -n, 0, n, 0, "妳忽略他但他一直盧你，但妳不怎麼覺得煩", 4, 15);
    events[3]->setResultTwo2(0, 0, -n, 0, -2*n, 0, "他一直盧你，你感到有些疲累");
    events[3]->setResultThree1(n, 5*n, 0, 0, 0, -n, "你很幸運的遇到了投資大師，賺了一波大的，朋友++", 6, 25);
    events[3]->setResultThree2(-2, -2*n, 0, 0, 0, -n, "早知道看股的時間拿來讀書就好，下輩子還跟大哥一起投資");

    // event5
    events.push_back(new Events(
        "你的目標校系實驗室因為操作不當爆炸了，該校決定讓該系招生人數砍半以去蕪存菁，你會...?",
        "1. 轉換跑道，改成其他學系/2. 台大有什麼了不起，爛台大，鬼轉其他學校/3. 開始更努力爆讀，並從此討厭可莉玩家"
    ));
    events[4]->setResultOne1(2*n, 0, 0, 0, n, 0, "幸好你書看得多，轉換跑道不需要耗費你太多精力", 1, 21);
    events[4]->setResultOne2(n, 0, 0, 0, 3*n, 0, "完蛋，鬼轉一個讓你有點力不從心");
    events[4]->setResultTwo1(-n, n, 2*n, 0, -n, 0, "真巧，妳的朋友們也這樣想，一起逃", 2, 15);
    events[4]->setResultTwo2(-n, 0, n, 0, -n, 0, "哇勒，沒人想跟你一起鬼轉，可憐...");
    events[4]->setResultThree1(4*n, 0, 0, -n, 3*n, 0, "你爆讀了一波，獲益良多，但有點累了", 4, 20);
    events[4]->setResultThree2(3*n, 0, 0, 0, 4*n, 0, "累死，名額減徵真的會讓人讀死");

    // event6
    events.push_back(new Events(
        "你的同學出車禍了，但你有點燒機讀不完，你會...?",
        "1. 讀書什麼的怎麼可能有朋友重要，當然是去探望啊/2. 我都要讀不完了你給我搞這齣，絕交/3. 乾好難抉擇，啊想到了！去醫院陪他讀書！"
    ));
    events[5]->setResultOne1(-n, 3*n, 3*n, 0, 0, n, "朋友覺得暖na，對你的評價大幅上升", 1, 15);
    events[5]->setResultOne2(-2*n, 3*n, 3*n, 0, 0, n, "朋友覺得暖na，對你的評價大幅上升");
    events[5]->setResultTwo1(2*n, -n, -n, 0, 0, 0, "好吧，確實要考試了，妳的朋友這麼想著...", 2, 15);
    events[5]->setResultTwo2(2*n, -3*n, -2*n, 0, 0, 0, "這人怎麼那麼無情，妳的朋友這麼想著...");
    events[5]->setResultThree1(2*n, n, 2*n, 0, n, 0, "朋友覺得你很聰明，雖然很累但你們度過了有意義的時光", 2, 15);
    events[5]->setResultThree2(2*n, 2*n, 3*n, 0, 2*n, 0, "朋友對你的觀感提升不少，聰明na");

    // event7
    events.push_back(new Events(
        "你爸媽今天突然被公司裁員了，家裡氣氛凝重，你想要...?",
        "1. 好好讀書，大人的是小孩不要管/2. 身為孩子必須當一下和事佬，去緩和氣氛/3. 反正我這輩子就這樣了，躺平比較快"
    ));
    events[6]->setResultOne1(2*n, 0, -n, -n, n, 0, "看在你乖乖讀書有成果的份上，爸媽沒有情勒妳，但你有點累了", 1, 20);
    events[6]->setResultOne2(2*n, 0, -2*n, -n, n, 0, "書沒讀好還這樣，哎，到底了，妳父母這樣覺得...");
    events[6]->setResultTwo1(0, 0, n, 0, n, 2*n, "運氣不錯，妳剛好用他們最想聽的話安慰到他們了", 6, 10);
    events[6]->setResultTwo2(0, 0, n, 0, n, n, "讚讚，雖然不是這麼中聽，但他們還是被安慰到了");
    events[6]->setResultThree1(-n,-n,-n,-2*n,0,-n,"有讀書也不能這樣躺平吧，父母生氣地說道...",1,20);
    events[6]->setResultThree2(-3*n,-n,-n,-2*n,0,-n,"這孩子怎麼不會讀空氣也不會讀書啊，父母如此喃喃自語道...");

    //event8
    events.push_back(new Events(
        "你的兄弟突然把他的秘密男友帶回家，你父母覺得難以接受，家中氣氛尷尬，你會...?",
        "1. 把自己關在房間，他們的事他們自己處理/2. 跟爸媽講一下現在開放的交往風氣，跟他們說這是哥哥/弟弟的自由/3. 離家出走，這個家沒救了"
    ));
    events[7]->setResultOne1(n,0,-n,0,n,-2*n,"除了讀到一點書以外什麼都沒發生",1,15);
    events[7]->setResultOne2(0,0,-n,0,2*n,-n,"這樣的低氣壓讓你讀不下書，你覺得一天都白費了");
    events[7]->setResultTwo1(0,2*n,2*n,0,2*n,3*n,"父母覺得你是他們的孩子非常幸運，他們很開心",3,15);
    events[7]->setResultTwo2(0,n,n,0,3*n,3*n,"你用了比較長的時間說服他們，累了");
    events[7]->setResultThree1(-3*n,-2*n,-2*n,0,n,0,"你在外面流浪許久，荒廢課業，父母擔心",4,15);
    events[7]->setResultThree2(-n,-n,-n,0,2*n,0,"幸好你是弱雞，流浪不了多久，課業沒有完全荒廢，但妳好累");

    //event9
    events.push_back(new Events(
        "你家人買的台股綠油油一片，他們心情非常躁，你會...?",
        "1. 跟他們說「啊哈哈我同學美股也綠一片啦」/2. 給他們看紅通通的考卷/3. 安慰他們投資理財有賺有賠，投資前請詳閱公開說明書"
    ));
    events[8]->setResultOne1(0,0,-3*n,0,-n,-n,"妳超幸運，他們今天心情沒有燥到很誇張，但還是小不爽",6,30);
    events[8]->setResultOne2(0,0,-4*n,0,-2*n,-n,"你被打了一頓，你在家人心中留下不好印象");
    events[8]->setResultTwo1(-n,0,n,0,0,2*n,"你家人知道你成績不錯，會這樣一定是意外，他們獲得些許安慰",1,20);
    events[8]->setResultTwo2(-n,0,-n,0,0,-n,"家人覺得讀不好書還這樣白目，你被打了一頓");
    events[8]->setResultThree1(n,0,n,0,0,n,"你在安慰的同時學到了一些理財內容，薛爆",1,15);
    events[8]->setResultThree2(0,0,n,0,0,n,"有安慰到，但不多");

    //event10
    events.push_back(new Events("你發現你閨蜜在情人節收到一堆巧克力但你一個都沒收到，你會...?",
    "1. 開始一個人哭/2. 跟閨蜜說他太胖了不適合吃甜的/3. 幫他慶祝，這樣他就會分你一些巧克力"
    ));
    events[9]->setResultOne1(0,0,0,0,2*n,0,"妳哭得有點累了",4,15);
    events[9]->setResultOne2(0,0,0,0,3*n,0,"妳哭得有點累了");
    events[9]->setResultTwo1(0,-n,-2*n,0,0,0,"閨蜜覺得交情再好也不能這樣，她有點難過",2,20);
    events[9]->setResultTwo2(0,-3*n,-5*n,0,2*n,-n,"閨蜜覺得妳超雞掰，開始散佈妳是ㄅㄗ的謠言");
    events[9]->setResultThree1(0,n,2*n,0,0,2*n,"閨蜜覺得有你這樣的朋友很幸運，開心～",3,15);
    events[9]->setResultThree2(0,n,2*n,0,0,0,"閨蜜覺得妳很讚，好耶～");
    //event11
    events.push_back(new Events("你坐公車回家的時候睡過站到終點站，回到家發現浪費了一個小時，你很生氣",
    "1. 告訴自己該休息了，空出一天不讀書休息/2. 乾又浪費一個小時讀書，睡少一點讀回來/3. 你根本不在乎，因為你是一個Chill guy"
    ));
    events[10]->setResultOne1(0,0,0,n,-3*n,0,"這選擇是對的，你的疲憊感下降了不少",1,20);
    events[10]->setResultOne2(-n,0,0,n,-3*n,0,"雖然荒廢一天有點過意不去，但獲得了大量休息，疲憊感大量下降");
    events[10]->setResultTwo1(2*n,0,0,-n,2*n,0,"死命讀了一下，有讀東西進去，但這樣真的好嗎...?",1,20);
    events[10]->setResultTwo2(0,0,0,-n,2*n,3*n,"爆肝但什麼都沒讀進去，甚至差點進了醫院");
    events[10]->setResultThree1(0,n,n,0,-2*n,-n,"你很幸運的在地上撿到錢，大家都喜歡chill guy",6,10);
    events[10]->setResultThree2(0,n,n,0,-2*n,0,"你成功引起其他人注意，因為大家都喜歡chill guy");

    //event12
    events.push_back(new Events("你在地上撿到了1000塊，你會...?","1. 火鍋吃到飽/2. 嘉獎/3. 放在原地瀟灑離去"));
    events[11]->setResultOne1(0,-n,0,n,0,-3*n,"你被朋友知道後被說不揪",2,15);
    events[11]->setResultOne2(0,0,0,n,0,-n,"沒人知道你選了火鍋，薛爆");
    events[11]->setResultTwo1(0,n,2*n,0,0,5*n,"你朋友多，多到這件事被當一段佳話傳下去",2,15);
    events[11]->setResultTwo2(0,n,n,0,0,5*n,"很少人知道，不過就當積陰德吧！");
    events[11]->setResultThree1(0,n,0,0,0,n,"朋友都覺得你是chill guy真不錯",2,25);
    events[11]->setResultThree2(0,0,0,0,0,n,"什麼事都沒發生...但幾沒做虧心事讓你積了一點陰德");

    //event13
    events.push_back(new Events(
        "看到別的男同學石門水庫沒拉，你會...?",
        "1. 小聲提醒他/2. 錄影然後傳到社交平台上/3. 當作什麼事都沒發生，不管他"
    ));
    events[12]->setResultOne1(0,2*n,2*n,0,0,0,"妳幸好你性別正確，他覺得妳很有禮貌",2,15);
    events[12]->setResultOne2(0,n,n,0,0,2*n,"積個陰德，不錯");
    events[12]->setResultTwo1(0,-3*n,-2*n,0,0,-n,"你的運氣不錯，影片沒有飄出去，不多人知道你很雞掰",6,30);
    events[12]->setResultTwo2(0,-5*n,-4*n,0,0,-n,"影片傳很開，你被發現是拍攝者，身敗名裂");
    events[12]->setResultThree1(0,0,0,0,n,n,"你朋友多，大家都把你當chill guy",3,20);
    events[1]->setResultThree2(0,0,0,0,n,0,"沒什麼事發生，但你的眼睛被傷到了QQ");

    //event14
    events.push_back(new Events(
        "你追了很久的漫畫突然爛尾了，雖然你早有預感，但還是感到難過，你現在身邊有一堆不要的周邊，你會...?",
        "1. 一怒之下把周邊全部丟了/2. 反正都是不要的，不如低價出掉/3. 不管他，並開始後悔為什麼要花大把時間吃一坨大便"
    ));
    events[13]->setResultOne1(n,0,0,0,2*n,0,"心無旁騖讀書，成績進步了一點，但妳丟得有點累",4,20);
    events[13]->setResultOne2(n,0,0,0,3*n,0,"乖乖讀書，成績進步，但你是弱雞，丟周邊讓你累到虛脫");
    events[13]->setResultTwo1(0,0,n,0,n,n,"商業頭腦get",6,5);
    events[13]->setResultTwo2(2*n,0,n,0,2*n,5*n,"你運氣超差，賣貨被詐騙，不過你已因此學到刑法內容");
    events[13]->setResultThree1(0,n,0,-2*n,n,0,"你耐受度高，覺得這沒什麼",4,25);
    events[13]->setResultThree2(0,0,0,-3*n,n,0,"妳哭慘了，最慘的那種，浪費了一天");

    //event15
    events.push_back(new Events(
        "搭捷運因為慣性不小心碰到旁邊的大媽，大媽以為妳看上她了，想要告你性騷擾，你會...?",
        "1. 跟她說妳是伊斯蘭教的不能吃豬肉/2. 跟她好好解釋慣性是什麼，禮貌道歉並遠離/3. 開始大吵，老娘讀書累一天了還要遇到這種破事"
    ));
    events[14]->setResultOne1(0,2*n,2*n,0,0,-3*n,"你的幽默讓其他路人笑出來了，但大媽不這麼覺得",3,15);
    events[14]->setResultOne2(0,n,n,0,0,-3*n,"只有旁邊的人有笑，但有一部分人覺得有點過分");
    events[14]->setResultTwo1(n,0,n,0,3*n,0,"複習了一下並讓大媽學到一課",1,10);
    events[14]->setResultTwo2(2*n,0,n,0,3*n,0,"獲益良多，自己和大媽");
    events[14]->setResultThree1(0,-2*n,-n,-n,3*n,-n,"大吵一架的你心情沒有變好，反而有點累",4,20);
    events[14]->setResultThree2(0,-2*n,-n,-n,4*n,-n,"大吵一架的你非常累，大家都不覺得你是chill guy");

    //event16
    events.push_back(new Events(
        "妳今天讀了一整天的書忘記吃東西，要出門買晚餐時發現腳踏車落鏈，你會...?",
        "1. 不吃了，繼續讀書/2. 用走的過去買，今天要吃東西不然會餓爆/3. 蹲在腳踏車旁邊哭，抱怨這世界的不公平"
    ));
    events[15]->setResultOne1(n,0,0,0,3*n,n,"你真的又爆讀了，很累但值得",1,20);
    events[15]->setResultOne2(2*n,0,0,-n,3*n,n,"你學到了不少，但差點胃穿孔送醫");
    events[15]->setResultTwo1(0,0,0,2*n,-n,n,"你成功吃到東西了，耶比\\>o</",4,15);
    events[15]->setResultTwo2(0,0,0,3*n,-2*n,n,"你體力不好，走得很累，但吃到東西了，讚讚");
    events[15]->setResultThree1(n,0,-n,0,2*n,n,"妳哭著哭著悟到人生真理",1,30);
    events[15]->setResultThree2(0,0,-n,0,2*n,n,"妳哭但沒人在乎，挺可憐的");

    //event17
    events.push_back(new Events(
        "你的錢包似乎被警衛偷走，追蹤錢包中的Air tag 發現跑到外縣市，你會...?",
        "1. 先讀書，不然要燒機了/2. 雖然裡面只有差不多500，但還是報個警/3. 好心提醒給警衛機會還，還了不追究"
    ));
    events[16]->setResultOne1(3*n,0,0,0,0,0,"化悲憤為力量，爆讀，學到許多",1,20);
    events[16]->setResultOne2(5*n,0,0,0,0,0,"因為有很大的進步空間，所以進步了許多");
    events[16]->setResultTwo1(0,0,-n,0,n,2*n,"報了一個大的，但警察似乎覺得沒意思想吃案",4,10);
    events[16]->setResultTwo2(0,0,-n,0,2*n,2*n,"長途拔涉報了案，你累了，為了500元");
    events[16]->setResultThree1(n,0,0,-2*n,3*n,2*n,"你學到了人生中的一課，不要相信其他人",1,20);
    events[16]->setResultThree2(0,0,0,-2*n,3*n,2*n,"你一直通知警衛但他都不鳥你，你快被磨光精神了");
    //event18
    events.push_back(new Events(
        "偷你錢包的警衛死不承認，你後來報警了，但他拖拖拉拉導致你浪費了好幾個小時等他，你會...?",
        "1. 這死人怎麼都不出來，我一定告死他/2. 求償最高的合理價格，省時間/3. 自認倒霉，下次一定等到"
    ));
    events[17]->setResultOne1(0,n,n,0,0,n,"大家都覺得你幹得好，早該這樣做了",3,15);
    events[17]->setResultOne2(0,-n,-n,0,0,n,"你人緣似乎不是很好，大家都覺得你不是chill guy了");
    events[17]->setResultTwo1(0,-n,-2*n,0,0,-n,"很幸運的，判決出來說你可以拿10倍補償金，但好多人都覺得你很急掰",6,10);
    events[17]->setResultTwo2(0,-n,-2*n,0,0,0,"你未能拿檔最高補償金，可憐");
    events[17]->setResultThree1(0,0,2*n,0,0,3*n,"大家都覺得你是chill guy，所以幫你報警了",2,15);
    events[17]->setResultThree2(0,0,n,0,0,3*n,"雖然沒什麼朋友，但妳看開了");

    //event19
    events.push_back(new Events(
        "你朋友心情好喝酒，但回宿舍後沖澡時暈倒了，這時候你會...?",
        "1. 打電話給110然後確認現場情況/2. 先錄影丟到社群平台再說/3. 打完110後不管他，偷卷"
    ));
    events[18]->setResultOne1(0,2*n,3*n,0,0,-n,"你運氣很好，朋友剛好用三點式落地最小化傷害",6,20);
    events[18]->setResultOne2(0,2*n,3*n,0,0,n,"運氣不好，醫護人員差點以為是你要暗殺他");
    events[18]->setResultTwo1(0,-3*n,-3*n,0,0,-n,"運氣不錯，沒有傳太遠，但還是有人覺得你很過分",6,10);
    events[18]->setResultTwo2(0,-6*n,-6*n,0,2*n,-n,"運氣不好，影片爆紅了，妳朋友漸漸疏離你，妳身敗名裂並被朋友告，身心俱疲");
    events[18]->setResultThree1(3*n,0,0,0,n,n,"少了一個對手捲起來更得心應手，舒服",1,15);
    events[18]->setResultThree2(4*n,0,0,0,n,n,"卷爛了，舒服，差距就是在喝酒後拉開的");

    //event20
    events.push_back(new Events(
        "妳因為分心，不小心把補習班的玻璃門推爆了，補習班事後向你求償，你會...?",
        "1. 先跑到外縣市朋友家避風頭/2. 直接付錢了事/3. 跟他們說工讀還錢，還能順便偷聽幾堂課"
    ));
    events[19]->setResultOne1(0,-n,-2*n,0,3*n,-n,"要這樣就是了，我沒想過你是這樣的人",4,15);
    events[19]->setResultOne2(0,-n,-2*n,0,4*n,-n,"長途跋涉讓你累了，逃避問題也讓朋友們逃離你");
    events[19]->setResultTwo1(0,n,2*n,0,0,-n,"你在路上刮刮樂剛好中了，賠償金一下子就賺到了",6,20);
    events[19]->setResultTwo2(0,2*n,3*n,0,2*n,0,"你湊了很久的賠償金，有點累，但朋友覺得你很有guts");
    events[19]->setResultThree1(2*n,0,n,-n,n,0,"朋友覺得你有夠卷，崇拜na",4,30);
    events[19]->setResultThree2(2*n,0,n,-2*n,2*n,0,"半工半讀讓你有點疲倦了...");

    //event21
    events.push_back(new Events(
        "妳的朋友暈船還一直犯花癡，但他暈船對象似乎沒戲，妳會...?",
        "1. 跟他直接說沒料，讓他認清現實/2. 爽啦，考試對手又少一個了，暈都暈/3. 跟他一起發瘋"
    ));
    events[20]->setResultOne1(0,-2*n,-3*n,0,0,-n,"你朋友剛好載暈船對象去買飲料，你只有讓他微破防",2,30);
    events[20]->setResultOne2(0,-3*n,-4*n,0,0,-n,"你朋友破防了，他認真覺得很難過，有點想絕交");
    events[20]->setResultTwo1(n,-n,-n,0,0,-n,"能學的已經不多了，基本都熟了",1,20);
    events[20]->setResultTwo2(2*n,-n,-n,0,0,-n,"還有蠻多進步空間，而且進步挺多");
    events[20]->setResultThree1(0,2*n,3*n,0,0,3*n,"妳的朋友很感謝你，他很開心",2,20);
    events[20]->setResultThree2(0,2*n,2*n,0,0,3*n,"妳的朋友和你感情更進一步了，真不戳");

    //event22
    events.push_back(new Events(
        "妳常逛的雜誌店店員是噁男，發現你的雜誌可能被他非禮過，你會...?",
        "1. 將自身遭遇發到網路上，抱怨世界的不公平/2. 把東西留著，畢竟深愛過/3. 把雜誌們都丟了，好噁"
    ));
    events[21]->setResultOne1(0,2*n,3*n,0,0,-n,"很多跟你站在一起的網友，讚",6,20);
    events[21]->setResultOne2(0,2*n,n,0,0,0,"有人站在你這裡也有人反對，但你現在順風局");
    events[21]->setResultTwo1(-n,0,0,0,n,0,"保養東西讓你累了，玩物喪志",4,15);
    events[21]->setResultTwo2(-n,0,0,0,2*n,0,"明明體力不好硬要留，浪費一堆讀書時間");
    events[21]->setResultThree1(0,0,2*n,0,n,0,"大家覺得你是有原則的人，對你好感度提升",4,10);
    events[21]->setResultThree2(0,0,2*n,0,3*n,0,"雖然搬的有點累，但真的很噁");

    //event23
    events.push_back(new Events(
        "喜歡的男團來台開演唱會，但大考在即，你會...?",
        "1. 偶像不一定明年會來，但學測會，追爆！！/2. 先讀書，之後跟朋友要演唱會的片段看/3. 好難決定啊啊啊，直接去演唱會讀書"
    ));
    events[22]->setResultOne1(-2*n,0,0,0,4*n,0,"你追星追到精疲力盡，沒力氣讀書，學力微幅下降",4,20);
    events[22]->setResultOne2(-3*n,0,0,0,5*n,0,"明明體力不好但還是追星了，累脱，而且躺了幾天根本不能讀書");
    events[22]->setResultTwo1(4*n,3*n,4*n,0,n,3*n,"妳超卷，這是很成功的選擇",2,20);
    events[22]->setResultTwo2(4*n,2*n,3*n,0,n,3*n,"朋友覺得你很厲害，願意放棄演唱會讀書，真不戳");
    events[22]->setResultThree1(n,-n,0,0,2*n,0,"你朋友覺得你不尊重歌手，不如回家讀書",2,10);
    events[22]->setResultThree2(n,-2*n,0,0,2*n,0,"你朋友對你很失望，友情危機");

    //event24
    events.push_back(new Events(
        "要期末考了，但你現在非常鬱悶，你會...?",
        "1. 給自己放鬆幾個小時，看看風景吹吹風/2. 走到頂樓，看著大家都在忙，覺得人生非常短暫，不由得哭了起來/3. 好煩喔，乾脆給車撞一撞好了"
    ));
    events[23]->setResultOne1(n,n,n,2*n,0,0,"因為你是chill guy所以你在吹風的時候也能自我提升",2,20);
    events[23]->setResultOne2(0,0,0,2*n,0,0,"吹個風放鬆一下，開心");
    events[23]->setResultTwo1(0,2*n,3*n,0,n,0,"你的知心好友一起陪你哭，雖然有點累但放鬆了不少",2,30);
    events[23]->setResultTwo2(0,n,2*n,0,n,0,"妳的朋友路過看到你在哭便上前安慰，你繼續哭但心情有比較好");
    events[23]->setResultThree1(20*n,0,0,0,5*n,-n,"你閃過一台車，有驚無險，妳決定好好讀書",6,100);
    events[23]->setResultThree2(-10*n,0,0,0,0,-n,"你被車撞到了，命危，因此少讀很多書，虧爆");

    //event25
    events.push_back(new Events(
        "期末報告有一個組員完全在狀況外，搞得你們其他人loading很重，你會...?",
        "1. 直接跟他說開，叫他做事及時止損/2. 就讓它擺爛不管他，最後組員名單放在未貢獻的欄位/3. 跟他一起擺爛，反正要大考了，他這樣是難免的"
    ));
    events[24]->setResultOne1(n,2*n,3*n,0,n,0,"跟他吵架讓你有點累了，但其他組員覺得你是英雄",4,30);
    events[24]->setResultOne2(2*n,2*n,3*n,0,2*n,0,"你沒想到吵架那麼累");
    events[24]->setResultTwo1(0,-n,-2*n,0,3*n,0,"少一個人扛很累，其他人對你的風評有點差...",4,25);
    events[24]->setResultTwo2(0,-n,-2*n,0,4*n,0,"妳扛了一波大的，累脱，但其他人在你背後說壞話");
    events[24]->setResultThree1(-n,2*n,3*n,0,0,0,"大家都喜歡你，他們都認爲你是chill guy",3,35);
    events[24]->setResultThree2(-n,-n,-2*n,0,0,0,"妳人緣似乎不太好，他們對妳議論紛紛");

    //event26
    events.push_back(new Events(
        "你走在路上的時候輩電線絆倒，跌倒後檢查發現膝蓋脫臼且脛骨骨折，你會...?",
        "1. 抱怨這世界的不公平，開始哭，自暴自棄/2. 去醫院讀書不錯欸，時不時就有醫學系的進來，可以問問題/3. 難過，選最高樓層病房然後趁其他人不注意一躍而下"
    ));
    events[25]->setResultOne1(0,0,0,0,2*n,0,"大哭一場讓你好了很多",4,30);
    events[25]->setResultOne2(0,0,0,0,3*n,0,"妳哭到累了，但是心情輕鬆很多");
    events[25]->setResultTwo1(5*n,0,0,0,n,4*n,"你很幸運，進來的醫生很願意分享知識",6,20);
    events[25]->setResultTwo2(2*n,0,0,0,n,3*n,"可惜，這個醫生有時候會敷衍你，但你還是有學到東西");
    events[25]->setResultThree1(n,0,0,0,10*n,-n,"妳剛好掉在放置廢棄病床的空地，受到輕傷，你學到人摔在超厚床墊上死不了",6,90);
    events[25]->setResultThree2(-5*n,-2*n,-3*n,0,20*n,-n,"妳嚇到朋友了，受重傷後無法讀書，什麼都沒了");

    //event27
    events.push_back(new Events(
        "你最近發票中了5000元，你會...?",
        "1. 拿5000元買刮刮樂，賭一把/2. 要考試了，把一部分獎金捐給慈善團體/3. 請朋友一起吃一頓好的"
    ));
    events[26]->setResultOne1(0,0,2*n,0,0,30*n,"運氣極好，妳刮中1000萬",6,70);
    events[26]->setResultOne2(0,0,2*n,0,0,0,"可惜了，什麼都沒有");
    events[26]->setResultTwo1(0,3*n,4*n,0,0,15*n,"你朋友覺得你很有愛心，你在默默積陰德",3,20);
    events[26]->setResultTwo2(0,2*n,3*n,0,0,15*n,"旁人覺得你很讚，默默做善事運氣一定好");
    events[26]->setResultThree1(0,2*n,3*n,4*n,0,2*n,"你朋友覺得你人好好",2,20);
    events[26]->setResultThree2(0,n,2*n,4*n,0,n,"你朋友雖然交情還沒很好但感情變好了");
    //event28
    events.push_back(new Events(
        "你刮刮樂中1000萬了，好事連連，你會...?",
        "1. 都有1000萬了可個屁試，先爽一年再說/2. 好好運用獎金，拿去給父母投資股票/3. 到文昌廟投10萬香油錢"
    ));
    events[27]->setResultOne1(20*n,0,0,0,10*n,-n,"投資賺了一波大的，請頂級家教幫你補成績",6,100);
    events[27]->setResultOne2(5*n,0,0,0,0,-n,"花了大錢但效果不彰，只學到一點東西");
    events[27]->setResultTwo1(20*n,0,3*n,0,0,-n,"父母投資成功，幫你請名師補習，家庭氣氛更融洽了",6,70);
    events[27]->setResultTwo2(5*n,0,2*n,0,0,0,"父母投資普普，幫你請普通家教，效果不太明顯");
    events[27]->setResultThree1(30*n,0,0,0,2*n,100*n,"文昌帝君顯靈，變超聰明，運氣變好",1,20);
    events[27]->setResultThree2(10*n,0,0,0,2*n,100*n,"文昌帝君顯靈只顯出上半身，但成績有變好");

    //event29
    events.push_back(new Events(
        "考試前一週你發現證件不見了，但補辦需要7個工作天，你會...?",
        "1. 死定了，還是就重考啊/2. 問一下能不能當急件，試著搶救一下/3. 發信問大考中心能不能拿其他證件作為警急替代"
    ));
    events[28]->setResultOne1(-7*n,0,0,0,3*n,4*n,"妳心態崩了，一瞬間忘記許多讀完的內容",1,40);
    events[28]->setResultOne2(-2*n,0,0,0,3*n,4*n,"你沒心態了，但你學的不多，忘的也不多");
    events[28]->setResultTwo1(0,0,0,0,5*n,0,"妳警急補件，這讓你心有點累",4,30);
    events[28]->setResultTwo2(0,0,0,0,6*n,0,"警急補件，但長途跋涉讓你累脱了");
    events[28]->setResultThree1(0,0,0,0,n,0,"你很幸運，可以用其他證件",6,50);
    events[28]->setResultThree2(0,0,0,0,5*n,0,"可惜了，這屆規定只能用身分證，你需要警急補件");

    //event30
    events.push_back(new Events(
        "在回家路上經過一個河濱，看到有狗勾和其他人一起玩耍，你會...?",
        "1. 停下車來看這美麗風景/2. 停車並加入他們/3. 在心裡偷偷羨慕狗勾不用讀書，然後跑回家讀書"
    ));
    events[29]->setResultOne1(0,0,0,0,-3*n,5*n,"你覺得很開心，並相信會一直幸運下去",6,10);
    events[29]->setResultOne2(0,0,0,0,-3*n,2,"你覺得普通開心");
    events[29]->setResultTwo1(0,0,2*n,0,0,3*n,"狗勾很喜歡你，恭喜",3,15);
    events[29]->setResultTwo2(0,0,3*n,0,0,3*n,"雖然素未謀面，但你和狗勾好像老朋友一般，玩得不亦樂乎");
    events[29]->setResultThree1(5*n,0,0,0,-n,3*n,"你覺得幸運，讀書時很有精神，讀得超多",1,15);
    events[29]->setResultThree2(7*n,0,0,0,-n,2*n,"你覺得非常開心，讀書時也神采奕奕，吸收許多知識");
}

void setCharacEvents(){
    int n = 5;
    //0-9: events about character C
    characEvents.push_back(new Events(5, 20, -5
        "在補習班遇到班上的跟你很不熟的帥哥王語崴，他從遠遠的地方走來就感覺在散發光芒！你會選擇...?",
        "1. 就這樣默默看著他/2. 去跟他交談，順便跟他要哀居/3. 拿書包裡的餅乾假裝跟所有人分享，有意無意的問他要不要一起吃"
    ));
    characEvents[0]->setResultOne1(0,0,0,0,0,0,"對方好像有看到你，對你好感度+5，不過你也沒有更認識他，但你暈了...。");
    characEvents[0]->setResultTwo1(0,0,0,0,0,0,"對方覺得你好主動、小小嚇到，不過好感度+20。");
    characEvents[0]->setResultThree1(0,0,0,0,0,0,"其實餅乾過期了，所有吃那包餅乾的人都食物中毒了！好感度-5。");

    characEvents.push_back(new Events(5, 20, -5
        "在舞會活動中，王語崴被全場注目，帥氣地站在舞池中央。你鼓起勇氣靠近他，他剛好在拿飲料。你會選擇...?",
        "1. 主動邀舞：「可以跟我跳一支舞嗎？」/2. 裝作不經意經過：「這飲料好喝嗎？」/3. 小聲自言自語：「這麼多女生圍著他，怎麼可能輪得到我？」"
    ));
    characEvents[1]->setResultOne1(0,0,0,0,0,0,"他有點意外但接受了，你們跳了一支尷尬但不失禮的舞，全場都羨慕死，好感度+8。");
    characEvents[1]->setResultTwo1(0,0,0,0,0,0,"他簡單回答「還行吧」，你們沒有進一步互動，好感度+1。");
    characEvents[1]->setResultThree1(0,0,0,0,0,0,"他聽到你的自言自語，偷偷笑了一下，但沒說什麼，好感度+3。");

    characEvents.push_back(new Events(5, 20, -5
        "你和王語崴在化學實驗被分到同一組，但他全程低頭玩手機。你會選擇...?",
        "1. 主動分工：「我們分一下工作吧，這樣快一點。」/2. 自己一人完成全部工作。/3. 用開玩笑的語氣提醒他：「帥哥，不做事是會扣分的喔！」"
    ));
    characEvents[2]->setResultOne1(0,0,0,0,0,0,"他勉強配合，好感度+5，但你發現他實驗很菜。");
    characEvents[2]->setResultTwo1(0,0,0,0,0,0,"他感激地說：「謝啦！」好感度+10，但你壓力滿滿。");
    characEvents[2]->setResultThree1(0,0,0,0,0,0,"他尷尬地放下手機，努力幫忙，好感度+8。");

    characEvents.push_back(new Events(5, 20, -5
        "你經過音樂教室，聽見王語崴在彈吉他。你會選擇...?",
        "1. 偷偷站在門外聽。/2. 大膽進去讚美：「哇，你彈得好好聽！」/3. 拿起手機偷偷錄影。"
    ));
    characEvents[3]->setResultOne1(0,0,0,0,0,0,"他完全沒注意到你，但你聽得如痴如醉，好感度+1");
    characEvents[3]->setResultTwo1(0,0,0,0,0,0,"他抬頭看了你一眼，微微一笑，好感度+5");
    characEvents[3]->setResultThree1(0,0,0,0,0,0,"他發現後直接停下來，冷冷地看著你：「你幹嘛？」好感度-5");

    characEvents.push_back(new Events(5, 20, -5
        "王語崴在校門口等人，手裡提著一大袋早餐。 你會選擇...?",
        "1. 主動打招呼：「早安！」/2. 假裝不經意經過，看他會不會主動說話。/3. 開玩笑問：「早餐這麼豐盛，分我一點吧！」"
    ));
    characEvents[4]->setResultOne1(0,0,0,0,0,0,"他點點頭回了句「早」，好感度+3。");
    characEvents[4]->setResultTwo1(0,0,0,0,0,0,"他沒有主動說話，你失望離開，也沒有增加好感度。");
    characEvents[4]->setResultThree1(0,0,0,0,0,0,"他大笑，把一個包子遞給你，好感度+10。");

    characEvents.push_back(new Events(5, 20, -5
        "一次分組實驗中，你和王語崴同時伸手去拿實驗器材，結果不小心碰到他的手！他抬頭看了你一眼，沒有說話。你會選擇...?",
        "1. 微微一笑，裝作不在意：「抱歉，借過一下。」/2. 主動問他：「你拿這個是要做什麼？」/3. 有些害羞地縮回手：「啊……不好意思！」"
    ));
    characEvents[5]->setResultOne1(0,0,0,0,0,0,"他點點頭，沒有多說什麼，但注意到你的冷靜，好感度+5。");
    characEvents[5]->setResultTwo1(0,0,0,0,0,0,"他簡單解釋了一下，然後遞給你器材：「給你用吧。」好感度+10。");
    characEvents[5]->setResultThree1(0,0,0,0,0,0,"他稍微皺眉：「沒事，拿去用吧。」好感度+3。");

    characEvents.push_back(new Events(5, 20, -5
        "校慶活動中，王語崴坐在角落低頭玩手機，你猶豫了一下走過去，他抬頭看著你，問：「怎麼了？」。你會選擇...?",
        "1. 鼓起勇氣說：「活動很有趣，要不要一起去看看？」/2. 假裝隨意地問：「你一個人在這裡，不無聊嗎？」/3. 直接問：「我可以坐在這裡嗎？」"
    ));
    characEvents[6]->setResultOne1(0,0,0,0,0,0,"他抬頭看了看你，放下手機說：「好啊，那妳帶路吧。」好感度+15，兩人一起參加活動。");
    characEvents[6]->setResultTwo1(0,0,0,0,0,0,"他淡淡地回：「還好，才剛玩了一下子。」好感度+5，你們沒有進一步互動。");
    characEvents[6]->setResultThree1(0,0,0,0,0,0,"他微微一笑：「可以啊，隨便坐。」好感度+8，兩人安靜坐著聊天。");

    characEvents.push_back(new Events(5, 20, -5
        "運動會上，你在加油時不小心喊出王語崴的名字，他回頭看向你，微微一笑。你會選擇...?",
        "1. 大方招手：「加油啊！」/2. 假裝沒事，快速移開視線。/3. 笑著補充：「你一定可以拿第一！」"
    ));
    characEvents[7]->setResultOne1(0,0,0,0,0,0,"他對你點頭示意，好感度+5。");
    characEvents[7]->setResultTwo1(0,0,0,0,0,0,"他有些疑惑地看了你一眼，好感度+3。");
    characEvents[7]->setResultThree1(0,0,0,0,0,0,"他輕輕笑了一下：「看來你很有信心。」好感度+8。");

    characEvents.push_back(new Events(5, 20, -5
        "某次下課，王語崴主動遞給你一個耳機：「聽聽看這首歌，應該適合你。」你會選擇...?",
        "1. 認真聽：「這歌詞好像在說我，謝謝你分享。」/2. 開玩笑：「你是看我壓力大特地挑的嗎？」/3. 隨口回應：「還行吧，謝謝。」"
    ));
    characEvents[8]->setResultOne1(0,0,0,0,0,0,"他嘴角微微上揚：「以後有好歌再分享。」好感度+10，進入曖昧階段。");
    characEvents[8]->setResultTwo1(0,0,0,0,0,0,"他輕笑：「你壓力還真大。」好感度+8。");
    characEvents[8]->setResultThree1(0,0,0,0,0,0,"氣氛好像有點尷尬，他也沒再多說什麼，好感度+3。");

    characEvents.push_back(new Events(5, 20, -5
        "一次自習結束後，你在教學樓頂碰到王語崴，他正在看晚霞。見到你，他淡淡地說：「風景不錯，你也喜歡嗎？」你會選擇...?",
        "1. 誠實地回答：「是啊，很漂亮，但你比風景更吸引人。」/2. 假裝隨意：「嗯，剛好路過，沒想到會碰到你。」/3. 半開玩笑地說：「你經常一個人看晚霞，不覺得孤單嗎？」"
    ));
    characEvents[9]->setResultOne1(0,0,0,0,0,0,"他側頭看了你一眼，嘴角微微上揚：「真有趣。」好感度+15，氣氛有點微妙。");
    characEvents[9]->setResultTwo1(0,0,0,0,0,0,"他點點頭：「嗯，還不錯吧。」好感度+8，但沒有更進一步的互動。");
    characEvents[9]->setResultThree1(0,0,0,0,0,0,"他笑了一下：「偶爾清靜也不錯，但今晚似乎有點不一樣。」好感度+10，氣氛輕鬆。");

    //10-17: events about character A
    characEvents.push_back(new Events(5, 20, -5
        "你和閨蜜陳愛芬正在圖書館一起念書，她翻著一本厚重的書，突然抬頭看著你，說：「如果我們考不上大學，就一起開奶茶店吧！」。你會選擇...?",
        "1. 認真點頭：「好啊！我們一定會成為全台最強奶茶店長的！」/2. 反駁她：「你才考不上咧，別亂說話，回去念書啦！」/3. 提議另一個計劃：「不然我們去開蛋糕店，我比較喜歡吃甜的！」"
    ));
    characEvents[10]->setResultOne1(0,0,0,0,0,0,"你們感情更好了，但因為太放鬆，今天念書進度微微不足。");
    characEvents[10]->setResultTwo1(0,0,0,0,0,0,"她被激怒但更努力念書，好感度-3，但你們一起多做了一份模擬考。");
    characEvents[10]->setResultThree1(0,0,0,0,0,0,"她覺得你的提議很棒，陷入甜點製作的討論中，考試壓力-10，但進度完全停擺。");
    
    characEvents.push_back(new Events(5, 20, -5
        "陳愛芬來你家熬夜念書，結果不到兩個小時就趴桌睡著了。你會選擇...?",
        "1. 輕輕推醒她：「喂喂，醒來啦！」/2. 幫她蓋上毯子，繼續自己念書。/3. 偷偷拍她的睡相，發到群組。"
    ));
    characEvents[11]->setResultOne1(0,0,0,0,0,0,"她醒來繼續奮鬥，但對你有點不爽，好感度-2，學習效率++。");
    characEvents[11]->setResultTwo1(0,0,0,0,0,0,"她醒來後感激地說謝謝，好感度+10，但你覺得有點孤單，壓力有點大");
    characEvents[11]->setResultThree1(0,0,0,0,0,0,"她醒來發現被偷拍，大叫：「你死定了！」好感度-5，不過你笑翻了。");
    
    characEvents.push_back(new Events(5, 20, -5
        "你和陳愛芬正在討論數學題，她突然說：「要是我們能直接猜題，全猜對就好了！」。你會選擇...?",
        "1. 認真回應：「猜題可不行，還是把公式記熟吧。」/2. 玩笑說：「我有個厲害的水晶球，要不要試試看？」/3. 附和她：「對啊，我們要不要試試跟老師賭題？」"
    ));
    characEvents[12]->setResultOne1(0,0,0,0,0,0,"她笑著說：「你真無聊！」但還是努力念書，好感度+3，學習進度++");
    characEvents[12]->setResultTwo1(0,0,0,0,0,0,"她笑得趴在桌上：「你是認真的嗎？」好感度+5，你們的壓力都在歡笑中變少了一點。");
    characEvents[12]->setResultThree1(0,0,0,0,0,0,"她眼睛發亮，真的開始幻想作弊，好感度+1，但就這樣分心了好久。");

    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[13]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[13]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[13]->setResultThree1(0,0,0,0,0,0,"");

    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[14]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[14]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[14]->setResultThree1(0,0,0,0,0,0,"");

    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[15]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[15]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[15]->setResultThree1(0,0,0,0,0,0,"");

    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[15]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[15]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[15]->setResultThree1(0,0,0,0,0,0,"");

    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[15]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[15]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[15]->setResultThree1(0,0,0,0,0,0,"");
    
    //18-27: events about character B
    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[15]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[15]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[15]->setResultThree1(0,0,0,0,0,0,"");

    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[15]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[15]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[15]->setResultThree1(0,0,0,0,0,0,"");

    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[15]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[15]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[15]->setResultThree1(0,0,0,0,0,0,"");

    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[15]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[15]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[15]->setResultThree1(0,0,0,0,0,0,"");

    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[15]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[15]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[15]->setResultThree1(0,0,0,0,0,0,"");

    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[15]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[15]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[15]->setResultThree1(0,0,0,0,0,0,"");

    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[15]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[15]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[15]->setResultThree1(0,0,0,0,0,0,"");

    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[15]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[15]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[15]->setResultThree1(0,0,0,0,0,0,"");

    characEvents.push_back(new Events(5, 20, -5
        "你會選擇...?",
        ""
    ));
    characEvents[15]->setResultOne1(0,0,0,0,0,0,"");
    characEvents[15]->setResultTwo1(0,0,0,0,0,0,"");
    characEvents[15]->setResultThree1(0,0,0,0,0,0,"");
    
}
