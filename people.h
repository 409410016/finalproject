#ifndef _PEOPLE_
#define _PEOPLE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

#define num_of_cities 5
#define num_in_A 500
#define num_in_B 290
#define num_in_C 670
#define num_in_D 340
#define num_in_E 330

//結構宣告
struct people{
    char ID[50];                                                            //案例編號
    int age;
    char sex;                                                               //性別
    char city;
    char name[50];
    /*<----------->*/
    int remain_day;                                                         //累積隔離天數       
    enum{isolation,quarantine,releases}state;
    /*<----------->*/    
    struct people *pre_inflect_people;                                      //誰是傳染源
    struct people *next;                                                    //下一個輸入人員
    struct people *prev;
};
typedef struct people *people_node;

struct city{                                                                //城市
    int total_people;
    int inflected_people;
    float inflected_rate;
}cities[num_of_cities];                                                     //各城市

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

//basic func()
void add();                                                                 //加入people，同時增加city人數
void add_user();
void update_city();                                                         //更新rate
void delete();                                                              //刪除people，同時減少city人數
void release(int day);
//sort part
ptrTree insert(ptrTree root, ptrTree front, ptrTree node, struct people *tmp, char *element, int big);                //插入node
void find_in_nameTree(ptrTree front, ptrTree nowNode, char *name, int big);                       //找到愈刪除點在nameTree中的位置
void find_in_IDTree(ptrTree front, ptrTree nowNode, struct people* target, int big);                 //找到愈刪除點在nameTree中的位置
void delete_in_tree (ptrTree front, ptrTree nowNode, int big);                                //刪除節點
void traversal(ptrTree root);                                                    //中序遍歷
void sort();                                                                //選擇其中一種tree並中序遍歷它

void search();
struct people *search_people_name(const char ppl_name[]);                   //people資料
struct people *search_people_ID(const char ppl_ID[]);
int search_city(const char ppl_city[]);                                     //city裡面的東西


//funny func
void dice_city(int city);
void clear(char city);
void protest();
void medicine(const char* ppl_name);                                                  //讓people痊癒(修改資料)
void block_days(char city);                                                              //一樣有輸入確診，不過跳過公告(封鎖訊息)即沒有訊息
void immigrate(char city);
#endif
