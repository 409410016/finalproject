#include"people.h"
#include"add_delete_update_shorten.c"
#include"sort.c"
#include"search_ppl_or_city.c"
#include"dice.c"

void init();
void print_all();
int* search_people();
int* search_city();
void search();
void chain();
void print_people(*);
void print_city(*);

int main(){
    
    init(); // initialized and input city info
    
    //初始化根節點
    rootName = malloc(sizeof(tree));
    rootName->data = NULL, rootName->left = NULL, rootName->right = NULL;
    rootID = malloc(sizeof(tree));
    rootID->data = NULL, rootID->left = NULL, rootID->right = NULL;
    
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
    cities[0].total_people = num_in_A;
    cities[1].total_people = num_in_B;
    cities[2].total_people = num_in_C;
    cities[3].total_people = num_in_D;
    cities[4].total_people = num_in_E;
    for(int i=0;i<num_of_cities;i++){
        cities[i].inflect = 0;
        cities[i].inflected_rate = 0;
    }
    // struct head
    head = (struct people*)malloc(sizeof(struct people));
    head->next = NULL;
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

