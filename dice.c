#include"people.h"

void dice_city(int city){
    char c;
    if(city==0) c='A';
    else if(city==1) c='B';
    else if(city==2) c='C';
    else if(city==3) c='D';
    else if(city==4) c='E';
    
    srand(time(NULL));
    int dice = rand()%5;
    people_node ptr;
    switch(dice){
        case 0:
            clear(c);
            break;
        case 1:
            block_days(c);
            break;
        case 2:
            immigrate(c);
            break;
       case 3:
            ptr = head->next;
            while(ptr->next!= NULL){
                if(ptr->city == c){
                    break;
                }
            } 
            medicine(ptr->name);
            break;
        case 4:
            protest();
            break;
    }
}

void medicine( const char *ppl_name){
    
    struct people *cur =head;
    cur = search_people_name(ppl_name);
    srand( time(NULL) );
    int min = 1;
    int max = 3;
    int x = rand() % (max - min + 1) + min;
    if(x==3)
        cur->remain_day = 0;

}

void clear(char city){
    struct people* ptr;
    ptr = head->next;
    while(ptr!=NULL){
        if (ptr->city == city){
            ptr->state = releases;
            ptr->remain_day = -1;
        }
        ptr = ptr->next;
    }
    return;
}

void protest(){
    srand(time(NULL));
    int dice = rand()%5;
    switch(dice){
        case 0:
            printf("We did a great job! Keep working!\n");
            break;
        case 1:
            printf("City A is totally a mess !!\n");
            break;
        case 2:
            printf("We want to attend WTO to have more resources to against the virus.\n");
            break;
        case 3:
            printf("Whom spread fake news will be fined 300million dollars\n");
            break;
        case 4:
            printf("Humble, humble, more humble\n");
            break;
    }
}

void immigrate(char city){
    people_node ptr;
    ptr = head->next;
    while(ptr->city != city){
        ptr = ptr->next;
    }
    if(ptr->city == 'E'){
        ptr->city = 'A';
    }else{
        ptr->city = ptr->city+1;
    }
    return;
}

void block_days(char city){

}