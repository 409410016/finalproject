#include"main.c"

//qusetion: input file name?data.txt 


//work to do:create pointer array(delete->NULL)

typedef struct people* ptr_people;



void add(){                 //新增人員、累加當天人數、結束時更新city資料(1 Amy F 18 A (id))             指標陣列要加入值
    char temp[1024];
    FILE* fp;
    fp = fopen("data.txt","r");
    fgets(temp,1024,fp);              //input file
    fclose(fp);
    char *id,*name,*age,*sex,*city,*chop,*pre_id;
    chop = strtok(temp," ");
    id = chop;
    chop = strtok(NULL," ");
    name = chop;
    chop = strtok(NULL," ");
    age = chop;
    for(int i = 0; i >= 0; i++ ){
        if(*(age+i) > 47 && *(age+i) < 58  ){
            continue;
        }else if(age+i == NULL){
            break;
        }else{
            printf("invalid input!\n");
            return;
        }
    }
    chop = strtok(NULL," ");
    sex = chop;
    if(*sex != 'F' || *sex != 'M'){
        printf("invalid input!\n");
        return;
    }
    chop = strtok(NULL," ");
    city = chop;
    if( *city != 'A' || *city != 'B' || *city != 'C' || *city != 'D' || *city != 'E'){
        printf("invalid input!\n");
        return;
    }
    chop = strtok(NULL," ");
    pre_id = chop;
    ptr_people qtr;
    qtr = head;
    int check = 0;
    while(qtr->next!= NULL){
        if(strcmp(pre_id,qtr->ID) == 0){
            check = 1;
            break;
        }
        qtr = qtr->next;
    }
    if(check == 0){
        printf("invalid input!\n");
        return; 
    }

    ptr_people ptr,temptr,preinflect;
    ptr = (ptr_people)malloc(sizeof(struct people));
    dataArray[dataNumber++] = ptr;
    temptr= head;
    while( temptr->next != NULL){                                       //從後面加入node
        temptr = temptr->next;
    }
    temptr->next = ptr;
    ptr->next = NULL;
    ptr->prev = temptr;
    temptr = head;
    while(strcmp(temptr->ID,pre_id) != 0){                              //感染源
        temptr = temptr->next;
    }
    ptr->pre_inflect_people = temptr;
    strcpy(ptr->ID,id);
    strcpy(ptr->name,name);
    ptr->age = stoi(age);
    strcpy(ptr->sex,sex);
    ptr->reside = (*city);
    cities[ptr->reside].inflect++;
    ptr->remain_day = 7;
    ptr->state = 0;
    update_city();
    return;
}

//刪除分chain刪除(有無傳染源)跟鏈上刪除

void delete(){                      // 搜尋並刪除任意人員   結束時更新city資料                  (使用者選擇要根據什麼刪除(未做))
    ptr_people ptr,temp,qtr;
    ptr = search_people();                        // 會回傳該名成員指標
    qtr = ptr->pre_inflect_people;
    cities[ptr->reside].inflect--;
    ptr->prev->next = ptr->next;                    //鏈上刪除
    ptr->next->prev = ptr->prev;
    temp = head;
    int check = 0;
    while(temp->next != NULL){
        if(strcmp(ptr->ID,temp->ID) == 0){
            check = 1;
            break;
        }
        temp = temp->next;
    }
    if(check == 0){
        printf("invalid input!\n");
        return;
    }

    temp = head;
    while(temp->next != NULL){
        if(strcmp(temp->ID,ptr->ID) == 0){
            temp->pre_inflect_people = qtr;
        }
    }
    for(int i=0;i<dataNumber;i++){
        if(dataArray[i] == qtr){
            dataArray[i] = NULL;
        }
    }
    free(ptr);                                      //指標陣列要改為null
    update_city();
    return;
}

void update_city(){
    for(int i=0;i<5;i++){
        cities[i].inflected_rate = cities[i].inflect/cities[i].total_people;
        cities[i].death_rate = cities[i].death/cities[i].total_people;
    }
    return;
}

void release(int day){
    ptr_people ptr;
    ptr = head->next;
    while(ptr->next != NULL){                   //未完
        if(ptr->remain_day > day){
            ptr->remain_day-=day;
        }else if(ptr->remain_day == day && ptr->state == 0){
            ptr->remain_day = 7;
            ptr->state = 1;
        }else if(ptr->remain_day == day && ptr->state == 1){
            ptr->remain_day = -1;
            ptr->state = 2;
        }
    }
    return;
}
//char states[4]={"隔離","居家","解隔"};                remain_day 7   7  -1 