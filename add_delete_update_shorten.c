#include"main.c"

typedef struct people* people_node;

void add(){                 //新增人員、累加當天人數、結束時更新city資料(1 Amy F 18 A)              \\qusetion: input file name?  init remain day?? init state?? *next is who??
    char temp[1024];
    fgets(temp,1024,);              //input file
    char *id,*name,*age,*sex,*city,*chop;
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

    struct people *ptr,*temptr;
    ptr = (struct people*)malloc(sizeof(struct people));
    temptr= head;
    while( temptr->next != NULL){
        temptr = temptr->next;
    }
    temptr->next = ptr;
    ptr->next = NULL;
    strcpy(ptr->ID,id);
    strcpy(ptr->name,name);
    ptr->age = stoi(age);
    strcpy(ptr->sex,sex);
    ptr->reside = (*city);
    cities[ptr->reside].inflect++;
    update_city();
}

void delete(){                      // 搜尋並刪除任意人員   結束時更新city資料
    people_node ptr;
    ptr = search_people();                        // 會回傳該名成員指標
    cities[ptr->reside].inflect--;
    free(ptr);                                  
    update_city(); 
}