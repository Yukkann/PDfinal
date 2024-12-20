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
    events[0]->setResultThree1(n,-2*n,-5*n,0,0,-n,"今天文昌帝君開心，沒有給你很大懲罰...",6,20);
    events[0]->setResultThree2(n,-2*n,-5*n,0,0,-n,"今天運氣不好，文昌帝君生氣了，給你下降頭...");

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
    events[2]->setResultTwo2(3*n, -2*n, -4*n, 0, 0, 0, "男人，只會影響我做題的速度（你似乎被討厭了）");
    events[2]->setResultThree1(2*n, 0, n, 0, 0, 2*n, "運氣不錯，他沒有不高興，反而因為你會規劃時間而覺得你很棒", 6, 15);
    events[2]->setResultThree2(2*n, 0, -n, 0, 0, 0, "可惜了，他今天不是很開心，但有給理由他覺得合理");

    // event4
    events.push_back(new Events(
        "在路上遇到推銷股票的店員，他說有一個剛上市的新創公司要你參考看看，你會...?",
        "1. 讀書啊，不要搞那些有的沒的/2. 忽略他然後去找朋友玩/3. 老子賭狗，不試試怎麼知道，本金allin!!"
    ));
    events[3]->setResultOne1(2*n, 0, -n, 0, 0, n, "你認真讀書不碰股票，心情穩定，但被推銷員暗中討厭", 1, 20);
    events[3]->setResultOne2(n, 0, 0, -n, 0, n, "推銷員有點不喜歡你...");
    events[3]->setResultTwo1(0, 0, -n, 0, n, 0, "你忽略他但他一直盧你，但你不怎麼覺得煩", 4, 15);
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
    events[4]->setResultTwo1(-n, n, 2*n, 0, -n, 0, "真巧，你的朋友們也這樣想，一起逃", 2, 15);
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
    events[5]->setResultTwo1(2*n, -n, -n, 0, 0, 0, "好吧，確實要考試了，你的朋友這麼想著...", 2, 15);
    events[5]->setResultTwo2(2*n, -3*n, -2*n, 0, 0, 0, "這人怎麼那麼無情，你的朋友這麼想著...");
    events[5]->setResultThree1(2*n, n, 2*n, 0, n, 0, "朋友覺得你很聰明，雖然很累但你們度過了有意義的時光", 2, 15);
    events[5]->setResultThree2(2*n, 2*n, 3*n, 0, 2*n, 0, "朋友對你的觀感提升不少，聰明na");

    // event7
    events.push_back(new Events(
        "你爸媽今天突然被公司裁員了，家裡氣氛凝重，你想要...?",
        "1. 好好讀書，大人的事小孩不要管/2. 身為孩子必須當一下和事佬，去緩和氣氛/3. 反正我這輩子就這樣了，躺平比較快"
    ));
    events[6]->setResultOne1(2*n, 0, -n, -n, n, 0, "看在你乖乖讀書有成果的份上，爸媽沒有情勒你，但你有點累了", 1, 20);
    events[6]->setResultOne2(2*n, 0, -2*n, -n, n, 0, "書沒讀好還這樣，哎，到底了，你父母這樣覺得...");
    events[6]->setResultTwo1(0, 0, n, 0, n, 2*n, "運氣不錯，你剛好用他們最想聽的話安慰到他們了", 6, 10);
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
    events[7]->setResultThree2(-n,-n,-n,0,2*n,0,"幸好你是弱雞，流浪不了多久，課業沒有完全荒廢，但你好累");

    //event9
    events.push_back(new Events(
        "你家人買的台股綠油油一片，他們心情非常躁，你會...?",
        "1. 跟他們說「啊哈哈我同學美股也綠一片啦」/2. 給他們看紅通通的考卷/3. 安慰他們投資理財有賺有賠，投資前請詳閱公開說明書"
    ));
    events[8]->setResultOne1(0,0,-3*n,0,-n,-n,"你超幸運，他們今天心情沒有燥到很誇張，但還是小不爽",6,30);
    events[8]->setResultOne2(0,0,-4*n,0,-2*n,-n,"你被打了一頓，你在家人心中留下不好印象");
    events[8]->setResultTwo1(-n,0,n,0,0,2*n,"你家人知道你成績不錯，會這樣一定是意外，他們獲得些許安慰",1,20);
    events[8]->setResultTwo2(-n,0,-n,0,0,-n,"家人覺得讀不好書還這樣白目，你被打了一頓");
    events[8]->setResultThree1(n,0,n,0,0,n,"你在安慰的同時學到了一些理財內容，薛爆",1,15);
    events[8]->setResultThree2(0,0,n,0,0,n,"有安慰到，但不多");

    //event10
    events.push_back(new Events("你發現你閨蜜在情人節收到一堆巧克力但你一個都沒收到，你會...?",
    "1. 開始一個人哭/2. 跟閨蜜說他太胖了不適合吃甜的/3. 幫他慶祝，這樣他就會分你一些巧克力"
    ));
    events[9]->setResultOne1(0,0,0,0,2*n,0,"你哭得有點累了",4,15);
    events[9]->setResultOne2(0,0,0,0,3*n,0,"你哭得有點累了");
    events[9]->setResultTwo1(0,-n,-2*n,0,0,0,"閨蜜覺得交情再好也不能這樣，她有點難過",2,20);
    events[9]->setResultTwo2(0,-3*n,-5*n,0,2*n,-n,"閨蜜覺得你超雞掰，開始散佈你是ㄅㄗ的謠言");
    events[9]->setResultThree1(0,n,2*n,0,0,2*n,"閨蜜覺得有你這樣的朋友很幸運，開心～",3,15);
    events[9]->setResultThree2(0,n,2*n,0,0,0,"閨蜜覺得你很讚，好耶～");
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
    events[12]->setResultOne1(0,2*n,2*n,0,0,0,"你幸好你性別正確，他覺得你很有禮貌",2,15);
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
    events[13]->setResultOne1(n,0,0,0,2*n,0,"心無旁騖讀書，成績進步了一點，但你丟得有點累",4,20);
    events[13]->setResultOne2(n,0,0,0,3*n,0,"乖乖讀書，成績進步，但你是弱雞，丟周邊讓你累到虛脫");
    events[13]->setResultTwo1(0,0,n,0,n,n,"商業頭腦get",6,5);
    events[13]->setResultTwo2(2*n,0,n,0,2*n,5*n,"你運氣超差，賣貨被詐騙，不過你已因此學到刑法內容");
    events[13]->setResultThree1(0,n,0,-2*n,n,0,"你耐受度高，覺得這沒什麼",4,25);
    events[13]->setResultThree2(0,0,0,-3*n,n,0,"你哭慘了，最慘的那種，浪費了一天");

    //event15
    events.push_back(new Events(
        "搭捷運因為慣性不小心碰到旁邊的大媽，大媽以為你看上她了，想要告你性騷擾，你會...?",
        "1. 跟她說你是伊斯蘭教的不能吃豬肉/2. 跟她好好解釋慣性是什麼，禮貌道歉並遠離/3. 開始大吵，老娘讀書累一天了還要遇到這種破事"
    ));
    events[14]->setResultOne1(0,2*n,2*n,0,0,-3*n,"你的幽默讓其他路人笑出來了，但大媽不這麼覺得",3,15);
    events[14]->setResultOne2(0,n,n,0,0,-3*n,"只有旁邊的人有笑，但有一部分人覺得有點過分");
    events[14]->setResultTwo1(n,0,n,0,3*n,0,"複習了一下並讓大媽學到一課",1,10);
    events[14]->setResultTwo2(2*n,0,n,0,3*n,0,"獲益良多，自己和大媽");
    events[14]->setResultThree1(0,-2*n,-n,-n,3*n,-n,"大吵一架的你心情沒有變好，反而有點累",4,20);
    events[14]->setResultThree2(0,-2*n,-n,-n,4*n,-n,"大吵一架的你非常累，大家都不覺得你是chill guy");

    //event16
    events.push_back(new Events(
        "你今天讀了一整天的書忘記吃東西，要出門買晚餐時發現腳踏車落鏈，你會...?",
        "1. 不吃了，繼續讀書/2. 用走的過去買，今天要吃東西不然會餓爆/3. 蹲在腳踏車旁邊哭，抱怨這世界的不公平"
    ));
    events[15]->setResultOne1(n,0,0,0,3*n,n,"你真的又爆讀了，很累但值得",1,20);
    events[15]->setResultOne2(2*n,0,0,-n,3*n,n,"你學到了不少，但差點胃穿孔送醫");
    events[15]->setResultTwo1(0,0,0,2*n,-n,n,"你成功吃到東西了，耶比\\>o</",4,15);
    events[15]->setResultTwo2(0,0,0,3*n,-2*n,n,"你體力不好，走得很累，但吃到東西了，讚讚");
    events[15]->setResultThree1(n,0,-n,0,2*n,n,"你哭著哭著悟到人生真理",1,30);
    events[15]->setResultThree2(0,0,-n,0,2*n,n,"你哭但沒人在乎，挺可憐的");

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
    events[17]->setResultThree2(0,0,n,0,0,3*n,"雖然沒什麼朋友，但你看開了");

    //event19
    events.push_back(new Events(
        "你朋友心情好喝酒，但回宿舍後沖澡時暈倒了，這時候你會...?",
        "1. 打電話給110然後確認現場情況/2. 先錄影丟到社群平台再說/3. 打完110後不管他，偷卷"
    ));
    events[18]->setResultOne1(0,2*n,3*n,0,0,-n,"你運氣很好，朋友剛好用三點式落地最小化傷害",6,20);
    events[18]->setResultOne2(0,2*n,3*n,0,0,n,"運氣不好，醫護人員差點以為是你要暗殺他");
    events[18]->setResultTwo1(0,-3*n,-3*n,0,0,-n,"運氣不錯，沒有傳太遠，但還是有人覺得你很過分",6,10);
    events[18]->setResultTwo2(0,-6*n,-6*n,0,2*n,-n,"運氣不好，影片爆紅了，你朋友漸漸疏離你，你身敗名裂並被朋友告，身心俱疲");
    events[18]->setResultThree1(3*n,0,0,0,n,n,"少了一個對手捲起來更得心應手，舒服",1,15);
    events[18]->setResultThree2(4*n,0,0,0,n,n,"卷爛了，舒服，差距就是在喝酒後拉開的");

    //event20
    events.push_back(new Events(
        "你因為分心，不小心把補習班的玻璃門推爆了，補習班事後向你求償，你會...?",
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
        "你的朋友暈船還一直犯花癡，但他暈船對象似乎沒戲，你會...?",
        "1. 跟他直接說沒料，讓他認清現實/2. 爽啦，考試對手又少一個了，暈都暈/3. 跟他一起發瘋"
    ));
    events[20]->setResultOne1(0,-2*n,-3*n,0,0,-n,"你朋友剛好載暈船對象去買飲料，你只有讓他微破防",2,30);
    events[20]->setResultOne2(0,-3*n,-4*n,0,0,-n,"你朋友破防了，他認真覺得很難過，有點想絕交");
    events[20]->setResultTwo1(n,-n,-n,0,0,-n,"能學的已經不多了，基本都熟了",1,20);
    events[20]->setResultTwo2(2*n,-n,-n,0,0,-n,"還有蠻多進步空間，而且進步挺多");
    events[20]->setResultThree1(0,2*n,3*n,0,0,3*n,"你的朋友很感謝你，他很開心",2,20);
    events[20]->setResultThree2(0,2*n,2*n,0,0,3*n,"你的朋友和你感情更進一步了，真不戳");

    //event22
    events.push_back(new Events(
        "你常逛的雜誌店店員是噁男，發現你的雜誌可能被他非禮過，你會...?",
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
    events[22]->setResultTwo1(4*n,3*n,4*n,0,n,3*n,"你超卷，這是很成功的選擇",2,20);
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
    events[23]->setResultTwo2(0,n,2*n,0,n,0,"你的朋友路過看到你在哭便上前安慰，你繼續哭但心情有比較好");
    events[23]->setResultThree1(20*n,0,0,0,5*n,-n,"你閃過一台車，有驚無險，你決定好好讀書",6,100);
    events[23]->setResultThree2(-10*n,0,0,0,0,-n,"你被車撞到了，命危，因此少讀很多書，虧爆");

    //event25
    events.push_back(new Events(
        "期末報告有一個組員完全在狀況外，搞得你們其他人loading很重，你會...?",
        "1. 直接跟他說開，叫他做事及時止損/2. 就讓它擺爛不管他，最後組員名單放在未貢獻的欄位/3. 跟他一起擺爛，反正要大考了，他這樣是難免的"
    ));
    events[24]->setResultOne1(n,2*n,3*n,0,n,0,"跟他吵架讓你有點累了，但其他組員覺得你是英雄",4,30);
    events[24]->setResultOne2(2*n,2*n,3*n,0,2*n,0,"你沒想到吵架那麼累");
    events[24]->setResultTwo1(0,-n,-2*n,0,3*n,0,"少一個人扛很累，其他人對你的風評有點差...",4,25);
    events[24]->setResultTwo2(0,-n,-2*n,0,4*n,0,"你扛了一波大的，累脱，但其他人在你背後說壞話");
    events[24]->setResultThree1(-n,2*n,3*n,0,0,0,"大家都喜歡你，他們都認爲你是chill guy",3,35);
    events[24]->setResultThree2(-n,-n,-2*n,0,0,0,"你人緣似乎不太好，他們對你議論紛紛");

    //event26
    events.push_back(new Events(
        "你走在路上的時候輩電線絆倒，跌倒後檢查發現膝蓋脫臼且脛骨骨折，你會...?",
        "1. 抱怨這世界的不公平，開始哭，自暴自棄/2. 去醫院讀書不錯欸，時不時就有醫學系的進來，可以問問題/3. 難過，選最高樓層病房然後趁其他人不注意一躍而下"
    ));
    events[25]->setResultOne1(0,0,0,0,2*n,0,"大哭一場讓你好了很多",4,30);
    events[25]->setResultOne2(0,0,0,0,3*n,0,"你哭到累了，但是心情輕鬆很多");
    events[25]->setResultTwo1(5*n,0,0,0,n,4*n,"你很幸運，進來的醫生很願意分享知識",6,20);
    events[25]->setResultTwo2(2*n,0,0,0,n,3*n,"可惜，這個醫生有時候會敷衍你，但你還是有學到東西");
    events[25]->setResultThree1(n,0,0,0,10*n,-n,"你剛好掉在放置廢棄病床的空地，受到輕傷，你學到人摔在超厚床墊上死不了",6,90);
    events[25]->setResultThree2(-5*n,-2*n,-3*n,0,20*n,-n,"你嚇到朋友了，受重傷後無法讀書，什麼都沒了");

    //event27
    events.push_back(new Events(
        "你最近發票中了5000元，你會...?",
        "1. 拿5000元買刮刮樂，賭一把/2. 要考試了，把一部分獎金捐給慈善團體/3. 請朋友一起吃一頓好的"
    ));
    events[26]->setResultOne1(0,0,2*n,0,0,30*n,"運氣極好，你刮中1000萬",6,70);
    events[26]->setResultOne2(0,0,2*n,0,0,0,"可惜了，什麼都沒有");
    events[26]->setResultTwo1(0,3*n,4*n,0,0,15*n,"你朋友覺得你很有愛心，你在默默積陰德",3,20);
    events[26]->setResultTwo2(0,2*n,3*n,0,0,15*n,"旁人覺得你很讚，默默做善事運氣一定好");
    events[26]->setResultThree1(0,2*n,3*n,4*n,0,2*n,"你朋友覺得你人好好",2,20);
    events[26]->setResultThree2(0,n,2*n,4*n,0,n,"你朋友雖然交情還沒很好但感情變好了");
    //event28
    events.push_back(new Events(
        "你刮刮樂中1000萬了，好事連連，你會...?",
        "1. 都有1000萬了考個屁試，先爽一年再說/2. 好好運用獎金，拿去給父母投資股票/3. 到文昌廟投10萬香油錢"
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
    events[28]->setResultOne1(-7*n,0,0,0,3*n,4*n,"你心態崩了，一瞬間忘記許多讀完的內容",1,40);
    events[28]->setResultOne2(-2*n,0,0,0,3*n,4*n,"你沒心態了，但你學的不多，忘的也不多");
    events[28]->setResultTwo1(0,0,0,0,5*n,0,"你警急補件，這讓你心有點累",4,30);
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

void EventSystem::setCharacEvents(){
    int n = 5;
    //0-9: events about character C
    characEvents.push_back(new CharacterEvents(5, 15, -5,
        "在補習班遇到班上的跟你很不熟的帥哥王語崴，他從遠遠的地方走來就感覺在散發光芒！你會選擇...?",
        "1. 就這樣默默看著他/2. 去跟他交談，順便跟他要哀居/3. 拿書包裡的餅乾假裝跟所有人分享，有意無意的問他要不要一起吃"
    ));
    characEvents[0]->setResultOne2(0,0,n,0,-n,0,"對方好像有看到你，對你好感度+5，不過你也沒有更認識他，但你暈了...。");
    characEvents[0]->setResultTwo2(0,0,2*n,0,0,0,"對方覺得你好主動、小小嚇到，不過好感度+20。");
    characEvents[0]->setResultThree2(0,-n,-n,0,0,n,"其實餅乾過期了，所有吃那包餅乾的人都食物中毒了！好感度-5。");

    characEvents.push_back(new CharacterEvents(20, 5, 10,
        "在舞會活動中，王語崴被全場注目，帥氣地站在舞池中央。你鼓起勇氣靠近他，他剛好在拿飲料。你會選擇...?",
        "1. 主動邀舞：「可以跟我跳一支舞嗎？」/2. 裝作不經意經過：「這飲料好喝嗎？」/3. 小聲自言自語：「這麼多女生圍著他，怎麼可能輪得到我？」"
    ));
    characEvents[1]->setResultOne2(0,n,2*n,0,n,n,"他有點意外但接受了，你們跳了一支尷尬但不失禮的舞，全場都羨慕死，好感度+20。");
    characEvents[1]->setResultTwo2(0,0,0,0,0,0,"他簡單回答「還行吧」，你們沒有進一步互動，好感度+5。");
    characEvents[1]->setResultThree2(0,0,n,0,0,0,"他聽到你的自言自語，偷偷笑了一下，但沒說什麼，好感度+10。");

    characEvents.push_back(new CharacterEvents(10, 5, 15,
        "你和王語崴在化學實驗被分到同一組，但他全程低頭玩手機。你會選擇...?",
        "1. 主動分工：「我們分一下工作吧，這樣快一點。」/2. 自己一人完成全部工作。/3. 用開玩笑的語氣提醒他：「帥哥，不做事是會扣分的喔！」"
    ));
    characEvents[2]->setResultOne2(n,0,0,0,-n,n,"他勉強配合，好感度+10，但你發現他實驗很菜。");
    characEvents[2]->setResultTwo2(2*n,0,2*n,0,-2*n,n,"他感激地說：「謝啦！」好感度+5，但你壓力滿滿。");
    characEvents[2]->setResultThree2(n,0,n,0,-n,0,"他尷尬地放下手機，努力幫忙，好感度+15。");

    characEvents.push_back(new CharacterEvents(5, 15, -5,
        "你經過音樂教室，聽見王語崴在彈吉他。你會選擇...?",
        "1. 偷偷站在門外聽。/2. 大膽進去讚美：「哇，你彈得好好聽！」/3. 拿起手機偷偷錄影。"
    ));
    characEvents[3]->setResultOne2(0,0,0,0,-n,0,"他完全沒注意到你，但你聽得如痴如醉，好感度+5");
    characEvents[3]->setResultTwo2(0,0,2*n,0,-n,n,"他抬頭看了你一眼，微微一笑，好感度+15");
    characEvents[3]->setResultThree2(0,0,0,0,0,-n,"他發現後直接停下來，冷冷地看著你：「你幹嘛？」好感度-5");

    characEvents.push_back(new CharacterEvents(10, 0, 15,
        "王語崴在校門口等人，手裡提著一大袋早餐。 你會選擇...?",
        "1. 主動打招呼：「早安！」/2. 假裝不經意經過，看他會不會主動說話。/3. 開玩笑問：「早餐這麼豐盛，分我一點吧！」"
    ));
    characEvents[4]->setResultOne2(0,0,2*n,0,0,n,"他點點頭回了句「早」，好感度+10。");
    characEvents[4]->setResultTwo2(0,0,0,0,0,0,"他沒有主動說話，你失望離開，也沒有增加好感度。");
    characEvents[4]->setResultThree2(0,0,n,n,0,0,"他大笑，把一個包子遞給你，好感度+15。");

    characEvents.push_back(new CharacterEvents(5, 20, -5,
        "一次分組實驗中，你和王語崴同時伸手去拿實驗器材，結果不小心碰到他的手！他抬頭看了你一眼，沒有說話。你會選擇...?",
        "1. 微微一笑，裝作不在意：「抱歉，借過一下。」/2. 主動問他：「你拿這個是要做什麼？」/3. 有些害羞地縮回手：「啊……不好意思！」"
    ));
    characEvents[5]->setResultOne2(0,0,2*n,0,0,0,"他點點頭，沒有多說什麼，但注意到你的冷靜，好感度+10。");
    characEvents[5]->setResultTwo2(0,0,n,0,0,0,"他簡單解釋了一下，然後遞給你器材：「給你用吧。」好感度+15。");
    characEvents[5]->setResultThree2(0,0,0,0,0,0,"他稍微皺眉：「沒事，拿去用吧。」好感度+5。");

    characEvents.push_back(new CharacterEvents(15, 5, 10,
        "校慶活動中，王語崴坐在角落低頭玩手機，你猶豫了一下走過去，他抬頭看著你，問：「怎麼了？」。你會選擇...?",
        "1. 鼓起勇氣說：「活動很有趣，要不要一起去看看？」/2. 假裝隨意地問：「你一個人在這裡，不無聊嗎？」/3. 直接問：「我可以坐在這裡嗎？」"
    ));
    characEvents[6]->setResultOne2(0,0,2*n,0,2*n,n,"他抬頭看了看你，放下手機說：「好啊，那你帶路吧。」好感度+15，兩人一起參加活動。");
    characEvents[6]->setResultTwo2(0,0,n,0,0,n,"他淡淡地回：「還好，才剛玩了一下子。」好感度+5，你們沒有進一步互動。");
    characEvents[6]->setResultThree2(0,0,2*n,0,n,0,"他微微一笑：「可以啊，隨便坐。」好感度+10，兩人安靜坐著聊天。");

    characEvents.push_back(new CharacterEvents(10, 5, 15,
        "運動會上，你在加油時不小心喊出王語崴的名字，他回頭看向你，微微一笑。你會選擇...?",
        "1. 大方招手：「加油啊！」/2. 假裝沒事，快速移開視線。/3. 笑著補充：「你一定可以拿第一！」"
    ));
    characEvents[7]->setResultOne2(0,n,n,0,0,n,"他對你點頭示意，好感度+10。");
    characEvents[7]->setResultTwo2(0,0,0,0,0,0,"他有些疑惑地看了你一眼，好感度+5。");
    characEvents[7]->setResultThree2(0,0,2*n,0,0,n,"他輕輕笑了一下：「看來你對我很有信心。」好感度+15。");

    characEvents.push_back(new CharacterEvents(15, 10, 5,
        "某次下課，王語崴主動遞給你一個耳機：「聽聽看這首歌，應該適合你。」你會選擇...?",
        "1. 認真聽：「這歌詞好像在說我，謝謝你分享。」/2. 開玩笑：「你是看我壓力大特地挑的嗎？」/3. 隨口回應：「還行吧，謝謝。」"
    ));
    characEvents[8]->setResultOne2(0,0,n,n,0,0,"他嘴角微微上揚：「以後有好歌再分享。」好感度+15，氣氛有點曖昧。");
    characEvents[8]->setResultTwo2(0,0,n,0,0,0,"他輕笑：「你壓力還真大。」好感度+10。");
    characEvents[8]->setResultThree2(0,0,0,0,0,0,"氣氛好像有點尷尬，他也沒再多說什麼，好感度+5。");

    characEvents.push_back(new CharacterEvents(15, 10, 15,
        "一次自習結束後，你在教學樓頂碰到王語崴，他正在看晚霞。見到你，他淡淡地說：「風景不錯，你也喜歡嗎？」你會選擇...?",
        "1. 誠實地回答：「是啊，很漂亮，但你比風景更吸引人。」/2. 假裝隨意：「嗯，剛好路過，沒想到會碰到你。」/3. 半開玩笑地說：「你經常一個人看晚霞，不覺得孤單嗎？」"
    ));
    characEvents[9]->setResultOne2(0,0,n,0,0,n,"他側頭看了你一眼，嘴角微微上揚：「真有趣。」好感度+15，氣氛有點微妙。");
    characEvents[9]->setResultTwo2(0,0,0,0,0,0,"他點點頭：「嗯，還不錯吧。」好感度+10，但沒有更進一步的互動。");
    characEvents[9]->setResultThree2(0,0,n,0,0,n,"他笑了一下：「偶爾清靜也不錯，但今晚似乎有點不一樣。」好感度+15，氣氛輕鬆。");

    //10-17: events about character A
    characEvents.push_back(new CharacterEvents(10, -5, 5,
        "你和閨蜜陳愛芬正在圖書館一起念書，她翻著一本厚重的書，突然抬頭看著你，說：「如果我們考不上大學，就一起開奶茶店吧！」。你會選擇...?",
        "1. 認真點頭：「好啊！我們一定會成為全台最強奶茶店長的！」/2. 反駁她：「你才考不上咧，別亂說話，回去念書啦！」/3. 提議另一個計劃：「不然我們去開蛋糕店，我比較喜歡吃甜的！」"
    ));
    characEvents[10]->setResultOne2(-n,0,n,0,0,0,"你們感情更好了，但因為太放鬆，今天念書進度微微不足，好感度+10。");
    characEvents[10]->setResultTwo2(0,0,-n,0,n,n,"她被激怒但更努力念書，好感度-5，但你們一起多做了一份模擬考。");
    characEvents[10]->setResultThree2(-n,0,n,0,n,0,"她覺得你的提議很棒，陷入甜點製作的討論中，但讀書進度完全停擺，好感度+5。");
    
    characEvents.push_back(new CharacterEvents(-5, 10, -5,
        "陳愛芬來你家熬夜念書，結果不到兩個小時就趴桌睡著了。你會選擇...?",
        "1. 輕輕推醒她：「喂喂，醒來啦！」/2. 幫她蓋上毯子，繼續自己念書。/3. 偷偷拍她的睡相，發到群組。"
    ));
    characEvents[11]->setResultOne2(n,0,n,0,n,n,"她醒來繼續奮鬥，但對你有點不爽，好感度-5，學習效率++。");
    characEvents[11]->setResultTwo2(2*n,0,n,0,n,2*n,"她醒來後感激地說謝謝，好感度+10，但你覺得有點孤單，而且壓力有點大");
    characEvents[11]->setResultThree2(0,0,0,0,-n,-n,"她醒來發現被偷拍，大叫：「你死定了！」好感度-5，不過你笑翻了。");
    
    characEvents.push_back(new CharacterEvents(5, 15, 10,
        "你和陳愛芬正在討論數學題，她突然說：「要是我們能直接猜題，全猜對就好了！」。你會選擇...?",
        "1. 認真回應：「猜題可不行，還是把公式記熟吧。」/2. 玩笑說：「我有個厲害的水晶球，要不要試試看？」/3. 附和她：「對啊，我們要不要試試跟老師賭題？」"
    ));
    characEvents[12]->setResultOne2(2*n,0,n,0,0,n,"她笑著說：「你真無聊！」但還是努力念書，好感度+5，學習進度++");
    characEvents[12]->setResultTwo2(0,0,2*n,0,-n,0,"她笑得趴在桌上：「你是認真的嗎？」好感度+15，你們的壓力都在歡笑中變少了一點。");
    characEvents[12]->setResultThree2(0,0,n,0,0,0,"她眼睛發亮，真的開始幻想作弊，好感度+10，但她就這樣分心了好久。");

    characEvents.push_back(new CharacterEvents(20, -5, 10,
        "陳愛芬忘記帶文具，向你借計算機。但你發現這是你唯一一台。你會選擇...?",
        "1. 借她：「拿去用吧！我用心算。」/2. 說謊：「我的也沒電了，幫不了你。」/3. 提議：「一起用，但我們得很快互換。」"
    ));
    characEvents[13]->setResultOne2(-n,0,2*n,0,n,n,"她覺得你是超級閨蜜，好感度+20，但你因為心算錯了幾題，也覺得有點小挫折。");
    characEvents[13]->setResultTwo2(n,0,0,0,0,-n,"她勉強笑了笑，但心裡有點不開心，好感度-5。");
    characEvents[13]->setResultThree2(2*n,0,0,0,2*n,n,"她覺得你貼心又務實，好感度+10，但你考試時間變得更緊湊，壓力+5。");

    characEvents.push_back(new CharacterEvents(15, -5, 10,
        "你和陳愛芬剛考完數學，她拉著你說：「快！去全家買炸雞慶祝一下！」。你會選擇...?",
        "1. 點頭答應：「好啊，我也餓死了！」/2. 糾正她：「炸雞熱量太高，吃沙拉比較健康吧？」/3. 提議：「不如回家煮個泡麵慶祝？」"
    ));
    characEvents[14]->setResultOne2(0,0,n,-n,n,0,"你們大吃特吃，超級紓壓，但體重可就沒那麼好看了，不過她對你的好感度+15。");
    characEvents[14]->setResultTwo2(0,0,0,n,0,0,"她翻白眼：「無趣！」好感度-5，但你的健康有顧到。");
    characEvents[14]->setResultThree2(0,0,2*n,0,n,n,"她覺得你很有創意，你們開了一場泡麵品評會，好感度+10。");

    characEvents.push_back(new CharacterEvents(15, 15, 10,
        "你在放學時看到陳愛芬看著日曆發呆，走近一問才想起今天是她的生日。她說：「其實也沒什麼特別的，就隨便過吧。」。你會選擇...?",
        "1. 提議：「怎麼可以隨便過！走，我們去吃大餐！」/2. 認真說：「生日應該好好慶祝，至少買個蛋糕吧！」/3. 開玩笑說：「要不要我送你一張考試全對的保證卡？」"
    ));
    characEvents[15]->setResultOne2(0,n,0,-n,n,0,"她愣了一下，接著開心地笑了：「那我就不客氣了！」好感度+15");
    characEvents[15]->setResultTwo2(0,n,n,0,0,0,"她臉紅點頭：「好啊，陪我一起買吧。」好感度+15。");
    characEvents[15]->setResultThree2(0,n,0,0,0,0,"她笑得趴在桌上：「要是有這種卡就好了！」好感度+10，氣氛變得很歡樂。");

    characEvents.push_back(new CharacterEvents(10, 15, 5,
        "某次晚自習時，A突然趴在桌上，低聲說：「我好累……可不可以休息一下？」。你會選擇...?",
        "1. 靜靜地拍拍她的肩膀：「休息一下吧，我幫你顧書。」/2. 主動把肩膀借給她靠：「要不要靠一下？」/3. 調侃她：「你不是說要超越我嗎？這樣怎麼行？」"
    ));
    characEvents[16]->setResultOne2(0,0,n,0,0,0,"她感激地笑了：「謝謝你...」好感度+10。");
    characEvents[16]->setResultTwo2(0,0,n,0,n,0,"她猶豫了一下，然後輕輕靠在你肩膀上，小聲說：「謝謝……真的很謝謝。」好感度+15。");
    characEvents[16]->setResultThree2(0,0,n,0,n,0,"她揮手假裝生氣：「我才不會輸給你呢！」好感度+5，你們都更有精神了！");

    characEvents.push_back(new CharacterEvents(15, 10, 10,
        "晚自習結束後，你和陳愛芬走在回宿舍的路上，她突然說：「如果我撐不下去，你會一直陪著我吧？」。你會選擇...?",
        "1. 認真回答：「當然，我會一直在你身邊的。」/2. 開玩笑：「只要你保證每天請我喝奶茶。」/3. 小心翼翼地問：「怎麼了？你是不是遇到什麼事了？」"
    ));
    characEvents[17]->setResultOne2(0,2*n,n,0,0,n,"她愣了一下，輕輕笑了：「你真的很溫柔……謝謝你。」好感度+15，你們都覺得內心暖暖的。");
    characEvents[17]->setResultTwo2(0,0,n,0,0,0,"她笑著拍你一下：「好啊，那記得別後悔！」好感度+10。");
    characEvents[17]->setResultThree2(0,n,0,0,0,0,"她沉默了一會兒，低聲說：「沒事，有你陪我就夠了。」好感度+10。");


    //18-27: events about character B
    characEvents.push_back(new CharacterEvents(15, 10, 5,
        "你的青梅竹馬黃梓祺在圖書館搬重重的書，你經過看到他。你會選擇...?",
        "1. 主動幫忙：「我來幫你吧！」/2. 提議交換條件：「幫你搬，但考完你請我喝奶茶。」/3. 站著看笑話：「你這麼壯，應該不需要幫忙吧？」"
    ));
    characEvents[18]->setResultOne2(0,n,0,-n,n,0,"他感激地對你笑，好感度+15，但你的手有點酸。");
    characEvents[18]->setResultTwo2(0,n,0,-n,n,0,"他答應了，並加一句：「那我請大杯的。」好感度+10。");
    characEvents[18]->setResultThree2(0,n,n,0,0,-n,"他忍不住笑了一下，吐槽你：「看來也就只能嘴上幫忙。」好感度+5。");

    characEvents.push_back(new CharacterEvents(10, 5, 15,
        "黃梓祺和你在同一補習班下課，問你：「要不要一起回家？」。你會選擇...?",
        "1. 答應：「好啊，順便聊聊今天的內容。」/2. 拒絕：「不了，我還想留下來複習一下。」/3. 提議：「我們去買晚餐再走吧？」"
    ));
    characEvents[19]->setResultOne2(0,0,n,0,0,0,"他和你一路聊得很開心，好感度+10。");
    characEvents[19]->setResultTwo2(0,0,0,0,0,-n,"他覺得你很努力，雖然有點失望，但也尊重你，好感度+5。");
    characEvents[19]->setResultThree2(0,n,n,0,-n,n,"他開心答應，並主動幫你提書包，好感度+15。");

    characEvents.push_back(new CharacterEvents(15, -5, 0,
        "黃梓祺邀請你來班際籃球比賽幫忙加油，你到了現場，卻發現王語崴也在同隊。你會選擇...?",
        "1. 只專注為黃梓祺加油。/2. 大喊王語崴的名字，想吸引他的注意。/3. 不喊口號，安靜地看完比賽。"
    ));
    characEvents[20]->setResultOne2(0,n,n,0,n,0,"他覺得你支持他，好感度+15。");
    characEvents[20]->setResultTwo2(0,0,-n,0,n,0,"他雖然表面不介意，但心裡有點不開心，好感度-5。");
    characEvents[20]->setResultThree2(0,0,0,0,0,0,"他覺得你心不在焉，但還是感謝你到場，沒有增減好感度，而王語崴沒注意到你。");
    
    characEvents.push_back(new CharacterEvents(15, 10, 5,
        "黃梓祺拉你參加校內跑步比賽，問你：「想要我讓你嗎？」。你會選擇...?",
        "1. 嚴肅回答：「不用，來真的吧！」/2. 自信說：「讓我贏就對了。」/3. 開玩笑：「你應該會輸吧？」"
    ));
    characEvents[21]->setResultOne2(0,0,n,-n,n,0,"他跟你跑完全程，覺得你認真的樣子很有魅力，好感度+15。");
    characEvents[21]->setResultTwo2(0,n,n,0,0,0,"他笑了：「好吧，當我欠你一次。」好感度+10。");
    characEvents[21]->setResultThree2(0,0,0,-n,2*n,0,"他被你激起鬥志，全力衝刺，最後跑贏，好感度+5。");


    characEvents.push_back(new CharacterEvents(-5, 10, 5,
        "黃梓祺邀你晚上去公園跑步。他一邊跑一邊說：「準備學測壓力大，我只能靠運動來發洩了。」這時，他突然問：「你呢？有什麼壓力釋放的方法嗎？」。你會選擇...?",
        "1. 直接回答：「我吃垃圾食物發洩！」/2. 假裝害羞：「我……跟你一起跑步其實就很放鬆了。」/3. 轉移話題：「我壓力太大，跑不動了，去買飲料吧？」"
    ));
    characEvents[22]->setResultOne2(0,0,n,0,0,0,"他笑你不健康，好感度-5，但他決定明天帶健康便當給你。");
    characEvents[22]->setResultTwo2(0,n,n,-n,2*n,0,"他臉紅，默默加快跑步速度，好感度+10。");
    characEvents[22]->setResultThree2(0,n,0,-n,0,0,"你們放棄夜跑一起喝飲料，他覺得你真隨性，好感度+5，但你體重++。");

    characEvents.push_back(new CharacterEvents(10, -5, 15,
        "一次整理教室，黃梓祺突然說：「喂，你還記得我們小時候玩的那個遊戲嗎？」。你會選擇...?",
        "1. 微笑點頭：「記得啊，超幼稚的那個？」/2. 假裝忘了：「是嗎？我怎麼不記得了？」/3. 提議再玩一次：「記得啊！現在玩還來得及嗎？」"
    ));
    characEvents[23]->setResultOne2(0,n,0,0,0,0,"他哈哈大笑：「對吧，真的很蠢。」好感度+10。");
    characEvents[23]->setResultTwo2(0,-n,-2*n,0,0,0,"他表情僵了一下：「不記得就算了。」好感度-5。");
    characEvents[23]->setResultThree2(0,2*n,0,0,0,0,"他笑著說：「你還真是孩子氣。」好感度+15。");

    characEvents.push_back(new CharacterEvents(10, 10, 15,
        "某晚，你收到黃梓祺的電話。他語氣輕鬆地說：「最近考試壓力大，有沒有什麼好笑的事，講來聽聽？」",
        "1. 認真分享一件趣事，逗他笑。/2. 開玩笑：「你不會是想找我聊到半夜吧？」/3. 直接問：「你最近怎麼樣？是不是遇到什麼事了？」"
    ));
    characEvents[24]->setResultOne2(0,n,0,0,0,0,"他大笑著說：「你真的太好笑了，謝啦！」好感度+10。");
    characEvents[24]->setResultTwo2(0,n,n,0,0,0,"他笑著回：「那你得負責陪我聊完！」好感度+10。");
    characEvents[24]->setResultThree2(0,2*n,n,0,0,0,"他停頓了一下，小聲說：「有點……但跟你聊聊就覺得好一點了。」好感度+15，你們的內心都覺得暖暖的。");

    characEvents.push_back(new CharacterEvents(10, 15, 15,
        "放學時突然下起大雨，你和黃梓祺都沒帶傘。他開口說：「怎麼辦？我們只能淋雨回去了。」",
        "1. 提議一起跑回家：「我們比賽看誰跑得快！」/2. 笑著說：「就當作雨中浪漫的體驗吧！」/3. 安排解決方案：「等等，我去借把傘。」"
    ));
    characEvents[25]->setResultOne2(0,n,0,-n,n,0,"他笑著同意，兩人一路奔跑，好感度+10，但衣服濕透。");
    characEvents[25]->setResultTwo2(0,n,0,0,0, 0,"他愣了一下，然後忍不住笑出聲：「你還真有想法！」好感度+15。");
    characEvents[25]->setResultThree2(0,2*n,n,0,0,0,"他驚訝地看著你：「你還真是細心。」好感度+15，雖然天氣很糟，你們的心情卻因為對方而十分雀躍。");

    characEvents.push_back(new CharacterEvents(15, 5, -5,
        "一次走在回家路上，黃梓祺突然說：「你覺得我們小時候的關係跟現在比，有變化嗎？」",
        "1. 認真回應：「當然變了，我們比以前更親了。」/2. 半開玩笑：「變了啊，你現在比以前更吵。」/3. 模糊回答：「也許吧，我也說不清楚。」"
    ));
    characEvents[26]->setResultOne2(0,3*n,3*n,0,0,3*n,"他愣了一下，接著笑著摸摸你的頭：「是啊……我也覺得。」好感度+15，你們就這樣進入了曖昧階段。");
    characEvents[26]->setResultTwo2(0,n,0,0,0,0,"他笑罵你：「虧我這麼認真問。」好感度+5。");
    characEvents[26]->setResultThree2(0,-n,0,0,0,0,"他若有所思，沒再繼續說什麼，好感度-5。");

    characEvents.push_back(new CharacterEvents(10, 15, 5,
        "放學時又又又突然下起了大雨，黃梓祺默默拿出一把傘說：「一起吧，我可不想要你淋感冒。」傘很小，兩人不得不靠得很近。",
        "1. 感激地說：「謝謝你，真貼心。」/2. 開玩笑：「要是感冒了，你會負責照顧我嗎？」/3. 不好意思地說：「傘太小了，要不你先走吧。」"
    ));
    characEvents[27]->setResultOne2(0,n,0,0,0,-n,"黃梓祺看著你笑了笑：「沒什麼，誰叫你是我最好的朋友呢。」好感度+10，你聽了覺得十分感動。");
    characEvents[27]->setResultTwo2(0,2*n,n,0,0,0,"黃梓祺微微紅了臉：「你想讓我負責什麼？說清楚啊！」好感度+15，氣氛有些微妙。");
    characEvents[27]->setResultThree2(0,n,0,0,0,0,"黃梓祺皺眉說：「別傻了，快過來。」好感度+5。");

    
    //28後為多個角色互動情境

    
        // 學力 人緣 魅力 耐力 疲勞 運氣 
    characEvents.push_back(new CharacterEvents(5, 4, -5,
        "在走廊上看見王語崴，他從遠遠的地方走就一直盯著你看！你會選擇...?",
        "1. 就這樣默默看著他/2. 去跟他聊天，邀請他一起去圖書館念書/3. 去跟他聊天，邀請他一起去夜店狂歡"
    ));
    characEvents[28]->setResultOne2(0,0,0,0,0,0,"你們就這樣默默對視一分鐘，好感度+5");
    characEvents[28]->setResultTwo2(2*n,0,0,0,0,0,"對方微微瞳孔地震，他竟然答應你了！好感度+4，一起念書學科能力 + 10");
    characEvents[28]->setResultThree2(0,0,0,0,0,0,"他很驚嚇，並表示自己不喜歡這樣的場合，好感度-5");
    
    characEvents.push_back(new CharacterEvents(-5, 5, 0,
        "王語崴在掃外掃區的女廁，他看起來很辛苦！你會選擇...?",
        "1. 直接進去拉一坨大的/2. 幫他一起掃，把有血的衛生棉清走/3. 不給他帶來麻煩，直接憋著"
    ));
    characEvents[29]->setResultOne2(0,0,0,n,0,0,"臭氣沖天但很舒爽，王語崴對你的印象下降了，好感度-5，體能+5");
    characEvents[29]->setResultTwo2(0,0,2*n,0,0,0,"王語崴感謝你的幫忙，你人真好，好感度+5，魅力+10");
    characEvents[29]->setResultThree2(0,0,0,0,n,0,"你得了膀胱炎了，體能-5，疲勞度+5");

    characEvents.push_back(new CharacterEvents(10, 0, 5,
        "王語崴在上課時睡著了，但現在課上到很重要的地方！你會選擇...?",
        "1. 輕輕拍打他的肩膀，輕柔地呼喚他起床/2. 揉一坨紙球丟他把他叫醒/3. 直接在他課本上畫畫"
    ));
    characEvents[30]->setResultOne2(0,0,4*n,0,0,0,"王語崴醒來了，你發現他有羞紅的一雙耳朵，好感度+10");
    characEvents[30]->setResultTwo2(0,0,0,0,0,4*n,"王語崴沒有醒來，繼續呼呼大睡，幸運值+20");
    characEvents[30]->setResultThree2(0,0,2*n,0,0,0,"你畫得很好，王語崴醒來後難得的稱讚了你的繪畫技巧，好感度+5，魅力+10");

    characEvents.push_back(new CharacterEvents(5, 4, -5,
        "陳愛芬興奮地向你跑來，並在你面前停下，她氣喘吁吁，似乎有什麼話要說，你會選擇...?",
        "1. 拿出手帕給她擦汗/2. 等她喘完再聽他要說什麼/3. 你瀟灑底地冷笑一聲，跑去飲水機裝水"
    ));
    characEvents[31]->setResultOne2(0,0,2*n,0,0,0,"陳愛芬很感謝你，並故作姿態地在手帕上聞了聞，你感到有點不好意思，好感度+5，魅力+10");
    characEvents[31]->setResultTwo2(0,2*n,0,0,0,0,"陳愛芬和你分享了很多有趣的八卦見聞，好感度+4，人緣 + 10");
    characEvents[31]->setResultThree2(0,0,0,2*n,0,0,"陳愛芬滿頭問號，但你喝了很多水變健康了，好感度-5，體能+10");

    characEvents.push_back(new CharacterEvents(0, 5, 0,
        "陳愛芬假日想約你出去逛街喝下午茶，但你那天剛好有補習，你會選擇...?",
        "1. 先答應再說/2. 委婉拒絕/3. 改成約在補習班下課後出去玩"
    ));
    characEvents[32]->setResultOne2(0,2*n,0,0,0,0,"陳愛芬當天剛好臨時有事無法赴約，好險你也是，人緣+10");
    characEvents[32]->setResultTwo2(0,n,0,0,0,0,"陳愛芬說沒關係下次再約，好感+5，人緣+5");
    characEvents[32]->setResultThree2(0,-n,0,0,0,0,"你那天考不及格被留下來課後輔導，陳愛芬在外頭乾等了一個小時，好感-5，人緣-5");

    characEvents.push_back(new CharacterEvents(-10, -5, 10,
        "陳愛芬最近似乎有心事，常常盯著某個點放空，身為她的閨蜜你會選擇...?",
        "1. 當作沒這回事/2. 去向他人打聽她最近的狀況/3. 直接去關心她最近怎麼了"
    ));
    characEvents[33]->setResultOne2(0,0,0,0,-2*n,0,"陳愛芬臉上的陰霾神奇地消失了，好感度-10，疲勞度-10");
    characEvents[33]->setResultTwo2(0,0,0,0,0,0,"陳愛芬誤以為你故意跟她不親近了，心結。好感度-5");
    characEvents[33]->setResultThree2(0,0,2*n,0,0,0,"她告訴你她最近喜歡吃的早餐倒了，她很傷心，好感度+10，人緣+10");

    characEvents.push_back(new CharacterEvents(10, 5, -5,
        "有一天黃梓祺拿著不會的數學題來問你，剛好你也不會，你會選擇...?",
        "1. 直接拿去問老師/2. 一起討論看看想法/3. 站在桌子上一言不發，"
    ));
    characEvents[34]->setResultOne2(2*n,0,0,0,0,0,"黃梓祺很欣賞你不恥下問的精神，好感度+10，學科能力+10");
    characEvents[34]->setResultTwo2(n,0,0,0,0,0,"兩個人討論一天也沒討論出什麼結果，好感度+5，學科能力 + 5");
    characEvents[34]->setResultThree2(0,0,0,0,0,0,"黃梓祺滿頭問號，好感度-5");

    characEvents.push_back(new CharacterEvents(5, 5, 10,
        "黃梓祺在籃球場上打籃球，汗水淋漓的看起來特別閃耀！你會選擇...?",
        "1. 默默在一旁觀察/2. 在場邊跳毛利戰舞，給他助力！/3. 等中場休息給他遞水"
    ));
    characEvents[35]->setResultOne2(0,0,0,0,0,n,"即使這樣，黃梓祺還是看見你了，他很高興你特地來見他，好感度+5，幸運+5");
    characEvents[35]->setResultTwo2(0,0,0,-2*n,0,0,"他一瞬間回過頭去看你，沒想到他一分神沒接到傳球，球砸到你臉上，好感度+5，體能-10");
    characEvents[35]->setResultThree2(0,0,2*n,0,0,0,"黃梓祺像一隻金毛狗狗一樣，在休息時朝著你跑去，好感+10，魅力+10");

    characEvents.push_back(new CharacterEvents(-10, -5, 5,
        "黃梓祺跟你抱怨最近王語崴都不理他，你會選擇...?",
        "1. 要是我是你女朋友，我才不會讓你委屈呢/2. 直接找王語崴輸贏/3.建議他跟王語崴比國際拉屎手勢，增進感情"
    ));
    characEvents[36]->setResultOne2(0,0,0,0,2*n,0,"你是綠茶嗎?黃梓祺略帶嘲諷的說，好感度-10，疲勞值+10");
    characEvents[36]->setResultTwo2(0,0,-2*n,0,0,0,"黃梓祺覺得是你加深了他們之間的嫌隙，好感度-5，魅力-10");
    characEvents[36]->setResultThree2(0,0,2*n,0,0,0,"黃梓祺覺得你很有病，但是過之後沒想到效果卓越，好感度+5，魅力+10");
    
}