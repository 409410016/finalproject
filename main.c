#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define num_of_cities 5

int num_of_people; //目前人數
int today; //今天第幾天

// 1 Amy F 18 A(city) //sex
typedef struct people* ptr_people;
struct people{
    char ID[50];                            //案例編號
    char name[50];
    char sex;
    enum state{};
    int age;
    int remain_day;                         //累積隔離天數
    enum City{A,B,C,D,E}reside;             //所在城市
    struct people *pre_inflect_people;      //誰是傳染源
    struct people *prev;
    struct people *next;                    //下一個輸入人員
};

//城市
struct city{
    int total_people;                       // 總人口
    int inflect, death;                     // 感染人數，死亡人數?
    double inflected_rate, death_rate;      // 感染率，死亡率
}cities[num_of_cities]; 

struct people *head;
ptr_people dataArray[100]={NULL};                     //用於排序

void init();
void add();
void delete();
void print_all();
int* search_people();
int* search_city();
void search();
void chain();
void print_people(*);
void print_city(*);
void sort();
void release();
void city_update();

int main(){
    
    init(); // initialized and input city info

    //每天
    while(){
        // read data
        // day4 +5
        // basic operation
        char instruct[10];
        while(scanf("%s",&instruct)){
            if(!strcmp(instruct,"ADD")) add();
            else if(!strcmp(instruct,"DELETE")) delete();
            else if(!strcmp(instruct,"TRAVERSE")) print_all();
            else if(!strcmp(instruct,"SEARCH")) search();
            else if(!strcmp(instruct,"SORT")) sort();
            else if(!strcmp(instruct,"END")) break;
        }
        // daily report
        // release
        release();
    }

    return 0;
}

void init(){
    // build city and initialized
    for(int i=0;i<num_of_cities;i++){
        scanf("%d",&cities[i].total_people);
        cities[i].inflect = 0;
        cities[i].death = 0;
        cities[i].inflected_rate = 0;
        cities[i].death_rate = 0;
    }
    // struct head
    head = (struct people*)malloc(sizeof(struct people));
    head->next = NULL;
}

void add(){
    // 新增人員
    // 累加當天人數
    // 結束時更新city資料
    update_city(); 
}

void delete(){
    // 搜尋並刪除任意人員
    search_people(); // 會回傳該名成員指標
    // 結束時更新city資料
    update_city(); 
}

void print_all(){
    // 人員基本資料
    struct people *cur;
    cur = head->next;
    while (cur != NULL) {
        cur = cur->next;
    }
    printf("\n");
    
    // 城市資料
    printf("City\tTotal\tinflect\tinflect rate\tdeath\tdeath rate\n");
    for(int i=0;i<num_of_cities;i++){
        print_city(i);
    }
    printf("\n");
}

void search(){
    // 二選一
    search_people(); // 指標
    print_people(); // 傳入指標
    chain(); // 傳入指標，尋找傳播鏈
    // 
    search_city(); // 指標
    print_city(); // 傳入指標
}

struct people *search_people(){
    // 回傳該名成員指標
}

struct people *search_people(){
    // 回傳該名成員指標
}

void print_people(){
    // 傳入指標，印出
    printf("%s\t%s\t%d\t%d\n", cur->ID, cur->name, cur->age, cur->remain_day);
}

void print_city(){
    // 傳入指標，印出
    printf("%d\t%d\t%d\t%f\t%d\t%f\n", i, cities[i].total_people, cities[i].inflect, cities[i].inflected_rate, cities[i].death, cities[i].death_rate);
}

void chain(){
    // 傳入指標
    // 搜尋傳播鍊，印出
}

void sort(){
    // 
}

void release(){
    // 縮短天數-1
    // 如果額滿，delete
}

