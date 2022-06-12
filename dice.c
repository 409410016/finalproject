#include"people.h" 
#include <time.h>

void dice(int city){
    char c;
    if(city==0) c='A';
    else if(city==1) c='B';
    else if(city==2) c='C';
    else if(city==3) c='D';
    else if(city==4) c='E';
    
    srand(time(NULL));
    int dice = rand()%6;
    switch(dice){
        case 0:
            break;
        case 1:
            clear(c);
            break;
        case 2:
            block_days(c);
            break;
        case 3:
            immigrate(c);
            break;
        case 4:
            medicine(c);
            break;
        case 5:
            protest();
            break;
    }
}

void medecine( const char *ppl_name)
{
    
    struct people *cur =*head;
    if (strcmp(cur->city, ppl_name))
    {
        cur = cur->next;
    }
    else
    {
        srand( time(NULL) );
        int min = 1;
        int max = 3;
        int x = rand() % (max - min + 1) + min;
        if(x==3)
            cur->remain_day = 0;
    }
}

void clear(const char *ppl_name){
    struct people* ptr;
    ptr = head->next;
    while(ptr!=NULL){
        if (!strcmp(cur->city, ppl_name)){
            ptr->state = release;
            ptr->remain_day = -1;
        }
        ptr = ptr->next;
    }
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
