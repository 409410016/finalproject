確診隔離人員資料庫(new virus)

2種搜尋
    1.人類個資搜尋
    2.傳染鏈查詢
command:
    n:next day

operation(工作內容):
    add:
        add people 
    delete:
        若被解隔及delete
    print all item:
        print formfat(可以選要people or city)
            再將各資料全印出
    sort:
        
    search:
        (Given certain infromation about the item to search?)
        基本資料搜尋:姓名、ID、編號、年齡、地區
    file I/O:(opinion?)
        5/13    +450000
        danny wong  female  ...
        ...
    funny func():(maybe divided in to 2 pieces?)
        print funny words or change the data in the system


//data structure

char states[4]={"隔離","居家","解隔"};

typedef struct people *people_node;
struct people{
    char ID[50];                                        //案例編號
    int age;
    char sex;                                           //性別
    char name[50];
    int remain_day;                                     //累積隔離天數
    enum{taipei,kauo,tainai....}c;
    struct people *pre_inflect_people;
    struct people *next;                                //下一個輸入人員
    int state;                                          //0,1,2
};

struct city{                                            //城市
    int total_people;
    int inflected_people;
    float inflected_rate;
    int death;
    double death_rate;
}cities[10];                                            //各城市

//funny func
clear()                         //清零
shorten_remain_day()            //縮短隔天數
fined()                         //300萬罰款
apply_for_WHO()                 //申請加入世衛
medicine()                      //讓people痊癒
todays_news()                   //按下next day command會有今日公告
next_days()                     //好幾天都沒有確診
block_days()                    //都沒有公告確診
move_paitient()                 //轉移確診人數