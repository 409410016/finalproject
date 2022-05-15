
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