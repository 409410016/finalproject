#include"people.h"
#include"add_delete_update_shorten.c"
#include"sort.c"
#include"search_ppl_or_city.c"
#include"dice.c"

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
    return;
}

void print_all(){
    // 人員基本資料
    struct people *cur;
    cur = head->next;
    printf("%s\t%s\t%d\t%d\n", cur->ID, cur->name, cur->sex, cur->age, cur->cuty, cur->remain_day);
    while (cur != NULL) {
        printf("%s\t%s\t%c\t%d\t%c\t%d\t", cur->ID, cur->name, cur->sex, cur->age, cur->city, cur->remain_day);
        if(cur->state==0) printf("isolation\n");
        else if(cur->state==1) printf("quarantine\n");
        else if(cur->state==2) printf("release\n");
        cur = cur->next;
    }
    printf("\n");
    
    // 城市資料
    printf("City\tTotal\tinflect\tinflect rate\n");
    printf("A\t%d\t%d\t%f\n", cities[i].total_people, cities[i].inflect, cities[i].inflected_rate);
    printf("B\t%d\t%d\t%f\n", cities[i].total_people, cities[i].inflect, cities[i].inflected_rate);
    printf("C\t%d\t%d\t%f\n", cities[i].total_people, cities[i].inflect, cities[i].inflected_rate);
    printf("D\t%d\t%d\t%f\n", cities[i].total_people, cities[i].inflect, cities[i].inflected_rate);
    printf("E\t%d\t%d\t%f\n", cities[i].total_people, cities[i].inflect, cities[i].inflected_rate);
}

int main(){
    
    init(); // initialized and input city info
    
    //初始化根節點
    rootName = malloc(sizeof(tree));
    rootName->data = NULL, rootName->left = NULL, rootName->right = NULL;
    rootID = malloc(sizeof(tree));
    rootID->data = NULL, rootID->left = NULL, rootID->right = NULL;
    
    FILE* fp;
    fp = fopen("data.txt","r");
    
    //每天
    while(){
        // read data
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




void search(){
    // 二選一
    search_people(); // 指標
    print_people(); // 傳入指標
    chain(); // 傳入指標，尋找傳播鏈
    // 
    search_city(); // 指標
    print_city(); // 傳入指標
}
