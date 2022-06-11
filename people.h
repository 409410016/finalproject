#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char states[4]={"隔離","居家","解隔"};

typedef struct people *people_node;
struct people{
    char ID[50];                                        //案例編號
    int age;
    char sex;                                           //性別
    char name[50];
    int remain_day;                                     //累積隔離天數
    enum{taipei,kauo,tainai....}c;
    struct people *pre_inflect_people;                  //誰是傳染源
    struct people *next;                                //下一個輸入人員
    int state;                                          //狀態
};

struct city{                                            //城市
    int total_people;
    int inflected_people;
    float inflected_rate;
    int death;
    double death_rate;
}cities[5];                                            //各城市

/ Binary Search Tree
typedef struct tree *ptrTree;
typedef struct tree
{
    struct people* data;
    ptrTree left;
    ptrTree right;
} tree;
ptrTree rootName;
ptrTree rootID;

//basic func()
add()                           //加入people，同時增加city人數
city_update()                   //更新rate
delete()                        //刪除people，同時減少city人數
shorten_remain_day_iter()       //更新people隔離天數且檢查state
print_all()
sort_ID()
sort_name()
search_people()                 //people資料
search_city()                   //city裡面的東西
FILE_I()
FILE_O()

//funny func
clear()                         //清零(改公告)
shorten_remain_day()            //縮短隔天數(每天)
fined()                         //300萬罰款
apply_for_WHO()                 //申請加入世衛
medicine()                      //讓people痊癒(修改資料)
todays_news()                   //按下next day command會有今日公告
//(保留)   next_days()                     //好幾天都沒有確診
block_days()                    //一樣有輸入確診，不過跳過公告(封鎖訊息)即沒有訊息
move_paitient()                 //轉移確診人數(city間的轉換)
