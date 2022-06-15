#include"people.h"

void dice_city(int city){
    char c;
    if(city==0) c='A';
    else if(city==1) c='B';
    else if(city==2) c='C';
    else if(city==3) c='D';
    else if(city==4) c='E';    
    int dice = rand()%5;
    people_node ptr;
    printf("Now is City %c's Mayor to do his job!!\n",c);
    switch(dice){
        case 0:
            printf("City %c is going to clear the city\n",c);
            clear(c);
            break;
        case 1:
            block_days(c);
            break;
        case 2:
            printf("City %c's first citizen is going to immigrate to another city!!\n",c);
            immigrate(c);
            break;
       case 3:
            printf("City %c get medicine to cure his citizen.\n",c);
            ptr = head->next;
            while(ptr->next!= NULL){
                if(ptr->city == c){
                    break;
                }
                ptr = ptr->next;
            } 
            medicine(ptr->name);
            break;
        case 4:
            protest();
            break;
    }
}

void medicine( const char *ppl_name){
    
    struct people *cur;
    cur = search_people_name(ppl_name);
    int min = 1;
    int max = 3;
    int x = rand() % (max - min + 1) + min;
    if(x==3 && cur->state == 0){
        cur->state = 1;
        cur->remain_day = 7;
    }else if(x==3 && cur->state == 1){
        cur->state = 2;
        cur->remain_day = -1;
    }
    return;
}

void clear(char city){
    struct people* ptr;
    ptr = head->next;
    cities[city-65].inflected_people = 0;
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
    while(ptr != NULL){
        if(ptr->city == city){
            continue;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL){
        return;
    }
    cities[ptr->city-65].inflected_people--;
    cities[ptr->city-65].total_people--;
    if(ptr->city == 'E'){
        ptr->city = 'A';
        cities[ptr->city-65].inflected_people++;
        cities[ptr->city-65].total_people++;
        update_city();
    }else{
        ptr->city = ptr->city+1;
        cities[ptr->city-65].inflected_people++;
        cities[ptr->city-65].total_people++;
        update_city();
    }
    return;
}

void block_days(char city){                                                 //block city (no input)
    printf("City %c is blocked right now!!\n",city);
    printf("There won't appear any inflected person in city %c\n",city);
    city_state[city-65] = 1;
    return;
}