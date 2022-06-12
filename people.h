#ifndef _PEOPLE_
#define _PEOPLE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define num_of_cities 5
#define num_in_A 50
#define num_in_B 109
#define num_in_C 67
#define num_in_D 340
#define num_in_E 33

//結構宣告
struct people{
    char ID[50];                                        //案例編號
    int age;
    char sex;                                           //性別
    char city;
    char name[50];
    /*<----------->*/
    int remain_day;                             //累積隔離天數       
    enum{isolation,quarantine,release} state;
    /*<----------->*/    
    struct people *pre_inflect_people;                  //誰是傳染源
    struct people *next;                                //下一個輸入人員
    struct people *prev;
};
typedef struct people *people_node;

struct city{                                            //城市
    int total_people;
    int inflected_people;
    float inflected_rate;
}cities[num_of_cities];                                 //各城市

// Binary Search Tree
typedef struct tree *ptrTree;
typedef struct tree
{
    struct people* data;
    ptrTree left;
    ptrTree right;
} tree;
ptrTree rootName;
ptrTree rootID;

//變數宣告
int today;
FILE *fp;
people_node head;
char states[3][11]={"isolation","quarantine","release"};

//basic func()
void add();                           //加入people，同時增加city人數
void add_user();
void update_city();                   //更新rate
void delete();                        //刪除people，同時減少city人數
//sort part
void insert(ptrTree, ptrTree, struct people *, char *, int); //插入node
void find_in_nameTree(ptrTree, ptrTree, char *, int);        //找到愈刪除點在nameTree中的位置
void find_in_IDTree(ptrTree, ptrTree, struct people*, int);          //找到愈刪除點在nameTree中的位置
void delete_in_tree (ptrTree, ptrTree, int);                         //刪除節點
void traversal(ptrTree);                                     //中序遍歷
void sort();                                 //選擇其中一種tree並中序遍歷它

struct people *search_people_name(const char ppl_name[]);           //people資料
struct people *search_people_ID(const char ppl_ID[]);
int search_city(const char ppl_city[]);           //city裡面的東西

/*FILE_I()
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
*/
#endif
